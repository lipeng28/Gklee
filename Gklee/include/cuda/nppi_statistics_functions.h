 /* Copyright 2009-2012 NVIDIA Corporation.  All rights reserved. 
  * 
  * NOTICE TO LICENSEE: 
  * 
  * The source code and/or documentation ("Licensed Deliverables") are 
  * subject to NVIDIA intellectual property rights under U.S. and 
  * international Copyright laws. 
  * 
  * The Licensed Deliverables contained herein are PROPRIETARY and 
  * CONFIDENTIAL to NVIDIA and are being provided under the terms and 
  * conditions of a form of NVIDIA software license agreement by and 
  * between NVIDIA and Licensee ("License Agreement") or electronically 
  * accepted by Licensee.  Notwithstanding any terms or conditions to 
  * the contrary in the License Agreement, reproduction or disclosure 
  * of the Licensed Deliverables to any third party without the express 
  * written consent of NVIDIA is prohibited. 
  * 
  * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE 
  * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE 
  * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  THEY ARE 
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
  * C.F.R. 12.212 (SEPT 1995) and are provided to the U.S. Government 
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
#ifndef NV_NPPI_STATISTICS_FUNCTIONS_H
#define NV_NPPI_STATISTICS_FUNCTIONS_H
 
/**
 * \file nppi_statistics_functions.h
 * NPP Image Processing Functionality.
 */
 
#include "nppdefs.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup image_statistics_functions Statistical Operations
 *  @ingroup nppi
 *
 * Primitives for computing the statistical properties of an image.
 * Some statistical primitives also require scratch buffer during the computation. For details, please 
 * refer to \ref general_scratch_buffer.
 * @{
 *
 */

/** @defgroup image_sum Sum
 * Primitives for computing the sum of all the pixel values in an image.
 * @{
 */

/** @name Sum
 * @{
 * Given an image \f$pSrc\f$ with width \f$W\f$ and height \f$H\f$, the sum
 * will be computed as
 * \f[Sum = \sum_{j=0}^{H-1}\sum_{i=0}^{W-1}pSrc(j,i)\f]
 * All the results are stored in a 64-bit double precision format, 
 * except for two primitives \ref nppiSum_8u64s_C1R and \ref nppiSum_8u64s_C4R.
 * The sum functions require additional scratch buffer for computations.
 */

/**
 * One-channel 8-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \param pSum Pointer to the computed sum.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pSum);

/**
 * One-channel 8-bit unsigned image sum. The result is 64-bit long long integer.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_8u64s_C1R to determine the minium number of bytes required.
 * \param pSum Pointer to the computed sum.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u64s_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64s * pSum);

/**
 * One-channel 16-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16u_C1R to determine the minium number of bytes required.
 * \param pSum Pointer to the computed sum.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pSum);

/**
 * One-channel 16-bit signed image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16s_C1R to determine the minium number of bytes required.
 * \param pSum Pointer to the computed sum.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pSum);

/**
 * One-channel 32-bit floating point image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_32f_C1R to determine the minium number of bytes required.
 * \param pSum Pointer to the computed sum.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pSum);

/**
 * Three-channel 8-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_8u_C3R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Three-channel 16-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16u_C3R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Three-channel 16-bit signed image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16s_C3R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Three-channel 32-bit floating point image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_32f_C3R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Four-channel 8-bit unsigned image sum ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_8u_AC4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel (alpha channel is not computed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Four-channel 16-bit unsigned image sum ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16u_AC4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel (alpha channel is not computed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Four-channel 16-bit signed image sum ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiSumGetBufferHostSize_16s_AC4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel (alpha channel is not computed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Four-channel 32-bit floating point image sum ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_32f_AC4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel (alpha channel is not computed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[3]);

/**
 * Four-channel 8-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_8u_C4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[4]);

/**
 * Four-channel 8-bit unsigned image sum. The result is 64-bit long long integer.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_8u64s_C4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_8u64s_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64s aSum[4]);

/**
 * Four-channel 16-bit unsigned image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_16u_C4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[4]);

/**
 * Four-channel 16-bit signed image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_16s_C4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[4]);

/**
 * Four-channel 32-bit floating point image sum.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiSumGetBufferHostSize_32f_C4R to determine the minium number of bytes required.
 * \param aSum Array that contains computed sum for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSum_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aSum[4]);

/** @} Sum */

/** @name SumGetBufferHostSize 
 * Companion primitives for computing the device buffer size (in bytes) required by the sum primitives.
 * @{
 */

/**
 * Buffer size for \ref nppiSum_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/**
 * Buffer size for \ref nppiSum_8u64s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u64s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_8u64s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u64s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiSum_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSumGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
 
/** @} SumGetBufferHostSize */
/** @} image_sum */

/** @defgroup image_min Min
 * Primitives for computing the minimal pixel value of an image.
 * @{
 */

/** @name Min
 * The scratch buffer is required by the min functions.
 * @{
 */

/**
 * One-channel 8-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed minimum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u * pMin);

/**
 * One-channel 16-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16u_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed minimum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u * pMin);

/**
 * One-channel 16-bit signed image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16s_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed minimum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s * pMin);

/**
 * One-channel 32-bit floating point image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_32f_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed minimum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f * pMin);

/**
 * Three-channel 8-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_8u_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[3]);

/**
 * Three-channel 16-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16u_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[3]);

/**
 * Three-channel 16-bit signed image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16s_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[3]);

/**
 * Three-channel 32-bit floating point image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_32f_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[3]);

/**
 * Four-channel 8-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_8u_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[4]);

/**
 * Four-channel 16-bit unsigned image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16u_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMin_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[4]);

/**
 * Four-channel 16-bit signed image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16s_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMin_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[4]);

/**
 * Four-channel 32-bit floating point image min. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_32f_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMin_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[4]);

/**
 * Four-channel 8-bit unsigned image min ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_8u_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[3]);

/**
 * Four-channel 16-bit unsigned image min ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16u_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[3]);

/**
 * Four-channel 16-bit signed image min ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_16s_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[3]);

/**
 * Four-channel 32-bit floating point image min ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinGetBufferHostSize_32f_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the computed minimum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMin_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[3]);

/** @} Min */

/** @name MinGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the min primitives.
 * @{
 */

/**
 * Buffer size for \ref nppiMin_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMin_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** @} MinGetBufferHostSize */
/** @} image_min */

/** @defgroup image_min_index MinIndx
 * Primitives for computing the minimal value and its indices (X and Y coordinates) of an image.
 * @{
 */
/** @name MinIndx
 * If there are several minima in the selected ROI, the function returns one on the top leftmost position.
 * The scratch buffer is required by the functions.
 * @{
 */
/**
 * One-channel 8-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed min result.
 * \param pIndexX Pointer to the X coordinate of the image min value.
 * \param pIndexY Ppointer to the Y coordinate of the image min value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u * pMin, int * pIndexX, int * pIndexY);

/**
 * One-channel 16-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16u_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed min result.
 * \param pIndexX Pointer to the X coordinate of the image min value.
 * \param pIndexY Pointer to the Y coordinate of the image min value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u * pMin, int * pIndexX, int * pIndexY);

/**
 * One-channel 16-bit signed image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16s_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed min result.
 * \param pIndexX Pointer to the X coordinate of the image min value.
 * \param pIndexY Pointer to the Y coordinate of the image min value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s * pMin, int * pIndexX, int * pIndexY);

/**
 * One-channel 32-bit floating point image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_32f_C1R to determine the minium number of bytes required.
 * \param pMin Pointer to the computed min result.
 * \param pIndexX Pointer to the X coordinate of the image min value.
 * \param pIndexY Pointer to the Y coordinate of the image min value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f * pMin, int * pIndexX, int * pIndexY);

/**
 * Three-channel 8-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_8u_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 16-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16u_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 16-bit signed image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16s_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 32-bit floating point image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_32f_C3R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 8-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_8u_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 16-bit unsigned image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16u_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 16-bit signed image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16s_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 32-bit floating point image MinIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_32f_C4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 8-bit unsigned image MinIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_8u_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 16-bit unsigned image MinIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16u_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 16-bit signed image MinIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_16s_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMin[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 32-bit floating point image MinIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMinIndxGetBufferHostSize_32f_AC4R to determine the minium number of bytes required.
 * \param aMin Array that contains the min values.
 * \param aIndexX Array that contains the X coordinates of the image min values.
 * \param aIndexY Array that contains the Y coordinates of the image min values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinIndx_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMin[3], int aIndexX[3], int aIndexY[3]);

/** @} Min */

/** @name MinIndxGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the MinIndx primitives.
 * @{
 */
/**
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMinIndx_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinIndxGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** @} MinIndxGetBufferHostSize */
/** @} image_min_index */

/** @defgroup image_max Max
 * Primitives for computing the maximal pixel value of an image.
 * @{
 */

/** @name Max
 *  The scratch buffer is required by the functions.
 * @{
 */

/**
 * One-channel 8-bit unsigned image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_8u_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed maximum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u * pMax);

/**
 * One-channel 16-bit unsigned image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16u_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed maximum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u * pMax);

/**
 * One-channel 16-bit signed image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16s_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed maximum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s * pMax);

/**
 * One-channel 32-bit floating point image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_32f_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed maximum result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f * pMax);

/**
 * Three-channel 8-bit unsigned image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_8u_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[3]);

/**
 * Three-channel 16-bit unsigned image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16u_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[3]);

/**
 * Three-channel 16-bit signed image Max.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16s_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[3]);

/**
 * Three-channel 32-bit floating point image Max. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_32f_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[3]);

/**
 * Four-channel 8-bit unsigned image Max. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_8u_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[4]);

/**
 * Four-channel 16-bit unsigned image Max. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16u_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMax_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[4]);

/**
 * Four-channel 16-bit signed image Max. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16s_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMax_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[4]);

/**
 * Four-channel 32-bit floating point image Max. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_32f_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel.
 * \return \ref image_data_error_codes, \ref roi_error_codes
*/
NppStatus 
nppiMax_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[4]);

/**
 * Four-channel 8-bit unsigned image Max ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_8u_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[3]);

/**
 * Four-channel 16-bit unsigned image Max ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16u_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[3]);

/**
 * Four-channel 16-bit signed image Max ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_16s_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[3]);

/**
 * Four-channel 32-bit floating point image Max ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxGetBufferHostSize_32f_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the computed maximum results for each channel (alpha channel is not processed).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMax_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[3]);
/** @} */

/** @name MaxGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Max primitives.
 * @{
 */
/**
 * Buffer size for \ref nppiMax_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMax_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
/** @} MaxGetBufferHostSize */
/** @} image_max */

/** @defgroup image_max_index MaxIndx
 * Primitives for computing the maximal value and its indices (X and Y coordinates) of an image.
 * @{
 */
/** @name MaxIndx
 * If there are several maxima in the selected region of interest, the function returns one on the top leftmost position. 
 * The scratch buffer is required by the functions.
 * @{
 *
 */

