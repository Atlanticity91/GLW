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
	 * CreateTexture2D function
	 * @note : Create texture according to query specification.
	 * @param specification : Query texture specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateTexture2D( const GlwTexture2DSpecification& specification );
	
	/**
	 * CreateTexture2D function
	 * @note : Create texture according to query specification and fill-it width pixels data.
	 * @param specification : Query texture specification.
	 * @param pixels : Query texture pixels data as unsigned byte.
	 * @return : True when creation succeeded.
	 **/
	bool CreateTexture2D(
		const GlwTexture2DSpecification& specification,
		const std::vector<uint8_t>& pixels
	);

	/**
	 * CreateCubemap function
	 * @note : Create cubemap texture according to query specification.
	 * @param specification : Query cubemap texture specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateCubemap( const GlwTextureCubemapSpecification& specification );

	/**
	 * CreateCubemap function
	 * @note : Create cubemap texture according to query specification.
	 * @param specification : Query cubemap texture specification.
	 * @param face_pixels : Array of the cubemap face texture pixels as unsigned byte.
	 * @return : True when creation succeeded.
	 **/
	bool CreateCubemap( 
		const GlwTextureCubemapSpecification& specification,
		const std::vector<uint8_t> face_pixels[ GlwTextureCubemap::FaceCount ]
	);

	/**
	 * CreateMaterial function
	 * @note : Create material according to query specification.
	 * @param specification : Query material specification.
	 * @return : True when creation succeeded.
	 **/
	bool CreateMaterial( const GlwMaterialSpecification& specification );

	/**
	 * ReplaceMesh function
	 * @note : Replace mesh according to query specification.
	 * @param mesh : Query mesh to replace.
	 * @param specification : Query mesh specification.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceMesh(
		const glw_ressource mesh,
		const GlwMeshSpecification& specification
	);

	/**
	 * ReplaceTexture2D function
	 * @note : Replace texture according to query specification.
	 * @param texture : Query texture to replace.
	 * @param specification : Query texture specification.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceTexture2D(
		const glw_ressource texture,
		const GlwTexture2DSpecification& specification
	);

	/**
	 * ReplaceTexture2D function
	 * @note : Replace texture according to query specification and fill-it width pixels data.
	 * @param texture : Query texture to replace.
	 * @param specification : Query texture specification.
	 * @param pixels : Query texture pixels data as unsigned byte.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceTexture2D(
		const glw_ressource texture,
		const GlwTexture2DSpecification& specification,
		const std::vector<uint8_t>& pixels
	);

	/**
	 * ReplaceCubemap function
	 * @note : Create cubemap texture according to query specification.
	 * @param cubemap : Query cubemap to replace.
	 * @param specification : Query cubemap texture specification.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceCubemap( 
		const glw_ressource cubemap, 
		const GlwTextureCubemapSpecification& specification 
	);

	/**
	 * ReplaceCubemap function
	 * @note : Create cubemap texture according to query specification.
	 * @param cubemap : Query cubemap to replace.
	 * @param specification : Query cubemap texture specification.
	 * @param face_pixels : Array of the cubemap face texture pixels as unsigned byte.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceCubemap(
		const glw_ressource cubemap,
		const GlwTextureCubemapSpecification& specification,
		const std::vector<uint8_t> face_pixels[ GlwTextureCubemap::FaceCount ]
	);

	/**
	 * ReplaceMaterial function
	 * @note : Replace material according to query specification.
	 * @param material : Query material to replace.
	 * @param specification : Query material specification.
	 * @return : True when creation succeeded.
	 **/
	bool ReplaceMaterial( 
		const glw_ressource material,
		const GlwMaterialSpecification& specification 
	);

	/**
	 * UseMesh function
	 * @note : Bind mesh for usage.
	 * @param mesh : Query mesh.
	 * @return : Return query mesh instance.
	 **/
	GlwMesh* UseMesh( const glw_ressource mesh );

	/**
	 * UseMaterial function
	 * @note : Bind material for usage.
	 * @param material : Query material.
	 * @return : Return query material instance.
	 **/
	GlwMaterial* UseMaterial( const glw_ressource material );

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

	/**
	 * ReplaceMesh template function
	 * @note : Replace mesh according to query specification.
	 * @template VertexType : Type of data used for vertex representation.
	 * @param mesh : Query mesh to replace.
	 * @param specification : Query mesh specification.
	 * @return : True when creation succeeded.
	 **/
	template<typename VertexType>
	bool ReplaceMesh(
		const glw_ressource mesh,
		const GlwMeshStaticSpecification<VertexType>& specification
	) {
		auto result = false;

		if ( GetMeshExist( mesh ) ) {
			auto new_mesh = GlwMesh{ };

			if ( result = new_mesh.Create<VertexType>( specification ) )
				m_meshes[ mesh ] = new_mesh;
		}

		return result;
	};

public:
	/**
	 * GetMeshCount const function
	 * @note : Get mesh count.
	 * @return : Return mesh count value.
	 **/
	uint32_t GetMeshCount( ) const;

	/**
	 * GetTexture2DCount const function
	 * @note : Get texture 2D count.
	 * @return : Return texture 2D count value.
	 **/
	uint32_t GetTexture2DCount( ) const;

	/**
	 * GetCubemapCount const function
	 * @note : Get cubemap count.
	 * @return : Return cubemap count value.
	 **/
	uint32_t GetCubemapCount( ) const;

	/**
	 * GetMaterialCount const function
	 * @note : Get material count.
	 * @return : Return material count value.
	 **/
	uint32_t GetMaterialCount( ) const;

	/**
	 * GetMeshExist const function
	 * @note : Get if a mesh exist.
	 * @param mesh : Query mesh.
	 * @return : Return true when mesh is valid.
	 **/
	bool GetMeshExist( const glw_ressource mesh ) const;

	/**
	 * GetTexture2DExist const function
	 * @note : Get if a texture 2D exist.
	 * @param mesh : Query texture 2D.
	 * @return : Return true when texture 2D is valid.
	 **/
	bool GetTexture2DExist( const glw_ressource texture ) const;

	/**
	 * GetTexture2DExist const function
	 * @note : Get if a cubemap exist.
	 * @param mesh : Query cubemap.
	 * @return : Return true when cubemap is valid.
	 **/
	bool GetCubemapExist( const glw_ressource cubemap ) const;

	/**
	 * GetMaterialExist const function
	 * @note : Get if a material exist.
	 * @param mesh : Query material.
	 * @return : Return true when material is valid.
	 **/
	bool GetMaterialExist( const glw_ressource material ) const;

	/**
	 * GetMesh function
	 * @note : Get mesh instance.
	 * @param mesh : Query mesh.
	 * @return : Return pointer to query mesh instance.
	 **/
	GlwMesh* GetMesh( const glw_ressource mesh );

	/**
	 * GetTexture2D function
	 * @note : Get texture 2D instance.
	 * @param texture : Query texture.
	 * @return : Return pointer to query texture 2D instance.
	 **/
	GlwTexture2D* GetTexture2D( const glw_ressource texture );

	/**
	 * GetCubemap function
	 * @note : Get cubemap instance.
	 * @param cubemap : Query cubemap.
	 * @return : Return pointer to query cubemap texture instance.
	 **/
	GlwTextureCubemap* GetCubemap( const glw_ressource cubemap );

	/**
	 * GetMaterial function
	 * @note : Get material instance.
	 * @param material : Query material.
	 * @return : Return pointer to query material instance.
	 **/
	GlwMaterial* GetMaterial( const glw_ressource material );

};
