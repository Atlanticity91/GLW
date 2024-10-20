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

#include "GlwTextureSpecification.h"

struct GlwTextureFillSpecification {

    uint32_t Level;
    uint32_t X;
    uint32_t Y;
    uint32_t Width;
    uint32_t Height;
    uint32_t Type;
    void* Pixels;
    
    /**
     * Constructor 
     **/
    GlwTextureFillSpecification( );

    /**
     * Constructor
     * @param width : Query filling width.
     * @param height : Query filling height.
     **/
    GlwTextureFillSpecification(
        const uint32_t width,
        const uint32_t height
    );

    /**
     * Constructor
     * @param width : Query filling width.
     * @param height : Query filling height.
     * @param type : Query OpenGL pixel data type.
     **/
    GlwTextureFillSpecification(
        const uint32_t width,
        const uint32_t height,
        const uint32_t type
    );

};
