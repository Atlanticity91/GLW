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

#pragma once

#include "GlwRenderPass.h"

class GlwRenderPassManager final { 

private:
	std::vector<GlwRenderPass> m_render_pass;

public:
	/**
	 * Constructor
	 **/
	GlwRenderPassManager( );

	/**
	 * Destructor
	 **/
	~GlwRenderPassManager( ) = default;
	
	/**
	 * Create function
	 * @note : Create render pass according to specification.
	 * @param specification : Query render pass specification.
	 * @return : True when creation succeeded.
	 **/
	bool Create( const GlwRenderPassSpecification& specification );

	/**
	 * CmdBlitRenderTarget method
	 * @note : Blit content of a render pass target to another render pass target.
	 * @param blit_specification : Query blit specification.
	 **/
	void CmdBlitRenderTarget( const GlwBlitSpecification& blit_specification );

	/**
	 * Destroy method
	 * @note : Destroy all render pass.
	 **/
	void Destroy( );

public:
	/**
	 * GetRenderPassCount const function
	 * @note : Get render pass count.
	 * @return : Return render pass count value.
	 **/
	uint32_t GetRenderPassCount( ) const;

	/**
	 * GetExist const function
	 * @note : Get if a render pass exist.
	 * @param render_pass : Query render pass.
	 * @return : Return true when render pass is valid.
	 **/
	bool GetExist( const uint32_t render_pass ) const;

	/**
	 * GetRenderPass const function
	 * @note : Get render pass.
	 * @param render_pass : Query render pass value.
	 * @return : Return pointer to query render pass.
	 **/
	GlwRenderPass* GetRenderPass( const uint32_t render_pass ) const;

	/**
	 * GetLast const function
	 * @note : Get last render pass instance.
	 * @return : Return pointer to last render pass instance.
	 **/
	const GlwRenderPass* GetLast( ) const;

	/**
	 * GetDimensions const function
	 * @note : Get render pass dimensions.
	 * @param render_pass : Query render pass value. 
	 * @return : Return render pass dimensions as integer point.
	 **/
	glm::ivec2 GetDimensions( const uint32_t render_pass ) const;

	/**
	 * GetColorAttachement const function
	 * @note : Get color attachement OpenGL handle.
	 * @param render_pass : Query render pass value.
	 * @param attachement : Query render pass attachement value.
	 * @return : Return color attachement OpenGL texture handle value.
	 **/
	const glTexture GetColorAttachement( 
		const uint32_t render_pass, 
		const uint32_t attachement 
	) const;

	/**
	 * GetDepthAttachement const function
	 * @note : Get depth attachement OpenGL handle.
	 * @param render_pass : Query render pass value.
	 * @return : Return depth attachement OpenGL texture handle value.
	 **/
	const glTexture GetDepthAttachement( const uint32_t render_pass ) const;

	/**
	 * GetStencilAttachement const function
	 * @note : Get stencil attachement OpenGL handle.
	 * @param render_pass : Query render pass value.
	 * @return : Return stencil attachement OpenGL texture handle value.
	 **/
	const glTexture GetStencilAttachement( const uint32_t render_pass ) const;

	/**
	 * GetAttachement const function
	 * @note : Get attachement OpenGL handle.
	 * @param type : Query attachement type.
	 * @param render_pass : Query render pass value.
	 * @param target : Query render pass target value.
	 * @return : Return attachement OpenGL texture handle value.
	 **/
	const glTexture GetAttachement(
		const GlwRenderAttachementTypes type,
		const uint32_t render_pass,
		const uint32_t target
	) const;

private:
	/**
	 * GetAttachementRange const function
	 * @note : Get attachement pixel range for blit operation.
	 * @param target : Query blit target.
	 * @return : Return attachemnt pixel range as unsigned vector.
	 **/
	glm::uvec4 GetAttachementRange( 
		const GlwBlitRenderTargetSpecifiction& target_specification
	) const;

};
