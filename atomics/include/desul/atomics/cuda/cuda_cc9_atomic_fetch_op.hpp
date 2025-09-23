// add sub min max
#define __DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP(OP,OPERATOR)                                                        \
template<class ctype>                                                                                                           \
requires has_arithmetic_##OP<ctype> && sizeof(ctype) == 16                                                                      \
inline __device__ ctype                                                                                                         \
device_atomic_fetch_##OP (ctype* dest, ctype val, __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) \
{                                                                                                                               \
    __int128_t* dest_int128 = reinterpret_cast<__int128_t*>(dest);                                                              \
    __int128_t old = *dest_int128, expected;                                                                                    \
                                                                                                                                \
    do {                                                                                                                        \
        expected = old;                                                                                                         \
        old = device_atomic_compare_exchange(dest_int128, expected,                                                             \
                        reinterpret_cast<__int128_t>(val OPERATOR                                                               \
                        reinterpret_cast<ctype>(expected)));                                                                    \
    } while (expected != old);                                                                                                  \
                                                                                                                                \
  return reinterpret_cast<ctype>(old);                                                                                          \
} 

#define __DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(OP,OPERATOR)                                                             \
template<class ctype>                                                                                                           \
requires has_logic_##OP<ctype> && sizeof(ctype) == 16                                                                           \
inline __device__ ctype                                                                                                         \
device_atomic_fetch_##OP (ctype* dest, ctype val, __DESUL_IMPL_CUDA_ASM_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE)    \
{                                                                                                                               \
    __int128_t* dest_int128 = reinterpret_cast<__int128_t*>(dest);                                                              \
    __int128_t old = *dest_int128, expected;                                                                                    \
                                                                                                                                \
    do {                                                                                                                        \
        expected = old;                                                                                                         \
        old = device_atomic_compare_exchange(dest_int128, expected,                                                             \
                        reinterpret_cast<__int128_t>(val OPERATOR reinterpret_cast<ctype>(expected) ?                           \
                        val : reinterpret_cast<ctype>(expected)));                                                              \
    } while (expected != old);                                                                                                  \
                                                                                                                                \
  return reinterpret_cast<ctype>(old);                                                                                          \
} 

__DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMEITC_FETCH_OP(add,+)
__DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP(sub,-)

__DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(min,<)
__DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(max,>)

#undef __DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMEITC_FETCH_OP
#undef __DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP
