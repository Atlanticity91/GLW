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

#include "GlwTexture.h"

struct GlwTexture2DSpecification : public GlwTextureSpecification { 

	GlwTextureLayouts Layout;
	GlwTextureFilterSpecification Filter;
	GlwTextureWrapSpecification Wrap;

	/**
	 * Constructor
	 **/
	GlwTexture2DSpecification( );

	/**
	 * Constructor
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 **/
	GlwTexture2DSpecification(
		const uint32_t width,
		const uint32_t height
	);

	/**
	 * Constructor
	 * @param layout : Query texture layout.
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 **/
	GlwTexture2DSpecification(
		const GlwTextureLayouts layout,
		const uint32_t width,
		const uint32_t height
	);

	/**
	 * Constructor
	 * @param format : Query texture format.
	 * @param layout : Query texture layout.
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 **/
	GlwTexture2DSpecification( 
		const GlwTextureFormats format,
		const GlwTextureLayouts layout,
		const uint32_t width,
		const uint32_t height
	);

	/**
	 * Constructor
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 * @param filter : Query texture filters.
	 * @param wrap : Query texture wrap.
	 **/
	GlwTexture2DSpecification(
		const uint32_t width,
		const uint32_t height,
		const GlwTextureFilterSpecification& filter,
		const GlwTextureWrapSpecification& wrap
	);

	/**
	 * Constructor
	 * @param format : Query texture format.
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 * @param filter : Query texture filters.
	 * @param wrap : Query texture wrap.
	 **/
	GlwTexture2DSpecification(
		const GlwTextureFormats format,
		const uint32_t width,
		const uint32_t height,
		const GlwTextureFilterSpecification& filter,
		const GlwTextureWrapSpecification& wrap
	);

	/**
	 * Constructor
	 * @param format : Query texture format.
	 * @param layout : Query texture layout.
	 * @param width : Query texture width value.
	 * @param height : Queryt texture height value.
	 * @param filter : Query texture filters.
	 * @param wrap : Query texture wrap.
	 **/
	GlwTexture2DSpecification( 
		const GlwTextureFormats format,
		const GlwTextureLayouts layout,
		const uint32_t width,
		const uint32_t height,
		const GlwTextureFilterSpecification& filter,
		const GlwTextureWrapSpecification& wrap
	);

	/**
	 * Copy-Constructor
	 * @param other : Query other 2d specification to copy.
	 **/
	GlwTexture2DSpecification( const GlwTexture2DSpecification& other );

	/**
	 * Move-Constructor
	 * @param other : Query other 2d specification to move.
	 **/
	GlwTexture2DSpecification( GlwTexture2DSpecification&& other );

	/**
	 * Asign operator
	 * @note : 
	 * @param other : Query other 2d specification to copy.
	 * @return : Return current texture 2d specification instance.
	 **/
	GlwTexture2DSpecification& operator=( const GlwTexture2DSpecification& other );

};
