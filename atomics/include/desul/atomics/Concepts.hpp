/*
Copyright (c) 2019, Lawrence Livermore National Security, LLC
and DESUL project contributors. See the COPYRIGHT file for details.
Source: https://github.com/desul/desul

SPDX-License-Identifier: (BSD-3-Clause)
*/

#ifndef DESUL_ATOMICS_CONCEPTS_HPP_
#define DESUL_ATOMICS_CONCEPTS_HPP_

#define __DESUL_IMPL_ARITHMETIC_CONCEPT(OP,OPERATOR)                                 \
template <class ctype>                                                               \
concept has_arithmetic_##OP = requires(ctype const & first, ctype const & second) {  \
    { first OPERATOR second } -> std::same_as<ctype>;                                \
};                                                                                   \
                                                                                     \

#define __DESUL_IMPL_LOGIC_CONCEPT(OP,OPERATOR)                                      \
template <class ctype>                                                               \
concept has_logic_##OP = requires(ctype const & first, ctype const & second) {       \
    { first OPERATOR second } -> std::same_as<bool>;                                 \
};                                                                                   \


namespace desul{
namespace impl{

// add sub min max
__DESUL_IMPL_ARITHMETIC_CONCEPT(add,+)
__DESUL_IMPL_ARITHMETIC_CONCEPT(sub,-)

__DESUL_IMPL_LOGIC_CONCEPT(min,<)
__DESUL_IMPL_LOGIC_CONCEPT(max,>)

}
}

#undef __DESUL_IMPL_ARITHMETIC_CONCEPT
#undef __DESUL_IMPL_LOGIC_CONCEPT

#endif
