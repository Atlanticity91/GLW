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
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderAttachementTexture::GlwRenderAttachementTexture( )
    : GlwTexture{ GlwTextureTypes::Texture2D }
{ }

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PROTECTED ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderAttachementTexture::CreateTexture( 
    const GlwAttachementSpecification& specification 
) {
    if ( specification.Samples > GlwTextureSamples::None )
        m_type = GlwTextureTypes::Texture2D_MultiSamples;

    auto target = GetTarget( );

    glCreateTextures( target, 1, &m_texture );

    auto result = glIsValid( m_texture );

    if ( result ) {
        glBindTexture( target, m_texture );

        if ( specification.Samples == GlwTextureSamples::None )
            glTexImage2D( GL_TEXTURE_2D, specification.Levels, (uint32_t)specification.Layout, specification.Width, specification.Height, 0, (uint32_t)specification.Format, GL_UNSIGNED_BYTE, NULL );
        else
            glTexImage2DMultisample( GL_TEXTURE_2D_MULTISAMPLE, (uint32_t)specification.Samples, (uint32_t)specification.Layout, specification.Width, specification.Height, GL_TRUE );
    }

    return result;
}

void GlwRenderAttachementTexture::SetTextureParameters(
    const GlwAttachementSpecification& specification
) {
    auto target = GetTarget( );

    glTexParameteri( target, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( target, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( target, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE );
    glTexParameteri( target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
}

void GlwRenderAttachementTexture::FillTexture( const GlwTextureFillSpecification& specification ) {
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const uint32_t GlwRenderAttachementTexture::GetTarget( ) const {
    return ( m_type == GlwTextureTypes::Texture2D ) ? GL_TEXTURE_2D : GL_TEXTURE_2D_MULTISAMPLE;
}
