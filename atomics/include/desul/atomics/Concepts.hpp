/*
Copyright (c) 2019, Lawrence Livermore National Security, LLC
and DESUL project contributors. See the COPYRIGHT file for details.
Source: https://github.com/desul/desul

SPDX-License-Identifier: (BSD-3-Clause)
*/

#ifndef DESUL_ATOMICS_CONCEPTS_HPP_
#define DESUL_ATOMICS_CONCEPTS_HPP_

#define DESUL_IMPL_ARITHMETIC_CONCEPT(OP,OPERATOR)                                   \
template <class ctype>                                                               \
concept has_arithmetic_##OP = requires(ctype const & first, ctype const & second) {  \
    { first OPERATOR second } -> std::same_as<ctype>;                                \
};                                                                                   

#define DESUL_IMPL_LOGIC_CONCEPT(OP,OPERATOR)                                        \
template <class ctype>                                                               \
concept has_logic_##OP = requires(ctype const & first, ctype const & second) {       \
    { first OPERATOR second } -> std::same_as<bool>;                                 \
};                                                                                   


namespace desul{
namespace Impl{

// add sub min max
DESUL_IMPL_ARITHMETIC_CONCEPT(add,+)
DESUL_IMPL_ARITHMETIC_CONCEPT(sub,-)

DESUL_IMPL_LOGIC_CONCEPT(min,<)
DESUL_IMPL_LOGIC_CONCEPT(max,>)

}
}

#undef DESUL_IMPL_ARITHMETIC_CONCEPT
#undef DESUL_IMPL_LOGIC_CONCEPT

#endif
