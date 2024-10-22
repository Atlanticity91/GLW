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

#include "GlwMeshStaticSpecification.h"

class GlwMesh : public GlwRessource<GlwMeshSpecification> {

protected:
	GlwVertexArray m_vao;
	GlwBuffer m_vbo;
	GlwBuffer m_ibo;

public:
	/**
	 * Constructor
	 **/
	GlwMesh( );

	/**
	 * Destructor
	 **/
	~GlwMesh( ) = default;

	/**
	 * Create function
	 * @note : Create mesh according to query specification.
	 * @param specification : Query mesh specification.
	 * @return : True when creation succeeded.
	 **/
	virtual bool Create( const GlwMeshSpecification& specification ) override;

	/**
	 * FillVertex function
	 * @note : Fill vertex buffer.
	 * @param length : Length of vertices buffer in bytes.
	 * @param vertices : Pointer to vertices buffer.
	 * @return : True when operation succeeded.
	 **/
	bool FillVertex( const uint32_t length, const void* vertices );

	/**
	 * FillIndex function
	 * @note : Fill index buffer.
	 * @param indexes : Index list.
	 * @return : True when operation succeeded.
	 **/
	bool FillIndex( const std::vector<uint32_t>& indexes );

	/**
	 * FillIndex function
	 * @note : Fill index buffer.
	 * @param length : Length of index buffer in bytes.
	 * @param vertices : Pointer to index buffer.
	 * @return : True when operation succeeded.
	 **/
	bool FillIndex( const uint32_t length, const uint32_t* indexes );

	/**
	 * Use method
	 * @note : Bind mesh for usage. 
	 **/
	void Use( );

	/**
	 * Destroy method
	 * @note : Destroy mesh.
	 **/
	virtual void Destroy( ) override;

public:
	/**
	 * Create template function
	 * @note : Create 'static' mesh according to query specification.
	 * @template VertexType : Type of data used for vertex representation.
	 * @param specification : Query 'static' mesh specification.
	 * @return : True when creation succeeded.
	 **/
	template<typename VertexType>
	bool Create( const GlwMeshStaticSpecification<VertexType>& specification ) {
		auto mesh_spec = specification.GetMeshSpec( );

		return  Create( mesh_spec )								 &&
				FillVertex<VertexType>( specification.Vertices ) &&
				FillIndex( specification.Indexes );
	};

	/**
	 * FillVertex template function
	 * @note : Fill vertex buffer.
	 * @template VertexType : Type of data used for vertex representation.
	 * @param vertices : Vertex list.
	 * @return : True when operation succeeded.
	 **/
	template<typename VertexType>
	bool FillVertex( const std::vector<VertexType>& vertices ) {
		auto* data  = (void*)vertices.data( );
		auto length = (uint32_t)( vertices.size( ) * sizeof( VertexType ) );

		return FillVertex( length, data );
	};

	/**
	 * Fill template function
	 * @note : Fill vertex and index buffer.
	 * @template VertexType : Type of data used for vertex representation.
	 * @param vertices : Vertex list.
	 * @param indexes : Index list.
	 * @return : True when operation succeeded.
	 **/
	template<typename VertexType>
	bool Fill(
		const std::vector<VertexType>& vertices,
		const std::vector<uint32_t>& indexes
	) {
		return FillVertex<VertexType>( vertices ) && FillIndex( indexes );
	};

public:
	/**
	 * GetIsValid const function
	 * @note : Get mesh validity.
	 * @return : Return true when mesh is valid.
	 **/
	virtual bool GetIsValid( ) const override;

	/**
	 * GetHasIndex const function
	 * @note : Get if current mesh use an index buffer.
	 * @return : True when mesh index buffer is valid.
	 **/
	bool GetHasIndex( ) const;

	/**
	 * GetVAO const function
	 * @note : Get current vertex array instance.
	 * @return : Constant reference to vertex array.
	 **/
	const GlwVertexArray& GetVAO( ) const;

	/**
	 * GetVBO const function
	 * @note : Get current vertex buffer instance.
	 * @return : Constant reference to vertex buffer.
	 **/
	const GlwBuffer& GetVBO( ) const;

	/**
	 * GetIBO const function
	 * @note : Get current index buffer instance.
	 * @return : Constant reference to index buffer.
	 **/
	const GlwBuffer& GetIBO( ) const;

};
