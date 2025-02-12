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

#include "GlwRenderPassTargetSpecification.h"

class GlwRenderTargetManager final { 

private:
	GlwColorTarget m_colors;
	GlwDepthTarget m_depth;
	GlwStencilTarget m_stencil;

public:
    /**
     * Constructor
     **/
	GlwRenderTargetManager( );

    /**
     * Destructor
     **/
	~GlwRenderTargetManager( ) = default;

    /**
     * Create function
     * @note : Create render pass targets according to specification.
     * @param specification : Query render pass specification.
     * @parma dimensions : Current render pass dimensions.
     * @param framebuffer : Current render pass framebuffer instance.
     * @param clear_flags : Reference to current render pass clear flags value.
     * @return : True when creation succeeded.
     **/
    bool Create(
        const GlwRenderPassTargetSpecification& specification,
        const glm::uvec2& dimensions,
        GlwFramebuffer& framebuffer,
        uint32_t& clear_flags
    );

    /**
     * Use method
     * @note : Bind render pass targets for usage.
     **/
	void Use( );
    
    /**
     * Destroy method
     * @note : Destroy render pass targets.
     **/
	void Destroy( );

private:
    /**
     * CreateDepthStencil function
     * @note : Create depth and stencil attachement.
     * @param specification : Query render pass specification.
     * @parma dimensions : Current render pass dimensions.
     * @param framebuffer : Current render pass framebuffer instance.
     * @param clear_flags : Reference to current render pass clear flags value.
     * @return : Return true when creation succeeded.
     **/
    bool CreateDepthStencil(
        const GlwRenderPassTargetSpecification& specification,
        const glm::uvec2& dimensions,
        GlwFramebuffer& framebuffer,
        uint32_t& clear_flags
    );

public:
    /**
     * GetColorAttachementCount const function
     * @note : Get current color attachement count.
     * @return : Return current color attachement count value.
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

};
