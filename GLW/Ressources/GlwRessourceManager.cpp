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
GlwRessourceManager::GlwRessourceManager( )
	: m_meshes{ },
	m_textures_2d{ },
	m_cubemaps{ },
	m_materials{ }
{ }

bool GlwRessourceManager::CreateMesh( const GlwMeshSpecification& specification ) {
	auto mesh   = GlwMesh{ };
	auto result = mesh.Create( specification );

	if ( result )
		m_meshes.emplace_back( mesh );
	else
		mesh.Destroy( );

	return result;
}

bool GlwRessourceManager::CreateTexture2D( const GlwTexture2DSpecification& specification ) {
	auto texture = GlwTexture2D{ };
	auto result  = texture.Create( specification );

	if ( result )
		m_textures_2d.emplace_back( texture );
	else
		texture.Destroy( );

	return result;
}

bool GlwRessourceManager::CreateTexture2D(
	const GlwTexture2DSpecification& specification,
	const std::vector<uint8_t>& pixels
) {
	auto texture = GlwTexture2D{ };
	auto result  = texture.Create( specification );

	if ( result ) {
		auto* pixel_data = pixels.data( );

		texture.Fill( { specification.Width, specification.Height, pixel_data } );

		m_textures_2d.emplace_back( texture );
	} else
		texture.Destroy( );

	return result;
}

bool GlwRessourceManager::CreateCubemap( const GlwTextureCubemapSpecification& specification ) {
	auto cubemap = GlwTextureCubemap{ };
	auto result  = cubemap.Create( specification );

	if ( result )
		m_cubemaps.emplace_back( cubemap );
	else
		cubemap.Destroy( );

	return result;
}

bool GlwRessourceManager::CreateCubemap(
	const GlwTextureCubemapSpecification& specification,
	const std::vector<uint8_t> face_pixels[ ]
) {
	auto cubemap = GlwTextureCubemap{ };
	auto result = cubemap.Create( specification );

	if ( result ) {
		for ( auto i = 0; i < GlwTextureCubemap::FaceCount; i++ ) {
			auto* pixel_data = face_pixels[ i ].data( );
			auto fill_spec   = GlwTextureFillSpecification{ specification.Width, specification.Height, pixel_data };
			
			fill_spec.Level = GL_TEXTURE_CUBE_MAP_POSITIVE_X + i;

			cubemap.Fill( fill_spec );
		}

		m_cubemaps.emplace_back( cubemap );
	} else
		cubemap.Destroy( );

	return result;
}

bool GlwRessourceManager::CreateMaterial( const GlwMaterialSpecification& specification ) {
	auto material = GlwMaterial{ };
	auto result   = material.Create( specification );

	if ( result )
		m_materials.emplace_back( material );
	else
		material.Destroy( );

	return result;
}

GlwMesh* GlwRessourceManager::UseMesh( const uint32_t mesh ) {
	auto* instance = GetMesh( mesh );

	if ( instance != nullptr )
		instance->Use( );

	return instance;
}

GlwMaterial* GlwRessourceManager::UseMaterial( const uint32_t material ) {
	auto instance = (GlwMaterial*)nullptr;

	if ( GetMaterialExist( material ) )
		instance = m_materials[ material ].Use( );

	return instance;
}

void GlwRessourceManager::Destroy( ) {
	for ( auto& mesh : m_meshes )
		mesh.Destroy( );

	for ( auto& texture : m_textures_2d )
		texture.Destroy( );

	for ( auto& cubemap : m_cubemaps )
		cubemap.Destroy( );

	for ( auto& material : m_materials )
		material.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRessourceManager::GetMeshExist( const uint32_t mesh ) const {
	return mesh < (uint32_t)m_meshes.size( );
}

bool GlwRessourceManager::GetTexture2DExist( const uint32_t texture ) const {
	return texture < (uint32_t)m_textures_2d.size( );
}

bool GlwRessourceManager::GetCubemapExist( const uint32_t cubemap ) const {
	return cubemap < (uint32_t)m_cubemaps.size( );
}

bool GlwRessourceManager::GetMaterialExist( const uint32_t material ) const {
	return material < (uint32_t)m_materials.size( );
}

GlwMesh* GlwRessourceManager::GetMesh( const uint32_t mesh ) {
	auto* instance = (GlwMesh*)nullptr;

	if ( GetMeshExist( mesh ) )
		instance = &m_meshes[ mesh ];

	return instance;
}

GlwTexture2D* GlwRessourceManager::GetTexture2D( const uint32_t texture ) {
	auto* instance = (GlwTexture2D*)nullptr;

	if ( GetTexture2DExist( texture ) )
		instance = &m_textures_2d[ texture ];

	return instance;
}

GlwTextureCubemap* GlwRessourceManager::GetCubemap( const uint32_t cubemap ) {
	auto* instance = ( GlwTextureCubemap* )nullptr;

	if ( GetCubemapExist( cubemap ) )
		instance = &m_cubemaps[ cubemap ];

	return instance;
}