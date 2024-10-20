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

#include "GlwTextureFillSpecification.h"

template<typename SpecificationType>
    requires ( std::is_base_of<GlwTextureSpecification, SpecificationType>::value )
class GlwTexture : public GlwRessource<SpecificationType> {

protected:
    uint32_t m_type;
    uint32_t m_format;
    glTexture m_texture;

public:
    /**
     * Constructor
     **/
    GlwTexture( )
        : m_type{ 0 },
        m_format{ 0 },
        m_texture{ GL_NULL }
    { };

    /**
     * Destructor
     **/
    virtual ~GlwTexture( ) = default;

    /**
     * Create function
     * @note : Create texture according to query specification.
     * @param specification : Query texture specification.
     * @return : True when creation succeeded.
     **/
    virtual bool Create( const SpecificationType& specification ) override {
        if ( CreateGlTexture( GL_TEXTURE_2D, specification ) ) {
            SetGlFilters( specification );
            SetGlWraps( specification );
        }

        return GetIsValid( );
    };

    /**
     * Fill function
     * @note : Fill texture according to specification.
     * @param specification : Query filling specification.
     * @return : True when texture filling succeeded.
     **/
    virtual bool Fill( const GlwTextureFillSpecification& specification ) {
        auto result = GetIsValid( ) && specification.Width > 0 && specification.Height > 0 && specification.Pixels != nullptr;

        if ( result ) {
            glBindTexture( m_type, m_texture );
            glTexSubImage2D( m_texture, specification.Level, specification.X, specification.Y, specification.Width, specification.Height, m_format, specification.Type, specification.Pixels );
            glBindTexture( m_type, GL_NULL );
        }

        return result;
    };

    /**
     * Destroy method
     * @note : Destroy texture.
     **/
    virtual void Destroy( ) override {
        if ( GetIsValid( ) ) {
            glDeleteTextures( 1, &m_texture );

            m_texture = GL_NULL;
        }
    };

protected:
    /**
     * CreateGlTexture function
     * @note : Create texture handle internaly.
     * @param type : OpenGL texture type.
     * @param specification : Query texture specification.
     * @return : True when creation succeeded.
     **/
    virtual bool CreateGlTexture( const GLuint type, const SpecificationType& specification ) {
        glCreateTextures( type, 1, &m_texture );

        auto result = glIsValid( m_texture );

        if ( result ) {
            m_type   = type;
            m_format = specification.Format;

            glBindTexture( m_type, m_texture );
            glTexStorage2D( m_type, specification.Levels, m_format, specification.Width, specification.Height );
        }

        return result;
    };

    /**
     * SetGlFilters method
     * @note : Set texture filters value.
     * @param specification : Query texture specification.
     **/
    void SetGlFilters( const GlwTextureSpecification& specification ) {
        glTexParameteri( m_type, GL_TEXTURE_MIN_FILTER, specification.MinFilter );
        glTexParameteri( m_type, GL_TEXTURE_MAG_FILTER, specification.MagFilter );
    };

    /**
     * SetGlWraps method
     * @note : Set texture wraping value.
     * @param specification : Query texture specification.
     **/
    void SetGlWraps( const GlwTextureSpecification& specification ) {
        glTexParameteri( m_type, GL_TEXTURE_WRAP_R, specification.WrapR );
        glTexParameteri( m_type, GL_TEXTURE_WRAP_S, specification.WrapS );
        glTexParameteri( m_type, GL_TEXTURE_WRAP_T, specification.WrapT );
    };

public:
    /**
     * GetIsValid const function
     * @note : Get if a texture is valid.
     * @return : True when texture is valid.
     **/
    virtual bool GetIsValid( ) const override {
        return glIsValid( m_texture );
    };

    /**
     * GetType const function
     * @note : Get texture type.
     * @return : OpenGL texture type value.
     **/
    uint32_t GetType( ) const {
        return m_type;
    };
    
    /**
     * GetFormat const function
     * @note : Get textur format.
     * @return : OpenGL texture format value.
     **/
    uint32_t GetFormat( ) const {
        return m_format;
    };

    /**
     * Get const function
     * @note : Get current OpenGL texture handle.
     * @return : Constant value for the OpenGL texture handle.
     **/
    const glTexture Get( ) const {
        return m_texture;
    };

public:
    /**
     * Cast operator
     * @note : Cast texture to OpenGL texture handle.
     * @return : Constant value for the OpenGL texture handle.
     **/
    operator const glTexture ( ) const {
        return Get( );
    };

};
