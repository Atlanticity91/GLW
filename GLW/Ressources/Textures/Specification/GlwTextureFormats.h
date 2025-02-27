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

#include "GlwTextureTypes.h"

enum class GlwTextureFormats : uint32_t {

    None    = 0,
    R_ONLY  = GL_RED,
    RG_ONLY = GL_RG,
    RGB     = GL_RGB,
    BGR     = GL_BGR,
    RGBA    = GL_RGBA,
    BGRA    = GL_BGRA,
    S_RGB   = GL_SRGB,
    S_RGBA  = GL_SRGB_ALPHA,
    Color   = RGBA,
    S_Color = S_RGBA,
    Depth   = GL_DEPTH_COMPONENT,
    Stencil = GL_STENCIL_INDEX,
    Depth_Stencil = GL_DEPTH_STENCIL

};
