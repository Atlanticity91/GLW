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
GlwTexture2DArray::GlwTexture2DArray( )
	: GlwTexture{ GlwTextureTypes::Texture2D_Array }
{ }

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PROTECTED ===
////////////////////////////////////////////////////////////////////////////////////////////
void GlwTexture2DArray::CreateTexture(
    const GlwTexture2DArraySpecification& specification 
) {
    glCreateTextures( GL_TEXTURE_2D_ARRAY, 1, &m_texture );

    if ( glIsValid( m_texture ) ) {
        glBindTexture( GL_TEXTURE_2D_ARRAY, m_texture );
        glTexImage3D( GL_TEXTURE_2D_ARRAY, specification.Levels, (uint32_t)specification.Layout, specification.Width, specification.Height, specification.Depth, 0, (uint32_t)specification.Format, GL_UNSIGNED_BYTE, NULL );
    }
}

void GlwTexture2DArray::SetTextureParameters(
    const GlwTexture2DArraySpecification& specification
) {
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, specification.Filter.Min );
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, specification.Filter.Mag );
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, specification.Wrap.R );
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, specification.Wrap.S );
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, specification.Wrap.T );
}

void GlwTexture2DArray::FillTexture( const GlwTextureFillSpecification& specification ) {
    glTexSubImage3D( GL_TEXTURE_2D_ARRAY, 0, specification.X, specification.Y, specification.Level, specification.Width, specification.Height, specification.Level, (uint32_t)m_format, specification.Type, specification.Pixels );
}
