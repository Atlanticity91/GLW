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
GlwDepthTarget::GlwDepthTarget( )
    : m_enabled{ false },
    m_parameters{ },
    m_attachement{ }
{ }

bool GlwDepthTarget::Create( 
    const GlwDepthTargetSpecification& specification,
    const glm::uvec2& dimensions,
    GlwFramebuffer& framebuffer,
    uint32_t& clear_flags
) {
    auto result = true;

    if ( specification.State == GlwStates::Enable ) {
        result = m_attachement.Create( specification, dimensions, 0, framebuffer );

        if ( result ) {
            m_enabled    = true;
            m_parameters = specification.Parameters;

            clear_flags |= GL_DEPTH_BUFFER_BIT;
        }
    }

    return result;
}

void GlwDepthTarget::Use( ) {
    if ( m_enabled ) {
        glEnable( GL_DEPTH_TEST );
        glDepthFunc( m_parameters.Function );
        glDepthRange( m_parameters.ClampedNear, m_parameters.ClampedFar );
    } else
        glDisable( GL_DEPTH_TEST );
}

void GlwDepthTarget::Destroy( ) {
    m_attachement.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const glTexture GlwDepthTarget::GetAttachement( ) const {
    return m_attachement.Get( );
}
