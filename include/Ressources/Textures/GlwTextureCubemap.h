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

#include "GlwTextureCubemapSpecification.h"

class GlwTextureCubemap : public GlwTexture<GlwTextureCubemapSpecification> {

public:
	/**
	 * Constructor
	 **/
	GlwTextureCubemap( );

	/**
	 * Destructor
	 **/
	~GlwTextureCubemap( ) = default;

	/**
	 * Create function
	 * @note : Create cubemap texture according to query specification.
	 * @param specification : Query Create specification.
	 * @return : True when creation succeeded.
	 **/
	virtual bool Create( const GlwTextureCubemapSpecification& specification ) override;

	/**
	 * Fill function
	 * @note : Fill texture according to specification, for cubemaps Level value 
	 *		   is used for cubemap face identification according to OpenGL cubemap
	 *		   face index from GL_TEXTURE_CUBE_MAP_POSITIVE_X to GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.
	 * @param specification : Query filling specification.
	 * @return : True when texture filling succeeded.
	 **/
	virtual bool Fill( const GlwTextureFillSpecification& specification ) override;

};
