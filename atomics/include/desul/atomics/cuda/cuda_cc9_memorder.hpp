#define __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER MemoryOrderRelaxed
#include "desul/atomics/cuda/cuda_cc9_atomic_fetch_op.hpp"
#include "desul/atomics/cuda/cuda_cc9_atomic_op.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER

#define __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER MemoryOrderRelease
#include "desul/atomics/cuda/cuda_cc9_atomic_fetch_op.hpp"
#include "desul/atomics/cuda/cuda_cc9_atomic_op.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER


#define __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER MemoryOrderAcquire
#include "desul/atomics/cuda/cuda_cc9_atomic_fetch_op.hpp"
#include "desul/atomics/cuda/cuda_cc9_atomic_op.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER

#define __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER MemoryOrderAcqRel
#include "desul/atomics/cuda/cuda_cc9_atomic_fetch_op.hpp"
#include "desul/atomics/cuda/cuda_cc9_atomic_op.hpp"
#undef __DESUL_IMPL_CUDA_128BIT_MEMORY_ORDER