/**
 * One-channel 8-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_8u_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed max result.
 * \param pIndexX Pointer to the X coordinate of the image max value.
 * \param pIndexY Ppointer to the Y coordinate of the image max value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u * pMax, int * pIndexX, int * pIndexY);

/**
 * One-channel 16-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16u_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed max result.
 * \param pIndexX Pointer to the X coordinate of the image max value.
 * \param pIndexY Pointer to the Y coordinate of the image max value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u * pMax, int * pIndexX, int * pIndexY);

/**
 * One-channel 16-bit signed image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16s_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed max result.
 * \param pIndexX Pointer to the X coordinate of the image max value.
 * \param pIndexY Pointer to the Y coordinate of the image max value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s * pMax, int * pIndexX, int * pIndexY);

/**
 * One-channel 32-bit floating point image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_32f_C1R to determaxe the maxium number of bytes required.
 * \param pMax Pointer to the computed max result.
 * \param pIndexX Pointer to the X coordinate of the image max value.
 * \param pIndexY Pointer to the Y coordinate of the image max value.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f * pMax, int * pIndexX, int * pIndexY);

/**
 * Three-channel 8-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_8u_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 16-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16u_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 16-bit signed image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16s_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Three-channel 32-bit floating point image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_32f_C3R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 8-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_8u_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 16-bit unsigned image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16u_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 16-bit signed image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16s_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 32-bit floating point image MaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_32f_C4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[4], int aIndexX[4], int aIndexY[4]);

/**
 * Four-channel 8-bit unsigned image MaxIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_8u_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp8u aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 16-bit unsigned image MaxIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16u_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16u aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 16-bit signed image MaxIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_16s_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp16s aMax[3], int aIndexX[3], int aIndexY[3]);

/**
 * Four-channel 32-bit floating point image MaxIndx ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMaxIndxGetBufferHostSize_32f_AC4R to determaxe the maxium number of bytes required.
 * \param aMax Array that contains the max values.
 * \param aIndexX Array that contains the X coordinates of the image max values.
 * \param aIndexY Array that contains the Y coordinates of the image max values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMaxIndx_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp32f aMax[3], int aIndexX[3], int aIndexY[3]);

/** @} */

/** @name MaxIndxGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the MaxIndx primitives.
 * @{
 */

/**
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Computes the dvice scratch buffer size (in bytes) for nppiMaxIndx_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMaxIndxGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
/** @} */
/** @} image_max_index */

/** @defgroup image_min_max MinMax
 * Primitives for computing both the minimal and the maximal values of an image.
 * @{
 */

/** @name MinMax
 * The functions require the device scratch buffer.
 * @{
 */
/**
 * One-channel 8-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMin Pointer to the computed minimal result.
 * \param pMax Pointer to the computed maximal result.
 * \param pDeviceBuffer Buffer to a scratch memory. 
 *        Use \ref nppiMinMaxGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pMin, Npp8u * pMax, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMin Pointer to the computed minimal result.
 * \param pMax Pointer to the computed maximal result.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16u_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16u * pMin, Npp16u * pMax, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMin Pointer to the computed minimal result.
 * \param pMax Pointer to the computed maximal result.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16s_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16s * pMin, Npp16s * pMax, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMin Pointer to the computed minimal result.
 * \param pMax Pointer to the computed maximal result.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_32f_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32f * pMin, Npp32f * pMax, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_8u_C3R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u aMin[3], Npp8u aMax[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16u_C3R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16u aMin[3], Npp16u aMax[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16s_C3R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16s aMin[3], Npp16s aMax[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_32f_C3R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32f aMin[3], Npp32f aMax[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image MinMax ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_8u_AC4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u aMin[3], Npp8u aMax[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image MinMax ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16u_AC4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16u aMin[3], Npp16u aMax[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image MinMax ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16s_AC4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16s aMin[3], Npp16s aMax[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image MinMax ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_32f_AC4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32f aMin[3], Npp32f aMax[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_8u_C4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u aMin[4], Npp8u aMax[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16u_C4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16u aMin[4], Npp16u aMax[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_16s_C4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16s aMin[4], Npp16s aMax[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image MinMax.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aMin Array that contains the minima.
 * \param aMax Array that contains the maxima.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxGetBufferHostSize_32f_C4R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMinMax_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32f aMin[4], Npp32f aMax[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name MinMaxGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the MinMax primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiMinMax_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
*/
NppStatus
nppiMinMaxGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMax_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus
nppiMinMaxGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
/** @} */
/** @} image_min_max */

/** @defgroup image_min_max_index MinMaxIndx
 * Primitives for computing the minimal and the maximal values with their indices (X and Y coordinates) of an image.
 * @{
 */

/** @name MinMaxIndx
 * If there are several minima and maxima in the selected region of interest, the function returns ones on the top leftmost position.
 * The scratch buffer is required by the functions.
 * @{
 */

/**
 * Computes the minimal and the maximal pixel values with their X and Y coordinates of 1-channel 8-bit unsigned char image. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8u_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pMinValue, Npp8u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Computes the minimal and the maximal pixel values with their X and Y coordinates of 1-channel 8-bit signed char image. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8s_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8s_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8s * pMinValue, Npp8s * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Computes the minimal and the maximal pixel values with their X and Y coordinates of 1-channel 16-bit unsigned short image. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_16u_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp16u * pMinValue, Npp16u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Computes the minimal and the maximal pixel values with their X and Y coordinates of 1-channel 32-bit floating point image. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_32f_C1R to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32f * pMinValue, Npp32f * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked MinMaxIndx
 * See \ref masked_operation.
 * @{
 */

/**
 * Masked one-channel 8-bit unsigned image MinMaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8u_C1MR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pMinValue, Npp8u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image MinMaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8s_C1MR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8s * pMinValue, Npp8s * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image MinMaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_16u_C1MR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes. 
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp16u * pMinValue, Npp16u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image MinMaxIndx.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_32f_C1MR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified.
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp32f * pMinValue, Npp32f * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);
/** @} */

/** @name Channel MinMaxIndx
 * See \ref channel_of_interest.
 * @{
 */

/**
 * Three-channel 8-bit unsigned image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8u_C3CR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8u_C3CR(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8u * pMinValue, Npp8u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit signed image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8s_C3CR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8s_C3CR(const Npp8s * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8s * pMinValue, Npp8s * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_16u_C3CR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_16u_C3CR(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp16u * pMinValue, Npp16u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_32f_C3CR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_32f_C3CR(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp32f * pMinValue, Npp32f * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Channel MinMaxIndx
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */

/**
 * Masked three-channel 8-bit unsigned image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8u_C3CMR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pMinValue, Npp8u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_8s_C3CMR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8s * pMinValue, Npp8s * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_16u_C3CMR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp16u * pMinValue, Npp16u * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image MinMaxIndx affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pMinValue Pointer to the minimum value.
 * \param pMaxValue Pointer to the maximum value.
 * \param pMinIndex Pointer to the indicies (X and Y coordinates) of the minimum value.
 * \param pMaxIndex Pointer to the indicies (X and Y coordinates) of the maximum value.
 * \param pDeviceBuffer Buffer to a scratch memory. Use \ref nppiMinMaxIndxGetBufferHostSize_32f_C3CMR to determine
 *          the minium number of bytes required.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 * If the mask is filled with zeros, then all the returned values are zeros, i.e., pMinIndex = {0, 0}, pMaxIndex = {0, 0},
 * pMinValue = 0, pMaxValue = 0.
 * If any of pMinValue, pMaxValue, pMinIndex, or pMaxIndex is not needed, zero pointer must be passed correspondingly.
 */
NppStatus 
nppiMinMaxIndx_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp32f * pMinValue, Npp32f * pMaxValue, NppiPoint * pMinIndex, NppiPoint * pMaxIndex, Npp8u * pDeviceBuffer);
/** @} */

/** @name MinMaxIndxGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the MinMaxIndx primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiMinMaxIndx_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
*/
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8u_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8u_C3CR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8s_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8s_C3CR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_16u_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_16u_C3CR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_32f_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_32f_C3CR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMinMaxIndx_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMinMaxIndxGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
/** @} */
/** @} image_min_max_index */

/** @defgroup image_mean Mean
 * Primitives for computing the arithmetic mean of all the pixel values in an image.
 * @{
 */

/** @name Mean
 * Given an image \f$pSrc\f$ with width \f$W\f$ and height \f$H\f$, the arithmetic mean
 * will be computed as
 * \f[Mean = \frac{1}{W\cdot H}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}pSrc(j,i)\f]
 * The mean functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * One-channel 16-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * One-channel 16-bit signed image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16s_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * One-channel 32-bit floating point image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus 
nppiMean_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Three-channel 8-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_C3R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Three-channel 16-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_C3R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Three-channel 16-bit signed image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16s_C3R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Three-channel 32-bit floating point image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_C3R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus 
nppiMean_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Four-channel 8-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_C4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[4]);

/**
 * Four-channel 16-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_C4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[4]);

/**
 * Four-channel 16-bit signed image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16s_C4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[4]);

/**
 * Four-channel 32-bit floating point image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_C4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus 
nppiMean_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[4]);

/**
 * Four-channel 8-bit unsigned image Mean ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_AC4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Four-channel 16-bit unsigned image Mean ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_AC4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Four-channel 16-bit signed image Mean ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16s_AC4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiMean_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/**
 * Four-channel 32-bit floating point image Mean ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_AC4R to determine the minium number of bytes required.
 * \param aMean Array that contains the computed mean results.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus 
nppiMean_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f aMean[3]);

/** @} */

/** @name Masked Mean
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiMean_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked one-channel 8-bit signed image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8s_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiMean_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked one-channel 16-bit unsigned image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiMean_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked one-channel 32-bit floating point image Mean.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus 
nppiMean_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean);
/** @} */

/** @name Masked Channel Mean
 * See \ref channel_of_interest and \ref masked_operation.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image Mean affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8u_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus 
nppiMean_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked three-channel 8-bit signed image Mean affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_8s_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus 
nppiMean_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked three-channel 16-bit unsigned image Mean affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_16u_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus 
nppiMean_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean);

/**
 * Masked three-channel 32-bit floating point image Mean affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanGetBufferHostSize_32f_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean result.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus 
nppiMean_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean);
/** @} */

/** @name MeanGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Mean primitives.
 * @{
 */
/**
 * Buffer size for \ref nppiMean_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/**
 * Buffer size for \ref nppiMean_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
*/
NppStatus 
nppiMeanGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/**
 * Buffer size for \ref nppiMean_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
*/
NppStatus 
nppiMeanGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
 
/** 
 * Buffer size for \ref nppiMean_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);

/** 
 * Buffer size for \ref nppiMean_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize /* host pointer */);
/** @} */
/** @} image_mean */

/** @defgroup image_mean_stddev Mean_StdDev
 * Primitives for computing both the arithmetic mean and the standard deviation of an image.
 * @{
 */

/** @name Mean_StdDev
 * Given an image \f$pSrc\f$ with width \f$W\f$ and height \f$H\f$, the mean and the standard deviation
 * will be computed as
 * \f[Mean = \frac{1}{W\cdot H}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}pSrc(j,i)\f]
 * \f[StdDev = \sqrt{\frac{1}{W\cdot H}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}(pSrc(j,i)-Mean)^2}\f]
 * The Mean_StdDev primitives require additional scratch buffer for computations.
 * @{
 */

