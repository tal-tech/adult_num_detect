/*
 * Copyright 2017-2022 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO LICENSEE:
 *
 * This source code and/or documentation ("Licensed Deliverables") are
 * subject to NVIDIA intellectual property rights under U.S. and
 * international Copyright laws.
 *
 * These Licensed Deliverables contained herein is PROPRIETARY and
 * CONFIDENTIAL to NVIDIA and is being provided under the terms and
 * conditions of a form of NVIDIA software license agreement by and
 * between NVIDIA and Licensee ("License Agreement") or electronically
 * accepted by Licensee.  Notwithstanding any terms or conditions to
 * the contrary in the License Agreement, reproduction or disclosure
 * of the Licensed Deliverables to any third party without the express
 * written consent of NVIDIA is prohibited.
 *
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
 * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
 * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.
 * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED
 * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY
 * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THESE LICENSED DELIVERABLES.
 *
 * U.S. Government End Users.  These Licensed Deliverables are a
 * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT
 * 1995), consisting of "commercial computer software" and "commercial
 * computer software documentation" as such terms are used in 48
 * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
 * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and
 * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all
 * U.S. Government End Users acquire the Licensed Deliverables with
 * only those rights set forth herein.
 *
 * Any use of the Licensed Deliverables in individual and commercial
 * software must include, in the user documentation and internal
 * comments to the code, the above Disclaimer and U.S. Government End
 * Users Notice.
 */

/*
 *  cudnn_ops_train : cuDNN's basic training operations and algorithms.
 */

#if !defined(CUDNN_OPS_TRAIN_H_)
#define CUDNN_OPS_TRAIN_H_

#include <cuda_runtime.h>
#include <stdint.h>

#include "cudnn_version.h"
#include "cudnn_ops_infer.h"

/* These version numbers are autogenerated, do not edit manually. */
#define CUDNN_OPS_TRAIN_MAJOR 8
#define CUDNN_OPS_TRAIN_MINOR 5
#define CUDNN_OPS_TRAIN_PATCH 0

#if (CUDNN_OPS_TRAIN_MAJOR != CUDNN_MAJOR) || (CUDNN_OPS_TRAIN_MINOR != CUDNN_MINOR) || \
    (CUDNN_OPS_TRAIN_PATCH != CUDNN_PATCHLEVEL)
#error Version mismatch in cuDNN OPS TRAIN!!!
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* Function to perform backward softmax */
cudnnStatus_t CUDNNWINAPI
cudnnSoftmaxBackward(cudnnHandle_t handle,
                     cudnnSoftmaxAlgorithm_t algo,
                     cudnnSoftmaxMode_t mode,
                     const void *alpha,
                     const cudnnTensorDescriptor_t yDesc,
                     const void *y,
                     const cudnnTensorDescriptor_t dyDesc,
                     const void *dy,
                     const void *beta,
                     const cudnnTensorDescriptor_t dxDesc,
                     void *dx);

/* Function to perform backward pooling */
cudnnStatus_t CUDNNWINAPI
cudnnPoolingBackward(cudnnHandle_t handle,
                     const cudnnPoolingDescriptor_t poolingDesc,
                     const void *alpha,
                     const cudnnTensorDescriptor_t yDesc,
                     const void *y,
                     const cudnnTensorDescriptor_t dyDesc,
                     const void *dy,
                     const cudnnTensorDescriptor_t xDesc,
                     const void *x,
                     const void *beta,
                     const cudnnTensorDescriptor_t dxDesc,
                     void *dx);

/* Function to perform backward activation  */
cudnnStatus_t CUDNNWINAPI
cudnnActivationBackward(cudnnHandle_t handle,
                        cudnnActivationDescriptor_t activationDesc,
                        const void *alpha,
                        const cudnnTensorDescriptor_t yDesc,
                        const void *y,
                        const cudnnTensorDescriptor_t dyDesc,
                        const void *dy,
                        const cudnnTensorDescriptor_t xDesc,
                        const void *x,
                        const void *beta,
                        const cudnnTensorDescriptor_t dxDesc,
                        void *dx);

