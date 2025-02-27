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

extern "C" {
	#include <inttypes.h>
};

#include <vector>

// === GLEW Header ===
#define GLEW_STATIC
#include "GL/glew.h"

#if defined( _DEBUG ) || defined( DEBUG )
#   define GLW_DEBUG
#endif

#define GL_NULL 0
#define GL_SHADER_NULL ((glShader)GL_NULL)
#define GL_TEXTURE_NULL ((glTexture)GL_NULL)

#define glIsValid( GL_HANDLE ) (bool)( GL_HANDLE > GL_NULL )
#define glwBoolToState( BOOL ) ( ( BOOL == true ) ? GlwStates::Enable : GlwStates::Disable )

typedef GLuint glFormat;
typedef GLuint glTexture;
typedef GLuint glShader;
typedef GLuint glProgram;
typedef GLuint glBuffer;
typedef GLuint glVertexArray;
typedef GLuint glFramebuffer;

enum class GlwStates : uint32_t {

	Disable = 0,
    Enable,

};

/**
 * glw_copy method
 * @note : Wrapper for platform specific memcopy.
 * @param src : Query source data. 
 * @param dst : Query destination data.
 * @param size : Query data size.
 **/
inline void glw_copy( const void* src, void* dst, const size_t size ) {
	#	ifdef _WIN32
	memmove_s( dst, size, src, size );
	#	else
	memmove( dst, src, size );
	#	endif
};
