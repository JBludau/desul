// add sub min max
#define __DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_OP(OP,OPERATOR)                                                        \
template<class ctype>                                                                                                     \
requires has_arithmetic_##OP<ctype> && sizeof(ctype) == 16                                                                \
inline __device__ ctype                                                                                                   \
device_atomic_##OP (ctype* dest, ctype val, __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) \
{                                                                                                                         \
  device_atomic_fetch_##OP (dest,val,__DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE);       \
} 

#define __DESUL_IMPL_CUDA_128BIT_LOGIC_ARITHMETIC_OP(OP,OPERATOR)                                                         \
template<class ctype>                                                                                                     \
requires has_logic_##OP<ctype> && sizeof(ctype) == 16                                                                     \
inline __device__ ctype                                                                                                   \
device_atomic_##OP (ctype* dest, ctype val, __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) \
{                                                                                                                         \
  device_atomic_fetch_##OP (dest,val,__DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER, __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE);       \
}

__DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMEITC_OP(add,+)
__DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_OP(sub,-)

__DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP(min,<)
__DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP(max,>)

#undef __DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMEITC_OP
#undef __DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP
