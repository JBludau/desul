// add sub min max
#define DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_OP(OP, OPERATOR)       \
  template <class ctype>                                                \
  requires has_arithmetic_##OP<ctype> &&                                \
      (sizeof(ctype) == 16) inline __device__ ctype device_atomic_##OP( \
          ctype* dest,                                                  \
          ctype val,                                                    \
          DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER,                          \
          DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) {                        \
    device_atomic_fetch_##OP(dest,                                      \
                             val,                                       \
                             DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER(),     \
                             DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE());    \
  }

#define DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP(OP, OPERATOR)            \
  template <class ctype>                                                \
  requires has_logic_##OP<ctype> &&                                     \
      (sizeof(ctype) == 16) inline __device__ ctype device_atomic_##OP( \
          ctype* dest,                                                  \
          ctype val,                                                    \
          DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER,                          \
          DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE) {                        \
    device_atomic_fetch_##OP(dest,                                      \
                             val,                                       \
                             DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER(),     \
                             DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE());    \
  }

DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_OP(add, +)
DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMETIC_OP(sub, -)

DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP(min, <)
DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP(max, >)

#undef DESUL_IMPL_CUDA_128BIT_ATOMIC_ARITHMEITC_OP
#undef DESUL_IMPL_CUDA_128BIT_ATOMIC_LOGIC_OP
