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

#include "Utils/GlwColorTargets.h"

struct GlwRenderPassSpecification {

    uint32_t Width;
    uint32_t Height;
    bool UseSeparateStencil;
    std::vector<GlwColorTargetSpecification> ColorTargets;
    GlwDepthTargetSpecification DepthTarget;
    GlwStencilTargetSpecification StencilTarget;
    GlwColorBlendSpecification ColorBlend;

    /**
     * Constructor
     **/
    GlwRenderPassSpecification( );

    /**
     * Constructor
     * @param width : Query render target width.
     * @param height : Query render target height.
     **/
    GlwRenderPassSpecification( const uint32_t width, const uint32_t height );

    /**
     * GetIsValid const function
     * @note : Get render pass validity.
     * @return : True when render pass specification is valid.
     **/
    bool GetIsValid( ) const;

    /**
     * Cast operator
     * @note : Cast specification to boolean, aka get is validity.
     **/
    operator bool ( ) const;

};
