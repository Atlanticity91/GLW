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
GlwRenderAttachement::GlwRenderAttachement( )
	: m_texture{ },
	m_render_buffer{ }
{ }

bool GlwRenderAttachement::Create(
	const GlwRenderTargetSpecification& specification,
	const glm::uvec2& dimensions,
	const uint32_t offset,
	GlwFramebuffer& framebuffer
) {
	auto attachement_type = GetAttachementType( specification.Format ) + offset;
	auto result			  = false;

	if ( specification.Accessibility == GlwRenderTargetAccessibility::None ) {
		if ( result = m_render_buffer.Create( specification.Samples, attachement_type, dimensions ) )
			framebuffer.AttachRenderbuffer( attachement_type, m_render_buffer );
	} else {
		if ( result = m_texture.Create( { specification, dimensions } ) )
			framebuffer.AttachTexture( attachement_type, m_texture );
	}

	return result;
}

void GlwRenderAttachement::Destroy( ) {
	m_render_buffer.Destroy( );
	m_texture.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderAttachement::GetIsValid( ) const {
	return m_texture.GetIsValid( ) || m_render_buffer.GetIsValid( );
}

const glTexture GlwRenderAttachement::Get( ) const {
	return m_texture.Get( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const uint32_t GlwRenderAttachement::GetAttachementType(
	const GlwTextureFormats format
) const {
	auto result = GL_COLOR_ATTACHMENT0;

	switch ( format ) {
		case GlwTextureFormats::Depth	: result = GL_DEPTH_ATTACHMENT;   break;
		case GlwTextureFormats::Stencil : result = GL_STENCIL_ATTACHMENT; break;

		default : break;
	}

	return result;
}
