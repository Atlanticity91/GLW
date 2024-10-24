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
GlwColorTarget::GlwColorTarget( )
	: m_attachements{ }
{ }

bool GlwColorTarget::Create(
	const GlwColorTargetSpecification& specification,
	const glm::uvec2& dimensions,
	GlwFramebuffer& framebuffer,
	uint32_t& clear_flags
) {
	auto attachement_id = specification.Colors.size( );
	auto result			= true;

	if ( attachement_id > 0 )
		m_attachements.resize( attachement_id );

	while ( result && attachement_id-- > 0 )
		result = m_attachements[ attachement_id ].Create( specification.Colors[ attachement_id ], dimensions, (uint32_t)attachement_id, framebuffer );

	if ( result )
		clear_flags |= GL_COLOR_BUFFER_BIT;

	return result;
}

void GlwColorTarget::Destroy( ) {
	for ( auto& attachement : m_attachements )
		attachement.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const glTexture GlwColorTarget::GetAttachement( const uint32_t target ) const {
	auto texture = GL_TEXTURE_NULL;

	if ( target < (uint32_t)m_attachements.size( ) )
		texture = m_attachements[ target ].Get( );

	return texture;
}