/**
 * One-channel 8-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8u_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * One-channel 8-bit signed image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8s_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_8s_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * One-channel 16-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_16u_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * One-channel 32-bit floating point image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_32f_C1R to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus nppiMean_StdDev_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );
/** @} */

/** @name Masked Mean_StdDev
 * See \ref masked_operation.
 * @{
 */

/**
 * Masked one-channel 8-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8u_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked one-channel 8-bit signed image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8s_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked one-channel 16-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_16u_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiMean_StdDev_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked one-channel 32-bit floating point image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_32f_C1MR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified.
 */
NppStatus nppiMean_StdDev_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );
/** @} */

 /** @name Channel Mean_StdDev
 * See \ref channel_of_interest.
 * @{
 */
 
/**
 * Three-channel 8-bit unsigned image Mean_StdDev affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8u_C3CR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_8u_C3CR(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Three-channel 8-bit signed image Mean_StdDev affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8s_C3CR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_8s_C3CR(const Npp8s * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Three-channel 16-bit unsigned image Mean_StdDev affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_16u_C3CR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_16u_C3CR(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Three-channel 32-bit floating point image Mean_StdDev affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_32f_C3CR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_32f_C3CR(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );
 /** @} */
 
 /** @name Masked Channel Mean_StdDev
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */

/**
 * Masked three-channel 8-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8u_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked three-channel 8-bit signed image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_8s_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked three-channel 16-bit unsigned image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_16u_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );

/**
 * Masked three-channel 32-bit floating point image Mean_StdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer
 *        Use \ref nppiMeanStdDevGetBufferHostSize_32f_C3CMR to determine the minium number of bytes required.
 * \param pMean Pointer to the computed mean.
 * \param pStdDev Pointer to the computed standard deviation.
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiMean_StdDev_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp8u * pDeviceBuffer, Npp64f * pMean, Npp64f * pStdDev );
/** @} */

/** @name MeanStdDevGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Mean_StdDev primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiMean_StdDev_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8u_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8u_C3CR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8s_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8s_C3CR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_16u_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_16u_C3CR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_32f_C3CR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_32f_C3CR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiMean_StdDev_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiMeanStdDevGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_mean_stddev */

/** @defgroup image_norm Image Norms
 *
 * Primitives for computing the norms of an image, the norms of difference, and the relative errors of two images.
 * Given an image \f$pSrc\f$ with width \f$W\f$ and height \f$H\f$, 
 * -# The infinity norm (Norm_Inf) is defined as the largest absolute pixel value of the image.
 * -# The L1 norm (Norm_L1) is defined as the sum of the absolute pixel value of the image, i.e., \f[Norm\_L1 = \sum_{j=0}^{H-1}\sum_{i=0}^{W-1}\left| pSrc(j,i)\right|\f].
 * -# The L2 norm (Norm_L2) is defined as the square root of the sum of the squared absolute pixel value of the image, i.e.,\f[Norm\_L2 = \sqrt{\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}\left| pSrc(j,i)\right| ^2}\f].
 * 
 * Given two images \f$pSrc1\f$ and \f$pSrc2\f$ both with width \f$W\f$ and height \f$H\f$, 
 * -# The infinity norm of differece (NormDiff_Inf) is defined as the largest absolute difference between pixels of two images.
 * -# The L1 norm of differece (NormDiff_L1) is defined as the sum of the absolute difference between pixels of two images, i.e., \f[NormDiff\_L1 = \sum_{j=0}^{H-1}\sum_{i=0}^{W-1}\left| pSrc1(j,i)-pSrc2(j,i)\right|\f].
 * -# The L2 norm of differece (NormDiff_L2) is defined as the squared root of the sum of the squared absolute difference between pixels of two images, i.e.,\f[NormDiff\_L2 = \sqrt{\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}\left| pSrc1(j,i)-pSrc2(j,i)\right| ^2}\f].
 * 
 * Given two images \f$pSrc1\f$ and \f$pSrc2\f$ both with width \f$W\f$ and height \f$H\f$, 
 * -# The relative error for the infinity norm of differece (NormRel_Inf) is defined as NormDiff_Inf divided by the infinity norm of the second image, i.e., \f[NormRel\_Inf = \frac{NormDiff\_Inf}{Norm\_Inf_{src2}}\f]
 * -# The relative error for the L1 norm of differece (NormRel_L1) is defined as NormDiff_L1 divided by the L1 norm of the second image, i.e., \f[NormRel\_L1 = \frac{NormDiff\_L1}{Norm\_L1_{src2}}\f]
 * -# The relative error for the L2 norm of differece (NormRel_L2) is defined as NormDiff_L2 divided by the L2 norm of the second image, i.e., \f[NormRel\_L2 = \frac{NormDiff\_L2}{Norm\_L2_{src2}}\f]
 * .
 * The norm functions require the addition device scratch buffer for the computations.
 * 
 * @{
 *
 */ 

/** @defgroup image_inf_norm Norm_Inf
 * Primitives for computing the infinity norm of an image. 
 * @{
 */

/** @name Basic Norm_Inf
 * @{
 */

/**
 * One-channel 8-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit signed image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32s_C1R(const Npp32s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_Inf ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_Inf ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_Inf ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_Inf ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Norm_Inf
 * See \ref masked_operation.
 * @{
 */

/**
 * Masked one-channel 8-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image Norm_Inf.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_Inf_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Channel Norm_Inf
 * See \ref channel_of_interest and \ref masked_operation.
 * @{
 */

/**
 * Masked three-channel 8-bit unsigned image Norm_Inf affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_Inf_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image Norm_Inf affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_Inf_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image Norm_Inf affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_Inf_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image Norm_Inf affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormInfGetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an invalid 
 * floating-point image is specified, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_Inf_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
/** @} */

/** @name NormInfGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Norm_Inf primitives.
 * @{
 */

/** Buffer size for \ref nppiNorm_Inf_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_Inf_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormInfGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_inf_norm */


/** @defgroup image_L1_norm Norm_L1
 * Primitives for computing the L1 norm of an image. 
 * @{
 */
/** @name Basic Norm_L1
 * @{
 */ 
/**
 * One-channel 8-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_L1 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_L1 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_L1 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_L1 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Norm_L1
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image Norm_L1.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L1_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Channel Norm_L1
 * See \ref channel_of_interest and \ref masked_operation.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image Norm_L1 affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L1_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image Norm_L1 affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L1_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image Norm_L1 affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L1_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image Norm_L1 affecting only single channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL1GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if the step of 
 * the source image cannot be divided by 4, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L1_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
 /** @} */
 
 /** @name NormL1GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Norm_L1 primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiNorm_L1_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L1_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL1GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @}  */
/** @} image_L1_norm */

/** @defgroup image_L2_norm Norm_L2
 * Primitives for computing the L2 norm of an image. 
 * @{
 */
/** @name Basic Norm_L2
 * Computes the L2 norm of an image. 
 * @{
 */
/**
 * One-channel 8-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_L2 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_L2 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_L2 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_L2 ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Three-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNorm Array that contains the norm values of Four-channels.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiNormL2GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp64f aNorm[4], Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Norm_L2
 * See \ref masked_operation.
 * @{
 */
 
/**
 * Masked one-channel 8-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8u_C1MR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_8s_C1MR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus nppiNorm_L2_16u_C1MR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if the step 
 * of the source image cannot be divided by 4. 
 */
NppStatus nppiNorm_L2_32f_C1MR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Channel Norm_L2
 * See \ref channel_of_interest and \ref masked_operation.
 * @{
 */
 /**
 * Masked three-channel 8-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiNormL2GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L2_8u_C3CMR(const Npp8u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiNormL2GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L2_8s_C3CMR(const Npp8s * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 *        Use \ref nppiNormL2GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L2_16u_C3CMR(const Npp16u * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image Norm_L2.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNorm Pointer to the norm value.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormL2GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if the step 
 * of the source image cannot be divided by 4, or NPP_COI_ERROR if an invalid channel of interest is specified.
 */
NppStatus nppiNorm_L2_32f_C3CMR(const Npp32f * pSrc, int nSrcStep, const Npp8u * pMask, int nMaskStep, NppiSize oSizeROI, int nCOI, Npp64f * pNorm, Npp8u * pDeviceBuffer);
/** @} */

/** @name NormL2GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Norm_L2 primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiNorm_L2_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNorm_L2_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormL2GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_L2_norm */

/** @defgroup image_inf_normdiff NormDiff_Inf
 * Primitives for computing the infinity norm of difference of pixels between two images.
 * @{
 */

/** @name Basic NormDiff_Inf
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                    const Npp16s * pSrc2, int nSrc2Step, 
                                    NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                    const Npp32f * pSrc2, int nSrc2Step, 
                                    NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name Masked NormDiff_Inf
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned images NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed images NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned images NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_Inf_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point images NormDiff_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                    const Npp32f * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
/** @} */
 
/** @name Masked Channel Mean
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image NormDiff_Inf affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_Inf_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                    const Npp8u * pSrc2, int nSrc2Step, 
                                    const Npp8u * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormDiff_Inf affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_Inf_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormDiff_Inf affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_Inf_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                     const Npp16u * pSrc2, int nSrc2Step, 
                                     const Npp8u  * pMask, int nMaskStep,
                                     NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormDiff_Inf affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffInfGetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel 
 * of interest is specified, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_Inf_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                     const Npp32f * pSrc2, int nSrc2Step, 
                                     const Npp8u  * pMask, int nMaskStep,
                                     NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
/** @} */
 
/** @name NormDiffInfGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormDiff_Inf primitives.
 * @{
 */
/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size for \ref nppiNormDiff_Inf_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffInfGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_inf_normdiff */

/** @defgroup image_L1_normdiff NormDiff_L1
 * Primitives for computing the L1 norm of difference of pixels between two images.
 * @{
 */

/** @name Basic NormDiff_L1
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked NormDiff_L1
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image NormDiff_L1.
 * 
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                  const Npp8s * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L1_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image NormDiff_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
 /** @} */
 
 /** @name Masked Channel NormDiff_L1
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */

/**
 * Masked three-channel 8-bit unsigned image NormDiff_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L1_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormDiff_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L1_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormDiff_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L1_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormDiff_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL1GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel 
 * of interest is specified, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L1_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                    const Npp32f * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
 /** @} */
 
 /** @name NormDiffL1GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormDiff_L1 primitives.
 * @{
 */
/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L1_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL1GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_L1_normdiff */

/** @defgroup image_L2_normdiff NormDiff_L2
 * Primitives for computing the L2 norm of difference of pixels between two images.
 * @{
 */
/** @name Basic NormDiff_L2
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormDiff[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormDiff Array that contains computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormDiff[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name Masked NormDiff_L2
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                  const Npp8s * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiNormDiff_L2_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image NormDiff_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
/** @} */
 
/** @name Masked Channel NormDiff_L2
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image NormDiff_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L2_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormDiff_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L2_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormDiff_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel of interest is specified.
*/
NppStatus nppiNormDiff_L2_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormDiff_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormDiff Pointer to the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormDiffL2GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel 
 * of interest is specified, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified.
*/
NppStatus nppiNormDiff_L2_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                    const Npp32f * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormDiff, Npp8u * pDeviceBuffer);
/** @} */

