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
GlwColorTargets::GlwColorTargets( )
	: m_targets{ }
{ }

bool GlwColorTargets::Create(
    GlwFramebuffer& framebuffer, 
    const std::vector<GlwColorTargetSpecification>& specifications 
) {
    auto color_count = (uint32_t)specifications.size( );
    auto result      = false;

    m_targets.resize( color_count );

    while ( color_count-- > 0 ) {
        result = m_targets[ color_count ].Create( specifications[ color_count ] );

        if ( result ) {
            auto texture = m_targets[ color_count ].Get( );

            framebuffer.Link( GL_COLOR_ATTACHMENT0 + color_count, texture );
        } else
            break;
    }

    return result;
}

void GlwColorTargets::Destroy( ) {
    for ( auto& target : m_targets )
        target.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const glTexture GlwColorTargets::GetAttachement( const uint32_t attachement ) const {
    auto texture = GL_TEXTURE_NULL;

    if ( attachement < (uint32_t)m_targets.size( ) )
        texture = m_targets[ attachement ].Get( );

    return texture;
}
