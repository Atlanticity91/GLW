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
GlwGraphicsManager::GlwGraphicsManager( )
	: m_swapchain{ },
	m_render_passes{ },
	m_ressources{ }
{ }

bool GlwGraphicsManager::Create(
	const GlwWindow* window,
	const GlwGraphicSpecification& specification
) {
	auto result = PlatformInit( window, specification );

	if ( result && glewInit( ) == GLEW_OK ) {
		PlatformSetup( window, specification );

		SetDebugContext( specification.Debug );
		SetFaceCullingContext( specification.Culling );

		m_swapchain.Create( *window );
	}

	return result;
}

void GlwGraphicsManager::SetDebugContext( const GlwDebugContext& context ) {
	if ( context.Callback == nullptr )
		return;

#	if defined( _DEBUG )|| defined( DEBUG )
	glEnable( GL_DEBUG_OUTPUT );
	glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );

	glDebugMessageCallback( context.Callback, context.UseParameters );
#	endif
}

void GlwGraphicsManager::SetFaceCullingContext( const GlwFaceCulling& context ) {
	if ( context.Enaled ) {
		glEnable( GL_CULL_FACE );
		glCullFace( context.Face );
		glFrontFace( context.Mode );
	} else
		glDisable( GL_CULL_FACE );
}

bool GlwGraphicsManager::CreateRenderPass( const GlwRenderPassSpecification& specification ) {
	return m_render_passes.Create( specification );
}

bool GlwGraphicsManager::CreateMesh( const GlwMeshSpecification& specification ) {
	return m_ressources.CreateMesh( specification );
}

bool GlwGraphicsManager::CreateTexture( const GlwTexture2DSpecification& specification ) {
	return m_ressources.CreateTexture( specification );
}

bool GlwGraphicsManager::CreateMaterial( const GlwMaterialSpecification& specification ) {
	return m_ressources.CreateMaterial( specification );
}

void GlwGraphicsManager::Acquire( GlwRenderContext& render_context ) {
	render_context = { };

	if ( m_render_passes.GetLast( ) == nullptr )
		m_swapchain.Use( );
}

bool GlwGraphicsManager::CmdUseRenderPass( GlwRenderContext& render_conext, const uint32_t render_pass ) {
	auto result = m_render_passes.GetExist( render_pass ) && m_render_passes.Use( render_pass );

	if ( result )
		render_conext.RenderPass = render_pass;
	else
		render_conext.RenderPass = UINT_MAX;

	return result;
}

void GlwGraphicsManager::CmdToggle(
	GlwRenderContext& render_conext,
	const uint32_t capability,
	GlwStates state 
) {
	if ( !render_conext.GetInUse( ) )
		return;

	if ( state == GlwStates::Enable )
		glEnable( capability );
	else
		glDisable( capability );
}

void GlwGraphicsManager::CmdToggleFaceCulling( GlwRenderContext& render_conext, GlwStates state ) {
	CmdToggle( render_conext, GL_CULL_FACE, state );
}

void GlwGraphicsManager::CmdToggleDepthTest( GlwRenderContext& render_conext, GlwStates state ) {
	CmdToggle( render_conext, GL_DEPTH_TEST, state );
}

void GlwGraphicsManager::CmdToggleStencilTest( GlwRenderContext& render_conext, GlwStates state ) {
	CmdToggle( render_conext, GL_STENCIL_TEST, state );
}

void GlwGraphicsManager::CmdToggleStencilWrite( GlwRenderContext& render_conext, GlwStates state ) {
	if ( !render_conext.GetInUse( ) )
		return;

	glStencilMask( ( state == GlwStates::Enable ) ? 0xFF : 0x00 );
}

GlwMaterial* GlwGraphicsManager::CmdUseMaterial( GlwRenderContext& render_conext, const uint32_t material ) {
	auto* instance = (GlwMaterial*)nullptr;
	
	if ( render_conext.GetInUse( ) ) {
		instance = m_ressources.UseMaterial( material );

		render_conext.Material = ( instance != nullptr ) ? material : UINT_MAX;
	}

	return instance;
}

GlwMesh* GlwGraphicsManager::CmdUseMesh( GlwRenderContext& render_conext, const uint32_t mesh ) {
	auto* instance = (GlwMesh*)nullptr;

	if ( render_conext.GetInUse( ) ) {
		instance = m_ressources.UseMesh( mesh );

		if ( instance != nullptr ) {
			render_conext.Mesh	   = mesh;
			render_conext.UseIndex = instance->GetHasIndex( );
		} else 
			render_conext.Mesh = UINT_MAX;
	}

	return instance;
}

void GlwGraphicsManager::CmdDraw( GlwRenderContext& render_conext, const uint32_t vertice_count ) {
	if ( !render_conext.GetCanDraw( ) )
		return;

	if ( render_conext.UseIndex )
		glDrawElements( GL_TRIANGLES, vertice_count, GL_UNSIGNED_INT, NULL );
	else
		glDrawArrays( GL_TRIANGLES, 0, vertice_count );
}

void GlwGraphicsManager::Present(
	const GlwWindow* window,
	GlwRenderContext& render_context,
	const GlwDisplaySpecification& display_spec
) {
	auto* render_pass = m_render_passes.GetLast( );

	if ( render_pass != nullptr ) {
		auto dimensions = render_pass->GetDimensions( );

		m_swapchain.Use( dimensions );

		Display( render_context, display_spec );
	}

	PlatformSwapBuffers( window );
}

void GlwGraphicsManager::Destroy( const GlwWindow* window ) {
	m_ressources.Destroy( );
	m_render_passes.Destroy( );

	PlatformDestroy( window );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PROTECTED ===
////////////////////////////////////////////////////////////////////////////////////////////
void GlwGraphicsManager::Display( 
	GlwRenderContext& render_context,
	const GlwDisplaySpecification& display_spec 
) {
	render_context.RenderPass = 0;

	auto* material = CmdUseMaterial( render_context, display_spec.Material );
	
	if ( material ) {
		for ( auto& target : display_spec.Attachements ) {
			auto texture = m_render_passes.GetColorAttachement( target.RenderPass, target.Attachement );

			material->SetTexture( target.Slot, GL_TEXTURE_2D, texture );
		}
	}

	CmdUseMesh( render_context, display_spec.Mesh );
	CmdDraw( render_context, 6 );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwRessourceManager& GlwGraphicsManager::GetRessources( ) {
	return m_ressources;
}

bool GlwGraphicsManager::GetMeshExist( const uint32_t mesh ) const {
	return m_ressources.GetMeshExist( mesh );
}

bool GlwGraphicsManager::GetTexture2DExist( const uint32_t texture ) const {
	return m_ressources.GetTexture2DExist( texture );
}

bool GlwGraphicsManager::GetCubemapExist( const uint32_t cubemap ) const {
	return m_ressources.GetCubemapExist( cubemap );
}

bool GlwGraphicsManager::GetMaterialExist( const uint32_t material ) const {
	return m_ressources.GetMaterialExist( material );
}

GlwMesh* GlwGraphicsManager::GetMesh( const uint32_t mesh ) {
	return m_ressources.GetMesh( mesh );
}

const GlwTexture2D* GlwGraphicsManager::GetTexture2D( const uint32_t texture ) const {
	return m_ressources.GetTexture2D( texture );
}
