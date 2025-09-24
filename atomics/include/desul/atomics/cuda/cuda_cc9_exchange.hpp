#define DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE MemoryScopeDevice
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

#define DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE MemoryScopeNode
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

#define DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE MemoryScopeCore
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

