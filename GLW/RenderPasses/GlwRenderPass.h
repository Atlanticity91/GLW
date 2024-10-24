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

#include "Specification/GlwRenderPassSpecification.h"

class GlwRenderPass final {

private:
    GlwFramebuffer m_framebuffer;
    GlwRenderTargetManager m_targets;
    GlwColorBlend m_color_blend;
    glm::ivec2 m_dimensions;
    glm::vec4 m_refresh;
    uint32_t m_clear_flags;

public:
    /**
     * Constructor
     **/
    GlwRenderPass( );

    /**
     * Destructor
     **/
    ~GlwRenderPass( ) = default;

    /**
     * Create function
     * @note : Create render pass according to specification.
     * @param specification : Query render pass specification.
     * @return : True when creation succeeded.
     **/
    bool Create( const GlwRenderPassSpecification& specification );

    /**
     * SetRefreshColor method
     * @note : Set refresh color.
     * @param color : Query refresh color value.
     **/
    void SetRefreshColor( const glm::vec4& color );

    /**
     * Use method
     * @note : Bind current render pass for usage.
     **/
    void Use( );

    /**
     * Destroy method
     * @note : Destroy render pass.
     **/
    void Destroy( );

public:
    /**
     * GetIsValid const function
     * @note : Get render pass validity.
     * @return : Return true when render pass is valid.
     **/
    bool GetIsValid( ) const;

    /**
     * GetDimensions const function
     * @note : Get render pass dimensions.
     * @return : Return render pass dimensions as integer point.
     **/
    glm::ivec2 GetDimensions( ) const;

    /**
     * GetRefreshColor const function
     * @note : Get render pass refresh color.
     * @return : Return refresh color value as vector 4.
     **/
    glm::vec4 GetRefreshColor( ) const;

    /**
     * GetColorAttachementCount const function
     * @note : Get current render pass color attachement count.
     * @return : Return current render pass color attachement count value.
     **/
    uint32_t GetColorAttachementCount( ) const;
    
    /**
     * GetColorAttachement const function
     * @note : Get color attachement OpenGL texture handle.
     * @param target : Query render pass target.
     * @return : Return attachement OpenGL texture handle value.
     **/
    const glTexture GetColorAttachement( const uint32_t target ) const;

    /**
     * GetDepthAttachement const function
     * @note : Get depth attachement OpenGL handle.
     * @return : Return depth attachement OpenGL texture handle value.
     **/
    const glTexture GetDepthAttachement( ) const;

    /**
     * GetStencilAttachement const function
     * @note : Get stencil attachement OpenGL handle.
     * @return : Return stencil attachement OpenGL texture handle value.
     **/
    const glTexture GetStencilAttachement( ) const;

    /**
     * GetAttachement const function
     * @note : Get attachement OpenGL handle.
     * @param type : Query attachement type.
     * @param target : Query render pass target value.
     * @return : Return attachement OpenGL texture handle value.
     **/
    const glTexture GetAttachement(
        const GlwRenderAttachementTypes type,
        const uint32_t target
    ) const;

public:
    /**
     * Cast operator
     * @note : Cast render pass validity.
     * @return : Return GetIsValid( ) call value.
     **/
    operator bool( ) const;

};
