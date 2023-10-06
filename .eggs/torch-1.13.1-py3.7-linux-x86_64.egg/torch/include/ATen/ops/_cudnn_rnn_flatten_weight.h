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



#include <ATen/ops/_cudnn_rnn_flatten_weight_ops.h>

namespace at {


// aten::_cudnn_rnn_flatten_weight(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional) -> Tensor
inline at::Tensor _cudnn_rnn_flatten_weight(at::TensorList weight_arr, int64_t weight_stride0, int64_t input_size, int64_t mode, int64_t hidden_size, int64_t proj_size, int64_t num_layers, bool batch_first, bool bidirectional) {
    return at::_ops::_cudnn_rnn_flatten_weight::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional);
}

// aten::_cudnn_rnn_flatten_weight(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional) -> Tensor
inline at::Tensor _cudnn_rnn_flatten_weight_symint(at::TensorList weight_arr, int64_t weight_stride0, c10::SymInt input_size, int64_t mode, c10::SymInt hidden_size, c10::SymInt proj_size, int64_t num_layers, bool batch_first, bool bidirectional) {
    return at::_ops::_cudnn_rnn_flatten_weight::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional);
}

// aten::_cudnn_rnn_flatten_weight.out(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _cudnn_rnn_flatten_weight_out(at::Tensor & out, at::TensorList weight_arr, int64_t weight_stride0, int64_t input_size, int64_t mode, int64_t hidden_size, int64_t proj_size, int64_t num_layers, bool batch_first, bool bidirectional) {
    return at::_ops::_cudnn_rnn_flatten_weight_out::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional, out);
}

// aten::_cudnn_rnn_flatten_weight.out(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _cudnn_rnn_flatten_weight_outf(at::TensorList weight_arr, int64_t weight_stride0, int64_t input_size, int64_t mode, int64_t hidden_size, int64_t proj_size, int64_t num_layers, bool batch_first, bool bidirectional, at::Tensor & out) {
    return at::_ops::_cudnn_rnn_flatten_weight_out::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional, out);
}

// aten::_cudnn_rnn_flatten_weight.out(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _cudnn_rnn_flatten_weight_symint_out(at::Tensor & out, at::TensorList weight_arr, int64_t weight_stride0, c10::SymInt input_size, int64_t mode, c10::SymInt hidden_size, c10::SymInt proj_size, int64_t num_layers, bool batch_first, bool bidirectional) {
    return at::_ops::_cudnn_rnn_flatten_weight_out::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional, out);
}

// aten::_cudnn_rnn_flatten_weight.out(Tensor[] weight_arr, int weight_stride0, SymInt input_size, int mode, SymInt hidden_size, SymInt proj_size, int num_layers, bool batch_first, bool bidirectional, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & _cudnn_rnn_flatten_weight_symint_outf(at::TensorList weight_arr, int64_t weight_stride0, c10::SymInt input_size, int64_t mode, c10::SymInt hidden_size, c10::SymInt proj_size, int64_t num_layers, bool batch_first, bool bidirectional, at::Tensor & out) {
    return at::_ops::_cudnn_rnn_flatten_weight_out::call(weight_arr, weight_stride0, input_size, mode, hidden_size, proj_size, num_layers, batch_first, bidirectional, out);
}

}
