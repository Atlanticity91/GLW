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

#include "__glw_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderPassSpecification::GlwRenderPassSpecification( )
    : GlwRenderPassSpecification{ { 0, 0 }, GlwRenderPassDepthStencilBind::Combined, { }, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification( const glm::uvec2& dimensions )
    : GlwRenderPassSpecification{ dimensions, GlwRenderPassDepthStencilBind::Combined, { }, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification( 
	const uint32_t width,
	const uint32_t height 
)
    : GlwRenderPassSpecification{ { width, height }, GlwRenderPassDepthStencilBind::Combined, { }, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const glm::uvec2& dimensions,
    const GlwRenderPassTargetSpecification& targets
)
    : GlwRenderPassSpecification{ dimensions, GlwRenderPassDepthStencilBind::Combined, targets, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const uint32_t width,
    const uint32_t height,
    const GlwRenderPassTargetSpecification& targets
)
    : GlwRenderPassSpecification{ { width, height }, GlwRenderPassDepthStencilBind::Combined, targets, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const glm::uvec2& dimensions,
    const GlwRenderPassDepthStencilBind depth_stencil_bind,
    const GlwRenderPassTargetSpecification& targets
)
    : GlwRenderPassSpecification{ dimensions, depth_stencil_bind, targets, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const uint32_t width,
    const uint32_t height,
    const GlwRenderPassDepthStencilBind depth_stencil_bind,
    const GlwRenderPassTargetSpecification& targets
)
    : GlwRenderPassSpecification{ { width, height }, depth_stencil_bind, targets, { } }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const glm::uvec2& dimensions,
    const GlwRenderPassDepthStencilBind depth_stencil_bind,
    const GlwRenderPassTargetSpecification& targets,
    const GlwColorBlendSpecification& color_blend
)
    : Dimensions{ dimensions },
    DepthStencilBind{ depth_stencil_bind },
    Targets{ targets },
    ColorBlend{ color_blend }
{ }

GlwRenderPassSpecification::GlwRenderPassSpecification(
    const uint32_t width,
    const uint32_t height,
    const GlwRenderPassDepthStencilBind depth_stencil_bind,
    const GlwRenderPassTargetSpecification& targets,
    const GlwColorBlendSpecification& color_blend
)
    : GlwRenderPassSpecification{ { width, height }, depth_stencil_bind, targets, color_blend }
{ }

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool GlwRenderPassSpecification::GetIsValid( ) const {
	return Dimensions.x > 0 && Dimensions.y > 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRenderPassSpecification::operator bool( ) const {
	return GetIsValid( );
}