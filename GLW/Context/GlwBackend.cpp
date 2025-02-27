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
GlwBackend::GlwBackend( )
	: GlwBackend{ 4, 5, 1 }
{ }

GlwBackend::GlwBackend( const GlwBackend& other )
	: Major{ other.Major },
	Minor{ other.Minor },
	Profile{ other.Profile },
	SwapInterval{ other.SwapInterval },
	DoubleBuffer{ other.DoubleBuffer }
{ }

GlwBackend::GlwBackend( const uint32_t major, const uint32_t minor )
	: GlwBackend{ major, minor, 1 }
{ }

GlwBackend::GlwBackend( 
	const uint32_t major, 
	const uint32_t minor,
	const uint32_t profile
)
	: Major{ major },
	Minor{ minor },
	Profile{ profile },
	SwapInterval{ GL_TRUE },
	DoubleBuffer{ GlwStates::Enable }
{ }
