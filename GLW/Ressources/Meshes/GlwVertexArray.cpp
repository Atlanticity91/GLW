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
GlwVertexArray::GlwVertexArray( )
	: m_handle{ GL_NULL }
{ }

bool GlwVertexArray::Create( ) {
	glGenVertexArrays( 1, &m_handle );

	auto result = glIsValid( m_handle );

	if ( result )
		glBindVertexArray( m_handle );

	return result;
}

void GlwVertexArray::Link( const std::vector<GlwVertexAttribute>& attributes ) {
	for ( auto attribute : attributes ) {
		if ( attribute.Size == 0 || attribute.Size > 4 )
			continue;

		glEnableVertexAttribArray( attribute.Location );
		glVertexAttribPointer( attribute.Location, attribute.Size, attribute.Type, GL_FALSE, attribute.Stride, NULL );
	}
}

void GlwVertexArray::Use( ) {
	glBindVertexArray( m_handle );
}

void GlwVertexArray::Destroy( ) {
	if ( glIsValid( m_handle ) ) {
		glDeleteVertexArrays( 1, &m_handle );

		m_handle = GL_NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const glVertexArray GlwVertexArray::Get( ) const {
	return m_handle;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwVertexArray::operator const glVertexArray( ) const {
	return Get( );
}
