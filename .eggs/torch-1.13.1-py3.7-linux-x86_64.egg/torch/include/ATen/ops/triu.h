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



#include <ATen/ops/triu_ops.h>

namespace at {


// aten::triu.out(Tensor self, int diagonal=0, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & triu_out(at::Tensor & out, const at::Tensor & self, int64_t diagonal=0) {
    return at::_ops::triu_out::call(self, diagonal, out);
}

// aten::triu.out(Tensor self, int diagonal=0, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & triu_outf(const at::Tensor & self, int64_t diagonal, at::Tensor & out) {
    return at::_ops::triu_out::call(self, diagonal, out);
}

// aten::triu(Tensor self, int diagonal=0) -> Tensor
inline at::Tensor triu(const at::Tensor & self, int64_t diagonal=0) {
    return at::_ops::triu::call(self, diagonal);
}

}
