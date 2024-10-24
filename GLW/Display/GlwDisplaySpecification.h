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

#include "GlwDisplayAttachementBind.h"

struct GlwDisplaySpecification {

	uint32_t Material;
	uint32_t Mesh;
	std::vector<GlwDisplayAttachementBind> Attachements;

	/**
	 * Constructor
	 **/
	GlwDisplaySpecification( );

	/**
	 * Constructor
	 * @param material : Query display material.
	 * @param mesh : Query display mesh.
	 **/
	GlwDisplaySpecification( const uint32_t material, const uint32_t mesh );

	/**
	 * Constructor
	 * @param material : Query display material.
	 * @param mesh : Query display mesh.
	 * @param attachement_binds : Query display attachement bindings.
	 **/
	GlwDisplaySpecification(
		const uint32_t material, 
		const uint32_t mesh,
		std::initializer_list<GlwDisplayAttachementBind> attachement_binds
	);

	/**
	 * Constructor
	 * @param material : Query display material.
	 * @param mesh : Query display mesh.
	 * @param attachement_binds : Query display attachement bindings.
	 **/
	GlwDisplaySpecification(
		const uint32_t material,
		const uint32_t mesh,
		const std::vector<GlwDisplayAttachementBind>& attachement_binds
	);

};