/** @name NormDiffL2GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormDiff_L2 primitives.
 * @{
 */
/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormDiff_L2_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormDiffL2GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */); 
/** @} */
/** @} image_L2_normdiff */

/** @defgroup image_inf_normrel NormRel_Inf
 * Primitives for computing the relative error of infinity norm between two images.
 * @{
 */
/** @name Basic NormRel_Inf
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormRel_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_Inf ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name Masked NormRel_Inf
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                  const Npp8s * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image NormRel_Inf.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);
 
/** @} */

/** @name Masked Channel NormRel_Inf
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image NormRel_Inf affecting only signle channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an 
 * invalid channel of interest is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormRel_Inf affecting only signle channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormRel_Inf affecting only signle channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the infinity
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormRel_Inf affecting only signle channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the infinity norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelInfGetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an invalid channel 
 * of interest is specified, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point 
 * image is specified, or NPP_DIVISOR_ERROR if the infinity norm of the second image is zero.
*/
NppStatus nppiNormRel_Inf_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                    const Npp32f * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);
/** @} */

/** @name NormRelInfGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormRel_Inf primitives.
 * @{
 */
/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_Inf_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelInfGetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */

/** @} image_inf_normrel */

/** @defgroup image_L1_normrel NormRel_L1
 * Primitives for computing the relative error of L1 norm between two images.
 * @{
 */

/** @name Basic NormRel_L1
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image NormRel_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_L1 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name Masked NormRel_L1
 * See \ref masked_operation.
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 const Npp8u * pMask, int nMaskStep,
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit signed image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                 const Npp8s * pSrc2, int nSrc2Step, 
                                 const Npp8u * pMask, int nMaskStep,
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  const Npp8u  * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormRel_L1.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L1
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  const Npp8u  * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);
/** @} */

/** @name Masked Channel NormRel_L1
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image NormRel_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the L1 norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormRel_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the L1 norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormRel_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the L1 norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormRel_L1 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L1 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL1GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid channel 
 * of interest is specified, NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified, 
 * or NPP_DIVISOR_ERROR if the L1 norm of the second image is zero.
*/
NppStatus nppiNormRel_L1_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);
/** @} */

/** @name NormRelL1GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormRel_L1 primitives.
 * @{
 */
/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L1_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL1GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */

/** @} image_L1_normrel */

/** @defgroup image_L2_normrel NormRel_L2
 * Primitives for computing the relative error of L2 norm between two images.
 * @{
 */

/** @name Basic NormRel_L2
 * @{
 */
/**
 * One-channel 8-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16s_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16s_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if an 
 * invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16s_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16s_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormRel_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16s_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16s_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                   const Npp16s * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_L2 ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   NppiSize oSizeROI, Npp64f aNormRel[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                 const Npp8u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                  const Npp16u * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16s_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16s_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                  const Npp16s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aNormRel Array that contains the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aNormRel[4], Npp8u * pDeviceBuffer);

/** @} */

/** @name Masked NormRel_L2
 * See \ref masked_operation.
 * @{
 */
/**
 * Masked one-channel 8-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_C1MR(const Npp8u * pSrc1, int nSrc1Step, 
                                  const Npp8u * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 8-bit signed image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8s_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8s_C1MR(const Npp8s * pSrc1, int nSrc1Step, 
                                  const Npp8s * pSrc2, int nSrc2Step, 
                                  const Npp8u * pMask, int nMaskStep,
                                  NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 16-bit unsigned image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_C1MR(const Npp16u * pSrc1, int nSrc1Step, 
                                   const Npp16u * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked one-channel 32-bit floating point image NormRel_L2.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_C1MR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_NOT_EVEN_STEP_ERROR if 
 * an invalid floating-point image is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_C1MR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, Npp64f * pNormRel, Npp8u * pDeviceBuffer); 
 
 /** @} */

 /** @name Masked Channel NormRel_L2
 * See \ref masked_operation and \ref channel_of_interest.
 * @{
 */
/**
 * Masked three-channel 8-bit unsigned image NormRel_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the L2 norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8u_C3CMR(const Npp8u * pSrc1, int nSrc1Step, 
                                   const Npp8u * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 8-bit signed image NormRel_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_8s_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_COI_ERROR if an invalid 
 * channel of interest is specified, or NPP_DIVISOR_ERROR if the L2 norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_8s_C3CMR(const Npp8s * pSrc1, int nSrc1Step, 
                                   const Npp8s * pSrc2, int nSrc2Step, 
                                   const Npp8u * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 16-bit unsigned image NormRel_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_16u_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an 
 * invalid channel of interest is specified, or NPP_DIVISOR_ERROR if the L2
 * norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_16u_C3CMR(const Npp16u * pSrc1, int nSrc1Step, 
                                    const Npp16u * pSrc2, int nSrc2Step, 
                                    const Npp8u  * pMask, int nMaskStep,
                                    NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

/**
 * Masked three-channel 32-bit floating point image NormRel_L2 affecting only single channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param pMask \ref mask_image_pointer.
 * \param nMaskStep \ref mask_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nCOI \ref channel_of_interest_number.
 * \param pNormRel Pointer to the computed relative error for the L2 norm of two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiNormRelL2GetBufferHostSize_32f_C3CMR to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, NPP_COI_ERROR if an invalid channel 
 * of interest is specified, or NPP_NOT_EVEN_STEP_ERROR if an invalid floating-point image is specified, 
 * or NPP_DIVISOR_ERROR if the L2 norm of the second image is zero.
*/
NppStatus nppiNormRel_L2_32f_C3CMR(const Npp32f * pSrc1, int nSrc1Step, 
                                   const Npp32f * pSrc2, int nSrc2Step, 
                                   const Npp8u  * pMask, int nMaskStep,
                                   NppiSize oSizeROI, int nCOI, Npp64f * pNormRel, Npp8u * pDeviceBuffer);

 /** @} */

/** @name NormRelL2GetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the NormRel_L2 primitives.
 * @{
 */
/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16s_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16s_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8s_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8s_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_C1MR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_C1MR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16s_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16s_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16s_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16s_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16s_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16s_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_8s_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_8s_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_16u_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_16u_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Computes the device scratch buffer size (in bytes) for nppiNormRel_L2_32f_C3CMR.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiNormRelL2GetBufferHostSize_32f_C3CMR(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_L2_normrel */
/** @} image_norm */

/** @defgroup image_dot_prod DotProd
 * Primitives for computing the dot product of two images.
 * @{
 *
 */

/** @name DotProd
 * Given two images \f$pSrc1\f$ and \f$pSrc2\f$ both with width \f$W\f$ and height \f$H\f$, 
 * the dot product will be computed as
 * \f[DotProd = \sum_{j=0}^{H-1}\sum_{i=0}^{W-1}[pSrc1(j,i)\cdot pSrc2(j,i)]\f]
 * The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8u64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8u64f_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8s64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8s64f_C1R(const Npp8s * pSrc1, int nSrc1Step, 
                                const Npp8s * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16u64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16u64f_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16s64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16s64f_C1R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32u64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32u64f_C1R(const Npp32u * pSrc1, int nSrc1Step, 
                                 const Npp32u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32s64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32s64f_C1R(const Npp32s * pSrc1, int nSrc1Step, 
                                 const Npp32s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pDp Pointer to the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32f64f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32f64f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f * pDp, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8u64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8u64f_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8s64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8s64f_C3R(const Npp8s * pSrc1, int nSrc1Step, 
                                const Npp8s * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16u64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16u64f_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16s64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16s64f_C3R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32u64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32u64f_C3R(const Npp32u * pSrc1, int nSrc1Step, 
                                 const Npp32u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32s64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32s64f_C3R(const Npp32s * pSrc1, int nSrc1Step, 
                                 const Npp32s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32f64f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32f64f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8u64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8u64f_C4R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8s64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8s64f_C4R(const Npp8s * pSrc1, int nSrc1Step, 
                                const Npp8s * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16u64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16u64f_C4R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16s64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16s64f_C4R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit unsigned image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32u64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32u64f_C4R(const Npp32u * pSrc1, int nSrc1Step, 
                                 const Npp32u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit signed image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32s64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32s64f_C4R(const Npp32s * pSrc1, int nSrc1Step, 
                                 const Npp32s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image DotProd.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32f64f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32f64f_C4R(const Npp32f * pSrc1, int nSrc1Step, 
                                 const Npp32f * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[4], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8u64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8u64f_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                                const Npp8u * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_8s64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_8s64f_AC4R(const Npp8s * pSrc1, int nSrc1Step, 
                                const Npp8s * pSrc2, int nSrc2Step, 
                                NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed Inf-norm of differences. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16u64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16u64f_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                                 const Npp16u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit signed image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_16s64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_16s64f_AC4R(const Npp16s * pSrc1, int nSrc1Step, 
                                 const Npp16s * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit unsigned image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32u64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32u64f_AC4R(const Npp32u * pSrc1, int nSrc1Step, 
                                 const Npp32u * pSrc2, int nSrc2Step, 
                                 NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit signed image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32s64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32s64f_AC4R(const Npp32s * pSrc1, int nSrc1Step, 
                                  const Npp32s * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image DotProd ignoring alpha channel.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aDp Array that contains the computed dot product of the two images. 
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiDotProdGetBufferHostSize_32f64f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiDotProd_32f64f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                                  const Npp32f * pSrc2, int nSrc2Step, 
                                  NppiSize oSizeROI, Npp64f aDp[3], Npp8u * pDeviceBuffer);
/** @} */

/** @name DotProdGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the Mean_StdDev primitives.
 * @{
 */ 
/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8u64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8u64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8s64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8s64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16u64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16u64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16s64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16s64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32u64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32u64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32s64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32s64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32f64f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32f64f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8u64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8u64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8s64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8s64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16u64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16u64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16s64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16s64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32u64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32u64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32s64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32s64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32f64f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32f64f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8u64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8u64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8s64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8s64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16u64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16u64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16s64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16s64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32u64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32u64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32s64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32s64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32f64f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32f64f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8u64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8u64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_8s64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_8s64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16u64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16u64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_16s64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_16s64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32u64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32u64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32s64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32s64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiDotProd_32f64f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiDotProdGetBufferHostSize_32f64f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_dot_prod */

/** @defgroup image_count_in_range CountInRange.
 * Primitives for computing the amount of pixels that fall into the specified intensity range.
 * @{
 *
 */

/** @name CountInRange
 * The lower bound and the upper bound are inclusive. The functions require additional
 * scratch buffer for computations. 
 * @{
 *
 */

/**
 * One-channel 8-bit unsigned image CountInRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pCounts Pointer to the number of pixels that fall into the specified range.
 * \param nLowerBound Lower bound of the specified range.
 * \param nUpperBound Upper bound of the specified range.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_8u_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                  int * pCounts, Npp8u nLowerBound, Npp8u nUpperBound, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image CountInRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pCounts Pointer to the number of pixels that fall into the specified range.
 * \param nLowerBound Lower bound of the specified range.
 * \param nUpperBound Upper bound of the specified range.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                   int * pCounts, Npp32f nLowerBound, Npp32f nUpperBound, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CountInRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aCounts Array that contains the number of pixels that fall into the specified range for Three-channels.
 * \param aLowerBound Fixed size array of the lower bound of the specified range, one per channel.
 * \param aUpperBound Fixed size array of the upper bound of the specified range, one per channel.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_8u_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                  int aCounts[3], Npp8u aLowerBound[3], Npp8u aUpperBound[3], Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image CountInRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aCounts Array that contains the number of pixels that fall into the specified range for Three-channels.
 * \param aLowerBound Fixed size array of the lower bound of the specified range, one per channel.
 * \param aUpperBound Fixed size array of the upper bound of the specified range, one per channel.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                   int aCounts[3], Npp32f aLowerBound[3], Npp32f aUpperBound[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CountInRange ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aCounts Array that contains the number of pixels that fall into the specified range for Three-channels.
 * \param aLowerBound Fixed size array of the lower bound of the specified range, one per channel.
 * \param aUpperBound Fixed size array of the upper bound of the specified range, one per channel.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_8u_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                   int aCounts[3], Npp8u aLowerBound[3], Npp8u aUpperBound[3], Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CountInRange ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param aCounts Array that contains the number of pixels that fall into the specified range for Three-channels.
 * \param aLowerBound Fixed size array of the lower bound of the specified range, one per channel.
 * \param aUpperBound Fixed size array of the upper bound of the specified range, one per channel.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiCountInRangeGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_RANGE_ERROR if the lower bound
 * is larger than the upper bound.
*/
NppStatus nppiCountInRange_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                    int aCounts[3], Npp32f aLowerBound[3], Npp32f aUpperBound[3], Npp8u * pDeviceBuffer);
/** @} */
 
 /** @name CountInRangeGetBufferHostSize
 * Companion primitives for computing the device buffer size (in bytes) required by the CountInRange primitives.
 * @{
 */

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_8u_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_8u_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_8u_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_8u_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_8u_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_8u_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Device scratch buffer size (in bytes) for nppiCountInRange_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiCountInRangeGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} image_count_in_range */

/** @defgroup image_maxevery MaxEvery
 * Primitives for computing the maximal value of the pixel pair from two images.
 * @{
 *
 */

/** @name MaxEvery
 * The maximum is stored into the second image.
 * @{
 *
 */
/**
 * One-channel 8-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_8u_C1IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 16-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16u_C1IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 16-bit signed image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16s_C1IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 32-bit floating point image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_32f_C1IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 8-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_8u_C3IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 16-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16u_C3IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 16-bit signed image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16s_C3IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 32-bit floating point image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_32f_C3IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 8-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_8u_C4IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit unsigned image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16u_C4IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit signed image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16s_C4IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 32-bit floating point image MaxEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_32f_C4IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 8-bit unsigned image MaxEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_8u_AC4IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit unsigned image MaxEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16u_AC4IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit signed image MaxEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_16s_AC4IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 32-bit floating point image MaxEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMaxEvery_32f_AC4IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);
/** @} */
/** @} image_maxevery*/

/** @defgroup image_minevery MinEvery
 * Primitives for computing the minimal value of the pixel pair from two images.
 * @{
 *
 */

/** @name MinEvery
 * The minimum is stored into the second image.
 * @{
 *
 */
/**
 * One-channel 8-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_8u_C1IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 16-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16u_C1IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 16-bit signed image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16s_C1IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * One-channel 32-bit floating point image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_32f_C1IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 8-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_8u_C3IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 16-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16u_C3IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 16-bit signed image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16s_C3IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Three-channel 32-bit floating point image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_32f_C3IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 8-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_8u_C4IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit unsigned image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16u_C4IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit signed image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16s_C4IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 32-bit floating point image MinEvery.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_32f_C4IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 8-bit unsigned image MinEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_8u_AC4IR(const Npp8u * pSrc, int nSrcStep, Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit unsigned image MinEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16u_AC4IR(const Npp16u * pSrc, int nSrcStep, Npp16u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 16-bit signed image MinEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_16s_AC4IR(const Npp16s * pSrc, int nSrcStep, Npp16s * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * Four-channel 32-bit floating point image MinEvery ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSrcDst \ref in_place_image_pointer.
 * \param nSrcDstStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
*/
NppStatus nppiMinEvery_32f_AC4IR(const Npp32f * pSrc, int nSrcStep, Npp32f * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);
/** @} */
/** @} image_minevery */

/** @defgroup image_integral Integral
 * Primitives for computing the integral image of a given image.
 * @{
 *
 */
                                  
/** @name Integral
 * Given an input image \f$pSrc\f$ and the specified value \f$nVal\f$, 
 * the pixel value of the integral image \f$pDst\f$ at coordinate 
 * (i, j) will be computed as
 * \f[pDst(j,i) = nVal + \sum_{l=0}^{j-1}\sum_{k=0}^{i-1}pSrc(l,k)\f]
 * If the size of the input image is \f$W \times H\f$, the size of 
 * the integral image will be \f$(W+1) \times (H+1)\f$.
 */

/**
 * One-channel 8-bit unsigned image Integral with 32-bit signed output.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oROI \ref roi_specification.
 * \param nVal The value to add to pDst image pixels
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiIntegral_8u32s_C1R(const Npp8u  * pSrc, int nSrcStep, 
                             Npp32s * pDst, int nDstStep, 
                             NppiSize oROI, Npp32s nVal);

/**
 * One-channel 8-bit unsigned image Integral with 32-bit floating point output.
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oROI \ref roi_specification.
 * \param nVal The value to add to pDst image pixels
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiIntegral_8u32f_C1R(const Npp8u  * pSrc, int nSrcStep, 
                             Npp32f * pDst, int nDstStep, 
                             NppiSize oROI, Npp32f nVal);

/** @} */
/** @} Integral */

/** @defgroup image_sqrintegral SqrIntegral
 * Primitives for computing both the integral and the squared integral images of a given image.
 * @{
 *
 */

/** @name SqrIntegral
 *
 * Given an input image \f$pSrc\f$ and the specified value \f$nVal\f$, 
 * the pixel value of the integral image \f$pDst\f$ at coordinate 
 * (i, j) will be computed as
 * \f[pDst(j,i) = nVal + \sum_{l=0}^{j-1}\sum_{k=0}^{i-1}pSrc(l,k)\f]
 * Given an input image \f$pSrc\f$ and the specified value \f$nValSqr\f$, 
 * the pixel value of the squared integral image \f$pSqr\f$ at coordinate 
 * (i, j) will be computed as
 * \f[pSqr(j,i) = nValSqr + \sum_{l=0}^{j-1}\sum_{k=0}^{i-1}{pSrc(l,k)}^2\f]
 * If the size of the input image is \f$W \times H\f$, the size of 
 * the squared integral image will be \f$(W+1) \times (H+1)\f$.
 */

 /**
 * One-channel 8-bit unsigned image SqrIntegral. 
 * Destination integral image and square integral image are 32-bit signed int.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param oSrcROI \ref roi_specification.
 * \param nVal The value to add to pDst image pixels
 * \param nValSqr The value to add to pSqr image pixels
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSqrIntegral_8u32s_C1R(const Npp8u  * pSrc, int nSrcStep, 
                                Npp32s * pDst, int nDstStep, 
                                Npp32s * pSqr, int nSqrStep,
                                NppiSize oSrcROI, Npp32s nVal, Npp32s nValSqr);

/**
 * One-channel 8-bit unsigned image SqrIntegral. 
 * Destination integral image is 32-bit signed int. 
 * Destination square integral image is 64-bit double floating point.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param oSrcROI \ref roi_specification.
 * \param nVal The value to add to pDst image pixels
 * \param nValSqr The value to add to pSqr image pixels
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSqrIntegral_8u32s64f_C1R(const Npp8u  * pSrc, int nSrcStep, 
                                   Npp32s * pDst, int nDstStep, 
                                   Npp64f * pSqr, int nSqrStep,
                                   NppiSize oSrcROI, Npp32s nVal, Npp64f nValSqr);

/**
 * One-channel 8-bit unsigned image SqrIntegral. 
 * Destination integral image is 32-bit floating point.
 * Destination square integral image is 64-bit double floating point.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param oSrcROI \ref roi_specification.
 * \param nVal The value to add to pDst image pixels
 * \param nValSqr The value to add to pSqr image pixels
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiSqrIntegral_8u32f64f_C1R(const Npp8u  * pSrc, int nSrcStep, 
                                   Npp32f * pDst, int nDstStep, 
                                   Npp64f * pSqr, int nSqrStep,
                                   NppiSize oSrcROI, Npp32f nVal, Npp64f nValSqr);
/** @}  */
/** @} image_sqrintegral */

/** @defgroup image_rectstddev RectStdDev
 * Primitives for computing the standard deviation of the integral images.
 * The function computes the standard deviation of the pixel in the rectangular window with the 
 * integral image \f$pSrc\f$ and the squared integral image \f$pSqr\f$, which can be obtained by calling
 * \ref image_integral and \ref image_sqrintegral.
 * 
 * The standard deviation of the pixel \f$(j, i)\f$ can be computed using the formula:
 * \f[pDst(j, i) = \sqrt{max(0, \frac{\sum(SqrIntegral)\cdot N - (\sum(Integral))^2}{N^2})}\f]
 * where \f$\sum(SqrIntegral) = pSqr[j+oRect.y+oRect.height, i+oRect.x+oRect.width] - pSqr[j+oRect.y,i+oRect.x+oRect.width]
 * - pSqr[j+oRect.y+oRect.height, i+oRect.x] + pSqr[j+oRect.y, i+oRect.x]\f$,
 * \f$\sum(Integral) = pSrc[j+oRect.y+oRect.height, i+oRect.x+oRect.width] - pSrc[j+oRect.y,i+oRect.x+oRect.width]
 * - pSrc[j+oRect.y+oRect.height, i+oRect.x] + pSrc[j+oRect.y, i+oRect.x]\f$,
 * \f$N = oRect.width \cdot oRect.height\f$.
 *
 * The size of the \f$pSrc\f$ and \f$pSqr\f$ should be \f$(oSizeROI.width + oRect.x + oRect.width, 
 * oSizeROI.height + oRect.y + oRect.height).\f$
 * @{
 *
 */
/** @name RectStdDev
 * @{
 */

