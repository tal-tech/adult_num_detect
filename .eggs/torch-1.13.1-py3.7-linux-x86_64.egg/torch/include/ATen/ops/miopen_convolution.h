#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/miopen_convolution_ops.h>

namespace at {


// aten::miopen_convolution(Tensor self, Tensor weight, Tensor? bias, int[] padding, int[] stride, int[] dilation, int groups, bool benchmark, bool deterministic) -> Tensor
inline at::Tensor miopen_convolution(const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias, at::IntArrayRef padding, at::IntArrayRef stride, at::IntArrayRef dilation, int64_t groups, bool benchmark, bool deterministic) {
    return at::_ops::miopen_convolution::call(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
}

// aten::miopen_convolution.out(Tensor self, Tensor weight, Tensor? bias, int[] padding, int[] stride, int[] dilation, int groups, bool benchmark, bool deterministic, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & miopen_convolution_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias, at::IntArrayRef padding, at::IntArrayRef stride, at::IntArrayRef dilation, int64_t groups, bool benchmark, bool deterministic) {
    return at::_ops::miopen_convolution_out::call(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic, out);
}

// aten::miopen_convolution.out(Tensor self, Tensor weight, Tensor? bias, int[] padding, int[] stride, int[] dilation, int groups, bool benchmark, bool deterministic, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & miopen_convolution_outf(const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias, at::IntArrayRef padding, at::IntArrayRef stride, at::IntArrayRef dilation, int64_t groups, bool benchmark, bool deterministic, at::Tensor & out) {
    return at::_ops::miopen_convolution_out::call(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic, out);
}

}
