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
GlwTextureFillSpecification::GlwTextureFillSpecification( )
	: GlwTextureFillSpecification{ 0, 0, nullptr }
{ }

GlwTextureFillSpecification::GlwTextureFillSpecification(
    const uint32_t width,
    const uint32_t height
)
    : GlwTextureFillSpecification{ width, height, GL_UNSIGNED_BYTE }
{ }

GlwTextureFillSpecification::GlwTextureFillSpecification(
    const uint32_t width,
    const uint32_t height,
    const uint32_t type
)
    : Level{ 0 },
    X{ 0 },
    Y{ 0 },
    Width{ width },
    Height{ height },
    Type{ type },
    Pixels{ nullptr }
{ }

GlwTextureFillSpecification::GlwTextureFillSpecification(
    const uint32_t width,
    const uint32_t height,
    const uint8_t* pixels
) 
    : GlwTextureFillSpecification{ width, height, GL_UNSIGNED_BYTE }
{ 
    Pixels = (void*)pixels;
}