/**
 * One-channel 32-bit floating point image RectStdDev.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param oRect rectangular window
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiRectStdDev_32f_C1R(const Npp32f *pSrc, int nSrcStep, const Npp64f *pSqr, int nSqrStep, 
                             Npp32f *pDst, int nDstStep, NppiSize oSizeROI, NppiRect oRect);

/**
 * One-channel 32-bit signed image RectStdDev, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param oRect rectangular window
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiRectStdDev_32s_C1RSfs(const Npp32s *pSrc, int nSrcStep, const Npp32s *pSqr, int nSqrStep, 
                                Npp32s *pDst, int nDstStep, NppiSize oSizeROI, NppiRect oRect, int nScaleFactor);

 /**
 * One-channel 32-bit signed image RectStdDev. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pSqr \ref destination_image_pointer.
 * \param nSqrStep \ref destination_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param oRect rectangular window
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiRectStdDev_32s32f_C1R(const Npp32s *pSrc, int nSrcStep, const Npp64f *pSqr, int nSqrStep, 
                                Npp32f *pDst, int nDstStep, NppiSize oSizeROI, NppiRect oRect);
/** @}  */
/** @} image_rectstddev */


/** @defgroup image_histogrameven HistogramEven
 * Primitives for computing the histogram of an image with evenly distributed bins.
 * @{
 *
 */

/** @name HistogramEven
 * The \f$nLowerLevel\f$ (inclusive) and \f$nUpperLevel\f$ (exclusive) define the boundaries of the range, 
 * which are evenly segmented into \f$nLevel - 1\f$ bins. The computed histogram is stored in \f$pHist\f$. 
 * The levels are calculated by another primitive \ref nppiEvenLevelsHost_32s and are stored 
 * in a host pointer \f$hpLevels\f$. The number of levels is also \f$nLevel - 1\f$.
 * The histogram \f$pHist[k]\f$ is defined as the total number of pixels that fall into the range:
 * \f$hpLevels[k] <= pSrc(j, i) < hpLevels[k+1]\f$.
 * The functions require additional scratch buffer for computations.
 * @{
 */

/**
 * Compute levels with even distribution.
 *
 * \param hpLevels A host pointer to array which receives the levels being
 *        computed. The array needs to be of size nLevels. 
 * \param nLevels The number of levels being computed. nLevels must be at least 2.
 * \param nLowerLevel Lower boundary value of the lowest level.
 * \param nUpperLevel Upper boundary value of the greatest level.
 * \return image_data_error_codes, or NPP_HISTO_NUMBER_OF_LEVELS_ERROR if an invalid nLevels is specified.
*/
NppStatus
nppiEvenLevelsHost_32s(Npp32s * hpLevels, int nLevels, Npp32s nLowerLevel, Npp32s nUpperLevel);

/**
 * One-channel 8-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param nLevels Number of levels.
 * \param nLowerLevel Lower boundary of lowest level bin.
 * \param nUpperLevel Upper boundary of highest level bin.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_8u_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiHistogramEven_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                         int nLevels, Npp32s nLowerLevel, Npp32s nUpperLevel, Npp8u * pBuffer);

/**
 * Three-channel 8-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_8u_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiHistogramEven_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                         int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);

/**
 * Four-channel 8-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_8u_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes.
 */
NppStatus 
nppiHistogramEven_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                               Npp32s * pHist[4], 
                         int nLevels[4], Npp32s nLowerLevel[4], Npp32s nUpperLevel[4], Npp8u * pBuffer);

/**
 * Four-channel 8-bit unsigned HistogramEven ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_8u_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                Npp32s * pHist[3], 
                          int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);

/**
 * One-channel 16-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param nLevels Number of levels.
 * \param nLowerLevel Lower boundary of lowest level bin.
 * \param nUpperLevel Upper boundary of highest level bin.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16u_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                          int nLevels, Npp32s nLowerLevel, Npp32s nUpperLevel, Npp8u * pBuffer);

/**
 * Three-channel 16-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16u_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                 Npp32s * pHist[3], 
                           int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);

/**
 * Four-channel 16-bit unsigned HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16u_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                Npp32s * pHist[4], 
                          int nLevels[4], Npp32s nLowerLevel[4], Npp32s nUpperLevel[4], Npp8u * pBuffer);

/**
 * Four-channel 16-bit unsigned HistogramEven ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16u_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                 Npp32s * pHist[3], 
                           int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);

/**
 * One-channel 16-bit signed HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param nLevels Number of levels.
 * \param nLowerLevel Lower boundary of lowest level bin.
 * \param nUpperLevel Upper boundary of highest level bin.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16s_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                         int nLevels, Npp32s nLowerLevel, Npp32s nUpperLevel, Npp8u * pBuffer);

/**
 * Three-channel 16-bit signed HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16s_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                 Npp32s * pHist[3], 
                           int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);

/**
 * Four-channel 16-bit signed HistogramEven.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16s_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                Npp32s * pHist[4], 
                          int nLevels[4], Npp32s nLowerLevel[4], Npp32s nUpperLevel[4], Npp8u * pBuffer);

/**
 * Four-channel 16-bit signed HistogramEven ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving computed histograms per color channel. 
 *      Array pointed by pHist[i] be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param nLowerLevel Array containing lower-level of lowest bin per color channel.
 * \param nUpperLevel Array containing upper-level of highest bin per color channel.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramEvenGetBufferSize_16s_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramEven_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, 
                                 Npp32s * pHist[3], 
                           int nLevels[3], Npp32s nLowerLevel[3], Npp32s nUpperLevel[3], Npp8u * pBuffer);
/** @} */
 
/** @name HistogramEvenGetBufferSize
 * Companion primitives for computing the device buffer size (in bytes) required by the HistogramEven primitives.
 * @{
 */

/**
 * Buffer size for \ref nppiHistogramEven_8u_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_8u_C1R(NppiSize oSizeROI, int nLevels ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_8u_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_8u_C3R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_8u_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_8u_C4R(NppiSize oSizeROI, int nLevels[4] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_8u_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_8u_AC4R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16u_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16u_C1R(NppiSize oSizeROI, int nLevels ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16u_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16u_C3R(NppiSize oSizeROI, int nLevels[3] , int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16u_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16u_C4R(NppiSize oSizeROI, int nLevels[4] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16u_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16u_AC4R(NppiSize oSizeROI, int nLevels[3] , int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16s_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16s_C1R(NppiSize oSizeROI, int nLevels ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16s_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16s_C3R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16s_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16s_C4R(NppiSize oSizeROI, int nLevels[4] ,int * hpBufferSize);

/**
 * Buffer size for \ref nppiHistogramEven_16s_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramEvenGetBufferSize_16s_AC4R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);
/** @} */

/** @} image_histogrameven */


/** @defgroup image_histogramrange HistogramRange
 * Primitives for computing the histogram of an image within specified ranges.
 * @{
 *
 */

/** @name HistogramEven
 * The histogram is computed according to the ranges provided in \f$pLevels\f$. 
 * The histogram \f$pHist[k]\f$ is defined as the total number of pixels that fall into the range:
 * \f$pLevels[k] <= pSrc(j, i) < pLevels[k+1]\f$. The number of the histogram bins is \f$nLevel - 1\f$.
 * The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param pLevels Pointer to array containing the level sizes of the bins.
        The array must be of size nLevels.
 * \param nLevels Number of levels in histogram.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_8u_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_8u_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                          const Npp32s * pLevels, int nLevels, Npp8u * pBuffer);

/**
 * Three-channel 8-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_8u_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_8u_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                           const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * Four-channel 8-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_8u_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_8u_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[4], 
                          const Npp32s * pLevels[4], int nLevels[4], Npp8u * pBuffer);

/**
 * Four-channel 8-bit unsigned HistogramRange ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_8u_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_8u_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                           const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * One-channel 16-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param pLevels Pointer to array containing the level sizes of the bins.
        The array must be of size nLevels.
 * \param nLevels Number of levels in histogram.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16u_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16u_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                           const Npp32s * pLevels, int nLevels, Npp8u * pBuffer);

/**
 * Three-channel 16-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16u_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16u_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * Four-channel 16-bit unsigned HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16u_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16u_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[4], 
                           const Npp32s * pLevels[4], int nLevels[4], Npp8u * pBuffer);

/**
 * Four-channel 16-bit unsigned HistogramRange ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16u_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16u_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * One-channel 16-bit signed HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param pLevels Pointer to array containing the level sizes of the bins.
        The array must be of size nLevels.
 * \param nLevels Number of levels in histogram.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16s_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16s_C1R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                           const Npp32s * pLevels, int nLevels, Npp8u * pBuffer);

/**
 * Three-channel 16-bit signed HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16s_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16s_C3R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * Four-channel 16-bit signed HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16s_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16s_C4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[4], 
                           const Npp32s * pLevels[4], int nLevels[4], Npp8u * pBuffer);

/**
 * Four-channel 16-bit signed HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_16s_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_16s_AC4R(const Npp16s * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32s * pLevels[3], int nLevels[3], Npp8u * pBuffer);

/**
 * One-channel 32-bit floating point HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Pointer to array that receives the computed histogram. 
 *      The array must be of size nLevels-1. 
 * \param pLevels Pointer to array containing the level sizes of the bins.
        The array must be of size nLevels.
 * \param nLevels Number of levels in histogram.
 * \param pBuffer Pointer to appropriately sized (\ref nppiHistogramRangeGetBufferSize_32f_C1R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist, 
                           const Npp32f * pLevels, int nLevels, Npp8u * pBuffer);

/**
 * Three-channel 32-bit floating point HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (nppiHistogramRangeGetBufferSize_32f_C3R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32f * pLevels[3], int nLevels[3], Npp8u * pBuffer);


/**
 * Four-channel 32-bit floating point HistogramRange.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (nppiHistogramRangeGetBufferSize_32f_C4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[4], 
                           const Npp32f * pLevels[4], int nLevels[4], Npp8u * pBuffer);

/**
 * Four-channel 32-bit floating point HistogramRange ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pHist Array of pointers which are receiving the computed histograms per color channel. 
 *      Array pointed by pHist[i] must be of size nLevels[i]-1.
 * \param nLevels Array containing number of levels per color channel. 
 * \param pLevels Array containing pointers to level-arrays per color channel.
        Array pointed by pLevel[i] must be of size nLevels[i].
 * \param pBuffer Pointer to appropriately sized (nppiHistogramRangeGetBufferSize_32f_AC4R) 
 *      scratch buffer.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiHistogramRange_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSizeROI, Npp32s * pHist[3], 
                            const Npp32f * pLevels[3], int nLevels[3], Npp8u * pBuffer);
/** @} */

/** @name HistogramRangeGetBufferSize
 * Companion primitives for computing the device buffer size (in bytes) required by the HistogramRange primitives.
 * @{
 */
 
/**
 * Scratch-buffer size for nppiHistogramRange_8u_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_8u_C1R(NppiSize oSizeROI, int nLevels ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_8u_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_8u_C3R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_8u_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_8u_C4R(NppiSize oSizeROI, int nLevels[4] ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_8u_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_8u_AC4R(NppiSize oSizeROI, int nLevels[3] ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16u_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16u_C1R(NppiSize oSizeROI, int nLevels ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16u_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16u_C3R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16u_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16u_C4R(NppiSize oSizeROI, int nLevels[4], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16u_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16u_AC4R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16s_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16s_C1R(NppiSize oSizeROI, int nLevels, int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16s_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16s_C3R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16s_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16s_C4R(NppiSize oSizeROI, int nLevels[4] ,int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_16s_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_16s_AC4R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_32f_C1R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Number of levels in the histogram.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_32f_C1R(NppiSize oSizeROI, int nLevels, int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_32f_C3R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_32f_C3R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_32f_C4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_32f_C4R(NppiSize oSizeROI, int nLevels[4], int * hpBufferSize);

/**
 * Scratch-buffer size for nppiHistogramRange_32f_AC4R.
 * 
 * \param oSizeROI \ref roi_specification.
 * \param nLevels Array containing number of levels per color channel.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes..
 */
