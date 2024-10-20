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

#include "GlwRenderContext.h"

enum class GlwStates : uint32_t {

    Enable = 0,
    Disable

};

class GlwGraphicsManager {

private:
    GlwSwapchain m_swapchain;
    GlwRenderPassManager m_render_passes;
    GlwRessourceManager m_ressources;

public:
    /**
     * Constructor
     **/
    GlwGraphicsManager( );

    /**
     * Destructor
     **/
    virtual ~GlwGraphicsManager( ) = default;

    /**
     * Create function
     * @note : Create graphic manager according to query specification.
     * @param window : Pointer to current window instance.
     * @param specification : Query graphic manager specification.
     * @return : True when creation succeeded.
     **/
    bool Create(
        const GlwWindow* window,
        const GlwGraphicSpecification& specification 
    );

    /**
     * Resize method
     * @note : Execute backend resize operation.
     * @param window : Pointer to current window instance.
     **/
    void Resize( const GlwWindow* window );

    /**
     * SetDebugContext method
     * @note : Set OpenGL debug context.
     * @param context : Query OpenGL context.
     **/
    void SetDebugContext( const GlwDebugContext& context );

    /**
     * SetFaceCullingContext method
     * @note : Set OpenGL face culling context.
     * @param context : Query face culling context.
     **/
    void SetFaceCullingContext( const GlwFaceCulling& context );

    /**
     * Create function
     * @note : Create render pass according to specification.
     * @param specification : Query render pass specification.
     * @return : True when creation succeeded.
     **/
    bool CreateRenderPass( const GlwRenderPassSpecification& specification );

    /**
     * CreateMesh function
     * @note : Create mesh according to query specification.
     * @param specification : Query mesh specification.
     * @return : True when creation succeeded.
     **/
    bool CreateMesh( const GlwMeshSpecification& specification );

    /**
     * CreateTexture function
     * @note : Create texture according to query specification.
     * @param specification : Query texture specification.
     * @return : True when creation succeeded.
     **/
    bool CreateTexture( const GlwTexture2DSpecification& specification );

    /**
     * CreateMaterial function
     * @note : Create material according to query specification.
     * @param specification : Query material specification.
     * @return : True when creation succeeded.
     **/
    bool CreateMaterial( const GlwMaterialSpecification& specification );

    /**
     * Acquire method
     * @note : Acquire render context.
     * @param render_context : Reference to current render context.
     **/
    void Acquire( GlwRenderContext& render_context );

    /**
     * CmdUseRenderPass function
     * @note : Bind and use render pass for rendering.
     * @param render_context : Reference to current render context.
     * @param render_pass : Query render pass.
     * @return : Return true when operation succeeded.
     **/
    bool CmdUseRenderPass( GlwRenderContext& render_conext, const uint32_t render_pass );

    /**
     * CmdToggle method
     * @note : Toggle OpenGL capability.
     * @param render_context : Reference to current render context.
     * @param capability : Query OpenGL capability.
     * @param state : Query capability state.
     **/
    void CmdToggle( GlwRenderContext& render_conext, const uint32_t capability, GlwStates state );

    /**
     * CmdToggleFaceCulling method
     * @note : Toggle OpenGL face culling.
     * @param render_context : Reference to current render context.
     * @param state : Query capability state.
     **/
    void CmdToggleFaceCulling( GlwRenderContext& render_conext, GlwStates state );

    /**
     * CmdToggleDepthTest method
     * @note : Toggle OpenGL depth test.
     * @param render_context : Reference to current render context.
     * @param state : Query capability state.
     **/
    void CmdToggleDepthTest( GlwRenderContext& render_conext, GlwStates state );

    /**
     * CmdToggleStencilTest method
     * @note : Toggle OpenGL stencil test.
     * @param render_context : Reference to current render context.
     * @param state : Query capability state.
     **/
    void CmdToggleStencilTest( GlwRenderContext& render_conext, GlwStates state );
    
    /**
     * CmdToggleStencilWrite method
     * @note : Toggle OpenGL stencil write operation.
     * @param render_context : Reference to current render context.
     * @param state : Query capability state.
     **/
    void CmdToggleStencilWrite( GlwRenderContext& render_conext, GlwStates state );

    /**
     * CmdUseMaterial function
     * @note : Use material for rendering.
     * @param render_context : Reference to current render context.
     * @param material : Query material.
     * @return : Return pointer to query material instance.
     **/
    GlwMaterial* CmdUseMaterial( GlwRenderContext& render_conext, const uint32_t material );

