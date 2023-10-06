#pragma once

// @generated by torchgen/gen.py from Operator.h

#include <tuple>
#include <vector>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {
namespace _ops {


struct TORCH_API embedding_dense_backward {
  using schema = at::Tensor (const at::Tensor &, const at::Tensor &, c10::SymInt, int64_t, bool);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::embedding_dense_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "embedding_dense_backward(Tensor grad_output, Tensor indices, SymInt num_weights, int padding_idx, bool scale_grad_by_freq) -> Tensor")
  static at::Tensor call(const at::Tensor & grad_output, const at::Tensor & indices, c10::SymInt num_weights, int64_t padding_idx, bool scale_grad_by_freq);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad_output, const at::Tensor & indices, c10::SymInt num_weights, int64_t padding_idx, bool scale_grad_by_freq);
};

struct TORCH_API embedding_dense_backward_out {
  using schema = at::Tensor & (const at::Tensor &, const at::Tensor &, c10::SymInt, int64_t, bool, at::Tensor &);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::embedding_dense_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "out")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "embedding_dense_backward.out(Tensor grad_output, Tensor indices, SymInt num_weights, int padding_idx, bool scale_grad_by_freq, *, Tensor(a!) out) -> Tensor(a!)")
  static at::Tensor & call(const at::Tensor & grad_output, const at::Tensor & indices, c10::SymInt num_weights, int64_t padding_idx, bool scale_grad_by_freq, at::Tensor & out);
  static at::Tensor & redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad_output, const at::Tensor & indices, c10::SymInt num_weights, int64_t padding_idx, bool scale_grad_by_freq, at::Tensor & out);
};

}} // namespace at::_ops
