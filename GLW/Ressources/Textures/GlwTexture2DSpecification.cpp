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
GlwTexture2DSpecification::GlwTexture2DSpecification( )
	: GlwTexture2DSpecification{ GlwTextureFormats::RGBA, GlwTextureLayouts::Default, 0, 0, { }, { } }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const uint32_t width,
	const uint32_t height
)
	: GlwTexture2DSpecification{ GlwTextureFormats::RGBA, GlwTextureLayouts::Default, width, height, { }, { } }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification( 
	const GlwTextureLayouts layout,
	const uint32_t width,
	const uint32_t height
) 
	: GlwTexture2DSpecification{ GlwTextureFormats::RGBA, layout, width, height, { }, { } }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const GlwTextureFormats format,
	const GlwTextureLayouts layout,
	const uint32_t width,
	const uint32_t height
)
	: GlwTexture2DSpecification{ format, layout, width, height, { }, { } }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const uint32_t width,
	const uint32_t height,
	const GlwTextureFilterSpecification& filter,
	const GlwTextureWrapSpecification& wrap
)
	: GlwTexture2DSpecification{ GlwTextureFormats::RGBA, GlwTextureLayouts::Default, width, height, filter, wrap }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const GlwTextureFormats format,
	const uint32_t width,
	const uint32_t height,
	const GlwTextureFilterSpecification& filter,
	const GlwTextureWrapSpecification& wrap
)
	: GlwTexture2DSpecification{ format, GlwTextureLayouts::Default, width, height, filter, wrap }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const GlwTextureFormats format,
	const GlwTextureLayouts layout,
	const uint32_t width,
	const uint32_t height,
	const GlwTextureFilterSpecification& filter,
	const GlwTextureWrapSpecification& wrap
)
	: GlwTextureSpecification{ format, width, height },
	Layout{ layout },
	Filter{ filter },
	Wrap{ wrap }
{ }

GlwTexture2DSpecification::GlwTexture2DSpecification(
	const GlwTexture2DSpecification& other 
)
{ 
	glw_copy( &other, this, sizeof( GlwTexture2DSpecification ) );
}

GlwTexture2DSpecification::GlwTexture2DSpecification( 
	GlwTexture2DSpecification&& other 
) 
{
	glw_copy( &other, this, sizeof( GlwTexture2DSpecification ) );
}

GlwTexture2DSpecification& GlwTexture2DSpecification::operator=(
	const GlwTexture2DSpecification& other
) {
	glw_copy( &other, this, sizeof( GlwTexture2DSpecification ) );

	return ( *this );
}
