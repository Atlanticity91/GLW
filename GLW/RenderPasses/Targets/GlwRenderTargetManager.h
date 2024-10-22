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

#include "Stencil/GlwStencilTarget.h"

class GlwRenderTargetManager final { 

private:
	GlwColorTargetManager m_colors;
	GlwDepthTarget m_depth;
	GlwStencilTarget m_stencil;

public:
	GlwRenderTargetManager( );

	~GlwRenderTargetManager( ) = default;

    /**
     * Create function
     * @note : Create render pass targets according to specification.
     * @param framebuffer : Current render pass framebuffer instance.
     * @param specification : Query render pass specification.
     * @param clear_flags : Reference to current render pass clear flags value.
     * @return : True when creation succeeded.
     **/
    bool Create( 
        const GlwFramebuffer& framebuffer,
        const GlwRenderPassSpecification& specification,
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
	 * CreateDepthAttachement function
	 * @note : Create depth attachement according to specification.
     * @param framebuffer : Current render pass framebuffer instance.
	 * @param specification : Query depth specification.
     * @param clear_flags : Reference to current render pass clear flags value.
	 * @return : Return true when operation succeeded.
	 **/
    bool CreateDepthAttachement( 
        const GlwFramebuffer& framebuffer, 
        const GlwDepthTargetSpecification& specification,
        uint32_t& clear_flags
    );

    /**
     * CreateStencilAttachement function
     * @note : Create stencil attachement according to specification.
     * @param framebuffer : Current render pass framebuffer instance.
     * @param specification : Query stencil specification.
     * @param clear_flags : Reference to current render pass clear flags value.
     * @return : Return true when operation succeeded.
     **/
    bool CreateStencilAttachement(
        const GlwFramebuffer& framebuffer, 
        const GlwStencilTargetSpecification& specification,
        uint32_t& clear_flags
    );

public:
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