/* LRN cross-channel backward computation. Double parameters cast to tensor data type */
cudnnStatus_t CUDNNWINAPI
cudnnLRNCrossChannelBackward(cudnnHandle_t handle,
                             cudnnLRNDescriptor_t normDesc,
                             cudnnLRNMode_t lrnMode,
                             const void *alpha,
                             const cudnnTensorDescriptor_t yDesc,
                             const void *y,
                             const cudnnTensorDescriptor_t dyDesc,
                             const void *dy,
                             const cudnnTensorDescriptor_t xDesc,
                             const void *x,
                             const void *beta,
                             const cudnnTensorDescriptor_t dxDesc,
                             void *dx);

cudnnStatus_t CUDNNWINAPI
cudnnDivisiveNormalizationBackward(cudnnHandle_t handle,
                                   cudnnLRNDescriptor_t normDesc,
                                   cudnnDivNormMode_t mode,
                                   const void *alpha,
                                   const cudnnTensorDescriptor_t xDesc, /* same desc for x, means, dy, temp, temp2 */
                                   const void *x,
                                   const void *means, /* if NULL, means are assumed to be zero */
                                   const void *dy,
                                   void *temp,
                                   void *temp2,
                                   const void *beta,
                                   const cudnnTensorDescriptor_t dXdMeansDesc, /* same desc for dx, dMeans */
                                   void *dx,                                   /* output x differential */
                                   void *dMeans); /* output means differential, can be NULL */

