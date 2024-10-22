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

#include "../../Ressources/GlwRessourceManager.h"

class GlwFramebuffer final { 

private:
	uint32_t m_framebuffer;

public:
	/**
	 * Constructor
	 **/
	GlwFramebuffer( );

	/**
	 * Destructor
	 **/
	~GlwFramebuffer( ) = default;

	/**
	 * Create function
	 * @note : Create framebuffer.
	 * @return : Return true when operation succeeded.
	 **/
	bool Create( );

	/**
	 * Attach method
	 * @note : Attach attachement to framebuffer.
	 * @param attachement : Query framebuffer attachement value.
	 * @param texture : OpenGL texture handle value.
	 **/
	void Attach( const uint32_t attachment, const uint32_t texture );

	/**
	 * Link method
	 * @note : Link color attachements to framebuffer.
	 * @param color_count : Query color attachement count.
	 **/
	void Link( const uint32_t color_count );

	/**
	 * Use method
	 * @note : Bind framebuffer for usage.
	 **/
	void Use( );

	/**
	 * Destroy method
	 * @note : Destroy framebuffer.
	 **/
	void Destroy( );

public:
	/**
	 * GetIsValid const function
	 * @note : Get framebuffer validity.
	 * @return : Return true when framebuffer is valid.
	 **/
	bool GetIsValid( ) const;

};
