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

#include "Specification/GlwAttachementSpecification.h"

class GlwRenderAttachementTexture final : public GlwTexture<GlwAttachementSpecification> {

public:
	/**
	 * Constructor
	 **/
	GlwRenderAttachementTexture( );

	/**
	 * Destructor
	 **/
	~GlwRenderAttachementTexture( ) = default;

protected:
	/**
	 * CreateTexture function
	 * @note : Create texture according to specification.
	 * @param specification : Query texture specification.
	 **/
	virtual void CreateTexture( const GlwAttachementSpecification& specification ) override;

	/**
	 * SetTextureParameters method
	 * @note : Set texture parameters according to specification.
	 * @param specification : Query texture specification.
	 **/
	virtual void SetTextureParameters( const GlwAttachementSpecification& specification ) override;

	/**
	 * FillTexture method
	 * @note : Fill texture pixels according to specification.
	 * @param specification : Query filling specification.
	 **/
	virtual void FillTexture( const GlwTextureFillSpecification& specification ) override;

private:
	/**
	 * GetTarget const function
	 * @note : Get OpenGL texture target type.
	 * @return : Return OpenGL texture target value.
	 **/
	const uint32_t GetTarget( ) const;

};