    /**
     * CmdUseMesh function
     * @note : Use mesh for rendering.
     * @param render_context : Reference to current render context.
     * @param mesh : Query mesh.
     * @return : Return pointer to query mesh instance.
     **/
    GlwMesh* CmdUseMesh( GlwRenderContext& render_conext, const uint32_t mesh );

    /**
     * CmdDraw method
     * @note : Draw call.
     * @param render_context : Reference to current render context.
     * @param vertice_count : Query vertex count.
     **/
    void CmdDraw( GlwRenderContext& render_conext, const uint32_t vertice_count );

    /**
     * Present method
     * @note : Present all previous operation to screen.
     * @param window : Pointer to current window instance.
     * @param render_context : Reference to current render context.
     * @param display_spec : Query display specification.
     **/
    void Present( 
        const GlwWindow* window, 
        GlwRenderContext& render_context,
        const GlwDisplaySpecification& display_spec
    );

    /**
     * Destroy method
     * @note : Destroy graphic manager.
     * @param window : Pointer to current window instance.
     **/
    void Destroy( const GlwWindow* window );

protected:
    /**
     * PlatformInit function
     * @note : Platform initialization.
     * @param window : Pointer to current window instance.
     * @param specification : Query graphic manager specification.
     * @return : Return true when operation succeeded.
     **/
    virtual bool PlatformInit(
        const GlwWindow* window,
        const GlwGraphicSpecification& specification
    ) = 0;

    /**
     * PlatformSetup function
     * @note : Platform setup.
     * @param window : Pointer to current window instance.
     * @param specification : Query graphic manager specification.
     * @return : Return true when operation succeeded.
     **/
    virtual void PlatformSetup(
        const GlwWindow* window,
        const GlwGraphicSpecification& specification
    ) = 0;

    /**
     * PlatformSwapBuffers method
     * @note : Platform swap OpenGL buffers.
     * @param window : Pointer to current window instance.
     **/
    virtual void PlatformSwapBuffers( const GlwWindow* window ) = 0;

    /**
     * PlatformDestroy method
     * @note : Platform cleanup.
     * @param window : Pointer to current window instance. 
     **/
    virtual void PlatformDestroy( const GlwWindow* window ) = 0;

    /**
     * Display method
     * @note : Used internaly for display last render pass to the screen.
     * @param render_context : Reference to current render context.
     * @param display_spec : Query display specification.
     **/
    virtual void Display( 
        GlwRenderContext& render_context,
        const GlwDisplaySpecification& display_spec 
    );

public:
    /**
     * CreateMesh template function
     * @note : Create mesh according to query specification.
     * @template VertexType : Type of data used for vertex representation.
     * @param specification : Query mesh specification.
     * @return : True when creation succeeded.
     **/
    template<typename VertexType>
    bool CreateMesh( const GlwMeshStaticSpecification<VertexType>& specification ) { 
        return m_ressources.CreateMesh<VertexType>( specification );
    };

public:
    /**
     * GetRessources function
     * @note : Get ressource manager instance.
     * @return : Return reference to ressource manager.
     **/
    GlwRessourceManager& GetRessources( );

    /**
     * GetMeshExist const function
     * @note : Get if a mesh exist.
     * @param mesh : Query mesh.
     * @return : Return true when mesh is valid.
     **/
    bool GetMeshExist( const uint32_t mesh ) const;

    /**
     * GetTexture2DExist const function
     * @note : Get if a texture 2D exist.
     * @param mesh : Query texture 2D.
     * @return : Return true when texture 2D is valid.
     **/
    bool GetTexture2DExist( const uint32_t texture ) const;

    /**
     * GetTexture2DExist const function
     * @note : Get if a cubemap exist.
     * @param mesh : Query cubemap.
     * @return : Return true when cubemap is valid.
     **/
    bool GetCubemapExist( const uint32_t cubemap ) const;

    /**
     * GetMaterialExist const function
     * @note : Get if a material exist.
     * @param mesh : Query material.
     * @return : Return true when material is valid.
     **/
    bool GetMaterialExist( const uint32_t material ) const;

    /**
     * GetMesh function
     * @note : Get mesh instance.
     * @param mesh : Query mesh.
     * @return : Return pointer to query mesh instance.
     **/
    GlwMesh* GetMesh( const uint32_t mesh );

    /**
     * GetTexture2D function
     * @note : Get texture 2D instance.
     * @param texture : Get texture instance.
     * @return : Return pointer to query texture 2D instance.
     **/
    const GlwTexture2D* GetTexture2D( const uint32_t texture ) const;

};
