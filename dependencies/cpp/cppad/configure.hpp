﻿// $Id:$
# ifndef CPPAD_CONFIGURE_INCLUDED
# define CPPAD_CONFIGURE_INCLUDED

/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-14 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

/*
$begin configure$$
$spell
	CppAD
$$

$section Preprocessor Definitions Used by CppAD$$
$index configure, symbol$$
$index symbol, configure$$

$head Preprocessor Symbols$$
$index preprocessor, symbol$$
$index symbol, processor$$
All of the preprocessor symbols used by CppAD begin with
$code CPPAD_$$
(there are some deprecated symbols that begin with $code CppAD$$).

$end
*/

/*!
 \file configure.hpp
Replacement for config.h so that all preprocessor symbols begin with CPPAD_ 
*/

/*!
\def CPPAD_HAS_RVALUE
Does this compiler cupport c++11 rvalues; i.e., values with move semantics
*/
# define CPPAD_HAS_RVALUE 0 // @cppad_has_rvalue@

/*!
\def CPPAD_PACKAGE_STRING
cppad-yyyymmdd as a C string where yyyy is year, mm is month, and dd is day.
*/
# define CPPAD_PACKAGE_STRING "cppad-@20141230@" // "cppad-@cppad_version@"

/*!
def CPPAD_HAS_COLPACK
Was a colpack_prefix specified on the cmake command line.
*/
# define CPPAD_HAS_COLPACK 0 // @cppad_has_colpack@

/*!
def CPPAD_HAS_NULLPTR
Does this compiler support the a c++11 null-pointer constant nullptr
(true = 1, false = 0).
*/
# define CPPAD_HAS_NULLPTR 1 // @cppad_has_nullptr@
 
 /*!
def CPPAD_INTERNAL_SPARSE_SET
is the internal representation used for sparse vectors of std::set<size_t>
either sparse_set or sparse_list).
*/
# define CPPAD_INTERNAL_SPARSE_SET sparse_set //!! wild guess, confirm correct value @cppad_internal_sparse_set@

/*!
\def CPPAD_IMPLICIT_CTOR_FROM_ANY_TYPE
If this symbol is one, an implicit constor of AD<Base> is defined 
where the argument has any type.
Otherwise this constructor is explicit.
*/
# define CPPAD_IMPLICIT_CTOR_FROM_ANY_TYPE 0 // @cppad_implicit_ctor_from_any_type@

/*!
\def CPPAD_BOOSTVECTOR
If this symbol is one, and _MSC_VER is not defined,
we are using boost vector for CPPAD_TESTVECTOR.
It this symbol is zero, 
we are not using boost vector for CPPAD_TESTVECTOR.
*/
# define CPPAD_BOOSTVECTOR 0 // @cppad_boostvector@

/*!
\def CPPAD_CPPADVECTOR
If this symbol is one, 
we are using CppAD vector for CPPAD_TESTVECTOR.
It this symbol is zero, 
we are not using CppAD vector for CPPAD_TESTVECTOR.
*/
# define CPPAD_CPPADVECTOR 0 // @cppad_cppadvector@

/*!
\def CPPAD_STDVECTOR
If this symbol is one, 
we are using standard vector for CPPAD_TESTVECTOR.
It this symbol is zero, 
we are not using standard vector for CPPAD_TESTVECTOR.
*/
# define CPPAD_STDVECTOR 1 // @cppad_stdvector@

/*!
\def CPPAD_EIGENVECTOR
If this symbol is one, 
we are using Eigen vector for CPPAD_TESTVECTOR.
If this symbol is zero, 
we are not using Eigen vector for CPPAD_TESTVECTOR.
*/
# define CPPAD_EIGENVECTOR 0 // @cppad_eigenvector@

/*!
\def CPPAD_HAS_GETTIMEOFDAY
If this symbol is one, and _MSC_VER is not defined,
this system supports the gettimeofday funcgtion.
Otherwise, this smybol should be zero.
*/
# define CPPAD_HAS_GETTIMEOFDAY 0 // @cppad_has_gettimeofday@

/*!
\def CPPAD_SIZE_T_NOT_UNSIGNED_INT 
If this symbol is zero, the type size_t is the same as the type unsigned int,
otherwise this symbol is one.
*/
# define CPPAD_SIZE_T_NOT_UNSIGNED_INT 0 // @cppad_size_t_not_unsigned_int@

/*!
\def CPPAD_HAS_CSTDINT_8_TO_64 
If this symbol is one, the types uint_8, uint_16, uint_32, and uint_64
are defined.  otherwise this symbol is zero.
*/
# define CPPAD_HAS_CSTDINT_8_TO_64 1 // @cppad_has_cstdint_8_to_64@

/*!
\def CPPAD_COMPILER_HAS_ERF
If this symbol is one, the function std::erf(double) is defined by the
C++ compiler, otherwise the symbol is zero.
*/
# define CPPAD_COMPILER_HAS_ERF 0 // @cppad_compiler_has_erf@

/*!
\def CPPAD_TAPE_ADDR_TYPE
Is the type used to store address on the tape. If not size_t, then 
<code>sizeof(CPPAD_TAPE_ADDR_TYPE) <= sizeof( size_t )</code>
to conserve memory.
This type must support \c std::numeric_limits,
the \c <= operator,
and conversion to \c size_t.
Make sure that the type chosen returns true for is_pod<CPPAD_TAPE_ADDR_TYPE>
in pod_vector.hpp.
This type is later defined as \c addr_t in the CppAD namespace.
*/
# define CPPAD_TAPE_ADDR_TYPE size_t // @cppad_tape_addr_type@

/*!
\def CPPAD_TAPE_ID_TYPE
Is the type used to store tape identifiers. If not size_t, then 
<code>sizeof(CPPAD_TAPE_ID_TYPE) <= sizeof( size_t )</code>
to conserve memory.
This type must support \c std::numeric_limits,
the \c <= operator,
and conversion to \c size_t.
Make sure that the type chosen returns true for is_pod<CPPAD_TAPE_ID_TYPE>
in pod_vector.hpp.
This type is later defined as \c tape_id_t in the CppAD namespace.
*/
# define CPPAD_TAPE_ID_TYPE size_t // @cppad_tape_id_type@
 
/*!
\def CPPAD_MAX_NUM_THREADS
Specifies the maximum number of threads that CppAD can support
(must be greater than or equal four).

The user may define CPPAD_MAX_NUM_THREADS before including any of the CppAD
header files.  If it is not yet defined,
*/
# ifndef CPPAD_MAX_NUM_THREADS
# define CPPAD_MAX_NUM_THREADS 4 // @cppad_max_num_threads@
# endif

# endif