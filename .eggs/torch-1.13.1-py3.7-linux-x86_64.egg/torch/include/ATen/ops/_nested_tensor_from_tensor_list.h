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



#include <ATen/ops/_nested_tensor_from_tensor_list_ops.h>

namespace at {


// aten::_nested_tensor_from_tensor_list(Tensor[] list, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None) -> Tensor
inline at::Tensor _nested_tensor_from_tensor_list(at::TensorList list, c10::optional<at::ScalarType> dtype=c10::nullopt, c10::optional<at::Layout> layout=c10::nullopt, c10::optional<at::Device> device=c10::nullopt, c10::optional<bool> pin_memory=c10::nullopt) {
    return at::_ops::_nested_tensor_from_tensor_list::call(list, dtype, layout, device, pin_memory);
}

// aten::_nested_tensor_from_tensor_list.out(Tensor[] list, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _nested_tensor_from_tensor_list_out(at::Tensor & out, at::TensorList list, c10::optional<at::ScalarType> dtype=c10::nullopt, c10::optional<at::Layout> layout=c10::nullopt, c10::optional<at::Device> device=c10::nullopt, c10::optional<bool> pin_memory=c10::nullopt) {
    return at::_ops::_nested_tensor_from_tensor_list_out::call(list, dtype, layout, device, pin_memory, out);
}

// aten::_nested_tensor_from_tensor_list.out(Tensor[] list, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _nested_tensor_from_tensor_list_outf(at::TensorList list, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory, at::Tensor & out) {
    return at::_ops::_nested_tensor_from_tensor_list_out::call(list, dtype, layout, device, pin_memory, out);
}

}