cudnnStatus_t CUDNNWINAPI
cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize(cudnnHandle_t handle,
                                                         cudnnBatchNormMode_t mode,
                                                         cudnnBatchNormOps_t bnOps,
                                                         const cudnnTensorDescriptor_t xDesc,
                                                         const cudnnTensorDescriptor_t zDesc,
                                                         const cudnnTensorDescriptor_t yDesc,
                                                         const cudnnTensorDescriptor_t bnScaleBiasMeanVarDesc,
                                                         const cudnnActivationDescriptor_t activationDesc,
                                                         size_t *sizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnGetBatchNormalizationBackwardExWorkspaceSize(cudnnHandle_t handle,
                                                  cudnnBatchNormMode_t mode,
                                                  cudnnBatchNormOps_t bnOps,
                                                  const cudnnTensorDescriptor_t xDesc,
                                                  const cudnnTensorDescriptor_t yDesc,
                                                  const cudnnTensorDescriptor_t dyDesc,
                                                  const cudnnTensorDescriptor_t dzDesc,
                                                  const cudnnTensorDescriptor_t dxDesc,
                                                  const cudnnTensorDescriptor_t dBnScaleBiasDesc,
                                                  const cudnnActivationDescriptor_t activationDesc,
                                                  size_t *sizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnGetBatchNormalizationTrainingExReserveSpaceSize(cudnnHandle_t handle,
                                                     cudnnBatchNormMode_t mode,
                                                     cudnnBatchNormOps_t bnOps,
                                                     const cudnnActivationDescriptor_t activationDesc,
                                                     const cudnnTensorDescriptor_t xDesc,
                                                     size_t *sizeInBytes);

/* Computes y = BN(x). Also accumulates moving averages of mean and inverse variances */
cudnnStatus_t CUDNNWINAPI
cudnnBatchNormalizationForwardTraining(
    cudnnHandle_t handle,
    cudnnBatchNormMode_t mode,

    const void *alpha, /* alpha[0] = result blend factor */
    const void *beta,  /* beta[0] = dest layer blend factor */

    const cudnnTensorDescriptor_t xDesc,
    const void *x, /* NxCxHxW */
    const cudnnTensorDescriptor_t yDesc,
    void *y, /* NxCxHxW */

    /* Shared desc for the next 6 tensors in the argument list.
       Data type to be set as follows:
       type = (typeOf(x) == double) ? double : float
       Dimensions for this descriptor depend on normalization mode
       - Spatial Normalization : tensors are expected to have dims 1xCx1x1
        (normalization is performed across NxHxW)
       - Per-Activation Normalization : tensors are expected to have dims of 1xCxHxW
        (normalization is performed across N) */
    const cudnnTensorDescriptor_t bnScaleBiasMeanVarDesc,

    /* 'Gamma' and 'Beta' respectively in Ioffe and Szegedy's paper's notation */
    const void *bnScale,
    const void *bnBias,

    /* MUST use factor=1 in the very first call of a complete training cycle.
       Use a factor=1/(1+n) at N-th call to the function to get
       Cumulative Moving Average (CMA) behavior
       CMA[n] = (x[1]+...+x[n])/n
       Since CMA[n+1] = (n*CMA[n]+x[n+1])/(n+1) =
       ((n+1)*CMA[n]-CMA[n])/(n+1) + x[n+1]/(n+1) =
       CMA[n]*(1-1/(n+1)) + x[n+1]*1/(n+1) */
    double exponentialAverageFactor,

    /* Used in Training phase only.
       runningMean = newMean*factor + runningMean*(1-factor) */
    void *resultRunningMean,
    /* Output in training mode, input in inference. Is the moving average
       of  variance[x] (factor is applied in the same way as for runningMean) */
    void *resultRunningVariance,

    /* Has to be >= CUDNN_BN_MIN_EPSILON. Should be the same in forward and backward functions. */
    double epsilon,

    /* Optionally save intermediate results from the forward pass here
       - can be reused to speed up backward pass. NULL if unused */
    void *resultSaveMean,
    void *resultSaveInvVariance);

/* Computes y = relu(BN(x) + z). Also accumulates moving averages of mean and inverse variances */
cudnnStatus_t CUDNNWINAPI
cudnnBatchNormalizationForwardTrainingEx(
    cudnnHandle_t handle,
    cudnnBatchNormMode_t mode,
    cudnnBatchNormOps_t bnOps,

    const void *alpha, /* alpha[0] = result blend factor */
    const void *beta,  /* beta[0] = dest layer blend factor */

    const cudnnTensorDescriptor_t xDesc,
    const void *xData,
    const cudnnTensorDescriptor_t zDesc,
    const void *zData,
    const cudnnTensorDescriptor_t yDesc,
    void *yData,

    const cudnnTensorDescriptor_t bnScaleBiasMeanVarDesc,
    const void *bnScale,
    const void *bnBias,

    double exponentialAverageFactor,
    void *resultRunningMean,
    void *resultRunningVariance,

    /* Has to be >= CUDNN_BN_MIN_EPSILON. Should be the same in forward and backward functions. */
    double epsilon,

    /* Optionally save intermediate results from the forward pass here
       - can be reused to speed up backward pass. NULL if unused */
    void *resultSaveMean,
    void *resultSaveInvVariance,

    cudnnActivationDescriptor_t activationDesc,
    void *workspace,
    size_t workSpaceSizeInBytes,
    void *reserveSpace,
    size_t reserveSpaceSizeInBytes);

/* Performs backward pass of Batch Normalization layer. Returns x gradient,
* bnScale gradient and bnBias gradient */
cudnnStatus_t CUDNNWINAPI
cudnnBatchNormalizationBackward(cudnnHandle_t handle,
                                cudnnBatchNormMode_t mode,
                                const void *alphaDataDiff,
                                const void *betaDataDiff,
                                const void *alphaParamDiff,
                                const void *betaParamDiff,
                                const cudnnTensorDescriptor_t xDesc, /* same desc for x, dx, dy */
                                const void *x,
                                const cudnnTensorDescriptor_t dyDesc,
                                const void *dy,
                                const cudnnTensorDescriptor_t dxDesc,
                                void *dx,
                                /* Shared tensor desc for the 4 tensors below */
                                const cudnnTensorDescriptor_t dBnScaleBiasDesc,
                                const void *bnScale, /* bnBias doesn't affect backpropagation */
                                /* scale and bias diff are not backpropagated below this layer */
                                void *dBnScaleResult,
                                void *dBnBiasResult,
                                /* Same epsilon as forward pass */
                                double epsilon,

                                /* Optionally cached intermediate results from
                                   forward pass */
                                const void *savedMean,
                                const void *savedInvVariance);

cudnnStatus_t CUDNNWINAPI
cudnnBatchNormalizationBackwardEx(cudnnHandle_t handle,
                                  cudnnBatchNormMode_t mode,
                                  cudnnBatchNormOps_t bnOps,

                                  const void *alphaDataDiff,
                                  const void *betaDataDiff,
                                  const void *alphaParamDiff,
                                  const void *betaParamDiff,
                                  const cudnnTensorDescriptor_t xDesc,
                                  const void *xData,
                                  const cudnnTensorDescriptor_t yDesc,
                                  const void *yData,
                                  const cudnnTensorDescriptor_t dyDesc,
                                  const void *dyData,
                                  const cudnnTensorDescriptor_t dzDesc,
                                  void *dzData,
                                  const cudnnTensorDescriptor_t dxDesc,
                                  void *dxData,

                                  /* Shared tensor desc for the 4 tensors below */
                                  const cudnnTensorDescriptor_t dBnScaleBiasDesc,
                                  const void *bnScaleData,
                                  const void *bnBiasData, /* needed if there is activation */
                                  void *dBnScaleData,
                                  void *dBnBiasData,
                                  double epsilon, /* Same epsilon as forward pass */

                                  /* Optionally cached intermediate results from
                                     forward pass */
                                  const void *savedMean,
                                  const void *savedInvVariance,
                                  cudnnActivationDescriptor_t activationDesc,
                                  void *workSpace,
                                  size_t workSpaceSizeInBytes,
                                  void *reserveSpace,
                                  size_t reserveSpaceSizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnGetNormalizationForwardTrainingWorkspaceSize(cudnnHandle_t handle,
                                                  cudnnNormMode_t mode,
                                                  cudnnNormOps_t normOps,
                                                  cudnnNormAlgo_t algo,
                                                  const cudnnTensorDescriptor_t xDesc,
                                                  const cudnnTensorDescriptor_t zDesc,
                                                  const cudnnTensorDescriptor_t yDesc,
                                                  const cudnnTensorDescriptor_t normScaleBiasDesc,
                                                  const cudnnActivationDescriptor_t activationDesc,
                                                  const cudnnTensorDescriptor_t normMeanVarDesc,
                                                  size_t *sizeInBytes,
                                                  int groupCnt); /* Place hold for future work, should be set to 1 now*/

cudnnStatus_t CUDNNWINAPI
cudnnGetNormalizationBackwardWorkspaceSize(cudnnHandle_t handle,
                                           cudnnNormMode_t mode,
                                           cudnnNormOps_t normOps,
                                           cudnnNormAlgo_t algo,
                                           const cudnnTensorDescriptor_t xDesc,
                                           const cudnnTensorDescriptor_t yDesc,
                                           const cudnnTensorDescriptor_t dyDesc,
                                           const cudnnTensorDescriptor_t dzDesc,
                                           const cudnnTensorDescriptor_t dxDesc,
                                           const cudnnTensorDescriptor_t dNormScaleBiasDesc,
                                           const cudnnActivationDescriptor_t activationDesc,
                                           const cudnnTensorDescriptor_t normMeanVarDesc,
                                           size_t *sizeInBytes,
                                           int groupCnt); /* Place hold for future work, should be set to 1 now*/

cudnnStatus_t CUDNNWINAPI
cudnnGetNormalizationTrainingReserveSpaceSize(cudnnHandle_t handle,
                                              cudnnNormMode_t mode,
                                              cudnnNormOps_t normOps,
                                              cudnnNormAlgo_t algo,
                                              const cudnnActivationDescriptor_t activationDesc,
                                              const cudnnTensorDescriptor_t xDesc,
                                              size_t *sizeInBytes,
                                              int groupCnt); /* Place hold for future work, should be set to 1 now*/

/* Computes y = relu(Norm(x) + z). Also accumulates moving averages of mean and inverse variances */
cudnnStatus_t CUDNNWINAPI
cudnnNormalizationForwardTraining(cudnnHandle_t handle,
                                  cudnnNormMode_t mode,
                                  cudnnNormOps_t normOps,
                                  cudnnNormAlgo_t algo,
                                  const void *alpha, /* alpha[0] = result blend factor */
                                  const void *beta,  /* beta[0] = dest layer blend factor */
                                  const cudnnTensorDescriptor_t xDesc,
                                  const void *xData,
                                  const cudnnTensorDescriptor_t normScaleBiasDesc,
                                  const void *normScale,
                                  const void *normBias,
                                  double exponentialAverageFactor,
                                  const cudnnTensorDescriptor_t normMeanVarDesc,
                                  void *resultRunningMean,
                                  void *resultRunningVariance,
                                  /* Has to be >= 0. Should be the same in forward and backward functions. */
                                  double epsilon,
                                  /* Optionally save intermediate results from the forward pass here
                                     - can be reused to speed up backward pass. NULL if unused */
                                  void *resultSaveMean,
                                  void *resultSaveInvVariance,
                                  cudnnActivationDescriptor_t activationDesc,
                                  const cudnnTensorDescriptor_t zDesc,
                                  const void *zData,
                                  const cudnnTensorDescriptor_t yDesc,
                                  void *yData,
                                  void *workspace,
                                  size_t workSpaceSizeInBytes,
                                  void *reserveSpace,
                                  size_t reserveSpaceSizeInBytes,
                                  int groupCnt); /* Place hold for future work, should be set to 1 now*/

cudnnStatus_t CUDNNWINAPI
cudnnNormalizationBackward(cudnnHandle_t handle,
                           cudnnNormMode_t mode,
                           cudnnNormOps_t normOps,
                           cudnnNormAlgo_t algo,
                           const void *alphaDataDiff,
                           const void *betaDataDiff,
                           const void *alphaParamDiff,
                           const void *betaParamDiff,
                           const cudnnTensorDescriptor_t xDesc,
                           const void *xData,
                           const cudnnTensorDescriptor_t yDesc,
                           const void *yData,
                           const cudnnTensorDescriptor_t dyDesc,
                           const void *dyData,
                           const cudnnTensorDescriptor_t dzDesc,
                           void *dzData,
                           const cudnnTensorDescriptor_t dxDesc,
                           void *dxData,
                           /* Shared tensor desc for the 4 tensors below */
                           const cudnnTensorDescriptor_t dNormScaleBiasDesc,
                           const void *normScaleData,
                           const void *normBiasData, /* needed if there is activation */
                           void *dNormScaleData,
                           void *dNormBiasData,
                           double epsilon, /* Same epsilon as forward pass */
                           const cudnnTensorDescriptor_t normMeanVarDesc,
                           /* Optionally cached intermediate results from
                              forward pass */
                           const void *savedMean,
                           const void *savedInvVariance,
                           cudnnActivationDescriptor_t activationDesc,
                           void *workSpace,
                           size_t workSpaceSizeInBytes,
                           void *reserveSpace,
                           size_t reserveSpaceSizeInBytes,
                           int groupCnt); /* Place hold for future work, should be set to 1 now*/

cudnnStatus_t CUDNNWINAPI
cudnnSpatialTfGridGeneratorBackward(cudnnHandle_t handle,
                                    const cudnnSpatialTransformerDescriptor_t stDesc,
                                    const void *dgrid,
                                    void *dtheta);

cudnnStatus_t CUDNNWINAPI
cudnnSpatialTfSamplerBackward(cudnnHandle_t handle,
                              cudnnSpatialTransformerDescriptor_t stDesc,
                              const void *alpha,
                              const cudnnTensorDescriptor_t xDesc,
                              const void *x,
                              const void *beta,
                              const cudnnTensorDescriptor_t dxDesc,
                              void *dx,
                              const void *alphaDgrid,
                              const cudnnTensorDescriptor_t dyDesc,
                              const void *dy,
                              const void *grid,
                              const void *betaDgrid,
                              void *dgrid);

cudnnStatus_t CUDNNWINAPI
cudnnDropoutBackward(cudnnHandle_t handle,
                     const cudnnDropoutDescriptor_t dropoutDesc,
                     const cudnnTensorDescriptor_t dydesc,
                     const void *dy,
                     const cudnnTensorDescriptor_t dxdesc,
                     void *dx,
                     void *reserveSpace,
                     size_t reserveSpaceSizeInBytes);

/*
 * \brief Cross-library version checker.
 * This function is implemented differently in each sub-library. Each sublib
 * checks whether its own version matches that of its dependencies.
 * \returns CUDNN_STATUS_SUCCESS if the version check passes,
 *          CUDNN_STATUS_VERSION_MISMATCH if the versions are inconsistent.
 */
cudnnStatus_t CUDNNWINAPI
cudnnOpsTrainVersionCheck(void);

#if defined(__cplusplus)
}
#endif

#endif /* CUDNN_OPS_TRAIN_H_ */
