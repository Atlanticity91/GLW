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

#include "GlwTextureSamples.h"

struct GlwTextureFilterSpecification {

	uint32_t Min;
	uint32_t Mag;

	/**
	 * Constructor
	 **/
	GlwTextureFilterSpecification( );

	/**
	 * Constructor
	 * @parma min : Query min OpenGL filter value.
	 * @param mag : Query mag OpenGL filter value.
	 **/
	GlwTextureFilterSpecification( const uint32_t min, const uint32_t mag );

	/**
	 * Copy-Constructor
	 * @param other : Query other filter specification to copy.
	 **/
	GlwTextureFilterSpecification( const GlwTextureFilterSpecification& other );

	/**
	 * Move-Constructor
	 * @param other : Query filter specification to move.
	 **/
	GlwTextureFilterSpecification( GlwTextureFilterSpecification&& other  );

	/**
	 * Asign operator
	 * @note : Asign current instance.
	 * @param other : Query filter to copy.
	 * @return : Return filter specification current instance.
	 **/
	GlwTextureFilterSpecification& operator=(
		const GlwTextureFilterSpecification& other
	);

};
