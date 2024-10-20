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
    m_colors{ },
    m_color_blend{ },
    m_depth{ },
    m_stencil{ },
    m_dimensions{ 1280, 720 },
    m_refresh{ 1.f, .256f, .512f, .0f },
    m_clear_flags{ GL_COLOR_BUFFER_BIT }
{ }

bool GlwRenderPass::Create( const GlwRenderPassSpecification& specification ) {
    auto result = m_framebuffer.Create( )                                      &&
                  m_colors.Create( m_framebuffer, specification.ColorTargets ) &&
                  CreateDepthAttachement( specification.DepthTarget )          &&
                  CreateStencilAttachement( specification.StencilTarget );

    if ( result )
        m_color_blend.Create( specification.ColorBlend );

    return result;
}

void GlwRenderPass::SetRefreshColor( const glm::vec4& color ) {
    m_refresh = color;
}

void GlwRenderPass::Use( ) {
    m_framebuffer.Use( );
    m_color_blend.Use( );
    m_depth.Use( );
    m_stencil.Use( );

    glViewport( 0, 0, m_dimensions.x, m_dimensions.y );
    glScissor( 0, 0, m_dimensions.x, m_dimensions.y );
    glClearColor( m_refresh.r, m_refresh.g, m_refresh.b, m_refresh.a );
    glClear( m_clear_flags );
}

void GlwRenderPass::Destroy( ) {
    m_stencil.Destroy( );
    m_depth.Destroy( );
    m_colors.Destroy( );
    m_framebuffer.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderPass::CreateDepthAttachement( const GlwDepthTargetSpecification& specification ) {
    auto result = true;

    if ( specification.Enable ) {
        m_clear_flags |= GL_DEPTH_BUFFER_BIT;

        result = m_depth.Create( specification );

        if ( result ) {
            auto texture = m_depth.Get( );

            m_framebuffer.Link( GL_DEPTH_ATTACHMENT, texture );
        }
    }

    return result;
}

bool GlwRenderPass::CreateStencilAttachement( const GlwStencilTargetSpecification& specification ) {
    auto result = true;

    if ( specification.Parameters.Enable ) {
        m_clear_flags |= GL_STENCIL_BUFFER_BIT;

        if ( m_depth.GetIsValid( ) ) {
            auto texture = m_depth.Get( );

            m_stencil.Setup( specification );
            m_framebuffer.Link( GL_STENCIL_ATTACHMENT, texture );
        } else {
            result = m_stencil.Create( specification );

            if ( result ) {
                auto texture = m_stencil.Get( );

                m_framebuffer.Link( GL_STENCIL_ATTACHMENT, texture );
            }
        }
    }

    return result;
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

const glTexture GlwRenderPass::GetColorAttachement( const uint32_t attachement ) const {
    return m_colors.GetAttachement( attachement );
}

const glTexture GlwRenderPass::GetDepthAttachement( ) const {
    return m_depth.Get( );
}

const glTexture GlwRenderPass::GetStencilAttachement( ) const {
    return m_stencil.Get( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderPass::operator bool( ) const {
    return GetIsValid( );
}
