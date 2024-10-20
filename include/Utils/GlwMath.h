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

#include "GlwOpenGL.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL

#include "../../Thirdparty/GLM/glm/glm.hpp"
#include "../../Thirdparty/GLM/glm/gtc/matrix_inverse.hpp"
#include "../../Thirdparty/GLM/glm/gtc/matrix_transform.hpp"
#include "../../Thirdparty/GLM/glm/gtc/type_ptr.hpp"
#include "../../Thirdparty/GLM/glm/gtx/matrix_decompose.hpp"
#include "../../Thirdparty/GLM/glm/gtx/transform.hpp"
#include "../../Thirdparty/GLM/glm/gtx/quaternion.hpp"
#include "../../Thirdparty/GLM/glm/gtx/string_cast.hpp"
