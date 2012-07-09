/**
*  Copyright (C) 2011 by Anush Krishnan, Simon Layton, Lorena Barba
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*  THE SOFTWARE.
*/

#pragma once

#include <cstdio>
#include <typeinfo>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <boundaryCondition.h>

// property.h
// generic property storage
class property
{
public:
	property()
	{
		// initialise the memory to 0
		memset(value,0,64);
	}
	// get a value given a type
	template <typename T> T get();
	// set a value given a type
	template <typename T> void set(T v);

	// return string describing value of property as appropriate
	const char *print();
private:
	template <typename T> T getInternal();
	// hack to get around std::type_info not having a default constructor
	const std::type_info *type;
	// 64 bytes of storage
	char value[64];
};

typedef std::map<std::string, property> componentParameter;
typedef std::map<std::string, componentParameter> parameterDB;

// output a DB
/*
void printDB(parameterDB &DB)
{
  for (parameterDB::iterator it=DB.begin(); it!=DB.end(); ++it)
  {
    printf("%s:\n",it->first.c_str());
    for (componentParameter::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2)
      printf("\t%s: %s\n",it2->first.c_str(),it2->second.print());
  }
}
*/
