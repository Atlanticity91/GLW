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
GlwDebugTracker::GlwDebugTracker( )
    : MeshCount{ 0 },
    MaterialCount{ 0 },
    TextureCount{ 0 },
    RenderPass{ }
{ }

void GlwDebugTracker::Reset( ) {
#   ifdef GLW_DEBUG
    for ( auto& render_pass : RenderPass ) {
        render_pass.Commands.clear( );
        render_pass.Draws.clear( );
    }
#   endif
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
uint32_t GlwDebugTracker::GetTotalDrawCall( ) const {
    uint32_t total = 0;

    for ( auto& render_pass : RenderPass )
        total += (uint32_t)render_pass.Draws.size( );

    return total;
}

uint32_t GlwDebugTracker::GetTotalDrawVertices( ) const {
    uint32_t total = 0;

    for ( auto& render_pass : RenderPass ) {
        for ( auto& draw : render_pass.Draws )
            total += draw.VerticeCount;
    }

    return total;
}

void GlwDebugTracker::GetTotalDrawMetadata(
    uint32_t& draw_count, 
    uint32_t& vertice_count 
) const {
    draw_count = 0;
    vertice_count = 0;

    for ( auto& render_pass : RenderPass ) {
        draw_count += (uint32_t)render_pass.Draws.size( );

        for ( auto& draw : render_pass.Draws )
            vertice_count += draw.VerticeCount;
    }
}
