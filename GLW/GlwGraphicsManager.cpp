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
	: m_state{ GlwStates::Enable },
	m_swapchain{ },
	m_render_passes{ },
	m_ressources{ }, 
	m_need_resize{ false }
{ }

bool GlwGraphicsManager::Create(
	const GlwWindow* window,
	const GlwGraphicSpecification& specification
) {
	auto result = false;
	
	if ( window != nullptr ) {
		result = PlatformInit( window, specification );

		if ( result && glewInit( ) == GLEW_OK ) {
			PlatformSetup( window, specification );

			SetDebugContext( specification.Debug );
			SetFaceCullingContext( specification.Culling );

			m_swapchain.Create( window );
		}
	}

	return result;
}

void GlwGraphicsManager::MarkResize( ) {
	m_need_resize = true;
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

bool GlwGraphicsManager::CreateRenderPasses(
	const std::vector<GlwRenderPassSpecification>& specification
) {
	auto result = false;

	for ( auto& render_pass_spec : specification ) {
		result = m_render_passes.Create( render_pass_spec );

		if ( !result )
			break;
	}

	return result;
}

bool GlwGraphicsManager::CreateRenderPasses(
	const std::initializer_list<GlwRenderPassSpecification> specification
) {
	auto result = false;

	for ( auto& render_pass_spec : specification ) {
		result = m_render_passes.Create( render_pass_spec );

		if ( !result )
			break;
	}

	return result;
}

bool GlwGraphicsManager::CreateMesh( const GlwMeshSpecification& specification ) {
	return m_ressources.CreateMesh( specification );
}

bool GlwGraphicsManager::CreateTexture2D( const GlwTexture2DSpecification& specification ) {
	return m_ressources.CreateTexture2D( specification );
}

bool GlwGraphicsManager::CreateTexture2D(
	const GlwTexture2DSpecification& specification,
	const std::vector<uint8_t>& pixels
) {
	return m_ressources.CreateTexture2D( specification, pixels );
}

bool GlwGraphicsManager::CreateCubemap( const GlwTextureCubemapSpecification& specification ) {
	return m_ressources.CreateCubemap( specification );
}

bool GlwGraphicsManager::CreateCubemap(
	const GlwTextureCubemapSpecification& specification,
	const std::vector<uint8_t> face_pixels[ GlwTextureCubemap::FaceCount ]
) {
	return m_ressources.CreateCubemap( specification, face_pixels );
}

bool GlwGraphicsManager::CreateMaterial( const GlwMaterialSpecification& specification ) {
	return m_ressources.CreateMaterial( specification );
}

void GlwGraphicsManager::FillTexture2D(
	const uint32_t texture,
	const GlwTextureFillSpecification& fill_specification
) {
	if ( auto* instance = m_ressources.GetTexture2D( texture ) )
		instance->Fill( fill_specification );
}

void GlwGraphicsManager::FillTexture2D(
	const uint32_t texture,
	const std::vector<GlwTextureFillSpecification>& fill_specifications
) {
	if ( auto* instance = m_ressources.GetTexture2D( texture ) ) {
		for ( const auto& specification : fill_specifications )
			instance->Fill( specification );
	}
}

void GlwGraphicsManager::FillCubemap(
	const uint32_t cubemap,
	const GlwTextureFillSpecification& fill_specification
) {
	if ( auto* instance = m_ressources.GetTexture2D( cubemap ) )
		instance->Fill( fill_specification );
}

void GlwGraphicsManager::FillCubemap(
	const uint32_t cubemap,
	const std::vector<GlwTextureFillSpecification>& fill_specifications
) {
	if ( auto* instance = m_ressources.GetTexture2D( cubemap ) ) {
		for ( const auto& specification : fill_specifications )
			instance->Fill( specification );
	}
}

void GlwGraphicsManager::SetDrawState( const GlwStates state ) {
	m_state = state;
}

void GlwGraphicsManager::SetRefresh( const glm::vec4& color ) {
	m_swapchain.SetRefresh( color );
}

bool GlwGraphicsManager::Acquire( 
	const GlwWindow* window, 
	GlwRenderContext& render_context 
) {
	render_context = { };

	if ( m_render_passes.GetLast( ) == nullptr ) {
		Resize( window );

		m_swapchain.Use( );
	}

	return m_state == GlwStates::Enable;
}

GlwRenderPass* GlwGraphicsManager::CmdUseRenderPass(
	GlwRenderContext& render_conext, 
	const uint32_t render_pass 
) {
	auto* instance = m_render_passes.GetRenderPass( render_pass );

	if ( instance != nullptr ) {
		render_conext.RenderPass = render_pass;
		
		instance->Use( );

		CmdToggleColorWrites( render_conext, GlwStates::Enable );
	} else
		render_conext.RenderPass = UINT_MAX;

	return instance;
}

void GlwGraphicsManager::CmdUseSwapchain( GlwRenderContext& render_conext ) {
	auto* render_pass = m_render_passes.GetLast( );

	if ( render_pass != nullptr ) {
		auto dimensions = render_pass->GetDimensions( );

		m_swapchain.Use( dimensions );
	}
}

void GlwGraphicsManager::CmdToggle(
	GlwRenderContext& render_conext,
	const uint32_t capability,
	const GlwStates state 
) {
	if ( !render_conext.GetInUse( ) )
		return;

	if ( state == GlwStates::Enable )
		glEnable( capability );
	else
		glDisable( capability );
}

void GlwGraphicsManager::CmdToggleFaceCulling(
	GlwRenderContext& render_conext, 
	const GlwStates state 
) {
	CmdToggle( render_conext, GL_CULL_FACE, state );
}

void GlwGraphicsManager::CmdSetViewport(
	GlwRenderContext& render_conext,
	const glm::uvec4& viewport 
) {
	if ( !render_conext.GetInUse( ) )
		return;

	glViewport( viewport.x, viewport.y, viewport.z, viewport.w );
}

void GlwGraphicsManager::CmdSetScissor(
	GlwRenderContext& render_conext, 
	const glm::uvec4& scissor 
) {
	if ( !render_conext.GetInUse( ) )
		return;

	glScissor( scissor.x, scissor.y, scissor.z, scissor.w );
}

void GlwGraphicsManager::CmdToggleColorWrites(
	GlwRenderContext& render_conext,
	const GlwStates state
) {
	if ( !render_conext.GetInUse( ) )
		return;

	auto value = ( state == GlwStates::Enable ) ? GL_TRUE : GL_FALSE;

	glColorMask( value, value, value, value );
}

void GlwGraphicsManager::CmdToggleDepthTest( 
	GlwRenderContext& render_conext, 
	const GlwStates state 
) {
	CmdToggle( render_conext, GL_DEPTH_TEST, state );
}

void GlwGraphicsManager::CmdToggleStencilTest( 
	GlwRenderContext& render_conext, 
	const GlwStates state 
) {
	CmdToggle( render_conext, GL_STENCIL_TEST, state );
}

void GlwGraphicsManager::CmdToggleStencilWrite( GlwRenderContext& render_conext, GlwStates state ) {
	if ( !render_conext.GetInUse( ) )
		return;

	glStencilMask( ( state == GlwStates::Enable ) ? 0xFF : 0x00 );
}

void GlwGraphicsManager::CmdBlitRenderTarget(
	GlwRenderContext& render_context,
	const GlwBlitSpecification& blit_specification
) {
	if ( !render_context.GetInUse( ) )
		return;

	m_render_passes.CmdBlitRenderTarget( blit_specification );
}

GlwMaterial* GlwGraphicsManager::CmdUseMaterial(
	GlwRenderContext& render_conext, 
	const uint32_t material 
) {
	auto* instance = (GlwMaterial*)nullptr;
	
	if ( render_conext.GetInUse( ) ) {
		instance = m_ressources.UseMaterial( material );

		render_conext.Material = ( instance != nullptr ) ? material : UINT_MAX;
	}

	return instance;
}

GlwMesh* GlwGraphicsManager::CmdUseMesh(
	GlwRenderContext& render_conext, 
	const uint32_t mesh 
) {
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

void GlwGraphicsManager::CmdDraw( 
	GlwRenderContext& render_conext, 
	const uint32_t vertice_count 
) {
	if ( !render_conext.GetCanDraw( ) )
		return;

	if ( render_conext.UseIndex )
		glDrawElements( GL_TRIANGLES, vertice_count, GL_UNSIGNED_INT, NULL );
	else
		glDrawArrays( GL_TRIANGLES, 0, vertice_count );
}

void GlwGraphicsManager::Present( 
	const GlwWindow* window, 
	GlwRenderContext& render_context 
) {
	PlatformSwapBuffers( window );
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
void GlwGraphicsManager::Resize( const GlwWindow* window ) {
	if ( window == nullptr || !m_need_resize )
		return;

	m_swapchain.Resize( window );

	m_need_resize = false;
}

void GlwGraphicsManager::Display( 
	GlwRenderContext& render_context,
	const GlwDisplaySpecification& display_spec 
) {
	render_context.RenderPass = 0;

	auto* material = CmdUseMaterial( render_context, display_spec.Material );
	
	if ( material ) {
		for ( auto& target : display_spec.Attachements ) {
			auto texture = m_render_passes.GetColorAttachement( target.RenderPass, target.Attachement );

			//material->SetTexture( target.Slot, GlwTextureTypes::Texture2D, GlwTextureLayouts::Default, texture );
		}
	}

	CmdUseMesh( render_context, display_spec.Mesh );
	CmdDraw( render_context, 6 );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
GlwStates GlwGraphicsManager::GetDrawState( ) const {
	return m_state;
}

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

GlwRenderPass* GlwGraphicsManager::GetRenderPass( const uint32_t render_pass ) const {
	return m_render_passes.GetRenderPass( render_pass );
}

GlwMesh* GlwGraphicsManager::GetMesh( const uint32_t mesh ) {
	return m_ressources.GetMesh( mesh );
}

GlwTexture2D* GlwGraphicsManager::GetTexture2D( const uint32_t texture ) {
	return m_ressources.GetTexture2D( texture );
}

GlwTextureCubemap* GlwGraphicsManager::GetCubemap( const uint32_t cubemap ) {
	return m_ressources.GetCubemap( cubemap );
}
