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
GlwTextureCubemap::GlwTextureCubemap( )
	: GlwTexture{ }
{ }

bool GlwTextureCubemap::Create( const GlwTextureCubemapSpecification& specification ) {
    if ( CreateGlTexture( GL_TEXTURE_CUBE_MAP, specification ) ) {
        SetGlFilters( specification );
        SetGlWraps( specification );
    }

    return GetIsValid( );
}

bool GlwTextureCubemap::Fill( const GlwTextureFillSpecification& specification ) {
    auto result = GetIsValid( ) && specification.Width > 0 && specification.Height > 0 && specification.Pixels != nullptr;

    if ( result ) {
        glBindTexture( m_type, m_texture );
        glTexImage2D( specification.Level, 0, m_format, specification.Width, specification.Y, 0, m_format, specification.Type, specification.Pixels );
        glBindTexture( m_type, GL_NULL );
    }

    return result;
}
