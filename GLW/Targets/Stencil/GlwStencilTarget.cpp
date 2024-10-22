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
GlwStencilTarget::GlwStencilTarget( )
    : m_parameters{ }
{ }

bool GlwStencilTarget::Create( const GlwStencilTargetSpecification& specification ) {
    auto result = GlwTexture::Create( specification );

    if ( result )
        Setup( specification );

    return result;
}

void GlwStencilTarget::Setup( const GlwStencilTargetSpecification& specification ) {
    m_parameters = specification.Parameters;
}

void GlwStencilTarget::Use( ) {
    if ( m_parameters.Enable ) {
        glEnable( GL_STENCIL_TEST );
        glStencilFuncSeparate( GL_FRONT, m_parameters.FrontFunction.Function, m_parameters.FrontFunction.Reference, m_parameters.FrontFunction.Mask );
        glStencilOpSeparate( GL_FRONT, m_parameters.FrontOperation.Fail, m_parameters.FrontOperation.Pass, m_parameters.FrontOperation.DepthStencilPass );
        glStencilFuncSeparate( GL_BACK, m_parameters.BackFunction.Function, m_parameters.BackFunction.Reference, m_parameters.BackFunction.Mask );
        glStencilOpSeparate( GL_BACK, m_parameters.BackOperation.Fail, m_parameters.BackOperation.Pass, m_parameters.BackOperation.DepthStencilPass );
    } else {
        glDisable( GL_STENCIL_TEST );
        glStencilMask( 0x00 );
    }
}
