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
//      === PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwMaterial::GlwMaterial( )
    : m_program_id{ GL_NULL } 
{ }

bool GlwMaterial::Create( const GlwMaterialSpecification& specification ) {
    auto shader_vert = GL_SHADER_NULL;
    auto shader_frag = GL_SHADER_NULL;
    auto shader_geom = GL_SHADER_NULL;
    auto result      = false;

    if (
        specification.GetIsValid( )                                    &&
        Compile( GL_VERTEX_SHADER, specification.Vertex, shader_vert ) &&
        Compile( GL_FRAGMENT_SHADER, specification.Fragment, shader_frag )
    ) {
        if ( GetIsSourceValid( specification.Geometry ) )
            Compile( GL_GEOMETRY_SHADER, specification.Geometry, shader_geom );

        result = Link( shader_vert, shader_frag, shader_geom );

        glDeleteShader( shader_vert );
        glDeleteShader( shader_frag );

        if ( glIsValid( shader_geom ) )
            glDeleteShader( shader_geom );
    }

    return result;
}

void GlwMaterial::SetUniform( const int32_t location, const int32_t scalar ) {
    if ( !GetIsLocationValid( location ) )
        return;

    glUniform1i( location, scalar );
}

void GlwMaterial::SetUniform( const int32_t location, const float scalar ) {
    if ( !GetIsLocationValid( location ) )
        return;

    glUniform1f( location, scalar );
}

void GlwMaterial::SetUniform( const int32_t location, const glm::vec2& vector ) {
    if ( !GetIsLocationValid( location ) )
        return;

    glUniform2f( location, vector.x, vector.y );
}

void GlwMaterial::SetUniform( const int32_t location, const glm::vec3& vector ) {
    if ( !GetIsLocationValid( location ) )
        return;

    glUniform3f( location, vector.x, vector.y, vector.z );
}

void GlwMaterial::SetUniform( const int32_t location, const glm::vec4& vector ) {
    if ( !GetIsLocationValid( location ) )
        return;

    glUniform4f( location, vector.x, vector.y, vector.z, vector.w );
}

void GlwMaterial::SetUniform( const int32_t location, const glm::mat3& matrix ) {
    if ( !GetIsLocationValid( location ) )
        return;

    auto* gl_matrix = glm::value_ptr( matrix );

    glUniformMatrix3fv( location, 1, GL_FALSE, gl_matrix );
}

void GlwMaterial::SetUniform( const int32_t location, const glm::mat4& matrix ) {
    if ( !GetIsLocationValid( location ) )
        return;

    auto* gl_matrix = glm::value_ptr( matrix );

    glUniformMatrix4fv( location, 1, GL_FALSE, gl_matrix );
}

void GlwMaterial::SetUniform( const std::string& name, const int32_t scalar ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, scalar );
}

void GlwMaterial::SetUniform( const std::string& name, const float scalar ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, scalar );
}

void GlwMaterial::SetUniform( const std::string& name, const glm::vec2& vector ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, vector );
}

void GlwMaterial::SetUniform( const std::string& name, const glm::vec3& vector ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, vector );
}

void GlwMaterial::SetUniform( const std::string& name, const glm::vec4& vector ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, vector );
}

void GlwMaterial::SetUniform( const std::string& name, const glm::mat3& matrix ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, matrix );
}

void GlwMaterial::SetUniform( const std::string& name, const glm::mat4& matrix ) {
    auto location = GetUniformLocation( name );

    SetUniform( location, matrix );
}

void GlwMaterial::SetUniformBuffer( const int32_t location, const GlwBuffer& buffer ) {
    if ( !GetIsLocationValid( location) || !buffer.GetIsValid( ) || buffer.GetType( ) != GlwBufferTypes::Uniform )
        return;

    auto gl_buffer = buffer.Get( );

    glUniformBlockBinding( m_program_id, gl_buffer, location );
}

void GlwMaterial::SetUniformBuffer( const std::string& name, const GlwBuffer& buffer ) {
    auto location = GetBufferLocation( name );

    SetUniformBuffer( location, buffer );
}

