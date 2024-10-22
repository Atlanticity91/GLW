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
GlwFramebuffer::GlwFramebuffer( )
	: m_framebuffer{ GL_NULL }
{ }

bool GlwFramebuffer::Create( ) {
	glGenFramebuffers( 1, &m_framebuffer );

	auto result = glIsValid( m_framebuffer );

	if ( result )
		glBindFramebuffer( GL_FRAMEBUFFER, m_framebuffer );

	return result;
}

void GlwFramebuffer::Attach( const uint32_t attachment, const uint32_t texture ) {
	glFramebufferTexture2D( GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture, 0 );
}

void GlwFramebuffer::Link( const uint32_t color_count ) {
	auto attachments	  = std::vector<uint32_t>( (size_t)color_count );
	auto color_id		  = color_count;
	auto* attachment_list = attachments.data( );

	while ( color_id-- > 0 )
		attachments[ color_id ] = GL_COLOR_ATTACHMENT0 + color_id;

	glDrawBuffers( color_count, attachment_list );
}

void GlwFramebuffer::Use( ) {
	glBindFramebuffer( GL_FRAMEBUFFER, m_framebuffer );
}

void GlwFramebuffer::Destroy( ) {
	if ( GetIsValid( ) )
		glDeleteFramebuffers( 1, &m_framebuffer );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwFramebuffer::GetIsValid( ) const {
	return glIsValid( m_framebuffer );
}
