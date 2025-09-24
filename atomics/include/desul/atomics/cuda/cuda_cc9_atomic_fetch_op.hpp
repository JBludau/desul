// add sub min max
#define DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP(OP,OPERATOR)                                                          \
template<class ctype>                                                                                                           \
requires has_arithmetic_##OP<ctype> && (sizeof(ctype) == 16)                                                                    \
inline __device__ ctype                                                                                                         \
device_atomic_fetch_##OP (ctype* dest, ctype val, DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) \
{                                                                                                                               \
    __int128_t* dest_int128 = reinterpret_cast<__int128_t*>(dest);                                                              \
    __int128_t old = *dest_int128, expected;                                                                                    \
                                                                                                                                \
    do {                                                                                                                        \
        expected = old;                                                                                                         \
        old = device_atomic_compare_exchange(dest_int128, expected,                                                             \
                        reinterpret_cast<__int128_t>(val OPERATOR                                                               \
                        reinterpret_cast<ctype>(expected)),DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER(), DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE() );                                                                    \
    } while (expected != old);                                                                                                  \
                                                                                                                                \
  return reinterpret_cast<ctype>(old);                                                                                          \
}

#define DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(OP,OPERATOR)                                                               \
template<class ctype>                                                                                                           \
requires has_logic_##OP<ctype> && (sizeof(ctype) == 16)                                                                         \
inline __device__ ctype                                                                                                         \
device_atomic_fetch_##OP (ctype* dest, ctype val, DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) \
{                                                                                                                               \
    __int128_t* dest_int128 = reinterpret_cast<__int128_t*>(dest);                                                              \
    __int128_t old = *dest_int128, expected;                                                                                    \
                                                                                                                                \
    do {                                                                                                                        \
        expected = old;                                                                                                         \
        old = device_atomic_compare_exchange(dest_int128, expected,                                                             \
                        reinterpret_cast<__int128_t>(val OPERATOR reinterpret_cast<ctype>(expected) ?                           \
                        val : reinterpret_cast<ctype>(expected)),DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER(), DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE());                                                              \
    } while (expected != old);                                                                                                  \
                                                                                                                                \
  return reinterpret_cast<ctype>(old);                                                                                          \
}

DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP(add, +)
DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP(sub, -)

DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(min, <)
DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP(max, >)

#undef DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_FETCH_OP
#undef DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_FETCH_OP
