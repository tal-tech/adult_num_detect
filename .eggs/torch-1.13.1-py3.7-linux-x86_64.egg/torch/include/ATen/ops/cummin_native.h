#pragma once

// @generated by torchgen/gen.py from NativeFunction.h

#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>
#include <c10/core/QScheme.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <tuple>
#include <vector>


namespace at {
namespace native {
TORCH_API ::std::tuple<at::Tensor,at::Tensor> cummin(const at::Tensor & self, int64_t dim);
TORCH_API ::std::tuple<at::Tensor &,at::Tensor &> cummin_out(const at::Tensor & self, int64_t dim, at::Tensor & values, at::Tensor & indices);
TORCH_API ::std::tuple<at::Tensor,at::Tensor> cummin(const at::Tensor & self, at::Dimname dim);
TORCH_API ::std::tuple<at::Tensor &,at::Tensor &> cummin_out(const at::Tensor & self, at::Dimname dim, at::Tensor & values, at::Tensor & indices);
} // namespace native
} // namespace at
