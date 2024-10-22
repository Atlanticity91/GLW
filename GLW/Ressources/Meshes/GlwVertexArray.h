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

#include "GlwVertexAttribute.h"

class GlwVertexArray final {

private:
	glVertexArray m_handle;

public:
	/**
	 * Constructor
	 **/
	GlwVertexArray( );
	
	/**
	 * Destructor
	 **/
	~GlwVertexArray( ) = default;

	/**
	 * Create function
	 * @note : Create vertex array.
	 * @return : True when operation succeeded.
	 **/
	bool Create( );

	/**
	 * Link method
	 * @note : Link query vertex attribute list.
	 * @param attributes : Query attribute list.
	 **/
	void Link( const std::vector<GlwVertexAttribute>& attributes );

	/**
	 * Use method
	 * @note : Bind vertex array for usage.
	 **/
	void Use( );

	/**
	 * Destroy method
	 * @note : Destroy vertex array.
	 **/
	void Destroy( );

public:
	/**
	 * Get const function
	 * @note : Get OpenGL vertex array handle.
	 * @return : Constant OpenGL vertex array handle value.
	 **/
	const glVertexArray Get( ) const;

public:
	/**
	 * Cast operator
	 * @note : Cast vertex array to OpenGL vertex array handle.
	 * @return : Return Get( ) call value.
	 **/
	operator const glVertexArray ( ) const;

};
