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

#include "../Context/GlwGraphicSpecification.h"

template<typename SpecificationType>
class GlwRessource { 

public:
	/**
	 * Constructor
	 **/
	GlwRessource( ) = default;

	/**
	 * Destructor
	 **/
	virtual ~GlwRessource( ) = default;

	/**
	 * Create function
	 * @note : Create ressource according to query specification.
	 * @param specification : Query ressource specification.
	 * @return : True when creation succeeded.
	 **/
	virtual bool Create( const SpecificationType& specification ) = 0;

	/**
	 * Destroy method
	 * @note : Destroy ressource.
	 **/
	virtual void Destroy( ) = 0;

public:
	/**
	 * GetIsValid const function
	 * @note : Get ressource validity.
	 * @return : Return true when ressource is valid.
	 **/
	virtual bool GetIsValid( ) const = 0;

public:
	/**
	 * Cast operator
	 * @note : Cast ressource to boolean.
	 * @return : Return GetIsValid( ) call value.
	 **/
	operator bool( ) const {
		return GetIsValid( );
	};

};
