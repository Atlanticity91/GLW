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

#include "GlwExtras.h"

struct GlwGraphicSpecification {

    GlwDebugContext Debug;
    GlwBackend Backend;
    GlwFaceCulling Culling; 
    GlwExtras Extras;

    /**
     * Constructor
     **/
    GlwGraphicSpecification( );
    
    /**
     * Copy-Constructor
     * @param other : Query specification to copy.
     **/
    GlwGraphicSpecification( const GlwGraphicSpecification& other );

    /**
     * Constructor
     * @param major : OpenGL context version major.
     * @param minor : OpenGL context version minor.
     **/
    GlwGraphicSpecification(
        const uint32_t major,
        const uint32_t minor
    );

    /**
     * Constructor
     * @param major : OpenGL context version major.
     * @param minor : OpenGL context version minor.
     * @param profile : OpenGL context profile value.
     **/
    GlwGraphicSpecification( 
        const uint32_t major,
        const uint32_t minor,
        const uint32_t profile
    );

};
