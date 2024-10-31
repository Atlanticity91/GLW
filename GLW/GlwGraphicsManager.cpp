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
	m_debug_tracker{ },
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

			ToggleMultiSampling( specification.Extras.MultiSampling );
			ToggleSRGB( specification.Extras.SRGB );

			m_swapchain.Create( window );
		}
	}

	return result;
}

void GlwGraphicsManager::MarkResize( ) {
	m_need_resize = true;
}

void GlwGraphicsManager::SetDebugContext(
	const GlwDebugContext& context 
) {
	if ( context.Callback == nullptr )
		return;

#	ifdef GLW_DEBUG
	glEnable( GL_DEBUG_OUTPUT );
	glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );

	glDebugMessageCallback( context.Callback, context.UseParameters );
#	endif
}

void GlwGraphicsManager::SetFaceCullingContext(
	const GlwFaceCulling& context
) {
	if ( context.State == GlwStates::Enable ) {
		glEnable( GL_CULL_FACE );
		glCullFace( context.Face );
		glFrontFace( context.Mode );
	} else
		glDisable( GL_CULL_FACE );
}

void GlwGraphicsManager::ToggleMultiSampling( const GlwStates state ) {
	if ( state == GlwStates::Enable )
		glEnable( GL_MULTISAMPLE );
	else
		glDisable( GL_MULTISAMPLE );

}

void GlwGraphicsManager::ToggleSRGB( const GlwStates state ) {
	if ( state == GlwStates::Enable )
		glEnable( GL_FRAMEBUFFER_SRGB );
	else
		glDisable( GL_FRAMEBUFFER_SRGB );
}

bool GlwGraphicsManager::CreateRenderPass(
	const GlwRenderPassSpecification& specification
) {
	auto result = m_render_passes.Create( specification );

	if ( result )
		m_debug_tracker.RenderPass.emplace_back( );

	return result;
}

bool GlwGraphicsManager::CreateRenderPasses(
	const std::vector<GlwRenderPassSpecification>& specification
) {
	auto result = false;

	for ( auto& render_pass_spec : specification ) {
		result = CreateRenderPass( render_pass_spec );

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
		result = CreateRenderPass( render_pass_spec );

		if ( !result )
			break;
	}

	return result;
}

