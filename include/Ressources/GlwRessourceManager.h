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

#include "Materials/GlwMaterial.h"

class GlwRessourceManager final { 

private:
	std::vector<GlwMesh> m_meshes;
	std::vector<GlwTexture2D> m_textures_2d;
	std::vector<GlwTextureCubemap> m_cubemaps;
	std::vector<GlwMaterial> m_materials;

public:
	/**
	 * Constructor
	 **/
	GlwRessourceManager( );

	/**
	 * Destructor
	 **/
	~GlwRessourceManager( ) = default;

	/**
	 * CreateMesh function
	 * @note : Create mesh according to query specification.
	 * @param specification : Query mesh specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateMesh( const GlwMeshSpecification& specification );

	/**
	 * CreateTexture function
	 * @note : Create texture according to query specification.
	 * @param specification : Query texture specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateTexture( const GlwTexture2DSpecification& specification );

	/**
	 * CreateMaterial function
	 * @note : Create material according to query specification.
	 * @param specification : Query material specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateMaterial( const GlwMaterialSpecification& specification );

	/**
	 * UseMesh function
	 * @note : Bind mesh for usage.
	 * @param mesh : Query mesh.
	 * @return : Return query mesh instance.
	 **/
	GlwMesh* UseMesh( const uint32_t mesh );

	/**
	 * UseMaterial function
	 * @note : Bind material for usage.
	 * @param material : Query material.
	 * @return : Return query material instance.
	 **/
	GlwMaterial* UseMaterial( const uint32_t material );

	/**
	 * Destroy method
	 * @note : Destroy all ressources.
	 **/
	void Destroy( );

public:
	/**
	 * CreateMesh template function
	 * @note : Create mesh according to query specification.
	 * @template VertexType : Type of data used for vertex representation.
	 * @param specification : Query mesh specification.
	 * @return : True when creation succeeded.
	 **/
	template<typename VertexType>
	bool CreateMesh( const GlwMeshStaticSpecification<VertexType>& specification ) {
		auto mesh   = GlwMesh{ };
		auto result = mesh.Create<VertexType>( specification );

		if ( result )
			m_meshes.emplace_back( mesh );
		else
			mesh.Destroy( );

		return result;
	};

public:
	/**
	 * GetMeshExist const function
	 * @note : Get if a mesh exist.
	 * @param mesh : Query mesh.
	 * @return : Return true when mesh is valid.
	 **/
	bool GetMeshExist( const uint32_t mesh ) const;

	/**
	 * GetTexture2DExist const function
	 * @note : Get if a texture 2D exist.
	 * @param mesh : Query texture 2D.
	 * @return : Return true when texture 2D is valid.
	 **/
	bool GetTexture2DExist( const uint32_t texture ) const;

	/**
	 * GetTexture2DExist const function
	 * @note : Get if a cubemap exist.
	 * @param mesh : Query cubemap.
	 * @return : Return true when cubemap is valid.
	 **/
	bool GetCubemapExist( const uint32_t cubemap ) const;

	/**
	 * GetMaterialExist const function
	 * @note : Get if a material exist.
	 * @param mesh : Query material.
	 * @return : Return true when material is valid.
	 **/
	bool GetMaterialExist( const uint32_t material ) const;

	/**
	 * GetMesh function
	 * @note : Get mesh instance.
	 * @param mesh : Query mesh.
	 * @return : Return pointer to query mesh instance.
	 **/
	GlwMesh* GetMesh( const uint32_t mesh );

	/**
	 * GetTexture2D function
	 * @note : Get texture 2D instance.
	 * @param texture : Get texture instance.
	 * @return : Return pointer to query texture 2D instance.
	 **/
	const GlwTexture2D* GetTexture2D( const uint32_t texture ) const;

};
