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

#include "GlwDebugTrackerRenderPass.h"

#define GlwTrackMesh( TRACKER ) TRACKER.MeshCount += 1
#define GlwTrackMaterial( TRACKER ) TRACKER.MaterialCount += 1
#define GlwTrackTexture( TRACKER ) TRACKER.TextureCount += 1

#ifdef DEBUG
#   define GlwTrackCommand( TRACKER, RENDER_PASS, NAME, VALUE )\
        TRACKER.RenderPass[ RENDER_PASS ].Commands.emplace_back( GlwDebugTrackerCommands{ NAME, (uint64_t)VALUE } );
#define GlwTrackDraw( TRACKER, RENDER_PASS, VERTICE_COUNT )\
        TRACKER.RenderPass[ RENDER_PASS ].Draws.emplace_back( GlwDebugTracherDraws{ VERTICE_COUNT } );
#else
#   define GlwTrackCommand( TRACKER, RENDER_PASS, NAME, VALUE ) 
#   define GlwTrackDraw( TRACKER, RENDER_PASS, VERTICE_COUNT )
#endif

struct GlwDebugTracker {

    uint32_t MeshCount;
    uint32_t MaterialCount;
    uint32_t TextureCount;
    std::vector<GlwDebugTrackerRenderPass> RenderPass;

    /**
     * Constructor
     **/
    GlwDebugTracker( );

    /**
     * GetTotalDrawCall const function
     * @note : Get total draw call count on a frame.
     * @return : Return total draw call count value for a frame.
     **/
    uint32_t GetTotalDrawCall( ) const;

    /**
     * GetTotalDrawVertices const function
     * @note : Get total draw vertice count on a frame.
     * @return : Return total draw vertice count value for a frame.
     **/
    uint32_t GetTotalDrawVertices( ) const;

    /**
     * GetTotalDrawCall const method
     * @note : Get total draw call count and draw vertice count on a frame.
     * @param draw_count : Used for retrive total draw call count value for a frame.
     * @param vertice_count : Used for retrive total draw vertice count value for a frame.
     **/
    void GetTotalDrawMetadata( 
        uint32_t& draw_count, 
        uint32_t& vertice_count 
    ) const;

};