bool GlwGraphicsManager::CreateMesh(
	const GlwMeshSpecification& specification
) {
	auto result = m_ressources.CreateMesh( specification );

	if ( result )
		GlwTrackMesh( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::CreateTexture2D( 
	const GlwTexture2DSpecification& specification
) {
	auto result = m_ressources.CreateTexture2D( specification );

	if ( result )
		GlwTrackTexture( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::CreateTexture2D(
	const GlwTexture2DSpecification& specification,
	const std::vector<uint8_t>& pixels
) {
	auto result = m_ressources.CreateTexture2D( specification, pixels );

	if ( result )
		GlwTrackTexture( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::CreateCubemap(
	const GlwTextureCubemapSpecification& specification
) {
	auto result = m_ressources.CreateCubemap( specification );

	if ( result )
		GlwTrackTexture( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::CreateCubemap(
	const GlwTextureCubemapSpecification& specification,
	const std::vector<uint8_t> face_pixels[ GlwTextureCubemap::FaceCount ]
) {
	auto result = m_ressources.CreateCubemap( specification, face_pixels );

	if ( result )
		GlwTrackTexture( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::CreateMaterial( 
	const GlwMaterialSpecification& specification
) {
	auto result = m_ressources.CreateMaterial( specification );

	if ( result )
		GlwTrackMaterial( m_debug_tracker );

	return result;
}

bool GlwGraphicsManager::ReplaceMesh(
	const glw_ressource mesh,
	const GlwMeshSpecification& specification
) {
	return m_ressources.ReplaceMesh( mesh, specification );
}

bool GlwGraphicsManager::ReplaceTexture2D(
	const glw_ressource texture,
	const GlwTexture2DSpecification& specification
) {
	return m_ressources.ReplaceTexture2D( texture, specification );
}

bool GlwGraphicsManager::ReplaceTexture2D(
	const glw_ressource texture,
	const GlwTexture2DSpecification& specification,
	const std::vector<uint8_t>& pixels
) {
	return m_ressources.ReplaceTexture2D( texture, specification );
}

bool GlwGraphicsManager::ReplaceCubemap(
	const glw_ressource cubemap,
	const GlwTextureCubemapSpecification& specification
) {
	return m_ressources.ReplaceCubemap( cubemap, specification );
}

bool GlwGraphicsManager::ReplaceCubemap(
	const glw_ressource cubemap,
	const GlwTextureCubemapSpecification& specification,
	const std::vector<uint8_t> face_pixels[ GlwTextureCubemap::FaceCount ]
) {
	return m_ressources.ReplaceCubemap( cubemap, specification );
}

bool GlwGraphicsManager::ReplaceMaterial(
	const glw_ressource material,
	const GlwMaterialSpecification& specification
) {
	return m_ressources.ReplaceMaterial( material, specification );
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

	m_debug_tracker.Reset( );

	Resize( window );

	if ( m_render_passes.GetLast( ) == nullptr )
		m_swapchain.Use( );

	return m_state == GlwStates::Enable;
}

GlwRenderPass* GlwGraphicsManager::CmdUseRenderPass(
	GlwRenderContext& render_context, 
	const uint32_t render_pass 
) {
	auto* instance = m_render_passes.GetRenderPass( render_pass );

	if ( instance != nullptr ) {
		render_context.RenderPass = render_pass;
		
		instance->Use( );

		CmdToggleColorWrites( render_context, GlwStates::Enable );
	} else
		render_context.RenderPass = UINT_MAX;

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdUseRenderPass", instance );

	return instance;
}

void GlwGraphicsManager::CmdUseSwapchain( GlwRenderContext& render_context ) {
	auto* render_pass = m_render_passes.GetLast( );

	render_context.RenderPass = 0;

	if ( render_pass != nullptr ) {
		auto dimensions = render_pass->GetDimensions( );

		m_swapchain.Use( dimensions );
	} else
		m_swapchain.Use( );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdUseSwapchain", render_pass );
}

void GlwGraphicsManager::CmdToggle(
	GlwRenderContext& render_context,
	const uint32_t capability,
	const GlwStates state 
) {
	if ( !render_context.GetInUse( ) )
		return;

	if ( state == GlwStates::Enable )
		glEnable( capability );
	else
		glDisable( capability );
}

void GlwGraphicsManager::CmdToggleFaceCulling(
	GlwRenderContext& render_context, 
	const GlwStates state 
) {
	CmdToggle( render_context, GL_CULL_FACE, state );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdToggleFaceCulling", state );
}

void GlwGraphicsManager::CmdSetViewport(
	GlwRenderContext& render_context,
	const glm::uvec4& viewport 
) {
	if ( !render_context.GetInUse( ) )
		return;

	glViewport( viewport.x, viewport.y, viewport.z, viewport.w );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdSetViewport", 0 );
}

void GlwGraphicsManager::CmdSetScissor(
	GlwRenderContext& render_context, 
	const glm::uvec4& scissor 
) {
	if ( !render_context.GetInUse( ) )
		return;

	glScissor( scissor.x, scissor.y, scissor.z, scissor.w );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdSetScissor", 0 );
}

void GlwGraphicsManager::CmdToggleColorWrites(
	GlwRenderContext& render_context,
	const GlwStates state
) {
	CmdToggleColorWrites( render_context, 0, state );
}

void GlwGraphicsManager::CmdToggleColorWrites(
	GlwRenderContext& render_context,
	const uint32_t attachement,
	const GlwStates state
) {
	if ( !render_context.GetInUse( ) )
		return;

	auto value = ( state == GlwStates::Enable ) ? GL_TRUE : GL_FALSE;

	glColorMaski( attachement, value, value, value, value );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdToggleColorWrites", ( (uint64_t)attachement << 32 ) & (uint32_t)state );
}

void GlwGraphicsManager::CmdToggleDepthTest( 
	GlwRenderContext& render_context, 
	const GlwStates state 
) {
	CmdToggle( render_context, GL_DEPTH_TEST, state );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdToggleDepthTest", state );
}

void GlwGraphicsManager::CmdToggleStencilTest( 
	GlwRenderContext& render_context, 
	const GlwStates state 
) {
	CmdToggle( render_context, GL_STENCIL_TEST, state );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdToggleStencilTest", state );
}

void GlwGraphicsManager::CmdToggleStencilWrite( GlwRenderContext& render_context, GlwStates state ) {
	if ( !render_context.GetInUse( ) )
		return;

	glStencilMask( ( state == GlwStates::Enable ) ? 0xFF : 0x00 );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdToggleStencilWrite", state );
}

void GlwGraphicsManager::CmdClearColor(
	GlwRenderContext& render_context,
	const uint32_t attachement,
	const glm::vec4& clear_value
) {
	if ( !render_context.GetInUse( ) )
		return;

	auto* color = glm::value_ptr( clear_value );

	glClearBufferfv( GL_COLOR, attachement, color );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdClearColor", attachement );
}

void GlwGraphicsManager::CmdClearDepth(
	GlwRenderContext& render_context,
	const float clear_value
) {
	if ( !render_context.GetInUse( ) )
		return;

	glClearDepth( clear_value );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdClearDepth", clear_value );
}

void GlwGraphicsManager::CmdClearStencil(
	GlwRenderContext& render_context, 
	const uint8_t clear_value 
) {
	if ( !render_context.GetInUse( ) )
		return;

	glClearStencil( clear_value );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdClearStencil", clear_value );
}

void GlwGraphicsManager::CmdBlitRenderTarget(
	GlwRenderContext& render_context,
	const GlwBlitSpecification& blit_specification
) {
	if ( !render_context.GetInUse( ) )
		return;

	m_render_passes.CmdBlitRenderTarget( blit_specification );

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdBlitRenderTarget", blit_specification.Type );
}

GlwMaterial* GlwGraphicsManager::CmdUseMaterial(
	GlwRenderContext& render_context, 
	const uint32_t material 
) {
	auto* instance = (GlwMaterial*)nullptr;
	
	if ( render_context.GetInUse( ) ) {
		instance = m_ressources.UseMaterial( material );

		render_context.Material = ( instance != nullptr ) ? material : UINT_MAX;
	}

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdUseMaterial", instance );

	return instance;
}

GlwMesh* GlwGraphicsManager::CmdUseMesh(
	GlwRenderContext& render_context, 
	const uint32_t mesh 
) {
	auto* instance = (GlwMesh*)nullptr;

	if ( render_context.GetInUse( ) ) {
		instance = m_ressources.UseMesh( mesh );

		if ( instance != nullptr ) {
			render_context.Mesh	   = mesh;
			render_context.UseIndex = instance->GetHasIndex( );
		} else 
			render_context.Mesh = UINT_MAX;
	}

	GlwTrackCommand( m_debug_tracker, render_context.RenderPass, "CmdUseMesh", instance );

	return instance;
}

void GlwGraphicsManager::CmdDraw( 
	GlwRenderContext& render_context, 
	const uint32_t vertice_count 
) {
	if ( !render_context.GetCanDraw( ) && vertice_count > 0 )
		return;

	if ( render_context.UseIndex )
		glDrawElements( GL_TRIANGLES, vertice_count, GL_UNSIGNED_INT, NULL );
	else
		glDrawArrays( GL_TRIANGLES, 0, vertice_count );

	GlwTrackDraw( m_debug_tracker, render_context.RenderPass, vertice_count );
}

void GlwGraphicsManager::Present( 
	const GlwWindow* window, 
	GlwRenderContext& render_context 
) {
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

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const GlwDebugTracker& GlwGraphicsManager::GetDebugTracker( ) const {
	return m_debug_tracker;
}

GlwStates GlwGraphicsManager::GetDrawState( ) const {
	return m_state;
}

GlwRessourceManager& GlwGraphicsManager::GetRessources( ) {
	return m_ressources;
}

uint32_t GlwGraphicsManager::GetMeshCount( ) const {
	return m_ressources.GetMeshCount( );
}

uint32_t GlwGraphicsManager::GetTexture2DCount( ) const {
	return m_ressources.GetTexture2DCount( );
}

uint32_t GlwGraphicsManager::GetCubemapCount( ) const {
	return m_ressources.GetCubemapCount( );
}

uint32_t GlwGraphicsManager::GetMaterialCount( ) const {
	return m_ressources.GetMaterialCount( );
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

GlwMaterial* GlwGraphicsManager::GetMaterial( const glw_ressource material ) {
	return m_ressources.GetMaterial( material );
}
