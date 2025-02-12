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

#include "GlwMaterialSpecification.h"

class GlwMaterial : public GlwRessource<GlwMaterialSpecification> {

private:
    glProgram m_program_id;

public:
    /**
     * Constructor
     **/
    GlwMaterial( );

    /**
     * Destructor
     **/
    ~GlwMaterial( ) = default;

    /**
     * Create function
     * @note : Create material according to query specification.
     * @param specification : Query material specification.
     * @return : True when creation succeeded.
     **/
    virtual bool Create( const GlwMaterialSpecification& specification ) override;

    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param scalar : Query uniform value.
     **/
    void SetUniform( const int32_t location, const int32_t scalar );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param scalar : Query uniform value.
     **/
    void SetUniform( const int32_t location, const float scalar );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const int32_t location, const glm::vec2& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const int32_t location, const glm::vec3& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const int32_t location, const glm::vec4& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param matrix : Query uniform value.
     **/
    void SetUniform( const int32_t location, const glm::mat3& matrix );

    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param location : Query material uniform location.
     * @param matrix : Query uniform value.
     **/
    void SetUniform( const int32_t location, const glm::mat4& matrix );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param scalar : Query uniform value.
     **/
    void SetUniform( const std::string& name, const int32_t scalar );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param scalar : Query uniform value.
     **/
    void SetUniform( const std::string& name, const float scalar );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const std::string& name, const glm::vec2& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const std::string& name, const glm::vec3& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param vector : Query uniform value.
     **/
    void SetUniform( const std::string& name, const glm::vec4& vector );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param matrix : Query uniform value.
     **/
    void SetUniform( const std::string& name, const glm::mat3& matrix );
    
    /**
     * SetUniform method
     * @note : Set material uniform value.
     * @param name : Query material uniform name.
     * @param matrix : Query uniform value.
     **/
    void SetUniform( const std::string& name, const glm::mat4& matrix );

    /**
     * SetUniformBuffer method
     * @note : Set material uniform value.
     * @param location : Query material uniform buffer location.
     * @param buffer : Query uniform buffer value.
     **/
    void SetUniformBuffer( const int32_t location, const GlwBuffer& buffer );

    /**
     * SetUniformBuffer method
     * @note : Set material uniform value.
     * @param name : Query material uniform buffer name.
     * @param buffer : Query uniform buffer value.
     **/
    void SetUniformBuffer( const std::string& name, const GlwBuffer& buffer );

    /**
     * SetTexture method
     * @note : Set material texture slot value.
     * @param slot : Query texture slot.
     * @param type : Query texture type.
     * @param format : Query texture format.
     * @param texture : Query OpenGL texture value.
     **/
    void SetTexture( 
        const uint32_t slot,
        const GlwTextureTypes type,
        const GlwTextureFormats format,
        const glTexture texture 
    );

    /**
     * Use function
     * @note : Bind material for usage.
     * @return : Return pointer to current material instance.
     **/
    GlwMaterial* Use( );

    /**
     * Destroy method
     * @note : Destroy material.
     **/
    virtual void Destroy( ) override;

private:
    /**
     * Compile function
     * @note : Compile OpenGL shader.
     * @param type : Shader type value.
     * @param source : Shader source value.
     * @param shader_id : Store compiled OpenGL shader value.
     * @return : Return true when operation succeeded.
     **/
    bool Compile( const uint32_t type, const std::vector<char>& source, glShader& shader_id );

    /**
     * Link function
     * @note : Link shaders to unique material.
     * @param shader_vert : OpenGL shader instance.
     * @param shader_frag : OpenGL shader instance.
     * @param shader_geom : OpenGL shader instance.
     * @return : Return true when operation succeeded.
     **/
    bool Link( const glShader shader_vert, const glShader shader_frag, const glShader shader_geom );

public:
    /**
     * SetTexture template method
     * @note : Set material texture slot value.
     * @template SpecificationType : Query texture specification type.
     * @param slot : Query texture slot.
     * @param texture : Query texture pointer.
     **/
    template<typename SpecificationType>
        requires ( std::is_base_of<GlwTextureSpecification, SpecificationType>::value )
    void SetTexture( const uint32_t slot, const GlwTexture<SpecificationType>* texture ) {
        if ( texture == nullptr )
            return;

        auto gl_texture = texture->Get( );
        auto format     = texture->GetFormat( );
        auto type       = texture->GetType( );

        SetTexture( slot, type, format, gl_texture );
    };

public:
    /**
     * GetIsValid const function
     * @note : Get material validity.
     * @return : Return true when material is valid.
     **/
    virtual bool GetIsValid( ) const override;

    /**
     * GetUniformLocation const function
     * @note : Get uniform location.
     * @param name : Query uniform name.
     * @return : Return OpenGL uniform location value.
     **/
    int32_t GetUniformLocation( const std::string& name ) const;

    /**
     * GetUniformLocation const function
     * @note : Get uniform location.
     * @param name : Query uniform name.
     * @param location : Store OpenGL uniform location value.
     * @return : Return true when uniform location exist.
     **/
    bool GetUniformLocation( const std::string& name, int32_t& location ) const;

    /**
     * GetBufferLocation const function
     * @note : Get uniform buffer location.
     * @param name : Query uniform buffer name.
     * @return : Return OpenGL uniform buffer location value.
     **/
    int32_t GetBufferLocation( const std::string& name ) const;

    /**
     * GetUniformLocation const function
     * @note : Get uniform buffer location.
     * @param name : Query uniform buffer name.
     * @param location : Store OpenGL uniform buffer location value.
     * @return : Return true when uniform buffer location exist.
     **/
    bool GetBufferLocation( const std::string& name, int32_t& location ) const;

    /**
     * GetIsLocationValid const function
     * @note : Get is a location is valid.
     * @param location : Query uniform location.\
     * @return : Return true when uniform location is valid.
     **/
    bool GetIsLocationValid( const int32_t location ) const;

private:
    /**
     * GetIsSourceValid function
     * @note : Get if a shader source code is valid.
     * @param source : Reference to shader source code.
     * @return : Return true when source is valid.
     **/
    bool GetIsSourceValid( const std::vector<char>& source );

    /**
     * GetTextureType const function
     * @note : Get OpenGL texture type.
     * @return : Return OpenGL texture type value.
     **/
    uint32_t GetTextureType( const GlwTextureTypes type ) const;

    /**
     * GetTextureMode const function
     * @note : Convert format to OpenGL depth stencil texture mode.
     * @param format : Query texture format.
     * @return : Return OpenGL depth stencil texture mode.
     **/
    uint32_t GetTextureMode( const GlwTextureFormats format ) const;

public:
    /**
     * Assign operator
     * @note : Destroy current material and assign other to replace it.
     * @param other : The other material.
     * @return : Return reference to current material instance.
     **/
    GlwMaterial& operator=( const GlwMaterial& other );

};
