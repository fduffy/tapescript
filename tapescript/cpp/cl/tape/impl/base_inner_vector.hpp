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

#ifndef CL_BASE_INNER_VECTOR_INCLUDED
#define CL_BASE_INNER_VECTOR_INCLUDED

#include <limits>

#include <cppad/configure.hpp>
//#include <cppad/local/ad.hpp>
#include <cl/tape/impl/inner_vector.hpp>

namespace CppAD
{
    inline cl::InnerVector CondExpOpEq(
        const cl::InnerVector&       left,
        const cl::InnerVector&       right,
        const cl::InnerVector&       exp_if_true,
        const cl::InnerVector&       exp_if_false)
    {
        if (left.is_scalar() && right.is_scalar())
        {
            return (left.scalar_value_ == right.scalar_value_)
                ? exp_if_true : exp_if_false;
        }

        std::valarray<bool> mask;
        size_t size;
        if (left.is_scalar() && right.is_vector())
        {
            mask = left.scalar_value_ == right.vector_value_;
            size = right.vector_value_.size();
        }
        else if (left.is_vector() && right.is_scalar())
        {
            mask = left.vector_value_ == right.scalar_value_;
            size = left.vector_value_.size();
        }
        else /* (left.is_vector() && right.is_vector()) */
        {
            mask = left.vector_value_ == right.vector_value_;
            size = left.vector_value_.size();
        }

        cl::InnerVector::vector_type result(size);
        if (exp_if_true.is_scalar())
        {
            result[mask] = exp_if_true.scalar_value_;
        }
        else
        {
            result[mask] = exp_if_true.vector_value_[mask];
        }
        if (exp_if_false.is_scalar())
        {
            result[!mask] = exp_if_false.scalar_value_;
        }
        else
        {
            result[!mask] = exp_if_false.vector_value_[!mask];
        }
        
        return result;
    }

    inline cl::InnerVector CondExpOpLt(
        const cl::InnerVector&       left,
        const cl::InnerVector&       right,
        const cl::InnerVector&       exp_if_true,
        const cl::InnerVector&       exp_if_false)
    {
        if (left.is_scalar() && right.is_scalar())
        {
            return (left.scalar_value_ < right.scalar_value_)
                ? exp_if_true : exp_if_false;
        }

        std::valarray<bool> mask;
        size_t size;
        if (left.is_scalar() && right.is_vector())
        {
            mask = left.scalar_value_ < right.vector_value_;
            size = right.vector_value_.size();
        }
        else if (left.is_vector() && right.is_scalar())
        {
            mask = left.vector_value_ < right.scalar_value_;
            size = left.vector_value_.size();
        }
        else /* (left.is_vector() && right.is_vector()) */
        {
            mask = left.vector_value_ < right.vector_value_;
            size = left.vector_value_.size();
        }

        cl::InnerVector::vector_type result(size);
        if (exp_if_true.is_scalar())
        {
            result[mask] = exp_if_true.scalar_value_;
        }
        else
        {
            result[mask] = exp_if_true.vector_value_[mask];
        }
        if (exp_if_false.is_scalar())
        {
            result[!mask] = exp_if_false.scalar_value_;
        }
        else
        {
            result[!mask] = exp_if_false.vector_value_[!mask];
        }

        return result;
    }
    
	inline cl::InnerVector CondExpOp( 
		enum CompareOp               cop          ,
		const cl::InnerVector&       left         ,
		const cl::InnerVector&       right        , 
		const cl::InnerVector&       exp_if_true  , 
		const cl::InnerVector&       exp_if_false )
	{
        switch (cop)
        {
        case CompareLt:
            return CondExpOpLt(left, right, exp_if_true, exp_if_false);
    
        case CompareLe:
            return CondExpOpLt(right, left, exp_if_false, exp_if_true);
    
        case CompareGe:
            return CondExpOpLt(left, right, exp_if_false, exp_if_true);
    
        case CompareGt:
            return CondExpOpLt(right, left, exp_if_true, exp_if_false);
    
        case CompareEq:
            return CondExpOpEq(left, right, exp_if_true, exp_if_false);
    
        default:
            throw std::exception("Unknown compare operation.");
        }
	}