NppStatus 
nppiHistogramRangeGetBufferSize_32f_AC4R(NppiSize oSizeROI, int nLevels[3], int * hpBufferSize);
/** @} */
/** @} image_histogramrange */

/** @defgroup image_proximity Image Proximity
 * Primitives for computing the proximity measure between a source image and a template image.
 *
 * \section general_introduction General Introduction
 * There are basically two approaches to compute the proximity measure for template matching, 
 * Euclidean distance and the cross correlation.
 * -# Euclidean distance computes the sum of the squared distance (SSD) between the corresponding 
 * pixels of the source image and the template image. The smaller the distance is, the more 
 * similar the source image and the template image is around the pixel. The anchor of the template  
 * image is used during the computations, which always lies in the gemotric center of the image. 
 * Given a source image \f$pSrc\f$ (\f$W_s \times H_s\f$) and a template image \f$pTpl\f$ (\f$W_t \times H_t\f$), 
 * the Euclidean distance \f$D_{st}(c,r)\f$ between two images at pixel in row \f$r\f$ and column 
 * \f$c\f$ is computed as (\f$s\f$ stands for source image and \f$t\f$ for template image for short):
 * \f[D_{st}(c,r)=\sum_{j=0}^{H_t-1}\sum_{i=0}^{W_t-1}[pTpl(j,i)-pSrc(j+c-\frac{H_t}{2}, i+r-\frac{W_t}{2})]^2 \f]
 * -# Cross correlation computes the sum of the product between the corresponding pixels of the source 
 * image and the template image. The cross correlation \f$R_{st}(c,r)\f$ is calculated as:
 * \f[R_{st}(c,r)=\sum_{j=0}^{H_t-1}\sum_{i=0}^{W_t-1}[pTpl(j,i)\cdot pSrc(j+c-\frac{H_t}{2}, i+r-\frac{W_t}{2})] \f]
 * The larger the cross correlation value is, the more similar the source image and the template image is around the pixel. 
 * -# The cross correlation \f$R_{st}(c,r)\f$ is affected by the brightness of the images which may vary due to the lighting 
 * and exposure conditions. Therefore, NPP computes the cross correlation coefficient to circumvent this dependence. 
 * This is typically done at every step by subtracting the mean from every pixel value, i.e.,
 * \f[\tilde{R}_{st}(c,r)=\sum_{j=0}^{H_t-1}\sum_{i=0}^{W_t-1}[pTpl(j,i)-Mean_t]\cdot [pSrc(j+c-\frac{H_t}{2}, i+r-\frac{W_t}{2})-Mean_s] \f]
 * 
 * NPP computes the normalized values of Euclidean distance, cross correlation and the cross correlation coefficient.
 * -# The normalized Euclidean distance \f$\sigma_{st}(c,r)\f$ is defined as:
 * \f[\sigma_{st}(c,r) = \frac{D_{st}(c,r)}{\sqrt{R_{ss}(c,r)\cdot R_{tt}(\frac{H_t}{2},\frac{W_t}{2})}} \f]
 * -# The normalized cross correlation \f$\rho_{st}(c,r)\f$ is defined as:
 * \f[\rho_{st}(c,r) = \frac{R_{st}(c,r)}{\sqrt{R_{ss}(c,r)\cdot R_{tt}(\frac{H_t}{2},\frac{W_t}{2})}} \f]
 * The \f$R_{ss}(c,r)\f$ and \f$R_{tt}(\frac{H_t}{2}, \frac{W_t}{2}\f$ denote the auto correlation of the source
 * image and the template image individually. They are defined as:
 * \f[R_{ss}(c,r)=\sum_{j=c-\frac{H_t}{2}}^{c+\frac{H_t}{2}}\sum_{i=r-\frac{W_t}{2}}^{r+\frac{W_t}{2}}pSrc(j, i) \f]
 * \f[R_{tt}(\frac{H_t}{2},\frac{W_t}{2})=\sum_{j=0}^{H_t-1}\sum_{i=0}^{W_t-1}pTpl(j,i) \f]
 * -# Similarly, the normalized cross correlation coefficient \f$\gamma_{st}(c,r)\f$ is calculated as:
 * \f[\gamma_{st}(c,r) = \frac{\tilde{R}_{st}(c,r)}{\sqrt{\tilde{R}_{ss}(c,r)\cdot \tilde{R}_{tt}(\frac{H_t}{2},\frac{W_t}{2})}} \f]
 * The \f$\tilde{R}_{ss}(c,r)\f$ and \f$\tilde{R}_{tt}(\frac{H_t}{2}, \frac{W_t}{2}\f$ are defined as:
 * \f[\tilde{R}_{ss}(c,r)=\sum_{j=c-\frac{H_t}{2}}^{c+\frac{H_t}{2}}\sum_{i=r-\frac{W_t}{2}}^{r+\frac{W_t}{2}}[pSrc(j, i)-Mean_s] \f]
 * \f[\tilde{R}_{tt}(\frac{H_t}{2},\frac{W_t}{2})=\sum_{j=0}^{H_t-1}\sum_{i=0}^{W_t-1}[pTpl(j,i)-Mean_t] \f]
 *
 * \section category Categorizations
 * The Euclidean distance and the cross correlation are categorized into three types, full, same, and valid. 
 * -# Full mode indicates that the anchor of the template image starts from the outside of the source image, 
 * assuming the out-of-boundary pixels are zeor-padded. The size of the destination
 * image is \f$(W_s + W_t - 1) \times (H_s + H_t - 1)\f$.
 * -# Same mode means that the anchor of the template image starts from the top left pixel
 * of the source image. All the out-of-boundary pixels are also zero-padded.
 * The size of the destination image is the same as the source one, i.e., \f$W_s \times H_s\f$.
 * -# Valid mode indicates that there are no out-of-boudnary readings from the source image.
 * The anchor of the template image starts from the inside of the source image. The 
 * size of the destination image is \f$(W_s - W_t + 1) \times (H_s - H_t + 1)\f$.
 * 
 * @{
 */

/** @defgroup sqrdistancefullnorm SqrDistanceFull_Norm 
 * Primitives for computing the normalized Euclidean distance between two images with full mode.
 * @{
 */
/**
 * @name SqrDistanceFull_Norm
 * The functions compute the \f$\sigma_{st}(c,r)\f$ in \ref general_introduction
 * with full mode (see \ref category).
 * @{
 */
 /**
 * One-channel 8-bit unsigned image SqrDistanceFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image SqrDistanceFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceFull_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceFull_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);
/** @} */
/** @} SqrDistanceFull_Norm */

/**
 * @defgroup sqrdistancesamenorm SqrDistanceSame_Norm
 * Primitives for computing the normalized Euclidean distance between two images with same mode.
 * @{
 */
/**
 * @name SqrDistanceSame_Norm
 * The functions compute the \f$\sigma_{st}(c,r)\f$ in \ref general_introduction 
 * with same mode (see \ref category).
 * @{
 */
/**
 * One-channel 8-bit unsigned image SqrDistanceSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image SqrDistanceSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceSame_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceSame_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);
/** @} */
/** @} SqrDistanceFull_Norm */

/**
 * @defgroup sqrdistancevalidnorm SqrDistanceValid_Norm
 * Primitives for computing the normalized Euclidean distance between two images with valid mode.
 * @{
 */
/**
 * @name SqrDistanceValid_Norm
 * The functions compute the \f$\sigma_{st}(c,r)\f$ in \ref general_introduction 
 * with valid mode (see \ref category).
 * @{
 */
/**
 * One-channel 8-bit unsigned image SqrDistanceValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image SqrDistanceValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image SqrDistanceValid_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image SqrDistanceValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */ 
NppStatus
nppiSqrDistanceValid_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image SqrDistanceValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image SqrDistanceValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image SqrDistanceValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiSqrDistanceValid_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep);
/** @} */
/** @} SqrDistanceValid_Norm*/

/**
 * @defgroup crosscorrfullnorm CrossCorrFull_Norm
 * Primitives for computing the normalized cross correlation between two images with full mode.
 *
 * @{
 */
/**
 * @name CrossCorrFull_Norm
 * The functions compute the \f$\rho_{st}(c,r)\f$ in \ref general_introduction 
 * with full mode (see \ref category).
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image CrossCorrFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrFull_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrFull_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);
/** @} */
/** @} CrossCorrFull_Norm */

/**
 * @defgroup crosscorrsamenorm CrossCorrSame_Norm
 * Primitives for computing the normalized cross correlation between two images with same mode.
 *
 * @{
 */
/**
 * @name CrossCorrSame_Norm
 * The functions compute the \f$\rho_{st}(c,r)\f$ in \ref general_introduction 
 * with same mode (see \ref category).
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image CrossCorrSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrSame_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrSame_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);
/** @} */
/** @} CrossCorrSame_Norm*/

/**
 * @defgroup crosscorrvalidnorm CrossCorrValid_Norm
 * Primitives for computing the normalized cross correlation between two images with valid mode.
 *
 * @{
 */
/**
 * @name CrossCorrValid_Norm
 * The functions compute the \f$\rho_{st}(c,r)\f$ in \ref general_introduction 
 * with valid mode (see \ref category).
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Three-channel 8-bit unsigned image CrossCorrValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_Norm, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_Norm ignoring alpha channel, scaled by \f$2^(-nScaleFactor)\f$. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp8u * pDst, int nDstStep, int nScaleFactor);

/**
 * One-channel 32-bit floating point image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Three-channel 32-bit floating point image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                 const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                       Npp32f * pDst, int nDstStep);

/**
 * Four-channel 32-bit floating point image CrossCorrValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                  const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                        Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 8-bit signed image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Three-channel 8-bit signed image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                   const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                         Npp32f * pDst, int nDstStep);

/**
 * Four-channel 8-bit signed image CrossCorrValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * One-channel 16-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Three-channel 16-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrValid_Norm. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep);

/**
 * Four-channel 16-bit unsigned image CrossCorrValid_Norm ignoring alpha channel. 
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_Norm_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep);
/** @} */
/** @} CrossCorrValid_Norm*/

/**
 * @defgroup crosscorrvalid CrossCorrValid
 * Primitives for computing the cross correlation between two images with valid mode.
 *
 * @{
 */
/**
 * @name CrossCorrValid
 * The functions compute the \f$R_{st}(c,r)\f$ in \ref general_introduction 
 * with valid mode (see \ref category).
 * @{
 */
