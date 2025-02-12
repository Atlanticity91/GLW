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
//      === PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwSwapchain::GlwSwapchain( )
    : m_dimensions{ },
    m_refresh{ 0.f, 0.f, 0.f, 1.f } 
{ };

void GlwSwapchain::Create( const GlwWindow* window ) {
    m_dimensions = window->GetDimensions( );
}

void GlwSwapchain::Resize( const GlwWindow* window ) {
    m_dimensions = window->GetDimensions( );
}

void GlwSwapchain::SetRefresh( const glm::vec4& color ) {
    m_refresh = color;
}

void GlwSwapchain::Use( const glm::ivec2& viewport_dimensions ) {
    auto destination = GetViewportDestination( viewport_dimensions );

    Bind( destination );
}

void GlwSwapchain::Use( ) {
    Bind( { 0, 0, m_dimensions.x, m_dimensions.y } );
}

////////////////////////////////////////////////////////////////////////////////////////////
//      === PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
glm::ivec4 GlwSwapchain::GetViewportDestination( const glm::ivec2& viewport_dimensions ) {
    auto destination = glm::ivec4{ };
    auto scale_x     = (float)m_dimensions.x / viewport_dimensions.x;
    auto scale_y     = (float)m_dimensions.y / viewport_dimensions.y;
    auto scale       = !( scale_x < scale_y ) ? scale_y : scale_x;

    destination.z = (int)( viewport_dimensions.x * scale );
    destination.w = (int)( viewport_dimensions.y * scale );
    destination.x = ( m_dimensions.x - destination.z ) / 2;
    destination.y = ( m_dimensions.y - destination.w ) / 2;

    return destination;
}

void GlwSwapchain::Bind( const glm::ivec4& viewport ) {
    glBindFramebuffer( GL_FRAMEBUFFER, GL_NULL );
    glDisable( GL_DEPTH_TEST );
    glDisable( GL_STENCIL_TEST );
    glViewport( viewport.x, viewport.y, viewport.z, viewport.w );
    glScissor( viewport.x, viewport.y, viewport.z, viewport.w );
    glClearColor( m_refresh.r, m_refresh.g, m_refresh.b, m_refresh.a );
    glClear( GL_COLOR_BUFFER_BIT );
}
