// Non returning atomic operation (ptx red instruction) only exists for relaxed and release memorder
#define __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE MemoryScopeDevice
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

#define __DESUL_IMPL_CUDA_128BBIT_MEMORY_SCOPE MemoryScopeNode
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

#define __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE MemoryScopeCore
#include "desul/atomics/cuda/cuda_cc9_memorder.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_SCOPE

