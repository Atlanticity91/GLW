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

#include "Specification/GlwTextureFillSpecification.h"

template<typename SpecificationType>
    requires ( std::is_base_of<GlwTextureSpecification, SpecificationType>::value )
class GlwTexture : public GlwRessource<SpecificationType> {

protected:
    GlwTextureTypes m_type;
    GlwTextureFormats m_format;
    glTexture m_texture;

public:
    /**
     * Constructor
     **/
    GlwTexture( )
        : GlwTexture{ GlwTextureTypes::Undefined }
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
        m_format = specification.Format;

        if ( specification.Format > GlwTextureFormats::None && CreateTexture( specification ) )
            SetTextureParameters( specification );

        return GetIsValid( );
    };

    /**
     * Fill method
     * @note : Fill texture according to specification.
     * @param specification : Query filling specification.
     **/
    virtual void Fill( const GlwTextureFillSpecification& specification ) {
        if ( !GetIsValid( ) || specification.Width == 0 || specification.Height == 0 )
            return;

        FillTexture( specification );
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
     * Constructor
     * @param type : Query texture instance type.
     **/
    GlwTexture( const GlwTextureTypes type )
        : m_type{ type },
        m_format{ GlwTextureFormats::None },
        m_texture{ GL_NULL } 
    { };

    /**
     * CreateTexture function
     * @note : Create texture according to specification.
     * @param specification : Query texture specification.
     * @return : True when creation succeeded.
     **/
    virtual bool CreateTexture( const SpecificationType& specification ) = 0;

    /**
     * SetTextureParameters method
     * @note : Set texture parameters according to specification.
     * @param specification : Query texture specification.
     **/
    virtual void SetTextureParameters( const SpecificationType& specification ) = 0;

    /**
     * FillTexture method
     * @note : Fill texture pixels according to specification.
     * @param specification : Query filling specification.
     **/
    virtual void FillTexture( const GlwTextureFillSpecification& specification ) = 0;

public:
    /**
     * GetIsValid const function
     * @note : Get if a texture is valid.
     * @return : True when texture is valid.
     **/
    virtual bool GetIsValid( ) const override {
        return  m_type   > GlwTextureTypes::Undefined &&
                m_format > GlwTextureFormats::None &&
                glIsValid( m_texture );
    };

    /**
     * GetType const function
     * @note : Get texture type.
     * @return : Return texture type value.
     **/
    GlwTextureTypes GetType( ) const {
        return m_type;
    };
    
    /**
     * GetFormat const function
     * @note : Get textur format.
     * @return : Return texture format value.
     **/
    GlwTextureFormats GetFormat( ) const {
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
