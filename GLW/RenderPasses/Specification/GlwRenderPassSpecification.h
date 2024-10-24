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

#include "GlwRenderPassDepthStencilBind.h"

struct GlwRenderPassSpecification {

    glm::uvec2 Dimensions;
    glm::vec4 Refresh;
    GlwRenderPassDepthStencilBind DepthStencilBind;
    GlwRenderPassTargetSpecification Targets;
    GlwColorBlendSpecification ColorBlend;

    /**
     * Constructor
     **/
    GlwRenderPassSpecification( );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     **/
    GlwRenderPassSpecification( const glm::uvec2& dimensions );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param refresh : Query render pass refresh color.
     **/
    GlwRenderPassSpecification( 
        const glm::uvec2& dimensions,
        const glm::vec4& refresh
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     **/
    GlwRenderPassSpecification( const uint32_t width, const uint32_t height );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param targets : Query render pass specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification( 
        const uint32_t width,
        const uint32_t height,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param refresh : Query render pass refresh color.
     * @param targets : Query render pass specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const glm::vec4& refresh,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param refresh : Query render pass refresh color.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification(
        const uint32_t width,
        const uint32_t height,
        const glm::vec4& refresh,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param refresh : Query render pass refresh color.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const glm::vec4& refresh,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification(
        const uint32_t width,
        const uint32_t height,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param refresh : Query render pass refresh color.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     **/
    GlwRenderPassSpecification(
        const uint32_t width,
        const uint32_t height,
        const glm::vec4& refresh,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets
    );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     * @param color_blend : Query color blending specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets,
        const GlwColorBlendSpecification& color_blend
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     * @param color_blend : Query color blending specification.
     **/
    GlwRenderPassSpecification(
        const uint32_t width,
        const uint32_t height,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets,
        const GlwColorBlendSpecification& color_blend
    );

    /**
     * Constructor
     * @param dimensions : Query render pass dimensions.
     * @param refresh : Query render pass refresh color.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     * @param color_blend : Query color blending specification.
     **/
    GlwRenderPassSpecification(
        const glm::uvec2& dimensions,
        const glm::vec4& refresh,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets,
        const GlwColorBlendSpecification& color_blend
    );

    /**
     * Constructor
     * @param width : Query render pass width.
     * @param height : Query render pass height.
     * @param refresh : Query render pass refresh color.
     * @param depth_stencil_bind : Query depth and stencil target bind mode.
     * @param targets : Query render targets specification.
     * @param color_blend : Query color blending specification.
     **/
    GlwRenderPassSpecification(
        const uint32_t width,
        const uint32_t height,
        const glm::vec4& refresh,
        const GlwRenderPassDepthStencilBind depth_stencil_bind,
        const GlwRenderPassTargetSpecification& targets,
        const GlwColorBlendSpecification& color_blend
    );

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
