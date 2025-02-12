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

#include "__glw_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwMesh::GlwMesh( )
	: m_vao{ },
	m_vbo{ },
	m_ibo{ }
{ }

bool GlwMesh::Create( const GlwMeshSpecification& specification ) {
	auto result = m_vao.Create( ) && m_vbo.Create( specification.Vertex );

	if ( result && specification.UseIndex )
		result = m_ibo.Create( specification.Index );

	if ( result )
		m_vao.Link( specification.Attributes );

	glBindVertexArray( GL_NULL );

	return result;
}

bool GlwMesh::FillVertex( const uint32_t length, const void* vertices ) {
	auto result = length > 0 && vertices != nullptr;

	if ( result )
		m_vbo.Fill( length, vertices );

	return result;
}

bool GlwMesh::FillIndex( const std::vector<uint32_t>& indexes ) {
	auto* data  = indexes.data( );
	auto length = (uint32_t)( indexes.size( ) * sizeof( uint32_t ) );

	return FillIndex( length, data );
}

bool GlwMesh::FillIndex( const uint32_t length, const uint32_t* indexes ) {
	auto result = length > 0 && indexes != nullptr;

	if ( result )
		m_ibo.Fill( length, indexes );

	return result;
}

void GlwMesh::Use( ) {
	m_vao.Use( );
}

void GlwMesh::Destroy( ) {
	m_vbo.Destroy( );
	m_ibo.Destroy( );
	m_vao.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwMesh::GetIsValid( ) const {
	return glIsValid( m_vao ) && m_vbo.GetIsValid( );
}

bool GlwMesh::GetHasIndex( ) const {
	return m_ibo.GetIsValid( );
}

const GlwVertexArray& GlwMesh::GetVAO( ) const {
	return m_vao;
}

const GlwBuffer& GlwMesh::GetVBO( ) const {
	return m_vbo;
}

const GlwBuffer& GlwMesh::GetIBO( ) const {
	return m_ibo;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwMesh& GlwMesh::operator=( const GlwMesh& other ) {
	if ( other.GetIsValid( ) ) {
		Destroy( );

		m_vao = other.GetVAO( );
		m_vbo = other.GetVBO( );
		m_ibo = other.GetIBO( );
	}

	return *this;
}
