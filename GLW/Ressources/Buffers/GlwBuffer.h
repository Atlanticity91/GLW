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

#include "GlwBufferSpecification.h"

class GlwBuffer : public GlwRessource<GlwBufferSpecification> {

protected:
	GLuint m_type;
	GLuint m_mode;
	glBuffer m_handle;

public:
	/**
	 * Constructor
	 **/
	GlwBuffer( );

	/**
	 * Destructor
	 **/
	~GlwBuffer( ) = default;

	/**
	 * Create function
	 * @note : Create buffer according to query specification.
	 * @param specification : Query buffer specification.
	 * @return : True when creation succeeded.
	 **/
	virtual bool Create( const GlwBufferSpecification& specification ) override;

	/**
	 * Fill function
	 * @note : Fill buffer.
	 * @param length : Length of buffer in bytes.
	 * @param vertices : Pointer to buffer data.
	 * @return : True when operation succeeded.
	 **/
	bool Fill( const uint32_t length, const void* data );

	/**
	 * Destroy method
	 * @note : Destroy buffer.
	 **/
	virtual void Destroy( ) override;

public:
	/**
	 * Fill template function
	 * @note : Fill buffer.
	 * @template Type : Type of data used by the buffer.
	 * @param buffer_data : Buffer data.
	 * @return : True when operation succeeded.
	 **/
	template<typename Type>
	bool Fill( const Type& buffer_data ) {
		auto length = (uint32_t)sizeof( Type );

		return Fill( length, &buffer_data );
	};

	/**
	 * Fill template function
	 * @note : Fill buffer.
	 * @template Type : Type of data used by the buffer.
	 * @param buffer_data : Buffer data list.
	 * @return : True when operation succeeded.
	 **/
	template<typename Type>
	bool Fill( const std::vector<Type>& buffer_data ) {
		auto* data  = (void*)buffer_data.data( );
		auto length = (uint32_t)( buffer_data.size( ) * sizeof( Type ) );
		
		return Fill( length, data );
	};

public:
	/**
	 * GetIsValid const function
	 * @note : Get buffer validity.
	 * @return : True when buffer is valid.
	 **/
	virtual bool GetIsValid( ) const override;

	/**
	 * GetType const function
	 * @note : Get buffer type.
	 * @return : Return buffer type value.
	 **/
	const GlwBufferTypes GetType( ) const;

	/**
	 * GetMode const function
	 * @note : Get OpenGL buffer mode.
	 * @return : Return OpenGL buffer mode value.
	 **/
	const GLuint GetMode( ) const;

	/**
	 * Get const function
	 * @note : Get OpenGL buffer handle.
	 * @return : Return OpenGL buffer handle value.
	 **/
	const glBuffer Get( ) const;

public:
	/**
	 * Cast operator
	 * @note : Cast buffer to OpenGL buffer handle.
	 * @return : Return Get( ) call value.
	 **/
	operator const glBuffer( ) const;

};
