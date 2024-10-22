/**
 *
 *  _____ __    _ _ _   
 * |   __|  |  | | | |  
 * |  |  |  |__| | | |  
 * |_____|_____|_____| 
 *
 * MIT License
 *
 * Copyright (c) 2024 Alves Quentin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **/

#include "__glw_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderPass::GlwRenderPass( )
    : m_framebuffer{ },
    m_targets{ },
    m_color_blend{ },
    m_dimensions{ 1280, 720 },
    m_refresh{ 1.f, .256f, .512f, .0f },
    m_clear_flags{ GL_COLOR_BUFFER_BIT }
{ }

bool GlwRenderPass::Create( const GlwRenderPassSpecification& specification ) {
    auto result = m_framebuffer.Create( ) && 
                  m_targets.Create( m_framebuffer, specification, m_clear_flags );

    if ( result )
        m_color_blend.Create( specification.ColorBlend );

    return result;
}

void GlwRenderPass::SetRefreshColor( const glm::vec4& color ) {
    m_refresh = color;
}

void GlwRenderPass::Use( ) {
    m_framebuffer.Use( );
    m_targets.Use( );
    m_color_blend.Use( );

    glViewport( 0, 0, m_dimensions.x, m_dimensions.y );
    glScissor( 0, 0, m_dimensions.x, m_dimensions.y );
    glClearColor( m_refresh.r, m_refresh.g, m_refresh.b, m_refresh.a );
    glClear( m_clear_flags );
}

void GlwRenderPass::Destroy( ) {
    m_targets.Destroy( );
    m_framebuffer.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderPass::GetIsValid( ) const {
    return m_framebuffer.GetIsValid( );
}

glm::ivec2 GlwRenderPass::GetDimensions( ) const {
    return m_dimensions;
}

glm::vec4 GlwRenderPass::GetRefreshColor( ) const {
    return { m_refresh };
}

const glTexture GlwRenderPass::GetColorAttachement( const uint32_t target ) const {
    return m_targets.GetColorAttachement( target );
}

const glTexture GlwRenderPass::GetDepthAttachement( ) const {
    return m_targets.GetDepthAttachement( );
}

const glTexture GlwRenderPass::GetStencilAttachement( ) const {
    return m_targets.GetStencilAttachement( );
}

const glTexture GlwRenderPass::GetAttachement(
    const GlwRenderAttachementTypes type,
    const uint32_t target
) const {
    auto texture = GL_TEXTURE_NULL;
    
    switch ( type ) {
        case GlwRenderAttachementTypes::Color   : texture = GetColorAttachement( target ); break;
        case GlwRenderAttachementTypes::Depth   : texture = GetDepthAttachement( ); break;
        case GlwRenderAttachementTypes::Stencil : texture = GetDepthAttachement( ); break;

        default : break;
    }

    return texture;
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderPass::operator bool( ) const {
    return GetIsValid( );
}
