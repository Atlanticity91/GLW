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

#include "../RenderPasses/GlwRenderPassManager.h"

class GlwSwapchain final {

private:
    glm::ivec2 m_dimensions;
    glm::vec4 m_refresh;

public:
    /**
     * Constructor
     **/
    GlwSwapchain( );

    /**
     * Destructor 
     **/
    ~GlwSwapchain( ) = default;

    /**
     * Create method
     * @note : Create swapchain.
     * @param window : Pointer to current window instance.
     **/
    void Create( const GlwWindow* window );

    /**
     * Resize method
     * @note : Resize current swapchain.
     * @param window : Pointer to current window instance.
     **/
    void Resize( const GlwWindow* window );

    /**
     * SetRefresh method
     * @note : Set refresh color.
     * @param color : Refresh color value.
     **/
    void SetRefresh( const glm::vec4& color );

    /**
     * Use method
     * @note : Use swapchain with render passes.
     * @param viewport_dimensions : Dimensions of the last render pass
     *                              to adjuste screen positioning according
     *                              to aspect ratio.
     **/
    void Use( const glm::ivec2& viewport_dimensions );

    /**
     * Use method
     * @note : Use swapchain without renderpass.
     **/
    void Use( );

private:
    /**
     * GetViewportDestination function
     * @note : Calculate viewport position and dimensions according to aspect ratio.
     * @return : Viewport position and dimensions as vector 4.
     **/
    glm::ivec4 GetViewportDestination( const glm::ivec2& viewport_dimensions );

    /**
     * Bind method
     * @note : Bind screen with query viewport.
     * @param viewport : Query viewport.
     **/
    void Bind( const glm::ivec4& viewport );

};
