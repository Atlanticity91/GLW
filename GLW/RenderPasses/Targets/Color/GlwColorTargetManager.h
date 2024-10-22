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

#include "GlwColorTarget.h"

class GlwColorTargetManager final {

private:
	std::vector<GlwColorTarget> m_targets;

public:
	/**
	 * Constructor
	 **/
	GlwColorTargetManager( );

	/**
	 * Destructor
	 **/
	~GlwColorTargetManager( ) = default;

	/**
	 * Create function
	 * @note : Create color attachements according to attachement specification list.
	 * @param framebuffer : Query framebuffer.
	 * @param specification : Query attachement specification list.
	 * @return : True when creation succeeded.
	 **/
	bool Create(
		GlwFramebuffer& framebuffer,
		const std::vector<GlwColorTargetSpecification>& specifications
	);

	/**
	 * Destroy method
	 * @note : Destroy color attachements.
	 **/
	void Destroy( );

public:
	/**
	 * GetAttachement const function
	 * @note : Get color attachement OpenGL texture handle.
	 * @param attachement : Query attachement.
	 * @return : Return color attachement as OpenGL texture handle.
	 **/
	const glTexture GetAttachement( const uint32_t attachement ) const;

};
