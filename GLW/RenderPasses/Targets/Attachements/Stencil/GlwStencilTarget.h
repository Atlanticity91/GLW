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

#include "GlwStencilTargetSpecification.h"

class GlwStencilTarget final {

private:
    bool m_enabled;
    GlwStencilParameters m_parameters;
    GlwRenderAttachement m_attachement;

public:
    /**
     * Constructor
     **/
    GlwStencilTarget( );

     /**
     * Destructor
     **/
    ~GlwStencilTarget( ) = default;

    /**
     * Create function
     * @note : Create render target according to specification.
     * @param specification : Query render target specification.
     * @param dimensions : Current render pass dimensions.
     * @param framebuffer : Reference to current render pass framebuffer instance.
     * @param clear_flags : Reference to current render pass clear flags instance.
     * @return : Return true when creation succeeded.
     **/
    bool Create(
        const GlwStencilTargetSpecification& specification,
        const glm::uvec2& dimensions,
        GlwFramebuffer& framebuffer,
        uint32_t& clear_flags
    );

    /**
     * Setup method
     * @note : Setup stencil buffer when depth buffer is present.
     * @param clear_flags : Reference to current render pass clear flags instance.
     * @param specification : Query stencil target specification.
     **/
    void Setup( 
        const GlwStencilTargetSpecification& specification,
        uint32_t& clear_flags 
    );

    /**
     * Use method
     * @note : Bind stencil buffer for usage.
     **/
    void Use( );

    /**
     * Destroy method
     * @note : Destroy current render target.
     **/
    void Destroy( );

public:
    /**
     * GetAttachement const function
     * @note : Get query target attachement value.
     * @return : Return OpenGL texture handle of the attachement.
     **/
    const glTexture GetAttachement( ) const;

};
