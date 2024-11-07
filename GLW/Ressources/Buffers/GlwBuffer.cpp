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
GlwBuffer::GlwBuffer( )
	: m_type{ 0 },
	m_mode{ 0 },
	m_handle{ GL_NULL }
{ }

bool GlwBuffer::Create( const GlwBufferSpecification& specification ) {
	glGenBuffers( 1, &m_handle );

	auto result = GetIsValid( );

	if ( result ) {
		m_type = (GLuint)specification.Type;
		m_mode = (GLuint)specification.Mode;

		glBindBuffer( m_type, m_handle );
	}

	return result;
}

bool GlwBuffer::Fill( const uint32_t length, const void* data ) {
	auto result = GetIsValid( ) && length > 0;

	if ( result ) {
		glBindBuffer( m_type, m_handle );
		glBufferData( m_type, length, data, m_mode );
		glBindBuffer( m_type, GL_NULL );
	}

	return result;
}

void GlwBuffer::Destroy( ) {
	if ( GetIsValid( ) ) {
		glDeleteBuffers( 1, &m_handle );

		m_handle = GL_NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwBuffer::GetIsValid( ) const {
	return glIsValid( m_handle );
}

const GlwBufferTypes GlwBuffer::GetType( ) const {
	return (GlwBufferTypes)m_type;
}

const GLuint GlwBuffer::GetMode( ) const {
	return m_mode;
}

const glBuffer GlwBuffer::Get( ) const {
	return m_handle;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwBuffer::operator const glBuffer( ) const {
	return Get( );
}
