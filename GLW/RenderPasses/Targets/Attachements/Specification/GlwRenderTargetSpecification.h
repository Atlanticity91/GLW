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

#include "GlwRenderTargetAccessibility.h"

struct GlwRenderTargetSpecification {

	GlwRenderTargetAccessibility Accessibility;
	GlwTextureFormats Format;
	GlwTextureLayouts Layout;
	GlwTextureSamples Samples;

	/**
	 * Constructor
	 **/
	GlwRenderTargetSpecification( );

	/**
	 * Constructor
	 * @param format : Query render target format.
	 * @param layout : Query render target layout.
	 **/
	GlwRenderTargetSpecification(
		const GlwTextureFormats format,
		const GlwTextureLayouts layout
	);

	/**
	 * Constructor
	 * @param format : Query render target format.
	 * @param layout : Query render target layout.
	 * @param samples : Query render target samples count.
	 **/
	GlwRenderTargetSpecification(
		const GlwTextureFormats format,
		const GlwTextureLayouts layout,
		const GlwTextureSamples samples
	);

	/**
	 * Constructor
	 * @param accessibility : Query render target accessibility value.
	 * @param format : Query render target format.
	 * @param layout : Query render target layout.
	 **/
	GlwRenderTargetSpecification( 
		const GlwRenderTargetAccessibility accessibility,
		const GlwTextureFormats format,
		const GlwTextureLayouts layout
	);

	/**
	 * Constructor
	 * @param accessibility : Query render target accessibility value.
	 * @param format : Query render target format.
	 * @param layout : Query render target layout.
	 * @param samples : Query render target samples count.
	 **/
	GlwRenderTargetSpecification(
		const GlwRenderTargetAccessibility accessibility,
		const GlwTextureFormats format,
		const GlwTextureLayouts layout,
		const GlwTextureSamples samples
	);

};
