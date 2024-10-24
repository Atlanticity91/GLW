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
GlwRenderbuffer::GlwRenderbuffer( )
	: m_render_buffer{ GL_NULL }
{ }

bool GlwRenderbuffer::Create(
	const glm::uvec2& dimensions,
	const uint32_t type
) {
	glGenRenderbuffers( 1, &m_render_buffer );

	auto result = GetIsValid( );

	if ( result ) {
		glBindRenderbuffer( GL_RENDERBUFFER, m_render_buffer );
		glRenderbufferStorage( GL_RENDERBUFFER, type, dimensions.x, dimensions.y );
	}

	return result;
}

void GlwRenderbuffer::Destroy( ) {
	if ( GetIsValid( ) )
		glDeleteRenderbuffers( 1, &m_render_buffer );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderbuffer::GetIsValid( ) const {
	return glIsValid( m_render_buffer );
}

const uint32_t GlwRenderbuffer::Get( ) const {
	return m_render_buffer;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderbuffer::operator const uint32_t( ) const {
	return Get( );
}
