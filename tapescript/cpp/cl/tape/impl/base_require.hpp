/*
Copyright (C) 2003-2015 CompatibL

This file is part of TapeScript, an open source library and tape encoding
standard for adjoint algorithmic differentiation (AAD), available from

http://github.com/compatibl/tapescript (source)
http://tapescript.org (documentation)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#ifndef CL_BASE_REQUIRE_INCLUDED
#define CL_BASE_REQUIRE_INCLUDED

// definitions that must come before base implementations
#include <cppad/error_handler.hpp>
#include <cppad/local/define.hpp>
#include <cppad/local/cppad_assert.hpp>
#include <cppad/local/declare_ad.hpp>

// grouping documentation by feature
#include <cppad/local/base_cond_exp.hpp>
#include <cppad/local/base_std_math.hpp>

// must define template class numeric_limits before the base cases
#include <cppad/local/limits.hpp>
#include <cppad/local/epsilon.hpp> // deprecated

// base cases
//#include <cl/tape/impl/base_inner_double.hpp>
#include <cl/tape/impl/base_inner_vector.hpp>
#include <cl/tape/impl/base_inner_array.hpp>

#endif