    //template <>
    //inline AD<cl::InnerVector> CondExpOp<cl::InnerVector>(
    //    enum CompareOp                   cop,
    //    const AD<cl::InnerVector>&       left,
    //    const AD<cl::InnerVector>&       right,
    //    const AD<cl::InnerVector>&       exp_if_true,
    //    const AD<cl::InnerVector>&       exp_if_false)
    //{
    //    return CondExpOp(cop, left.value_, right.value_, exp_if_true.value_, exp_if_false.value_);
    //}
}

namespace CppAD {
	CPPAD_COND_EXP_REL(cl::InnerVector)
}

//namespace CppAD {
//	inline bool EqualOpSeq(const cl::InnerVector& x, const cl::InnerVector& y)
//	{	return x == y; }
//}
//
namespace CppAD {
	inline bool IdenticalPar(const cl::InnerVector& x)
	{	return true; }
	inline bool IdenticalZero(const cl::InnerVector& x)
	{	return (x == 0.); }
	inline bool IdenticalOne(const cl::InnerVector& x)
	{	return (x == 1.); }
	inline bool IdenticalEqualPar(const cl::InnerVector& x, const cl::InnerVector& y)
	{	return (x == y); }
}

namespace CppAD {
	inline int Integer(const cl::InnerVector& x)
	{	return static_cast<int>(x.to_scalar()); }
}

namespace CppAD {
	inline bool GreaterThanZero(const cl::InnerVector& x)
	{	return x > 0.; }
	inline bool GreaterThanOrZero(const cl::InnerVector& x)
	{	return x >= 0.; }
	inline bool LessThanZero(const cl::InnerVector& x)
	{	return x < 0.; }
	inline bool LessThanOrZero(const cl::InnerVector& x)
	{	return x <= 0.; }
	inline bool abs_geq(const cl::InnerVector& x, const cl::InnerVector& y)
	{	return std::abs(x) >= std::abs(y); }
}

namespace CppAD {
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, acos)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, asin)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, atan)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, cos)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, cosh)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, exp)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, fabs)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, log)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, log10)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, sin)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, sinh)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, sqrt)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, tan)
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, tanh)
# if CPPAD_COMPILER_HAS_ERF
	CPPAD_STANDARD_MATH_UNARY(cl::InnerVector, erf)
# endif
}

namespace CppAD {
	inline cl::InnerVector abs(const cl::InnerVector& x)
	{	return std::fabs(x); }
}

namespace CppAD {
	inline cl::InnerVector sign(const cl::InnerVector& x)
	{
        auto sign_func = [](double v)
        {
            if (v > 0.)
                return 1.;
            if (v == 0.)
                return 0.;
            return -1.;
        };

        return x.apply(sign_func);
	}
}

namespace CppAD {
	inline cl::InnerVector pow(const cl::InnerVector& x, const cl::InnerVector& y)
	{ return std::pow(x, y); }
}

namespace CppAD {
	template <>
	class numeric_limits<cl::InnerVector> {
	public:
		// machine epsilon
		static cl::InnerVector epsilon(void)
		{	return std::numeric_limits<cl::InnerVector>::epsilon(); }
		// minimum positive normalized value
		static cl::InnerVector min(void)
		{	return std::numeric_limits<cl::InnerVector>::min(); }
		// maximum finite value
		static cl::InnerVector max(void)
		{	return std::numeric_limits<cl::InnerVector>::max(); }
	};
	// deprecated machine epsilon
	template <> 
	inline cl::InnerVector epsilon<cl::InnerVector>(void)
	{	return numeric_limits<cl::InnerVector>::epsilon(); }
}


# endif