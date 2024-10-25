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

#include "GlwSwapchain.h"

struct GlwDisplayAttachementBind {

	uint32_t Slot;
	uint32_t RenderPass;
	GlwRenderAttachementTypes Type;
	uint32_t Attachement;

	/**
	 * Constructor
	 **/
	GlwDisplayAttachementBind( );

	/**
	 * Constructor
	 * @param slot : Query texture bind slot.
	 * @param render_pass : Query render pass.
	 * @param attachement : Query render pass attachement value.
	 **/
	GlwDisplayAttachementBind(
		const uint32_t slot,
		const uint32_t render_pass,
		const uint32_t attachement
	);

	/**
	 * Constructor
	 * @param slot : Query texture bind slot.
	 * @param render_pass : Query render pass.
	 * @param type : Query render pass attachement type.
	 * @param attachement : Query render pass attachement value.
	 **/
	GlwDisplayAttachementBind(
		const uint32_t slot,
		const uint32_t render_pass,
		const GlwRenderAttachementTypes type,
		const uint32_t attachement
	);

};
