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
GlwRenderTargetManager::GlwRenderTargetManager( )
    : m_colors{ },
    m_depth{ },
    m_stencil{ }
{ }

bool GlwRenderTargetManager::Create( 
    const GlwRenderPassTargetSpecification& specification,
    const glm::uvec2& dimensions,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    return  m_colors.Create( specification.Color, dimensions, framebuffer, clear_flags ) &&
            CreateDepthStencil( specification, dimensions, framebuffer, clear_flags );
}

void GlwRenderTargetManager::Use( ) {
    m_depth.Use( );
    m_stencil.Use( );
}

void GlwRenderTargetManager::Destroy( ) {
	m_stencil.Destroy( );
	m_depth.Destroy( );
	m_colors.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderTargetManager::CreateDepthStencil(
    const GlwRenderPassTargetSpecification& specification,
    const glm::uvec2& dimensions,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    auto result = false;

    if ( specification.Depth.State == GlwStates::Enable || specification.Stencil.State == GlwStates::Enable ) {
        if ( specification.Depth.State == GlwStates::Enable && specification.Stencil.State == GlwStates::Enable ) {
            auto depth_stencil_spec = GlwDepthTargetSpecification{
                GlwTextureFormats::Depth_Stencil,
                GlwTextureLayouts::D24_S08,
                specification.Depth.Parameters
            };
            
            result = m_depth.Create( depth_stencil_spec, dimensions, framebuffer, clear_flags );

            m_stencil.Setup( specification.Stencil, clear_flags );
        } else if ( specification.Depth.State == GlwStates::Enable )
            result = m_depth.Create( specification.Depth, dimensions, framebuffer, clear_flags );
        else if ( specification.Stencil.State == GlwStates::Enable ) 
            result = m_stencil.Create( specification.Stencil, dimensions, framebuffer, clear_flags );
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
uint32_t GlwRenderTargetManager::GetColorAttachementCount( ) const {
    return m_colors.GetCount( );
}

const glTexture GlwRenderTargetManager::GetColorAttachement( const uint32_t target ) const {
    return m_colors.GetAttachement( target );
}

const glTexture GlwRenderTargetManager::GetDepthAttachement( ) const {
    return m_depth.GetAttachement( );
}

const glTexture GlwRenderTargetManager::GetStencilAttachement( ) const {
    return m_stencil.GetAttachement( );
}