/**
 * One-channel 32-bit floating point images CrossCorrValid.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                           const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                 Npp32f * pDst, int nDstStep);
                                        
/**
 * One-channel 8-bit unsigned images CrossCorrValid.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                             const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                   Npp32f * pDst, int nDstStep);
                                          
/**
 * One-channel 8-bit signed images CrossCorrValid.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                             const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                   Npp32f * pDst, int nDstStep);
                                          
/**
 * One-channel 16-bit unsigned images CrossCorrValid.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                              const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                    Npp32f * pDst, int nDstStep);                                          
/** @} */
/** @} CrossCorrValid*/

/**
 * @defgroup crosscorrfullnormlevel CrossCorrFull_NormLevel
 * Primitives for computing the normalized cross correlation coefficient between two images with full mode.
 *
 * @{
 */
/**
 * @name CrossCorrFull_NormLevel
 * The functions compute the \f$\gamma_{st}(c,r)\f$ in \ref general_introduction 
 * with full mode (see \ref category). The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u_C1RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u_C3RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u_C4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u_AC4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrFull_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrFull_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit signed image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8s32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit signed image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8s32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8s32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrFull_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_8s32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_16u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_16u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrFull_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_16u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrFull_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiFullNormLevelGetBufferHostSize_16u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrFull_NormLevel_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                        const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                              Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);
/** @} */

/** @name FullNormLevelGetBufferHostSize 
 * Companion primitives for computing the device buffer size (in bytes) required by the CrossCorrFull_NormLevel primitives.
 * @{
 */
/** 
 * Buffer size (in bytes) for nppiCrossCorrFull_NormLevel_8u_C1RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u_C1RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u_C3RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u_C3RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u_C4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u_C4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u_AC4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u_AC4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8s32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8s32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8s32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8s32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8s32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8s32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_8s32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_8s32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_16u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_16u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_16u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_16u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_16u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_16u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrFull_NormLevel_16u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiFullNormLevelGetBufferHostSize_16u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} CrossCorrFull_NormLevel*/

/**
 * @defgroup crosscorrsamenormlevel CrossCorrSame_NormLevel
 * Primitives for computing the normalized cross correlation coefficient between two images with same mode.
 *
 * @{
 */
/**
 * @name CrossCorrSame_NormLevel
 * The functions compute the \f$\gamma_{st}(c,r)\f$ in \ref general_introduction 
 * with same mode (see \ref category). The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u_C1RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u_C3RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u_C4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u_AC4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrSame_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrSame_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit signed image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8s32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit signed image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8s32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8s32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrSame_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_8s32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_16u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_16u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrSame_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_16u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrSame_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiSameNormLevelGetBufferHostSize_16u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrSame_NormLevel_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                        const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                              Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);
/** @} */

/** @name SameNormLevelGetBufferHostSize 
 * Companion primitives for computing the device buffer size (in bytes) required by the CrossCorrSame_NormLevel primitives.
 * @{
 */
/** 
 * Buffer size (in bytes) for nppiCrossCorrSame_NormLevel_8u_C1RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u_C1RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u_C3RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u_C3RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u_C4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u_C4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u_AC4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u_AC4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8s32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8s32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8s32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8s32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8s32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8s32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_8s32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_8s32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_16u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_16u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_16u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_16u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_16u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_16u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrSame_NormLevel_16u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiSameNormLevelGetBufferHostSize_16u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @} */
/** @} CrossCorrSame_NormLevel*/

/**
 * @defgroup crosscorrvalidnormlevel CrossCorrValid_NormLevel
 * Primitives for computing the normalized cross correlation coefficient between two images with valid mode.
 *
 * @{
 */
/**
 * @name CrossCorrValid_NormLevel
 * The functions compute the \f$\gamma_{st}(c,r)\f$ in \ref general_introduction 
 * with valid mode (see \ref category). The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u_C1RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u_C1RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u_C3RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u_C3RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u_C4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u_C4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param nScaleFactor \ref integer_result_scaling.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u_AC4RSfs to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u_AC4RSfs(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp8u * pDst, int nDstStep, int nScaleFactor, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_32f_C1R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_32f_C3R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_32f_C4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                    const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                          Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image CrossCorrValid_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_32f_AC4R(const Npp32f * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                     const Npp32f * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                           Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u32f_C1R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u32f_C3R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u32f_C4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image CrossCorrValid_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8u32f_AC4R(const Npp8u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 8-bit signed image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8s32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8s32f_C1R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit signed image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8s32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8s32f_C3R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8s32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8s32f_C4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                      const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                            Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit signed image CrossCorrValid_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_8s32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_8s32f_AC4R(const Npp8s * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp8s * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_16u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_16u32f_C1R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_16u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_16u32f_C3R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrValid_NormLevel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_16u32f_C4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_16u32f_C4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                       const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                             Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image CrossCorrValid_NormLevel ignoring alpha channel.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param oSrcRoiSize \ref roi_specification.
 * \param pTpl Pointer to the template image.
 * \param nTplStep Number of bytes between successive rows in the template image.
 * \param oTplRoiSize \ref roi_specification.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiValidNormLevelGetBufferHostSize_16u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus
nppiCrossCorrValid_NormLevel_16u32f_AC4R(const Npp16u * pSrc, int nSrcStep, NppiSize oSrcRoiSize, 
                                        const Npp16u * pTpl, int nTplStep, NppiSize oTplRoiSize, 
                                              Npp32f * pDst, int nDstStep, Npp8u * pDeviceBuffer);
/** @} */

/** @name ValidNormLevelGetBufferHostSize 
 * Companion primitives for computing the device buffer size (in bytes) required by the CrossCorrValid_NormLevel primitives.
 * @{
 */
/** 
 * Buffer size (in bytes) for nppiCrossCorrValid_NormLevel_8u_C1RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u_C1RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u_C3RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u_C3RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u_C4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u_C4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u_AC4RSfs.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u_AC4RSfs(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8s32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8s32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8s32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8s32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8s32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8s32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_8s32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_8s32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_16u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_16u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_16u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_16u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_16u32f_C4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_16u32f_C4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiCrossCorrValid_NormLevel_16u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiValidNormLevelGetBufferHostSize_16u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** @} */
/** @} CrossCorrValid_NormLevel*/
/** @} image_proximity */

/** @defgroup image_quality_index Image Quality Index
 * Primitives for computing the image quality index of two images.
 * @{
 */
/**
 * @name QualityIndex
  * Given two images \f$M\f$ and \f$N\f$ (both \f$W \times H\f$), the
 * mathematical formula to calculate the image quality index \f$Q\f$ between them is expressed as:
 * \f[Q = \frac{4\sigma_{MN}\tilde{M}\tilde{N}}{[(\tilde{M}^2)+(\tilde{N}^2)][(\sigma_M)^2+(\sigma_N)^2]} \f]
 * where
 * \f[\tilde{M} = \frac{1}{W\cdot H}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}M(j,i)\f]
 * \f[\tilde{N} = \frac{1}{W\cdot H}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}N(j,i)\f]
 * \f[\sigma_{M} = \sqrt{\frac{1}{W\cdot H-1}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}[M(j,i)-\tilde{M}]^2}\f]
 * \f[\sigma_{N} = \sqrt{\frac{1}{W\cdot H-1}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}[N(j,i)-\tilde{N}]^2}\f]
 * \f[\sigma_{MN} = \frac{1}{W\cdot H-1}\sum_{j=0}^{H-1}\sum_{i=0}^{W-1}[M(j,i)-\tilde{M}][N(j,i)-\tilde{N}]\f]
 * The functions require additional scratch buffer for computations.
 * @{
 */
/**
 * One-channel 8-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_8u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_8u32f_C1R(const Npp8u * pSrc1, int nSrc1Step, 
                           const Npp8u * pSrc2, int nSrc2Step, 
                           NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * One-channel 16-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_16u32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_16u32f_C1R(const Npp16u * pSrc1, int nSrc1Step, 
                            const Npp16u * pSrc2, int nSrc2Step, 
                            NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * One-channel 32-bit floating point image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_32f_C1R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_32f_C1R(const Npp32f * pSrc1, int nSrc1Step, 
                         const Npp32f * pSrc2, int nSrc2Step, 
                         NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Three-channel 8-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_8u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_8u32f_C3R(const Npp8u * pSrc1, int nSrc1Step, 
                           const Npp8u * pSrc2, int nSrc2Step, 
                           NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Three-channel 16-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_16u32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_16u32f_C3R(const Npp16u * pSrc1, int nSrc1Step, 
                            const Npp16u * pSrc2, int nSrc2Step, 
                            NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Three-channel 32-bit floating point image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_32f_C3R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_32f_C3R(const Npp32f * pSrc1, int nSrc1Step, 
                         const Npp32f * pSrc2, int nSrc2Step, 
                         NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Four-channel 8-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_8u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_8u32f_AC4R(const Npp8u * pSrc1, int nSrc1Step, 
                            const Npp8u * pSrc2, int nSrc2Step, 
                            NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Four-channel 16-bit unsigned image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_16u32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_16u32f_AC4R(const Npp16u * pSrc1, int nSrc1Step, 
                             const Npp16u * pSrc2, int nSrc2Step, 
                             NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);

/**
 * Four-channel 32-bit floating point image QualityIndex.
 *
 * \param pSrc1 \ref source_image_pointer.
 * \param nSrc1Step \ref source_image_line_step.
 * \param pSrc2 \ref source_image_pointer.
 * \param nSrc2Step \ref source_image_line_step.
 * \param oRoiSize \ref roi_specification.
 * \param pDst Pointer to the quality index.
 * \param pDeviceBuffer Pointer to the required device memory allocation, \ref general_scratch_buffer. 
 * Use \ref nppiQualityIndexGetBufferHostSize_32f_AC4R to compute the required size (in bytes).
 * \return \ref image_data_error_codes, \ref roi_error_codes, or NPP_QUALITY_INDEX_ERROR if pixels of 
 * either image are constant numberse.
 */
NppStatus
nppiQualityIndex_32f_AC4R(const Npp32f * pSrc1, int nSrc1Step, 
                          const Npp32f * pSrc2, int nSrc2Step, 
                          NppiSize oRoiSize, Npp32f * pDst, Npp8u * pDeviceBuffer);
/** @} */

/** @name QualityIndexGetBufferHostSize 
 * Companion primitives for computing the device buffer size (in bytes) required by the QualityIndex primitives.
 * @{
 */
/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_8u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_8u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_16u32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_16u32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_32f_C1R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_32f_C1R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_8u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_8u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_16u32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_16u32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_32f_C3R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_32f_C3R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_8u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_8u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_16u32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_16u32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);

/** 
 * Buffer size (in bytes) for \ref nppiQualityIndex_32f_AC4R.
 * \param oSizeROI \ref roi_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 * \return NPP_NULL_POINTER_ERROR if hpBufferSize is 0 (NULL),  \ref roi_error_codes.
 */
NppStatus 
nppiQualityIndexGetBufferHostSize_32f_AC4R(NppiSize oSizeROI, int * hpBufferSize/* host pointer */);
/** @}  */
/** @} image_quality_index */

/** @} image_statistics_functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NV_NPPI_STATISTICS_FUNCTIONS_H */
