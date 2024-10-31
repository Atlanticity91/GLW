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

#include "GlwRenderAttachementTexture.h"

class GlwRenderAttachement final {

private:
	GlwRenderAttachementTexture m_texture;
	GlwRenderbuffer m_render_buffer;

public:
	/**
	 * Constructor
	 **/
	GlwRenderAttachement( );

	/**
	 * Destructor
	 **/
	~GlwRenderAttachement( ) = default;

	/**
	 * Create function
	 * @note : Create attachement according to specification.
	 * @param specification : Query render target specification.
	 * @param dimensions : Current render pass dimensions.
	 * @param offset :
	 * @param framebuffer : Reference to current render pass framebuffer instance.
	 * @return : Return true when creation succeeded.
	 **/
	bool Create( 
		const GlwRenderTargetSpecification& specification,
		const glm::uvec2& dimensions,
		const uint32_t offset,
		GlwFramebuffer& framebuffer
	);

	/**
	 * Destroy method
	 * @note : Destroy current attachement.
	 **/
	void Destroy( );

public:
	/**
	 * GetIsValid const function
	 * @note : Get if attachement if valid.
	 * @return : Return true when attachement is valid.
	 **/
	bool GetIsValid( ) const;

	/**
	 * Get const function
	 * @note : Get attachement OpenGL texture handle.
	 * @return : Return attachement OpenGL texture handle value.
	 **/
	const glTexture Get( ) const;

private:
	/**
	 * GetAttachementType const function
	 * @note : Get OpenGL attachement type based on GlwTextureFormats.
	 * @param format : Query attachement internal texture format.
	 * @return : Return OpenGL attachement type value.
	 **/
	const uint32_t GetAttachementType( const GlwTextureFormats format ) const;

};
