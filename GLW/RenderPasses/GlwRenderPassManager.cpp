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
GlwRenderPassManager::GlwRenderPassManager( )
	: m_render_pass{ }
{ }

bool GlwRenderPassManager::Create( const GlwRenderPassSpecification& specification ) {
	auto render_pass = GlwRenderPass{ };
	auto result		 = render_pass.Create( specification );

	if ( result )
		m_render_pass.emplace_back( render_pass );

	return result;
}

bool GlwRenderPassManager::Use( const uint32_t render_pass ) {
	auto result = GetExist( render_pass );

	if ( result )
		m_render_pass[ render_pass ].Use( );

	return result;
}

void GlwRenderPassManager::Destroy( ) {
	for ( auto& render_pass : m_render_pass )
		render_pass.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderPassManager::GetExist( const uint32_t render_pass ) const {
	return render_pass < (uint32_t)m_render_pass.size( );
}

GlwRenderPass* GlwRenderPassManager::GetRenderPass( const uint32_t render_pass ) const {
	auto* instance = (GlwRenderPass*)nullptr;

	if ( GetExist( render_pass ) )
		instance = (GlwRenderPass*)&m_render_pass[ render_pass ];

	return instance;
}

const GlwRenderPass* GlwRenderPassManager::GetLast( ) const {
	auto render_pass = m_render_pass.size( );
	auto* instance   = (const GlwRenderPass*)nullptr;

	if ( render_pass > 0 )
		instance = &m_render_pass[ render_pass - 1 ];

	return instance;
}
const glTexture GlwRenderPassManager::GetColorAttachement(
	const uint32_t render_pass,
	const uint32_t attachement
) const {
	auto texture = GL_TEXTURE_NULL;

	if ( auto* instance = GetRenderPass( render_pass ) )
		texture = instance->GetColorAttachement( attachement );

	return texture;
}

const glTexture GlwRenderPassManager::GetDepthAttachement( const uint32_t render_pass ) const {
	auto texture = GL_TEXTURE_NULL;

	if ( auto* instance = GetRenderPass( render_pass ) )
		texture = instance->GetDepthAttachement( );

	return texture;
}

const glTexture GlwRenderPassManager::GetStencilAttachement( const uint32_t render_pass ) const {
	auto texture = GL_TEXTURE_NULL;

	if ( auto* instance = GetRenderPass( render_pass ) )
		texture = instance->GetStencilAttachement( );

	return texture;
}
