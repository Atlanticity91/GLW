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
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwTextureWrapSpecification::GlwTextureWrapSpecification( )
	: GlwTextureWrapSpecification{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE }
{ }

GlwTextureWrapSpecification::GlwTextureWrapSpecification( const uint32_t value )
	: GlwTextureWrapSpecification{ value, value, value }
{ }

GlwTextureWrapSpecification::GlwTextureWrapSpecification( 
	const uint32_t r,
	const uint32_t s, 
	const uint32_t t
)
	: R{ r },
	S{ s },
	T{ t }
{ }

GlwTextureWrapSpecification::GlwTextureWrapSpecification( 
	const GlwTextureWrapSpecification& other 
)
	: R{ other.R },
	S{ other.S },
	T{ other.T } 
{ }

GlwTextureWrapSpecification::GlwTextureWrapSpecification( GlwTextureWrapSpecification&& other )
	: R{ other.R },
	S{ other.S },
	T{ other.T }
{ }

GlwTextureWrapSpecification& GlwTextureWrapSpecification::operator=(
	const GlwTextureWrapSpecification& other
){
	R = other.R;
	S = other.S;
	T = other.T;

	return ( *this );
}
