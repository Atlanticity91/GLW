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

#include "GlwMeshSpecification.h"

template<typename VertexType>
struct GlwMeshStaticSpecification {

	std::vector<VertexType> Vertices;
	std::vector<uint32_t> Indexes;
	std::vector<GlwVertexAttribute> Attributes;

	/**
	 * Constructor
	 **/
	GlwMeshStaticSpecification( )
		: GlwMeshStaticSpecification{ { }, { }, {  } }
	{ };

	/**
	 * Constructor
	 * @param attributes : Vertex attribute list.
	 **/
	GlwMeshStaticSpecification(
		const std::vector<GlwVertexAttribute>& attributes
	)
		: GlwMeshStaticSpecification{ { }, { }, attributes }
	{ };
	
	/**
	 * Constructor
	 * @param vertices : Vertex list.
	 * @param attributes : Vertex attribute list.
	 **/
	GlwMeshStaticSpecification(
		const std::vector<VertexType>& vertices,
		const std::vector<GlwVertexAttribute>& attributes
	)
		: GlwMeshStaticSpecification{ vertices, { }, attributes } 
	{ };

	/**
	 * Constructor
	 * @param vertices : Vertex list.
	 * @param indexes : Index list.
	 * @param attributes : Vertex attribute list.
	 **/
	GlwMeshStaticSpecification(
		const std::vector<VertexType>& vertices,
		const std::vector<uint32_t>& indexes,
		const std::vector<GlwVertexAttribute>& attributes
	)
		: Vertices{ vertices },
		Indexes{ indexes },
		Attributes{ attributes } 
	{ };

	/**
	 * GetMeshSpec const function
	 * @note : Get mesh specification from current statis mesh specification.
	 * @return : Return mesh specification value.
	 **/
	GlwMeshSpecification GetMeshSpec( ) const {
		auto specification = GlwMeshSpecification{ };

		specification.UseIndex   = Indexes.size( ) > 0;
		specification.Vertex	 = { GlwBufferTypes::Vertex, GlwBufferModes::Static_Draw };
		specification.Index		 = { GlwBufferTypes::Index, GlwBufferModes::Static_Draw };
		specification.Attributes = Attributes;

		return specification;
	};

};
