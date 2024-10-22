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
{ }

bool GlwRenderTargetManager::Create( 
    const GlwRenderPassTargetSpecification& specification,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    return  m_colors.Create( framebuffer, specification.Colors )                    &&
            CreateDepthAttachement( specification.Depth, framebuffer, clear_flags ) &&
            CreateStencilAttachement( specification.Stencil, framebuffer, clear_flags );
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
bool GlwRenderTargetManager::CreateDepthAttachement(
    const GlwDepthTargetSpecification& specification,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    auto result = true;

    if ( specification.Enable ) {
        clear_flags |= GL_DEPTH_BUFFER_BIT;

        result = m_depth.Create( specification );

        if ( result ) {
            auto texture = m_depth.Get( );

            framebuffer.Attach( GL_DEPTH_ATTACHMENT, texture );
        }
    }

    return result;
}

bool GlwRenderTargetManager::CreateStencilAttachement(
    const GlwStencilTargetSpecification& specification,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    auto result = true;

    if ( specification.Parameters.Enable ) {
        clear_flags |= GL_STENCIL_BUFFER_BIT;

        if ( m_depth.GetIsValid( ) ) {
            auto texture = m_depth.Get( );

            m_stencil.Setup( specification );
            
            framebuffer.Attach( GL_STENCIL_ATTACHMENT, texture );
        } else {
            result = m_stencil.Create( specification );

            if ( result ) {
                auto texture = m_stencil.Get( );

                framebuffer.Attach( GL_STENCIL_ATTACHMENT, texture );
            }
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const glTexture GlwRenderTargetManager::GetColorAttachement( const uint32_t target ) const {
    return m_colors.GetAttachement( target );
}

const glTexture GlwRenderTargetManager::GetDepthAttachement( ) const {
    return m_depth.Get( );
}

const glTexture GlwRenderTargetManager::GetStencilAttachement( ) const {
    return m_stencil.Get( );
}