void GlwMaterial::SetTexture( 
    const uint32_t slot,
    const GlwTextureTypes type,
    const GlwTextureFormats format,
    const glTexture texture
) {
    if ( !glIsValid( texture ) )
        return;

    auto gl_type = GetTextureType( type );
    auto gl_mode = GetTextureMode( format );

    glActiveTexture( GL_TEXTURE0 + slot );
    glBindTexture( gl_type, texture );

    if ( gl_mode > 0 )
        glTexParameteri( gl_type, GL_DEPTH_STENCIL_TEXTURE_MODE, gl_mode );
}

GlwMaterial* GlwMaterial::Use( ) {
    glUseProgram( m_program_id );

    return this;
}

void GlwMaterial::Destroy( ) {
    if ( GetIsValid( ) )
        glDeleteProgram( m_program_id );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwMaterial::Compile( const uint32_t type, const std::vector<char>& source, glShader& shader_id ) {
    auto result = GL_FALSE;

    if ( GetIsSourceValid( source ) ) {
        auto* source_data = source.data( );

        shader_id = glCreateShader( type );

        glShaderSource( shader_id, 1, &source_data, NULL );
        glCompileShader( shader_id );

        glGetShaderiv( shader_id, GL_COMPILE_STATUS, &result );

#       ifdef _DEBUG
        if ( !result ) {
            char gl_log_data[ 512 ];

            glGetShaderInfoLog( shader_id, 512, NULL, gl_log_data );

            printf( "[ GL - ERROR ] Shader Compilation :\n%s\n", gl_log_data );
        }
#       endif
    }

    return result == GL_TRUE;
}

bool GlwMaterial::Link( const glShader shader_vert, const glShader shader_frag, const glShader shader_geom ) {
    auto result = GL_FALSE;

    m_program_id = glCreateProgram( );

    glAttachShader( m_program_id, shader_vert );
    glAttachShader( m_program_id, shader_frag );

    if ( glIsValid( shader_geom ) )
        glAttachShader( m_program_id, shader_geom );

    glLinkProgram( m_program_id );

#   ifdef _DEBUG
    glGetProgramiv( m_program_id, GL_LINK_STATUS, &result );
    if ( !result ) {
        char gl_log_data[ 512 ];

        glGetProgramInfoLog( m_program_id, 512, NULL, gl_log_data );
        printf( "[ GL - ERROR ] Shader Linking :\n%s\n", gl_log_data );
    }
#   endif

    return result == GL_TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwMaterial::GetIsValid( ) const {
    return glIsValid( m_program_id );
}

int32_t GlwMaterial::GetUniformLocation( const std::string& name ) const {
    auto* _name = name.c_str( );

    return glGetUniformLocation( m_program_id, _name );
}

bool GlwMaterial::GetUniformLocation( const std::string& name, int32_t& location ) const {
    location = GetUniformLocation( name );

    return GetIsLocationValid( location );
}

int32_t GlwMaterial::GetBufferLocation( const std::string& name ) const {
    auto* _name = name.c_str( );

    return glGetUniformBlockIndex( m_program_id, _name );
}

bool GlwMaterial::GetBufferLocation( const std::string& name, int32_t& location ) const {
    location = GetBufferLocation( name );

    return GetIsLocationValid( location );
}

bool GlwMaterial::GetIsLocationValid( const int32_t location ) const {
    return location > -1;
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwMaterial::GetIsSourceValid( const std::vector<char>& source ) {
    return source.size( ) > 0;
}

uint32_t GlwMaterial::GetTextureType( const GlwTextureTypes type ) const {
    auto result = GL_TEXTURE_2D;

    switch ( type ) {
        case GlwTextureTypes::Cubemap : result = GL_TEXTURE_CUBE_MAP; break;

        default: break;
    }

    return result;
}

uint32_t GlwMaterial::GetTextureMode( const GlwTextureFormats format ) const {
    auto result = 0;

    switch ( format ) {
        case GlwTextureFormats::Depth   : result = GL_DEPTH_COMPONENT; break;
        case GlwTextureFormats::Stencil : result = GL_STENCIL_INDEX;   break;

        default: break;
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwMaterial& GlwMaterial::operator=( const GlwMaterial& other ) {
    if ( other.GetIsValid( ) ) {
        Destroy( );

        m_program_id = other.m_program_id;
    }

    return *this;
}
