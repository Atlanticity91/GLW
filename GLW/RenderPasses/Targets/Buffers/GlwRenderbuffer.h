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

#include "GlwFramebuffer.h"

class GlwRenderbuffer final { 

private:
	uint32_t m_render_buffer;

public:
	/**
	 * Constructor
	 **/
	GlwRenderbuffer( );
	
	/**
	 * Destructor
	 **/
	~GlwRenderbuffer( ) = default;

	/**
	 * Create function
	 * @note : Create render buffer according to specification.
	 * @param dimensions : Query render buffer dimensions.
	 * @param type : Query render buffer OpenGL type.
	 * @return : Return true when operation succeeded.
	 **/
	bool Create(
		const glm::uvec2& dimensions,
		const uint32_t type
	);

	/**
	 * Destroy method
	 * @note : Destroy current render buffer.
	 **/
	void Destroy( );

public:
	/**
	 * GetIsValid const function
	 * @note : Get if render buffer is valid.
	 * @return : Return true when render buffer is valid.
	 **/
	bool GetIsValid( ) const;

	/**
	 * Get const function
	 * @note : Get render buffer OpenGL handle.
	 * @return : Return render buffer OpenGL handle value.
	 **/
	const uint32_t Get( ) const;

public:
	/**
	 * Cast operator
	 * @note : Cast to render buffer OpenGL handle.
	 * @return : Return Get( ) call value.
	 **/
	operator const uint32_t ( ) const;

};
