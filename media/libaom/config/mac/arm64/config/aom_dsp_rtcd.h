/*
 * Copyright (c) 2025, Alliance for Open Media. All rights reserved.
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

// This file is generated. Do not edit.
#ifndef AOM_DSP_RTCD_H_
#define AOM_DSP_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * DSP
 */

#include "aom/aom_integer.h"
#include "aom_dsp/aom_dsp_common.h"
#include "av1/common/blockd.h"
#include "av1/common/enums.h"


#ifdef __cplusplus
extern "C" {
#endif

unsigned int aom_avg_4x4_c(const uint8_t *, int p);
unsigned int aom_avg_4x4_neon(const uint8_t *, int p);
#define aom_avg_4x4 aom_avg_4x4_neon

unsigned int aom_avg_8x8_c(const uint8_t *, int p);
unsigned int aom_avg_8x8_neon(const uint8_t *, int p);
#define aom_avg_8x8 aom_avg_8x8_neon

void aom_avg_8x8_quad_c(const uint8_t *s, int p, int x16_idx, int y16_idx, int *avg);
void aom_avg_8x8_quad_neon(const uint8_t *s, int p, int x16_idx, int y16_idx, int *avg);
#define aom_avg_8x8_quad aom_avg_8x8_quad_neon

void aom_blend_a64_hmask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
void aom_blend_a64_hmask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
#define aom_blend_a64_hmask aom_blend_a64_hmask_neon

void aom_blend_a64_mask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh);
void aom_blend_a64_mask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh);
#define aom_blend_a64_mask aom_blend_a64_mask_neon

void aom_blend_a64_vmask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
void aom_blend_a64_vmask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
#define aom_blend_a64_vmask aom_blend_a64_vmask_neon

void aom_comp_avg_pred_c(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride);
void aom_comp_avg_pred_neon(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride);
#define aom_comp_avg_pred aom_comp_avg_pred_neon

void aom_comp_mask_pred_c(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride, const uint8_t *mask, int mask_stride, int invert_mask);
void aom_comp_mask_pred_neon(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride, const uint8_t *mask, int mask_stride, int invert_mask);
#define aom_comp_mask_pred aom_comp_mask_pred_neon

double aom_compute_correlation_c(const unsigned char *frame1, int stride1, int x1, int y1, double mean1, double one_over_stddev1, const unsigned char *frame2, int stride2, int x2, int y2, double mean2, double one_over_stddev2);
#define aom_compute_correlation aom_compute_correlation_c

void aom_compute_flow_at_point_c(const uint8_t *src, const uint8_t *ref, int x, int y, int width, int height, int stride, double *u, double *v);
void aom_compute_flow_at_point_neon(const uint8_t *src, const uint8_t *ref, int x, int y, int width, int height, int stride, double *u, double *v);
#define aom_compute_flow_at_point aom_compute_flow_at_point_neon

bool aom_compute_mean_stddev_c(const unsigned char *frame, int stride, int x, int y, double *mean, double *one_over_stddev);
#define aom_compute_mean_stddev aom_compute_mean_stddev_c

void aom_convolve8_horiz_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_horiz_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_horiz_neon_dotprod(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_horiz_neon_i8mm(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
RTCD_EXTERN void (*aom_convolve8_horiz)(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);

void aom_convolve8_vert_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_vert_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_vert_neon_dotprod(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
void aom_convolve8_vert_neon_i8mm(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);
RTCD_EXTERN void (*aom_convolve8_vert)(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h);

void aom_convolve_copy_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, int w, int h);
void aom_convolve_copy_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, int w, int h);
#define aom_convolve_copy aom_convolve_copy_neon

void aom_dc_128_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_16x16 aom_dc_128_predictor_16x16_neon

void aom_dc_128_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_16x32 aom_dc_128_predictor_16x32_neon

void aom_dc_128_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_16x4 aom_dc_128_predictor_16x4_neon

void aom_dc_128_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_16x64 aom_dc_128_predictor_16x64_neon

void aom_dc_128_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_16x8 aom_dc_128_predictor_16x8_neon

void aom_dc_128_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_32x16 aom_dc_128_predictor_32x16_neon

void aom_dc_128_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_32x32 aom_dc_128_predictor_32x32_neon

void aom_dc_128_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_32x64 aom_dc_128_predictor_32x64_neon

void aom_dc_128_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_32x8 aom_dc_128_predictor_32x8_neon

void aom_dc_128_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_4x16 aom_dc_128_predictor_4x16_neon

void aom_dc_128_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_4x4 aom_dc_128_predictor_4x4_neon

void aom_dc_128_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_4x8 aom_dc_128_predictor_4x8_neon

void aom_dc_128_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_64x16 aom_dc_128_predictor_64x16_neon

void aom_dc_128_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_64x32 aom_dc_128_predictor_64x32_neon

void aom_dc_128_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_64x64 aom_dc_128_predictor_64x64_neon

void aom_dc_128_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_8x16 aom_dc_128_predictor_8x16_neon

void aom_dc_128_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_8x32 aom_dc_128_predictor_8x32_neon

void aom_dc_128_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_8x4 aom_dc_128_predictor_8x4_neon

void aom_dc_128_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_128_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_128_predictor_8x8 aom_dc_128_predictor_8x8_neon

void aom_dc_left_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_16x16 aom_dc_left_predictor_16x16_neon

void aom_dc_left_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_16x32 aom_dc_left_predictor_16x32_neon

void aom_dc_left_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_16x4 aom_dc_left_predictor_16x4_neon

void aom_dc_left_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_16x64 aom_dc_left_predictor_16x64_neon

void aom_dc_left_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_16x8 aom_dc_left_predictor_16x8_neon

void aom_dc_left_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_32x16 aom_dc_left_predictor_32x16_neon

void aom_dc_left_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_32x32 aom_dc_left_predictor_32x32_neon

void aom_dc_left_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_32x64 aom_dc_left_predictor_32x64_neon

void aom_dc_left_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_32x8 aom_dc_left_predictor_32x8_neon

void aom_dc_left_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_4x16 aom_dc_left_predictor_4x16_neon

void aom_dc_left_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_4x4 aom_dc_left_predictor_4x4_neon

void aom_dc_left_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_4x8 aom_dc_left_predictor_4x8_neon

void aom_dc_left_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_64x16 aom_dc_left_predictor_64x16_neon

void aom_dc_left_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_64x32 aom_dc_left_predictor_64x32_neon

void aom_dc_left_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_64x64 aom_dc_left_predictor_64x64_neon

void aom_dc_left_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_8x16 aom_dc_left_predictor_8x16_neon

void aom_dc_left_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_8x32 aom_dc_left_predictor_8x32_neon

void aom_dc_left_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_8x4 aom_dc_left_predictor_8x4_neon

void aom_dc_left_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_left_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_left_predictor_8x8 aom_dc_left_predictor_8x8_neon

void aom_dc_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_16x16 aom_dc_predictor_16x16_neon

void aom_dc_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_16x32 aom_dc_predictor_16x32_neon

void aom_dc_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_16x4 aom_dc_predictor_16x4_neon

void aom_dc_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_16x64 aom_dc_predictor_16x64_neon

void aom_dc_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_16x8 aom_dc_predictor_16x8_neon

void aom_dc_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_32x16 aom_dc_predictor_32x16_neon

void aom_dc_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_32x32 aom_dc_predictor_32x32_neon

void aom_dc_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_32x64 aom_dc_predictor_32x64_neon

void aom_dc_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_32x8 aom_dc_predictor_32x8_neon

void aom_dc_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_4x16 aom_dc_predictor_4x16_neon

void aom_dc_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_4x4 aom_dc_predictor_4x4_neon

void aom_dc_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_4x8 aom_dc_predictor_4x8_neon

void aom_dc_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_64x16 aom_dc_predictor_64x16_neon

void aom_dc_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_64x32 aom_dc_predictor_64x32_neon

void aom_dc_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_64x64 aom_dc_predictor_64x64_neon

void aom_dc_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_8x16 aom_dc_predictor_8x16_neon

void aom_dc_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_8x32 aom_dc_predictor_8x32_neon

void aom_dc_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_8x4 aom_dc_predictor_8x4_neon

void aom_dc_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_predictor_8x8 aom_dc_predictor_8x8_neon

void aom_dc_top_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_16x16 aom_dc_top_predictor_16x16_neon

void aom_dc_top_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_16x32 aom_dc_top_predictor_16x32_neon

void aom_dc_top_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_16x4 aom_dc_top_predictor_16x4_neon

void aom_dc_top_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_16x64 aom_dc_top_predictor_16x64_neon

void aom_dc_top_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_16x8 aom_dc_top_predictor_16x8_neon

void aom_dc_top_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_32x16 aom_dc_top_predictor_32x16_neon

void aom_dc_top_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_32x32 aom_dc_top_predictor_32x32_neon

void aom_dc_top_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_32x64 aom_dc_top_predictor_32x64_neon

void aom_dc_top_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_32x8 aom_dc_top_predictor_32x8_neon

void aom_dc_top_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_4x16 aom_dc_top_predictor_4x16_neon

void aom_dc_top_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_4x4 aom_dc_top_predictor_4x4_neon

void aom_dc_top_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_4x8 aom_dc_top_predictor_4x8_neon

void aom_dc_top_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_64x16 aom_dc_top_predictor_64x16_neon

void aom_dc_top_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_64x32 aom_dc_top_predictor_64x32_neon

void aom_dc_top_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_64x64 aom_dc_top_predictor_64x64_neon

void aom_dc_top_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_8x16 aom_dc_top_predictor_8x16_neon

void aom_dc_top_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_8x32 aom_dc_top_predictor_8x32_neon

void aom_dc_top_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_8x4 aom_dc_top_predictor_8x4_neon

void aom_dc_top_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_dc_top_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_dc_top_predictor_8x8 aom_dc_top_predictor_8x8_neon

void aom_fdct4x4_c(const int16_t *input, tran_low_t *output, int stride);
void aom_fdct4x4_neon(const int16_t *input, tran_low_t *output, int stride);
#define aom_fdct4x4 aom_fdct4x4_neon

void aom_fdct4x4_lp_c(const int16_t *input, int16_t *output, int stride);
void aom_fdct4x4_lp_neon(const int16_t *input, int16_t *output, int stride);
#define aom_fdct4x4_lp aom_fdct4x4_lp_neon

void aom_fft16x16_float_c(const float *input, float *temp, float *output);
#define aom_fft16x16_float aom_fft16x16_float_c

void aom_fft2x2_float_c(const float *input, float *temp, float *output);
#define aom_fft2x2_float aom_fft2x2_float_c

void aom_fft32x32_float_c(const float *input, float *temp, float *output);
#define aom_fft32x32_float aom_fft32x32_float_c

void aom_fft4x4_float_c(const float *input, float *temp, float *output);
#define aom_fft4x4_float aom_fft4x4_float_c

void aom_fft8x8_float_c(const float *input, float *temp, float *output);
#define aom_fft8x8_float aom_fft8x8_float_c

void aom_get_blk_sse_sum_c(const int16_t *data, int stride, int bw, int bh, int *x_sum, int64_t *x2_sum);
void aom_get_blk_sse_sum_neon(const int16_t *data, int stride, int bw, int bh, int *x_sum, int64_t *x2_sum);
#define aom_get_blk_sse_sum aom_get_blk_sse_sum_neon

unsigned int aom_get_mb_ss_c(const int16_t *);
unsigned int aom_get_mb_ss_neon(const int16_t *);
#define aom_get_mb_ss aom_get_mb_ss_neon

void aom_get_var_sse_sum_16x16_dual_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse16x16, unsigned int *tot_sse, int *tot_sum, uint32_t *var16x16);
void aom_get_var_sse_sum_16x16_dual_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse16x16, unsigned int *tot_sse, int *tot_sum, uint32_t *var16x16);
void aom_get_var_sse_sum_16x16_dual_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse16x16, unsigned int *tot_sse, int *tot_sum, uint32_t *var16x16);
RTCD_EXTERN void (*aom_get_var_sse_sum_16x16_dual)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse16x16, unsigned int *tot_sse, int *tot_sum, uint32_t *var16x16);

void aom_get_var_sse_sum_8x8_quad_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse8x8, int *sum8x8, unsigned int *tot_sse, int *tot_sum, uint32_t *var8x8);
void aom_get_var_sse_sum_8x8_quad_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse8x8, int *sum8x8, unsigned int *tot_sse, int *tot_sum, uint32_t *var8x8);
void aom_get_var_sse_sum_8x8_quad_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse8x8, int *sum8x8, unsigned int *tot_sse, int *tot_sum, uint32_t *var8x8);
RTCD_EXTERN void (*aom_get_var_sse_sum_8x8_quad)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse8x8, int *sum8x8, unsigned int *tot_sse, int *tot_sum, uint32_t *var8x8);

void aom_h_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_16x16 aom_h_predictor_16x16_neon

void aom_h_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_16x32 aom_h_predictor_16x32_neon

void aom_h_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_16x4 aom_h_predictor_16x4_neon

void aom_h_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_16x64 aom_h_predictor_16x64_neon

void aom_h_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_16x8 aom_h_predictor_16x8_neon

void aom_h_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_32x16 aom_h_predictor_32x16_neon

void aom_h_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_32x32 aom_h_predictor_32x32_neon

void aom_h_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_32x64 aom_h_predictor_32x64_neon

void aom_h_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_32x8 aom_h_predictor_32x8_neon

void aom_h_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_4x16 aom_h_predictor_4x16_neon

void aom_h_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_4x4 aom_h_predictor_4x4_neon

void aom_h_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_4x8 aom_h_predictor_4x8_neon

void aom_h_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_64x16 aom_h_predictor_64x16_neon

void aom_h_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_64x32 aom_h_predictor_64x32_neon

void aom_h_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_64x64 aom_h_predictor_64x64_neon

void aom_h_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_8x16 aom_h_predictor_8x16_neon

void aom_h_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_8x32 aom_h_predictor_8x32_neon

void aom_h_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_8x4 aom_h_predictor_8x4_neon

void aom_h_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_h_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_h_predictor_8x8 aom_h_predictor_8x8_neon

void aom_hadamard_16x16_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_hadamard_16x16_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_hadamard_16x16 aom_hadamard_16x16_neon

void aom_hadamard_32x32_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_hadamard_32x32_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_hadamard_32x32 aom_hadamard_32x32_neon

void aom_hadamard_4x4_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_hadamard_4x4_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_hadamard_4x4 aom_hadamard_4x4_neon

void aom_hadamard_8x8_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_hadamard_8x8_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_hadamard_8x8 aom_hadamard_8x8_neon

void aom_hadamard_lp_16x16_c(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
void aom_hadamard_lp_16x16_neon(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
#define aom_hadamard_lp_16x16 aom_hadamard_lp_16x16_neon

void aom_hadamard_lp_8x8_c(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
void aom_hadamard_lp_8x8_neon(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
#define aom_hadamard_lp_8x8 aom_hadamard_lp_8x8_neon

void aom_hadamard_lp_8x8_dual_c(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
void aom_hadamard_lp_8x8_dual_neon(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
#define aom_hadamard_lp_8x8_dual aom_hadamard_lp_8x8_dual_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance128x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance128x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance128x128 aom_highbd_10_masked_sub_pixel_variance128x128_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance128x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance128x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance128x64 aom_highbd_10_masked_sub_pixel_variance128x64_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance16x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance16x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance16x16 aom_highbd_10_masked_sub_pixel_variance16x16_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance16x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance16x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance16x32 aom_highbd_10_masked_sub_pixel_variance16x32_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance16x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance16x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance16x4 aom_highbd_10_masked_sub_pixel_variance16x4_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance16x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance16x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance16x64 aom_highbd_10_masked_sub_pixel_variance16x64_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance16x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance16x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance16x8 aom_highbd_10_masked_sub_pixel_variance16x8_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance32x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance32x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance32x16 aom_highbd_10_masked_sub_pixel_variance32x16_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance32x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance32x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance32x32 aom_highbd_10_masked_sub_pixel_variance32x32_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance32x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance32x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance32x64 aom_highbd_10_masked_sub_pixel_variance32x64_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance32x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance32x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance32x8 aom_highbd_10_masked_sub_pixel_variance32x8_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance4x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance4x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance4x16 aom_highbd_10_masked_sub_pixel_variance4x16_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance4x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance4x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance4x4 aom_highbd_10_masked_sub_pixel_variance4x4_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance4x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance4x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance4x8 aom_highbd_10_masked_sub_pixel_variance4x8_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance64x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance64x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance64x128 aom_highbd_10_masked_sub_pixel_variance64x128_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance64x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance64x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance64x16 aom_highbd_10_masked_sub_pixel_variance64x16_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance64x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance64x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance64x32 aom_highbd_10_masked_sub_pixel_variance64x32_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance64x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance64x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance64x64 aom_highbd_10_masked_sub_pixel_variance64x64_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance8x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance8x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance8x16 aom_highbd_10_masked_sub_pixel_variance8x16_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance8x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance8x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance8x32 aom_highbd_10_masked_sub_pixel_variance8x32_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance8x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance8x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance8x4 aom_highbd_10_masked_sub_pixel_variance8x4_neon

unsigned int aom_highbd_10_masked_sub_pixel_variance8x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_10_masked_sub_pixel_variance8x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_10_masked_sub_pixel_variance8x8 aom_highbd_10_masked_sub_pixel_variance8x8_neon

unsigned int aom_highbd_10_mse16x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_10_mse16x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_10_mse16x16 aom_highbd_10_mse16x16_neon

unsigned int aom_highbd_10_mse16x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_10_mse16x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_10_mse16x8 aom_highbd_10_mse16x8_neon

unsigned int aom_highbd_10_mse8x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_10_mse8x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_10_mse8x16 aom_highbd_10_mse8x16_neon

unsigned int aom_highbd_10_mse8x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_10_mse8x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_10_mse8x8 aom_highbd_10_mse8x8_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance128x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance128x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance128x128 aom_highbd_10_obmc_sub_pixel_variance128x128_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance128x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance128x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance128x64 aom_highbd_10_obmc_sub_pixel_variance128x64_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance16x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance16x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance16x16 aom_highbd_10_obmc_sub_pixel_variance16x16_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance16x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance16x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance16x32 aom_highbd_10_obmc_sub_pixel_variance16x32_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance16x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance16x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance16x4 aom_highbd_10_obmc_sub_pixel_variance16x4_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance16x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance16x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance16x64 aom_highbd_10_obmc_sub_pixel_variance16x64_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance16x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance16x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance16x8 aom_highbd_10_obmc_sub_pixel_variance16x8_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance32x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance32x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance32x16 aom_highbd_10_obmc_sub_pixel_variance32x16_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance32x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance32x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance32x32 aom_highbd_10_obmc_sub_pixel_variance32x32_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance32x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance32x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance32x64 aom_highbd_10_obmc_sub_pixel_variance32x64_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance32x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance32x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance32x8 aom_highbd_10_obmc_sub_pixel_variance32x8_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance4x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance4x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance4x16 aom_highbd_10_obmc_sub_pixel_variance4x16_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance4x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance4x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance4x4 aom_highbd_10_obmc_sub_pixel_variance4x4_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance4x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance4x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance4x8 aom_highbd_10_obmc_sub_pixel_variance4x8_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance64x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance64x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance64x128 aom_highbd_10_obmc_sub_pixel_variance64x128_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance64x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance64x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance64x16 aom_highbd_10_obmc_sub_pixel_variance64x16_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance64x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance64x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance64x32 aom_highbd_10_obmc_sub_pixel_variance64x32_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance64x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance64x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance64x64 aom_highbd_10_obmc_sub_pixel_variance64x64_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance8x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance8x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance8x16 aom_highbd_10_obmc_sub_pixel_variance8x16_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance8x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance8x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance8x32 aom_highbd_10_obmc_sub_pixel_variance8x32_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance8x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance8x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance8x4 aom_highbd_10_obmc_sub_pixel_variance8x4_neon

unsigned int aom_highbd_10_obmc_sub_pixel_variance8x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_sub_pixel_variance8x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_sub_pixel_variance8x8 aom_highbd_10_obmc_sub_pixel_variance8x8_neon

unsigned int aom_highbd_10_obmc_variance128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance128x128 aom_highbd_10_obmc_variance128x128_neon

unsigned int aom_highbd_10_obmc_variance128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance128x64 aom_highbd_10_obmc_variance128x64_neon

unsigned int aom_highbd_10_obmc_variance16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance16x16 aom_highbd_10_obmc_variance16x16_neon

unsigned int aom_highbd_10_obmc_variance16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance16x32 aom_highbd_10_obmc_variance16x32_neon

unsigned int aom_highbd_10_obmc_variance16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance16x4 aom_highbd_10_obmc_variance16x4_neon

unsigned int aom_highbd_10_obmc_variance16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance16x64 aom_highbd_10_obmc_variance16x64_neon

unsigned int aom_highbd_10_obmc_variance16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance16x8 aom_highbd_10_obmc_variance16x8_neon

unsigned int aom_highbd_10_obmc_variance32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance32x16 aom_highbd_10_obmc_variance32x16_neon

unsigned int aom_highbd_10_obmc_variance32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance32x32 aom_highbd_10_obmc_variance32x32_neon

unsigned int aom_highbd_10_obmc_variance32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance32x64 aom_highbd_10_obmc_variance32x64_neon

unsigned int aom_highbd_10_obmc_variance32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance32x8 aom_highbd_10_obmc_variance32x8_neon

unsigned int aom_highbd_10_obmc_variance4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance4x16 aom_highbd_10_obmc_variance4x16_neon

unsigned int aom_highbd_10_obmc_variance4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance4x4 aom_highbd_10_obmc_variance4x4_neon

unsigned int aom_highbd_10_obmc_variance4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance4x8 aom_highbd_10_obmc_variance4x8_neon

unsigned int aom_highbd_10_obmc_variance64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance64x128 aom_highbd_10_obmc_variance64x128_neon

unsigned int aom_highbd_10_obmc_variance64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance64x16 aom_highbd_10_obmc_variance64x16_neon

unsigned int aom_highbd_10_obmc_variance64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance64x32 aom_highbd_10_obmc_variance64x32_neon

unsigned int aom_highbd_10_obmc_variance64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance64x64 aom_highbd_10_obmc_variance64x64_neon

unsigned int aom_highbd_10_obmc_variance8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance8x16 aom_highbd_10_obmc_variance8x16_neon

unsigned int aom_highbd_10_obmc_variance8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance8x32 aom_highbd_10_obmc_variance8x32_neon

unsigned int aom_highbd_10_obmc_variance8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance8x4 aom_highbd_10_obmc_variance8x4_neon

unsigned int aom_highbd_10_obmc_variance8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_10_obmc_variance8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_10_obmc_variance8x8 aom_highbd_10_obmc_variance8x8_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance128x128 aom_highbd_10_sub_pixel_avg_variance128x128_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance128x64 aom_highbd_10_sub_pixel_avg_variance128x64_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance16x16 aom_highbd_10_sub_pixel_avg_variance16x16_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance16x32 aom_highbd_10_sub_pixel_avg_variance16x32_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance16x4 aom_highbd_10_sub_pixel_avg_variance16x4_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance16x64 aom_highbd_10_sub_pixel_avg_variance16x64_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance16x8 aom_highbd_10_sub_pixel_avg_variance16x8_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance32x16 aom_highbd_10_sub_pixel_avg_variance32x16_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance32x32 aom_highbd_10_sub_pixel_avg_variance32x32_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance32x64 aom_highbd_10_sub_pixel_avg_variance32x64_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance32x8 aom_highbd_10_sub_pixel_avg_variance32x8_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance4x16 aom_highbd_10_sub_pixel_avg_variance4x16_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance4x4 aom_highbd_10_sub_pixel_avg_variance4x4_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance4x8 aom_highbd_10_sub_pixel_avg_variance4x8_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance64x128 aom_highbd_10_sub_pixel_avg_variance64x128_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance64x16 aom_highbd_10_sub_pixel_avg_variance64x16_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance64x32 aom_highbd_10_sub_pixel_avg_variance64x32_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance64x64 aom_highbd_10_sub_pixel_avg_variance64x64_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance8x16 aom_highbd_10_sub_pixel_avg_variance8x16_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance8x32 aom_highbd_10_sub_pixel_avg_variance8x32_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance8x4 aom_highbd_10_sub_pixel_avg_variance8x4_neon

uint32_t aom_highbd_10_sub_pixel_avg_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_10_sub_pixel_avg_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_10_sub_pixel_avg_variance8x8 aom_highbd_10_sub_pixel_avg_variance8x8_neon

uint32_t aom_highbd_10_sub_pixel_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance128x128 aom_highbd_10_sub_pixel_variance128x128_neon

uint32_t aom_highbd_10_sub_pixel_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance128x64 aom_highbd_10_sub_pixel_variance128x64_neon

uint32_t aom_highbd_10_sub_pixel_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance16x16 aom_highbd_10_sub_pixel_variance16x16_neon

uint32_t aom_highbd_10_sub_pixel_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance16x32 aom_highbd_10_sub_pixel_variance16x32_neon

uint32_t aom_highbd_10_sub_pixel_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance16x4 aom_highbd_10_sub_pixel_variance16x4_neon

uint32_t aom_highbd_10_sub_pixel_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance16x64 aom_highbd_10_sub_pixel_variance16x64_neon

uint32_t aom_highbd_10_sub_pixel_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance16x8 aom_highbd_10_sub_pixel_variance16x8_neon

uint32_t aom_highbd_10_sub_pixel_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance32x16 aom_highbd_10_sub_pixel_variance32x16_neon

uint32_t aom_highbd_10_sub_pixel_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance32x32 aom_highbd_10_sub_pixel_variance32x32_neon

uint32_t aom_highbd_10_sub_pixel_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance32x64 aom_highbd_10_sub_pixel_variance32x64_neon

uint32_t aom_highbd_10_sub_pixel_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance32x8 aom_highbd_10_sub_pixel_variance32x8_neon

uint32_t aom_highbd_10_sub_pixel_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance4x16 aom_highbd_10_sub_pixel_variance4x16_neon

uint32_t aom_highbd_10_sub_pixel_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance4x4 aom_highbd_10_sub_pixel_variance4x4_neon

uint32_t aom_highbd_10_sub_pixel_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance4x8 aom_highbd_10_sub_pixel_variance4x8_neon

uint32_t aom_highbd_10_sub_pixel_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance64x128 aom_highbd_10_sub_pixel_variance64x128_neon

uint32_t aom_highbd_10_sub_pixel_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance64x16 aom_highbd_10_sub_pixel_variance64x16_neon

uint32_t aom_highbd_10_sub_pixel_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance64x32 aom_highbd_10_sub_pixel_variance64x32_neon

uint32_t aom_highbd_10_sub_pixel_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance64x64 aom_highbd_10_sub_pixel_variance64x64_neon

uint32_t aom_highbd_10_sub_pixel_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance8x16 aom_highbd_10_sub_pixel_variance8x16_neon

uint32_t aom_highbd_10_sub_pixel_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance8x32 aom_highbd_10_sub_pixel_variance8x32_neon

uint32_t aom_highbd_10_sub_pixel_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance8x4 aom_highbd_10_sub_pixel_variance8x4_neon

uint32_t aom_highbd_10_sub_pixel_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_10_sub_pixel_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_sub_pixel_variance8x8 aom_highbd_10_sub_pixel_variance8x8_neon

unsigned int aom_highbd_10_variance128x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance128x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance128x128 aom_highbd_10_variance128x128_neon

unsigned int aom_highbd_10_variance128x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance128x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance128x64 aom_highbd_10_variance128x64_neon

unsigned int aom_highbd_10_variance16x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance16x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance16x16 aom_highbd_10_variance16x16_neon

unsigned int aom_highbd_10_variance16x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance16x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance16x32 aom_highbd_10_variance16x32_neon

unsigned int aom_highbd_10_variance16x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance16x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance16x4 aom_highbd_10_variance16x4_neon

unsigned int aom_highbd_10_variance16x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance16x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance16x64 aom_highbd_10_variance16x64_neon

unsigned int aom_highbd_10_variance16x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance16x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance16x8 aom_highbd_10_variance16x8_neon

unsigned int aom_highbd_10_variance32x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance32x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance32x16 aom_highbd_10_variance32x16_neon

unsigned int aom_highbd_10_variance32x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance32x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance32x32 aom_highbd_10_variance32x32_neon

unsigned int aom_highbd_10_variance32x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance32x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance32x64 aom_highbd_10_variance32x64_neon

unsigned int aom_highbd_10_variance32x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance32x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance32x8 aom_highbd_10_variance32x8_neon

unsigned int aom_highbd_10_variance4x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance4x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance4x16 aom_highbd_10_variance4x16_neon

unsigned int aom_highbd_10_variance4x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance4x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance4x4 aom_highbd_10_variance4x4_neon

unsigned int aom_highbd_10_variance4x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance4x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance4x8 aom_highbd_10_variance4x8_neon

unsigned int aom_highbd_10_variance64x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance64x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance64x128 aom_highbd_10_variance64x128_neon

unsigned int aom_highbd_10_variance64x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance64x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance64x16 aom_highbd_10_variance64x16_neon

unsigned int aom_highbd_10_variance64x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance64x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance64x32 aom_highbd_10_variance64x32_neon

unsigned int aom_highbd_10_variance64x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance64x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance64x64 aom_highbd_10_variance64x64_neon

unsigned int aom_highbd_10_variance8x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance8x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance8x16 aom_highbd_10_variance8x16_neon

unsigned int aom_highbd_10_variance8x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance8x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance8x32 aom_highbd_10_variance8x32_neon

unsigned int aom_highbd_10_variance8x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance8x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance8x4 aom_highbd_10_variance8x4_neon

unsigned int aom_highbd_10_variance8x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_10_variance8x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_10_variance8x8 aom_highbd_10_variance8x8_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance128x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance128x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance128x128 aom_highbd_12_masked_sub_pixel_variance128x128_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance128x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance128x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance128x64 aom_highbd_12_masked_sub_pixel_variance128x64_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance16x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance16x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance16x16 aom_highbd_12_masked_sub_pixel_variance16x16_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance16x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance16x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance16x32 aom_highbd_12_masked_sub_pixel_variance16x32_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance16x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance16x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance16x4 aom_highbd_12_masked_sub_pixel_variance16x4_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance16x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance16x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance16x64 aom_highbd_12_masked_sub_pixel_variance16x64_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance16x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance16x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance16x8 aom_highbd_12_masked_sub_pixel_variance16x8_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance32x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance32x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance32x16 aom_highbd_12_masked_sub_pixel_variance32x16_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance32x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance32x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance32x32 aom_highbd_12_masked_sub_pixel_variance32x32_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance32x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance32x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance32x64 aom_highbd_12_masked_sub_pixel_variance32x64_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance32x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance32x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance32x8 aom_highbd_12_masked_sub_pixel_variance32x8_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance4x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance4x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance4x16 aom_highbd_12_masked_sub_pixel_variance4x16_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance4x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance4x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance4x4 aom_highbd_12_masked_sub_pixel_variance4x4_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance4x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance4x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance4x8 aom_highbd_12_masked_sub_pixel_variance4x8_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance64x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance64x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance64x128 aom_highbd_12_masked_sub_pixel_variance64x128_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance64x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance64x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance64x16 aom_highbd_12_masked_sub_pixel_variance64x16_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance64x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance64x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance64x32 aom_highbd_12_masked_sub_pixel_variance64x32_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance64x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance64x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance64x64 aom_highbd_12_masked_sub_pixel_variance64x64_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance8x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance8x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance8x16 aom_highbd_12_masked_sub_pixel_variance8x16_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance8x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance8x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance8x32 aom_highbd_12_masked_sub_pixel_variance8x32_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance8x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance8x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance8x4 aom_highbd_12_masked_sub_pixel_variance8x4_neon

unsigned int aom_highbd_12_masked_sub_pixel_variance8x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_12_masked_sub_pixel_variance8x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_12_masked_sub_pixel_variance8x8 aom_highbd_12_masked_sub_pixel_variance8x8_neon

unsigned int aom_highbd_12_mse16x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_12_mse16x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_12_mse16x16 aom_highbd_12_mse16x16_neon

unsigned int aom_highbd_12_mse16x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_12_mse16x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_12_mse16x8 aom_highbd_12_mse16x8_neon

unsigned int aom_highbd_12_mse8x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_12_mse8x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_12_mse8x16 aom_highbd_12_mse8x16_neon

unsigned int aom_highbd_12_mse8x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_12_mse8x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
#define aom_highbd_12_mse8x8 aom_highbd_12_mse8x8_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance128x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance128x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance128x128 aom_highbd_12_obmc_sub_pixel_variance128x128_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance128x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance128x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance128x64 aom_highbd_12_obmc_sub_pixel_variance128x64_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance16x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance16x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance16x16 aom_highbd_12_obmc_sub_pixel_variance16x16_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance16x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance16x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance16x32 aom_highbd_12_obmc_sub_pixel_variance16x32_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance16x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance16x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance16x4 aom_highbd_12_obmc_sub_pixel_variance16x4_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance16x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance16x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance16x64 aom_highbd_12_obmc_sub_pixel_variance16x64_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance16x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance16x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance16x8 aom_highbd_12_obmc_sub_pixel_variance16x8_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance32x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance32x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance32x16 aom_highbd_12_obmc_sub_pixel_variance32x16_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance32x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance32x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance32x32 aom_highbd_12_obmc_sub_pixel_variance32x32_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance32x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance32x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance32x64 aom_highbd_12_obmc_sub_pixel_variance32x64_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance32x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance32x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance32x8 aom_highbd_12_obmc_sub_pixel_variance32x8_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance4x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance4x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance4x16 aom_highbd_12_obmc_sub_pixel_variance4x16_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance4x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance4x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance4x4 aom_highbd_12_obmc_sub_pixel_variance4x4_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance4x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance4x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance4x8 aom_highbd_12_obmc_sub_pixel_variance4x8_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance64x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance64x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance64x128 aom_highbd_12_obmc_sub_pixel_variance64x128_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance64x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance64x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance64x16 aom_highbd_12_obmc_sub_pixel_variance64x16_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance64x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance64x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance64x32 aom_highbd_12_obmc_sub_pixel_variance64x32_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance64x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance64x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance64x64 aom_highbd_12_obmc_sub_pixel_variance64x64_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance8x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance8x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance8x16 aom_highbd_12_obmc_sub_pixel_variance8x16_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance8x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance8x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance8x32 aom_highbd_12_obmc_sub_pixel_variance8x32_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance8x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance8x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance8x4 aom_highbd_12_obmc_sub_pixel_variance8x4_neon

unsigned int aom_highbd_12_obmc_sub_pixel_variance8x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_sub_pixel_variance8x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_sub_pixel_variance8x8 aom_highbd_12_obmc_sub_pixel_variance8x8_neon

unsigned int aom_highbd_12_obmc_variance128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance128x128 aom_highbd_12_obmc_variance128x128_neon

unsigned int aom_highbd_12_obmc_variance128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance128x64 aom_highbd_12_obmc_variance128x64_neon

unsigned int aom_highbd_12_obmc_variance16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance16x16 aom_highbd_12_obmc_variance16x16_neon

unsigned int aom_highbd_12_obmc_variance16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance16x32 aom_highbd_12_obmc_variance16x32_neon

unsigned int aom_highbd_12_obmc_variance16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance16x4 aom_highbd_12_obmc_variance16x4_neon

unsigned int aom_highbd_12_obmc_variance16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance16x64 aom_highbd_12_obmc_variance16x64_neon

unsigned int aom_highbd_12_obmc_variance16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance16x8 aom_highbd_12_obmc_variance16x8_neon

unsigned int aom_highbd_12_obmc_variance32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance32x16 aom_highbd_12_obmc_variance32x16_neon

unsigned int aom_highbd_12_obmc_variance32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance32x32 aom_highbd_12_obmc_variance32x32_neon

unsigned int aom_highbd_12_obmc_variance32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance32x64 aom_highbd_12_obmc_variance32x64_neon

unsigned int aom_highbd_12_obmc_variance32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance32x8 aom_highbd_12_obmc_variance32x8_neon

unsigned int aom_highbd_12_obmc_variance4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance4x16 aom_highbd_12_obmc_variance4x16_neon

unsigned int aom_highbd_12_obmc_variance4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance4x4 aom_highbd_12_obmc_variance4x4_neon

unsigned int aom_highbd_12_obmc_variance4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance4x8 aom_highbd_12_obmc_variance4x8_neon

unsigned int aom_highbd_12_obmc_variance64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance64x128 aom_highbd_12_obmc_variance64x128_neon

unsigned int aom_highbd_12_obmc_variance64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance64x16 aom_highbd_12_obmc_variance64x16_neon

unsigned int aom_highbd_12_obmc_variance64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance64x32 aom_highbd_12_obmc_variance64x32_neon

unsigned int aom_highbd_12_obmc_variance64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance64x64 aom_highbd_12_obmc_variance64x64_neon

unsigned int aom_highbd_12_obmc_variance8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance8x16 aom_highbd_12_obmc_variance8x16_neon

unsigned int aom_highbd_12_obmc_variance8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance8x32 aom_highbd_12_obmc_variance8x32_neon

unsigned int aom_highbd_12_obmc_variance8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance8x4 aom_highbd_12_obmc_variance8x4_neon

unsigned int aom_highbd_12_obmc_variance8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_12_obmc_variance8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_12_obmc_variance8x8 aom_highbd_12_obmc_variance8x8_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance128x128 aom_highbd_12_sub_pixel_avg_variance128x128_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance128x64 aom_highbd_12_sub_pixel_avg_variance128x64_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance16x16 aom_highbd_12_sub_pixel_avg_variance16x16_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance16x32 aom_highbd_12_sub_pixel_avg_variance16x32_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance16x4 aom_highbd_12_sub_pixel_avg_variance16x4_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance16x64 aom_highbd_12_sub_pixel_avg_variance16x64_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance16x8 aom_highbd_12_sub_pixel_avg_variance16x8_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance32x16 aom_highbd_12_sub_pixel_avg_variance32x16_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance32x32 aom_highbd_12_sub_pixel_avg_variance32x32_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance32x64 aom_highbd_12_sub_pixel_avg_variance32x64_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance32x8 aom_highbd_12_sub_pixel_avg_variance32x8_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance4x16 aom_highbd_12_sub_pixel_avg_variance4x16_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance4x4 aom_highbd_12_sub_pixel_avg_variance4x4_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance4x8 aom_highbd_12_sub_pixel_avg_variance4x8_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance64x128 aom_highbd_12_sub_pixel_avg_variance64x128_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance64x16 aom_highbd_12_sub_pixel_avg_variance64x16_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance64x32 aom_highbd_12_sub_pixel_avg_variance64x32_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance64x64 aom_highbd_12_sub_pixel_avg_variance64x64_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance8x16 aom_highbd_12_sub_pixel_avg_variance8x16_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance8x32 aom_highbd_12_sub_pixel_avg_variance8x32_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance8x4 aom_highbd_12_sub_pixel_avg_variance8x4_neon

uint32_t aom_highbd_12_sub_pixel_avg_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_12_sub_pixel_avg_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_12_sub_pixel_avg_variance8x8 aom_highbd_12_sub_pixel_avg_variance8x8_neon

uint32_t aom_highbd_12_sub_pixel_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance128x128 aom_highbd_12_sub_pixel_variance128x128_neon

uint32_t aom_highbd_12_sub_pixel_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance128x64 aom_highbd_12_sub_pixel_variance128x64_neon

uint32_t aom_highbd_12_sub_pixel_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance16x16 aom_highbd_12_sub_pixel_variance16x16_neon

uint32_t aom_highbd_12_sub_pixel_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance16x32 aom_highbd_12_sub_pixel_variance16x32_neon

uint32_t aom_highbd_12_sub_pixel_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance16x4 aom_highbd_12_sub_pixel_variance16x4_neon

uint32_t aom_highbd_12_sub_pixel_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance16x64 aom_highbd_12_sub_pixel_variance16x64_neon

uint32_t aom_highbd_12_sub_pixel_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance16x8 aom_highbd_12_sub_pixel_variance16x8_neon

uint32_t aom_highbd_12_sub_pixel_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance32x16 aom_highbd_12_sub_pixel_variance32x16_neon

uint32_t aom_highbd_12_sub_pixel_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance32x32 aom_highbd_12_sub_pixel_variance32x32_neon

uint32_t aom_highbd_12_sub_pixel_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance32x64 aom_highbd_12_sub_pixel_variance32x64_neon

uint32_t aom_highbd_12_sub_pixel_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance32x8 aom_highbd_12_sub_pixel_variance32x8_neon

uint32_t aom_highbd_12_sub_pixel_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance4x16 aom_highbd_12_sub_pixel_variance4x16_neon

uint32_t aom_highbd_12_sub_pixel_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance4x4 aom_highbd_12_sub_pixel_variance4x4_neon

uint32_t aom_highbd_12_sub_pixel_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance4x8 aom_highbd_12_sub_pixel_variance4x8_neon

uint32_t aom_highbd_12_sub_pixel_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance64x128 aom_highbd_12_sub_pixel_variance64x128_neon

uint32_t aom_highbd_12_sub_pixel_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance64x16 aom_highbd_12_sub_pixel_variance64x16_neon

uint32_t aom_highbd_12_sub_pixel_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance64x32 aom_highbd_12_sub_pixel_variance64x32_neon

uint32_t aom_highbd_12_sub_pixel_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance64x64 aom_highbd_12_sub_pixel_variance64x64_neon

uint32_t aom_highbd_12_sub_pixel_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance8x16 aom_highbd_12_sub_pixel_variance8x16_neon

uint32_t aom_highbd_12_sub_pixel_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance8x32 aom_highbd_12_sub_pixel_variance8x32_neon

uint32_t aom_highbd_12_sub_pixel_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance8x4 aom_highbd_12_sub_pixel_variance8x4_neon

uint32_t aom_highbd_12_sub_pixel_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_12_sub_pixel_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_sub_pixel_variance8x8 aom_highbd_12_sub_pixel_variance8x8_neon

unsigned int aom_highbd_12_variance128x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance128x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance128x128 aom_highbd_12_variance128x128_neon

unsigned int aom_highbd_12_variance128x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance128x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance128x64 aom_highbd_12_variance128x64_neon

unsigned int aom_highbd_12_variance16x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance16x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance16x16 aom_highbd_12_variance16x16_neon

unsigned int aom_highbd_12_variance16x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance16x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance16x32 aom_highbd_12_variance16x32_neon

unsigned int aom_highbd_12_variance16x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance16x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance16x4 aom_highbd_12_variance16x4_neon

unsigned int aom_highbd_12_variance16x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance16x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance16x64 aom_highbd_12_variance16x64_neon

unsigned int aom_highbd_12_variance16x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance16x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance16x8 aom_highbd_12_variance16x8_neon

unsigned int aom_highbd_12_variance32x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance32x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance32x16 aom_highbd_12_variance32x16_neon

unsigned int aom_highbd_12_variance32x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance32x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance32x32 aom_highbd_12_variance32x32_neon

unsigned int aom_highbd_12_variance32x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance32x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance32x64 aom_highbd_12_variance32x64_neon

unsigned int aom_highbd_12_variance32x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance32x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance32x8 aom_highbd_12_variance32x8_neon

unsigned int aom_highbd_12_variance4x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance4x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance4x16 aom_highbd_12_variance4x16_neon

unsigned int aom_highbd_12_variance4x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance4x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance4x4 aom_highbd_12_variance4x4_neon

unsigned int aom_highbd_12_variance4x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance4x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance4x8 aom_highbd_12_variance4x8_neon

unsigned int aom_highbd_12_variance64x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance64x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance64x128 aom_highbd_12_variance64x128_neon

unsigned int aom_highbd_12_variance64x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance64x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance64x16 aom_highbd_12_variance64x16_neon

unsigned int aom_highbd_12_variance64x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance64x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance64x32 aom_highbd_12_variance64x32_neon

unsigned int aom_highbd_12_variance64x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance64x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance64x64 aom_highbd_12_variance64x64_neon

unsigned int aom_highbd_12_variance8x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance8x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance8x16 aom_highbd_12_variance8x16_neon

unsigned int aom_highbd_12_variance8x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance8x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance8x32 aom_highbd_12_variance8x32_neon

unsigned int aom_highbd_12_variance8x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance8x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance8x4 aom_highbd_12_variance8x4_neon

unsigned int aom_highbd_12_variance8x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_12_variance8x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_12_variance8x8 aom_highbd_12_variance8x8_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance128x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance128x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance128x128 aom_highbd_8_masked_sub_pixel_variance128x128_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance128x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance128x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance128x64 aom_highbd_8_masked_sub_pixel_variance128x64_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance16x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance16x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance16x16 aom_highbd_8_masked_sub_pixel_variance16x16_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance16x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance16x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance16x32 aom_highbd_8_masked_sub_pixel_variance16x32_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance16x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance16x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance16x4 aom_highbd_8_masked_sub_pixel_variance16x4_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance16x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance16x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance16x64 aom_highbd_8_masked_sub_pixel_variance16x64_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance16x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance16x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance16x8 aom_highbd_8_masked_sub_pixel_variance16x8_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance32x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance32x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance32x16 aom_highbd_8_masked_sub_pixel_variance32x16_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance32x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance32x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance32x32 aom_highbd_8_masked_sub_pixel_variance32x32_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance32x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance32x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance32x64 aom_highbd_8_masked_sub_pixel_variance32x64_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance32x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance32x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance32x8 aom_highbd_8_masked_sub_pixel_variance32x8_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance4x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance4x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance4x16 aom_highbd_8_masked_sub_pixel_variance4x16_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance4x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance4x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance4x4 aom_highbd_8_masked_sub_pixel_variance4x4_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance4x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance4x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance4x8 aom_highbd_8_masked_sub_pixel_variance4x8_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance64x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance64x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance64x128 aom_highbd_8_masked_sub_pixel_variance64x128_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance64x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance64x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance64x16 aom_highbd_8_masked_sub_pixel_variance64x16_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance64x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance64x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance64x32 aom_highbd_8_masked_sub_pixel_variance64x32_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance64x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance64x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance64x64 aom_highbd_8_masked_sub_pixel_variance64x64_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance8x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance8x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance8x16 aom_highbd_8_masked_sub_pixel_variance8x16_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance8x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance8x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance8x32 aom_highbd_8_masked_sub_pixel_variance8x32_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance8x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance8x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance8x4 aom_highbd_8_masked_sub_pixel_variance8x4_neon

unsigned int aom_highbd_8_masked_sub_pixel_variance8x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_highbd_8_masked_sub_pixel_variance8x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_highbd_8_masked_sub_pixel_variance8x8 aom_highbd_8_masked_sub_pixel_variance8x8_neon

unsigned int aom_highbd_8_mse16x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse16x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse16x16_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_highbd_8_mse16x16)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_highbd_8_mse16x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse16x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse16x8_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_highbd_8_mse16x8)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_highbd_8_mse8x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse8x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse8x16_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_highbd_8_mse8x16)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_highbd_8_mse8x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse8x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_highbd_8_mse8x8_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_highbd_8_mse8x8)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_highbd_8_obmc_sub_pixel_variance128x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance128x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance128x128 aom_highbd_8_obmc_sub_pixel_variance128x128_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance128x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance128x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance128x64 aom_highbd_8_obmc_sub_pixel_variance128x64_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance16x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance16x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance16x16 aom_highbd_8_obmc_sub_pixel_variance16x16_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance16x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance16x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance16x32 aom_highbd_8_obmc_sub_pixel_variance16x32_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance16x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance16x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance16x4 aom_highbd_8_obmc_sub_pixel_variance16x4_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance16x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance16x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance16x64 aom_highbd_8_obmc_sub_pixel_variance16x64_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance16x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance16x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance16x8 aom_highbd_8_obmc_sub_pixel_variance16x8_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance32x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance32x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance32x16 aom_highbd_8_obmc_sub_pixel_variance32x16_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance32x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance32x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance32x32 aom_highbd_8_obmc_sub_pixel_variance32x32_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance32x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance32x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance32x64 aom_highbd_8_obmc_sub_pixel_variance32x64_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance32x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance32x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance32x8 aom_highbd_8_obmc_sub_pixel_variance32x8_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance4x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance4x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance4x16 aom_highbd_8_obmc_sub_pixel_variance4x16_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance4x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance4x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance4x4 aom_highbd_8_obmc_sub_pixel_variance4x4_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance4x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance4x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance4x8 aom_highbd_8_obmc_sub_pixel_variance4x8_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance64x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance64x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance64x128 aom_highbd_8_obmc_sub_pixel_variance64x128_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance64x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance64x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance64x16 aom_highbd_8_obmc_sub_pixel_variance64x16_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance64x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance64x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance64x32 aom_highbd_8_obmc_sub_pixel_variance64x32_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance64x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance64x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance64x64 aom_highbd_8_obmc_sub_pixel_variance64x64_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance8x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance8x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance8x16 aom_highbd_8_obmc_sub_pixel_variance8x16_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance8x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance8x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance8x32 aom_highbd_8_obmc_sub_pixel_variance8x32_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance8x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance8x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance8x4 aom_highbd_8_obmc_sub_pixel_variance8x4_neon

unsigned int aom_highbd_8_obmc_sub_pixel_variance8x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_sub_pixel_variance8x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_sub_pixel_variance8x8 aom_highbd_8_obmc_sub_pixel_variance8x8_neon

unsigned int aom_highbd_8_obmc_variance128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance128x128 aom_highbd_8_obmc_variance128x128_neon

unsigned int aom_highbd_8_obmc_variance128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance128x64 aom_highbd_8_obmc_variance128x64_neon

unsigned int aom_highbd_8_obmc_variance16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance16x16 aom_highbd_8_obmc_variance16x16_neon

unsigned int aom_highbd_8_obmc_variance16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance16x32 aom_highbd_8_obmc_variance16x32_neon

unsigned int aom_highbd_8_obmc_variance16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance16x4 aom_highbd_8_obmc_variance16x4_neon

unsigned int aom_highbd_8_obmc_variance16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance16x64 aom_highbd_8_obmc_variance16x64_neon

unsigned int aom_highbd_8_obmc_variance16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance16x8 aom_highbd_8_obmc_variance16x8_neon

unsigned int aom_highbd_8_obmc_variance32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance32x16 aom_highbd_8_obmc_variance32x16_neon

unsigned int aom_highbd_8_obmc_variance32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance32x32 aom_highbd_8_obmc_variance32x32_neon

unsigned int aom_highbd_8_obmc_variance32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance32x64 aom_highbd_8_obmc_variance32x64_neon

unsigned int aom_highbd_8_obmc_variance32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance32x8 aom_highbd_8_obmc_variance32x8_neon

unsigned int aom_highbd_8_obmc_variance4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance4x16 aom_highbd_8_obmc_variance4x16_neon

unsigned int aom_highbd_8_obmc_variance4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance4x4 aom_highbd_8_obmc_variance4x4_neon

unsigned int aom_highbd_8_obmc_variance4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance4x8 aom_highbd_8_obmc_variance4x8_neon

unsigned int aom_highbd_8_obmc_variance64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance64x128 aom_highbd_8_obmc_variance64x128_neon

unsigned int aom_highbd_8_obmc_variance64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance64x16 aom_highbd_8_obmc_variance64x16_neon

unsigned int aom_highbd_8_obmc_variance64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance64x32 aom_highbd_8_obmc_variance64x32_neon

unsigned int aom_highbd_8_obmc_variance64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance64x64 aom_highbd_8_obmc_variance64x64_neon

unsigned int aom_highbd_8_obmc_variance8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance8x16 aom_highbd_8_obmc_variance8x16_neon

unsigned int aom_highbd_8_obmc_variance8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance8x32 aom_highbd_8_obmc_variance8x32_neon

unsigned int aom_highbd_8_obmc_variance8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance8x4 aom_highbd_8_obmc_variance8x4_neon

unsigned int aom_highbd_8_obmc_variance8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_highbd_8_obmc_variance8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_highbd_8_obmc_variance8x8 aom_highbd_8_obmc_variance8x8_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance128x128 aom_highbd_8_sub_pixel_avg_variance128x128_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance128x64 aom_highbd_8_sub_pixel_avg_variance128x64_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance16x16 aom_highbd_8_sub_pixel_avg_variance16x16_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance16x32 aom_highbd_8_sub_pixel_avg_variance16x32_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance16x4 aom_highbd_8_sub_pixel_avg_variance16x4_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance16x64 aom_highbd_8_sub_pixel_avg_variance16x64_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance16x8 aom_highbd_8_sub_pixel_avg_variance16x8_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance32x16 aom_highbd_8_sub_pixel_avg_variance32x16_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance32x32 aom_highbd_8_sub_pixel_avg_variance32x32_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance32x64 aom_highbd_8_sub_pixel_avg_variance32x64_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance32x8 aom_highbd_8_sub_pixel_avg_variance32x8_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance4x16 aom_highbd_8_sub_pixel_avg_variance4x16_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance4x4 aom_highbd_8_sub_pixel_avg_variance4x4_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance4x8 aom_highbd_8_sub_pixel_avg_variance4x8_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance64x128 aom_highbd_8_sub_pixel_avg_variance64x128_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance64x16 aom_highbd_8_sub_pixel_avg_variance64x16_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance64x32 aom_highbd_8_sub_pixel_avg_variance64x32_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance64x64 aom_highbd_8_sub_pixel_avg_variance64x64_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance8x16 aom_highbd_8_sub_pixel_avg_variance8x16_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance8x32 aom_highbd_8_sub_pixel_avg_variance8x32_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance8x4 aom_highbd_8_sub_pixel_avg_variance8x4_neon

uint32_t aom_highbd_8_sub_pixel_avg_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_highbd_8_sub_pixel_avg_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_highbd_8_sub_pixel_avg_variance8x8 aom_highbd_8_sub_pixel_avg_variance8x8_neon

uint32_t aom_highbd_8_sub_pixel_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance128x128 aom_highbd_8_sub_pixel_variance128x128_neon

uint32_t aom_highbd_8_sub_pixel_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance128x64 aom_highbd_8_sub_pixel_variance128x64_neon

uint32_t aom_highbd_8_sub_pixel_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance16x16 aom_highbd_8_sub_pixel_variance16x16_neon

uint32_t aom_highbd_8_sub_pixel_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance16x32 aom_highbd_8_sub_pixel_variance16x32_neon

uint32_t aom_highbd_8_sub_pixel_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance16x4 aom_highbd_8_sub_pixel_variance16x4_neon

uint32_t aom_highbd_8_sub_pixel_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance16x64 aom_highbd_8_sub_pixel_variance16x64_neon

uint32_t aom_highbd_8_sub_pixel_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance16x8 aom_highbd_8_sub_pixel_variance16x8_neon

uint32_t aom_highbd_8_sub_pixel_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance32x16 aom_highbd_8_sub_pixel_variance32x16_neon

uint32_t aom_highbd_8_sub_pixel_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance32x32 aom_highbd_8_sub_pixel_variance32x32_neon

uint32_t aom_highbd_8_sub_pixel_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance32x64 aom_highbd_8_sub_pixel_variance32x64_neon

uint32_t aom_highbd_8_sub_pixel_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance32x8 aom_highbd_8_sub_pixel_variance32x8_neon

uint32_t aom_highbd_8_sub_pixel_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance4x16 aom_highbd_8_sub_pixel_variance4x16_neon

uint32_t aom_highbd_8_sub_pixel_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance4x4 aom_highbd_8_sub_pixel_variance4x4_neon

uint32_t aom_highbd_8_sub_pixel_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance4x8 aom_highbd_8_sub_pixel_variance4x8_neon

uint32_t aom_highbd_8_sub_pixel_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance64x128 aom_highbd_8_sub_pixel_variance64x128_neon

uint32_t aom_highbd_8_sub_pixel_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance64x16 aom_highbd_8_sub_pixel_variance64x16_neon

uint32_t aom_highbd_8_sub_pixel_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance64x32 aom_highbd_8_sub_pixel_variance64x32_neon

uint32_t aom_highbd_8_sub_pixel_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance64x64 aom_highbd_8_sub_pixel_variance64x64_neon

uint32_t aom_highbd_8_sub_pixel_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance8x16 aom_highbd_8_sub_pixel_variance8x16_neon

uint32_t aom_highbd_8_sub_pixel_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance8x32 aom_highbd_8_sub_pixel_variance8x32_neon

uint32_t aom_highbd_8_sub_pixel_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance8x4 aom_highbd_8_sub_pixel_variance8x4_neon

uint32_t aom_highbd_8_sub_pixel_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_highbd_8_sub_pixel_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_sub_pixel_variance8x8 aom_highbd_8_sub_pixel_variance8x8_neon

unsigned int aom_highbd_8_variance128x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance128x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance128x128 aom_highbd_8_variance128x128_neon

unsigned int aom_highbd_8_variance128x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance128x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance128x64 aom_highbd_8_variance128x64_neon

unsigned int aom_highbd_8_variance16x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance16x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance16x16 aom_highbd_8_variance16x16_neon

unsigned int aom_highbd_8_variance16x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance16x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance16x32 aom_highbd_8_variance16x32_neon

unsigned int aom_highbd_8_variance16x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance16x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance16x4 aom_highbd_8_variance16x4_neon

unsigned int aom_highbd_8_variance16x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance16x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance16x64 aom_highbd_8_variance16x64_neon

unsigned int aom_highbd_8_variance16x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance16x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance16x8 aom_highbd_8_variance16x8_neon

unsigned int aom_highbd_8_variance32x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance32x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance32x16 aom_highbd_8_variance32x16_neon

unsigned int aom_highbd_8_variance32x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance32x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance32x32 aom_highbd_8_variance32x32_neon

unsigned int aom_highbd_8_variance32x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance32x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance32x64 aom_highbd_8_variance32x64_neon

unsigned int aom_highbd_8_variance32x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance32x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance32x8 aom_highbd_8_variance32x8_neon

unsigned int aom_highbd_8_variance4x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance4x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance4x16 aom_highbd_8_variance4x16_neon

unsigned int aom_highbd_8_variance4x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance4x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance4x4 aom_highbd_8_variance4x4_neon

unsigned int aom_highbd_8_variance4x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance4x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance4x8 aom_highbd_8_variance4x8_neon

unsigned int aom_highbd_8_variance64x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance64x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance64x128 aom_highbd_8_variance64x128_neon

unsigned int aom_highbd_8_variance64x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance64x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance64x16 aom_highbd_8_variance64x16_neon

unsigned int aom_highbd_8_variance64x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance64x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance64x32 aom_highbd_8_variance64x32_neon

unsigned int aom_highbd_8_variance64x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance64x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance64x64 aom_highbd_8_variance64x64_neon

unsigned int aom_highbd_8_variance8x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance8x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance8x16 aom_highbd_8_variance8x16_neon

unsigned int aom_highbd_8_variance8x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance8x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance8x32 aom_highbd_8_variance8x32_neon

unsigned int aom_highbd_8_variance8x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance8x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance8x4 aom_highbd_8_variance8x4_neon

unsigned int aom_highbd_8_variance8x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
unsigned int aom_highbd_8_variance8x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_highbd_8_variance8x8 aom_highbd_8_variance8x8_neon

unsigned int aom_highbd_avg_4x4_c(const uint8_t *, int p);
unsigned int aom_highbd_avg_4x4_neon(const uint8_t *, int p);
#define aom_highbd_avg_4x4 aom_highbd_avg_4x4_neon

unsigned int aom_highbd_avg_8x8_c(const uint8_t *, int p);
unsigned int aom_highbd_avg_8x8_neon(const uint8_t *, int p);
#define aom_highbd_avg_8x8 aom_highbd_avg_8x8_neon

void aom_highbd_blend_a64_d16_mask_c(uint8_t *dst, uint32_t dst_stride, const CONV_BUF_TYPE *src0, uint32_t src0_stride, const CONV_BUF_TYPE *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, ConvolveParams *conv_params, const int bd);
void aom_highbd_blend_a64_d16_mask_neon(uint8_t *dst, uint32_t dst_stride, const CONV_BUF_TYPE *src0, uint32_t src0_stride, const CONV_BUF_TYPE *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, ConvolveParams *conv_params, const int bd);
#define aom_highbd_blend_a64_d16_mask aom_highbd_blend_a64_d16_mask_neon

void aom_highbd_blend_a64_hmask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h, int bd);
void aom_highbd_blend_a64_hmask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h, int bd);
#define aom_highbd_blend_a64_hmask aom_highbd_blend_a64_hmask_neon

void aom_highbd_blend_a64_mask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, int bd);
void aom_highbd_blend_a64_mask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, int bd);
#define aom_highbd_blend_a64_mask aom_highbd_blend_a64_mask_neon

void aom_highbd_blend_a64_vmask_c(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h, int bd);
void aom_highbd_blend_a64_vmask_neon(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h, int bd);
#define aom_highbd_blend_a64_vmask aom_highbd_blend_a64_vmask_neon

void aom_highbd_comp_avg_pred_c(uint8_t *comp_pred8, const uint8_t *pred8, int width, int height, const uint8_t *ref8, int ref_stride);
void aom_highbd_comp_avg_pred_neon(uint8_t *comp_pred8, const uint8_t *pred8, int width, int height, const uint8_t *ref8, int ref_stride);
#define aom_highbd_comp_avg_pred aom_highbd_comp_avg_pred_neon

void aom_highbd_comp_mask_pred_c(uint8_t *comp_pred, const uint8_t *pred8, int width, int height, const uint8_t *ref8, int ref_stride, const uint8_t *mask, int mask_stride, int invert_mask);
void aom_highbd_comp_mask_pred_neon(uint8_t *comp_pred, const uint8_t *pred8, int width, int height, const uint8_t *ref8, int ref_stride, const uint8_t *mask, int mask_stride, int invert_mask);
#define aom_highbd_comp_mask_pred aom_highbd_comp_mask_pred_neon

void aom_highbd_convolve8_horiz_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bd);
void aom_highbd_convolve8_horiz_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bd);
#define aom_highbd_convolve8_horiz aom_highbd_convolve8_horiz_neon

void aom_highbd_convolve8_vert_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bd);
void aom_highbd_convolve8_vert_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bd);
#define aom_highbd_convolve8_vert aom_highbd_convolve8_vert_neon

void aom_highbd_convolve_copy_c(const uint16_t *src, ptrdiff_t src_stride, uint16_t *dst, ptrdiff_t dst_stride, int w, int h);
void aom_highbd_convolve_copy_neon(const uint16_t *src, ptrdiff_t src_stride, uint16_t *dst, ptrdiff_t dst_stride, int w, int h);
#define aom_highbd_convolve_copy aom_highbd_convolve_copy_neon

void aom_highbd_dc_128_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_16x16 aom_highbd_dc_128_predictor_16x16_neon

void aom_highbd_dc_128_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_16x32 aom_highbd_dc_128_predictor_16x32_neon

void aom_highbd_dc_128_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_16x4 aom_highbd_dc_128_predictor_16x4_neon

void aom_highbd_dc_128_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_16x64 aom_highbd_dc_128_predictor_16x64_neon

void aom_highbd_dc_128_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_16x8 aom_highbd_dc_128_predictor_16x8_neon

void aom_highbd_dc_128_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_32x16 aom_highbd_dc_128_predictor_32x16_neon

void aom_highbd_dc_128_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_32x32 aom_highbd_dc_128_predictor_32x32_neon

void aom_highbd_dc_128_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_32x64 aom_highbd_dc_128_predictor_32x64_neon

void aom_highbd_dc_128_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_32x8 aom_highbd_dc_128_predictor_32x8_neon

void aom_highbd_dc_128_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_4x16 aom_highbd_dc_128_predictor_4x16_neon

void aom_highbd_dc_128_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_4x4 aom_highbd_dc_128_predictor_4x4_neon

void aom_highbd_dc_128_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_4x8 aom_highbd_dc_128_predictor_4x8_neon

void aom_highbd_dc_128_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_64x16 aom_highbd_dc_128_predictor_64x16_neon

void aom_highbd_dc_128_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_64x32 aom_highbd_dc_128_predictor_64x32_neon

void aom_highbd_dc_128_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_64x64 aom_highbd_dc_128_predictor_64x64_neon

void aom_highbd_dc_128_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_8x16 aom_highbd_dc_128_predictor_8x16_neon

void aom_highbd_dc_128_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_8x32 aom_highbd_dc_128_predictor_8x32_neon

void aom_highbd_dc_128_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_8x4 aom_highbd_dc_128_predictor_8x4_neon

void aom_highbd_dc_128_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_128_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_128_predictor_8x8 aom_highbd_dc_128_predictor_8x8_neon

void aom_highbd_dc_left_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_16x16 aom_highbd_dc_left_predictor_16x16_neon

void aom_highbd_dc_left_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_16x32 aom_highbd_dc_left_predictor_16x32_neon

void aom_highbd_dc_left_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_16x4 aom_highbd_dc_left_predictor_16x4_neon

void aom_highbd_dc_left_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_16x64 aom_highbd_dc_left_predictor_16x64_neon

void aom_highbd_dc_left_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_16x8 aom_highbd_dc_left_predictor_16x8_neon

void aom_highbd_dc_left_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_32x16 aom_highbd_dc_left_predictor_32x16_neon

void aom_highbd_dc_left_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_32x32 aom_highbd_dc_left_predictor_32x32_neon

void aom_highbd_dc_left_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_32x64 aom_highbd_dc_left_predictor_32x64_neon

void aom_highbd_dc_left_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_32x8 aom_highbd_dc_left_predictor_32x8_neon

void aom_highbd_dc_left_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_4x16 aom_highbd_dc_left_predictor_4x16_neon

void aom_highbd_dc_left_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_4x4 aom_highbd_dc_left_predictor_4x4_neon

void aom_highbd_dc_left_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_4x8 aom_highbd_dc_left_predictor_4x8_neon

void aom_highbd_dc_left_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_64x16 aom_highbd_dc_left_predictor_64x16_neon

void aom_highbd_dc_left_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_64x32 aom_highbd_dc_left_predictor_64x32_neon

void aom_highbd_dc_left_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_64x64 aom_highbd_dc_left_predictor_64x64_neon

void aom_highbd_dc_left_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_8x16 aom_highbd_dc_left_predictor_8x16_neon

void aom_highbd_dc_left_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_8x32 aom_highbd_dc_left_predictor_8x32_neon

void aom_highbd_dc_left_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_8x4 aom_highbd_dc_left_predictor_8x4_neon

void aom_highbd_dc_left_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_left_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_left_predictor_8x8 aom_highbd_dc_left_predictor_8x8_neon

void aom_highbd_dc_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_16x16 aom_highbd_dc_predictor_16x16_neon

void aom_highbd_dc_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_16x32 aom_highbd_dc_predictor_16x32_neon

void aom_highbd_dc_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_16x4 aom_highbd_dc_predictor_16x4_neon

void aom_highbd_dc_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_16x64 aom_highbd_dc_predictor_16x64_neon

void aom_highbd_dc_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_16x8 aom_highbd_dc_predictor_16x8_neon

void aom_highbd_dc_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_32x16 aom_highbd_dc_predictor_32x16_neon

void aom_highbd_dc_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_32x32 aom_highbd_dc_predictor_32x32_neon

void aom_highbd_dc_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_32x64 aom_highbd_dc_predictor_32x64_neon

void aom_highbd_dc_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_32x8 aom_highbd_dc_predictor_32x8_neon

void aom_highbd_dc_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_4x16 aom_highbd_dc_predictor_4x16_neon

void aom_highbd_dc_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_4x4 aom_highbd_dc_predictor_4x4_neon

void aom_highbd_dc_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_4x8 aom_highbd_dc_predictor_4x8_neon

void aom_highbd_dc_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_64x16 aom_highbd_dc_predictor_64x16_neon

void aom_highbd_dc_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_64x32 aom_highbd_dc_predictor_64x32_neon

void aom_highbd_dc_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_64x64 aom_highbd_dc_predictor_64x64_neon

void aom_highbd_dc_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_8x16 aom_highbd_dc_predictor_8x16_neon

void aom_highbd_dc_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_8x32 aom_highbd_dc_predictor_8x32_neon

void aom_highbd_dc_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_8x4 aom_highbd_dc_predictor_8x4_neon

void aom_highbd_dc_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_predictor_8x8 aom_highbd_dc_predictor_8x8_neon

void aom_highbd_dc_top_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_16x16 aom_highbd_dc_top_predictor_16x16_neon

void aom_highbd_dc_top_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_16x32 aom_highbd_dc_top_predictor_16x32_neon

void aom_highbd_dc_top_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_16x4 aom_highbd_dc_top_predictor_16x4_neon

void aom_highbd_dc_top_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_16x64 aom_highbd_dc_top_predictor_16x64_neon

void aom_highbd_dc_top_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_16x8 aom_highbd_dc_top_predictor_16x8_neon

void aom_highbd_dc_top_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_32x16 aom_highbd_dc_top_predictor_32x16_neon

void aom_highbd_dc_top_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_32x32 aom_highbd_dc_top_predictor_32x32_neon

void aom_highbd_dc_top_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_32x64 aom_highbd_dc_top_predictor_32x64_neon

void aom_highbd_dc_top_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_32x8 aom_highbd_dc_top_predictor_32x8_neon

void aom_highbd_dc_top_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_4x16 aom_highbd_dc_top_predictor_4x16_neon

void aom_highbd_dc_top_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_4x4 aom_highbd_dc_top_predictor_4x4_neon

void aom_highbd_dc_top_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_4x8 aom_highbd_dc_top_predictor_4x8_neon

void aom_highbd_dc_top_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_64x16 aom_highbd_dc_top_predictor_64x16_neon

void aom_highbd_dc_top_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_64x32 aom_highbd_dc_top_predictor_64x32_neon

void aom_highbd_dc_top_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_64x64 aom_highbd_dc_top_predictor_64x64_neon

void aom_highbd_dc_top_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_8x16 aom_highbd_dc_top_predictor_8x16_neon

void aom_highbd_dc_top_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_8x32 aom_highbd_dc_top_predictor_8x32_neon

void aom_highbd_dc_top_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_8x4 aom_highbd_dc_top_predictor_8x4_neon

void aom_highbd_dc_top_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_dc_top_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_dc_top_predictor_8x8 aom_highbd_dc_top_predictor_8x8_neon

void aom_highbd_h_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_16x16 aom_highbd_h_predictor_16x16_neon

void aom_highbd_h_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_16x32 aom_highbd_h_predictor_16x32_neon

void aom_highbd_h_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_16x4 aom_highbd_h_predictor_16x4_neon

void aom_highbd_h_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_16x64 aom_highbd_h_predictor_16x64_neon

void aom_highbd_h_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_16x8 aom_highbd_h_predictor_16x8_neon

void aom_highbd_h_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_32x16 aom_highbd_h_predictor_32x16_neon

void aom_highbd_h_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_32x32 aom_highbd_h_predictor_32x32_neon

void aom_highbd_h_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_32x64 aom_highbd_h_predictor_32x64_neon

void aom_highbd_h_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_32x8 aom_highbd_h_predictor_32x8_neon

void aom_highbd_h_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_4x16 aom_highbd_h_predictor_4x16_neon

void aom_highbd_h_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_4x4 aom_highbd_h_predictor_4x4_neon

void aom_highbd_h_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_4x8 aom_highbd_h_predictor_4x8_neon

void aom_highbd_h_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_64x16 aom_highbd_h_predictor_64x16_neon

void aom_highbd_h_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_64x32 aom_highbd_h_predictor_64x32_neon

void aom_highbd_h_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_64x64 aom_highbd_h_predictor_64x64_neon

void aom_highbd_h_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_8x16 aom_highbd_h_predictor_8x16_neon

void aom_highbd_h_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_8x32 aom_highbd_h_predictor_8x32_neon

void aom_highbd_h_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_8x4 aom_highbd_h_predictor_8x4_neon

void aom_highbd_h_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_h_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_h_predictor_8x8 aom_highbd_h_predictor_8x8_neon

void aom_highbd_hadamard_16x16_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_highbd_hadamard_16x16_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_highbd_hadamard_16x16 aom_highbd_hadamard_16x16_neon

void aom_highbd_hadamard_32x32_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_highbd_hadamard_32x32_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_highbd_hadamard_32x32 aom_highbd_hadamard_32x32_neon

void aom_highbd_hadamard_8x8_c(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
void aom_highbd_hadamard_8x8_neon(const int16_t *src_diff, ptrdiff_t src_stride, tran_low_t *coeff);
#define aom_highbd_hadamard_8x8 aom_highbd_hadamard_8x8_neon

void aom_highbd_lpf_horizontal_14_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_horizontal_14_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_horizontal_14 aom_highbd_lpf_horizontal_14_neon

void aom_highbd_lpf_horizontal_14_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1,int bd);
void aom_highbd_lpf_horizontal_14_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1,int bd);
#define aom_highbd_lpf_horizontal_14_dual aom_highbd_lpf_horizontal_14_dual_neon

void aom_highbd_lpf_horizontal_4_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_horizontal_4_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_horizontal_4 aom_highbd_lpf_horizontal_4_neon

void aom_highbd_lpf_horizontal_4_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_horizontal_4_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_horizontal_4_dual aom_highbd_lpf_horizontal_4_dual_neon

void aom_highbd_lpf_horizontal_6_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_horizontal_6_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_horizontal_6 aom_highbd_lpf_horizontal_6_neon

void aom_highbd_lpf_horizontal_6_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_horizontal_6_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_horizontal_6_dual aom_highbd_lpf_horizontal_6_dual_neon

void aom_highbd_lpf_horizontal_8_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_horizontal_8_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_horizontal_8 aom_highbd_lpf_horizontal_8_neon

void aom_highbd_lpf_horizontal_8_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_horizontal_8_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_horizontal_8_dual aom_highbd_lpf_horizontal_8_dual_neon

void aom_highbd_lpf_vertical_14_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_vertical_14_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_vertical_14 aom_highbd_lpf_vertical_14_neon

void aom_highbd_lpf_vertical_14_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_vertical_14_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_vertical_14_dual aom_highbd_lpf_vertical_14_dual_neon

void aom_highbd_lpf_vertical_4_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_vertical_4_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_vertical_4 aom_highbd_lpf_vertical_4_neon

void aom_highbd_lpf_vertical_4_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_vertical_4_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_vertical_4_dual aom_highbd_lpf_vertical_4_dual_neon

void aom_highbd_lpf_vertical_6_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_vertical_6_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_vertical_6 aom_highbd_lpf_vertical_6_neon

void aom_highbd_lpf_vertical_6_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_vertical_6_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_vertical_6_dual aom_highbd_lpf_vertical_6_dual_neon

void aom_highbd_lpf_vertical_8_c(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
void aom_highbd_lpf_vertical_8_neon(uint16_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh, int bd);
#define aom_highbd_lpf_vertical_8 aom_highbd_lpf_vertical_8_neon

void aom_highbd_lpf_vertical_8_dual_c(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
void aom_highbd_lpf_vertical_8_dual_neon(uint16_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1, int bd);
#define aom_highbd_lpf_vertical_8_dual aom_highbd_lpf_vertical_8_dual_neon

unsigned int aom_highbd_masked_sad128x128_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad128x128_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad128x128 aom_highbd_masked_sad128x128_neon

unsigned int aom_highbd_masked_sad128x64_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad128x64_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad128x64 aom_highbd_masked_sad128x64_neon

unsigned int aom_highbd_masked_sad16x16_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad16x16_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad16x16 aom_highbd_masked_sad16x16_neon

unsigned int aom_highbd_masked_sad16x32_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad16x32_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad16x32 aom_highbd_masked_sad16x32_neon

unsigned int aom_highbd_masked_sad16x4_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad16x4_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad16x4 aom_highbd_masked_sad16x4_neon

unsigned int aom_highbd_masked_sad16x64_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad16x64_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad16x64 aom_highbd_masked_sad16x64_neon

unsigned int aom_highbd_masked_sad16x8_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad16x8_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad16x8 aom_highbd_masked_sad16x8_neon

unsigned int aom_highbd_masked_sad32x16_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad32x16_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad32x16 aom_highbd_masked_sad32x16_neon

unsigned int aom_highbd_masked_sad32x32_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad32x32_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad32x32 aom_highbd_masked_sad32x32_neon

unsigned int aom_highbd_masked_sad32x64_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad32x64_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad32x64 aom_highbd_masked_sad32x64_neon

unsigned int aom_highbd_masked_sad32x8_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad32x8_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad32x8 aom_highbd_masked_sad32x8_neon

unsigned int aom_highbd_masked_sad4x16_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad4x16_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad4x16 aom_highbd_masked_sad4x16_neon

unsigned int aom_highbd_masked_sad4x4_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad4x4_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad4x4 aom_highbd_masked_sad4x4_neon

unsigned int aom_highbd_masked_sad4x8_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad4x8_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad4x8 aom_highbd_masked_sad4x8_neon

unsigned int aom_highbd_masked_sad64x128_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad64x128_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad64x128 aom_highbd_masked_sad64x128_neon

unsigned int aom_highbd_masked_sad64x16_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad64x16_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad64x16 aom_highbd_masked_sad64x16_neon

unsigned int aom_highbd_masked_sad64x32_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad64x32_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad64x32 aom_highbd_masked_sad64x32_neon

unsigned int aom_highbd_masked_sad64x64_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad64x64_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad64x64 aom_highbd_masked_sad64x64_neon

unsigned int aom_highbd_masked_sad8x16_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad8x16_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad8x16 aom_highbd_masked_sad8x16_neon

unsigned int aom_highbd_masked_sad8x32_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad8x32_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad8x32 aom_highbd_masked_sad8x32_neon

unsigned int aom_highbd_masked_sad8x4_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad8x4_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad8x4 aom_highbd_masked_sad8x4_neon

unsigned int aom_highbd_masked_sad8x8_c(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_highbd_masked_sad8x8_neon(const uint8_t *src8, int src_stride, const uint8_t *ref8, int ref_stride, const uint8_t *second_pred8, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_highbd_masked_sad8x8 aom_highbd_masked_sad8x8_neon

void aom_highbd_minmax_8x8_c(const uint8_t *s, int p, const uint8_t *d, int dp, int *min, int *max);
void aom_highbd_minmax_8x8_neon(const uint8_t *s, int p, const uint8_t *d, int dp, int *min, int *max);
#define aom_highbd_minmax_8x8 aom_highbd_minmax_8x8_neon

unsigned int aom_highbd_obmc_sad128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad128x128 aom_highbd_obmc_sad128x128_neon

unsigned int aom_highbd_obmc_sad128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad128x64 aom_highbd_obmc_sad128x64_neon

unsigned int aom_highbd_obmc_sad16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad16x16 aom_highbd_obmc_sad16x16_neon

unsigned int aom_highbd_obmc_sad16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad16x32 aom_highbd_obmc_sad16x32_neon

unsigned int aom_highbd_obmc_sad16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad16x4 aom_highbd_obmc_sad16x4_neon

unsigned int aom_highbd_obmc_sad16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad16x64 aom_highbd_obmc_sad16x64_neon

unsigned int aom_highbd_obmc_sad16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad16x8 aom_highbd_obmc_sad16x8_neon

unsigned int aom_highbd_obmc_sad32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad32x16 aom_highbd_obmc_sad32x16_neon

unsigned int aom_highbd_obmc_sad32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad32x32 aom_highbd_obmc_sad32x32_neon

unsigned int aom_highbd_obmc_sad32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad32x64 aom_highbd_obmc_sad32x64_neon

unsigned int aom_highbd_obmc_sad32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad32x8 aom_highbd_obmc_sad32x8_neon

unsigned int aom_highbd_obmc_sad4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad4x16 aom_highbd_obmc_sad4x16_neon

unsigned int aom_highbd_obmc_sad4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad4x4 aom_highbd_obmc_sad4x4_neon

unsigned int aom_highbd_obmc_sad4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad4x8 aom_highbd_obmc_sad4x8_neon

unsigned int aom_highbd_obmc_sad64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad64x128 aom_highbd_obmc_sad64x128_neon

unsigned int aom_highbd_obmc_sad64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad64x16 aom_highbd_obmc_sad64x16_neon

unsigned int aom_highbd_obmc_sad64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad64x32 aom_highbd_obmc_sad64x32_neon

unsigned int aom_highbd_obmc_sad64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad64x64 aom_highbd_obmc_sad64x64_neon

unsigned int aom_highbd_obmc_sad8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad8x16 aom_highbd_obmc_sad8x16_neon

unsigned int aom_highbd_obmc_sad8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad8x32 aom_highbd_obmc_sad8x32_neon

unsigned int aom_highbd_obmc_sad8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad8x4 aom_highbd_obmc_sad8x4_neon

unsigned int aom_highbd_obmc_sad8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_highbd_obmc_sad8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_highbd_obmc_sad8x8 aom_highbd_obmc_sad8x8_neon

void aom_highbd_paeth_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_16x16 aom_highbd_paeth_predictor_16x16_neon

void aom_highbd_paeth_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_16x32 aom_highbd_paeth_predictor_16x32_neon

void aom_highbd_paeth_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_16x4 aom_highbd_paeth_predictor_16x4_neon

void aom_highbd_paeth_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_16x64 aom_highbd_paeth_predictor_16x64_neon

void aom_highbd_paeth_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_16x8 aom_highbd_paeth_predictor_16x8_neon

void aom_highbd_paeth_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_32x16 aom_highbd_paeth_predictor_32x16_neon

void aom_highbd_paeth_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_32x32 aom_highbd_paeth_predictor_32x32_neon

void aom_highbd_paeth_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_32x64 aom_highbd_paeth_predictor_32x64_neon

void aom_highbd_paeth_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_32x8 aom_highbd_paeth_predictor_32x8_neon

void aom_highbd_paeth_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_4x16 aom_highbd_paeth_predictor_4x16_neon

void aom_highbd_paeth_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_4x4 aom_highbd_paeth_predictor_4x4_neon

void aom_highbd_paeth_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_4x8 aom_highbd_paeth_predictor_4x8_neon

void aom_highbd_paeth_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_64x16 aom_highbd_paeth_predictor_64x16_neon

void aom_highbd_paeth_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_64x32 aom_highbd_paeth_predictor_64x32_neon

void aom_highbd_paeth_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_64x64 aom_highbd_paeth_predictor_64x64_neon

void aom_highbd_paeth_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_8x16 aom_highbd_paeth_predictor_8x16_neon

void aom_highbd_paeth_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_8x32 aom_highbd_paeth_predictor_8x32_neon

void aom_highbd_paeth_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_8x4 aom_highbd_paeth_predictor_8x4_neon

void aom_highbd_paeth_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_paeth_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_paeth_predictor_8x8 aom_highbd_paeth_predictor_8x8_neon

void aom_highbd_quantize_b_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b aom_highbd_quantize_b_neon

void aom_highbd_quantize_b_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_32x32_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b_32x32 aom_highbd_quantize_b_32x32_neon

void aom_highbd_quantize_b_32x32_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_32x32_adaptive_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b_32x32_adaptive aom_highbd_quantize_b_32x32_adaptive_neon

void aom_highbd_quantize_b_64x64_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_64x64_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b_64x64 aom_highbd_quantize_b_64x64_neon

void aom_highbd_quantize_b_64x64_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_64x64_adaptive_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b_64x64_adaptive aom_highbd_quantize_b_64x64_adaptive_neon

void aom_highbd_quantize_b_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_highbd_quantize_b_adaptive_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_highbd_quantize_b_adaptive aom_highbd_quantize_b_adaptive_neon

unsigned int aom_highbd_sad128x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad128x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad128x128 aom_highbd_sad128x128_neon

unsigned int aom_highbd_sad128x128_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad128x128_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad128x128_avg aom_highbd_sad128x128_avg_neon

void aom_highbd_sad128x128x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad128x128x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad128x128x3d aom_highbd_sad128x128x3d_neon

void aom_highbd_sad128x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad128x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad128x128x4d aom_highbd_sad128x128x4d_neon

unsigned int aom_highbd_sad128x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad128x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad128x64 aom_highbd_sad128x64_neon

unsigned int aom_highbd_sad128x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad128x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad128x64_avg aom_highbd_sad128x64_avg_neon

void aom_highbd_sad128x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad128x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad128x64x3d aom_highbd_sad128x64x3d_neon

void aom_highbd_sad128x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad128x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad128x64x4d aom_highbd_sad128x64x4d_neon

unsigned int aom_highbd_sad16x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad16x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad16x16 aom_highbd_sad16x16_neon

unsigned int aom_highbd_sad16x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad16x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad16x16_avg aom_highbd_sad16x16_avg_neon

void aom_highbd_sad16x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x16x3d aom_highbd_sad16x16x3d_neon

void aom_highbd_sad16x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x16x4d aom_highbd_sad16x16x4d_neon

unsigned int aom_highbd_sad16x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad16x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad16x32 aom_highbd_sad16x32_neon

unsigned int aom_highbd_sad16x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad16x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad16x32_avg aom_highbd_sad16x32_avg_neon

void aom_highbd_sad16x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x32x3d aom_highbd_sad16x32x3d_neon

void aom_highbd_sad16x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x32x4d aom_highbd_sad16x32x4d_neon

unsigned int aom_highbd_sad16x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad16x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad16x4 aom_highbd_sad16x4_neon

void aom_highbd_sad16x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x4x3d aom_highbd_sad16x4x3d_neon

void aom_highbd_sad16x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x4x4d aom_highbd_sad16x4x4d_neon

unsigned int aom_highbd_sad16x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad16x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad16x64 aom_highbd_sad16x64_neon

unsigned int aom_highbd_sad16x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad16x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad16x64_avg aom_highbd_sad16x64_avg_neon

void aom_highbd_sad16x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x64x3d aom_highbd_sad16x64x3d_neon

void aom_highbd_sad16x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x64x4d aom_highbd_sad16x64x4d_neon

unsigned int aom_highbd_sad16x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad16x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad16x8 aom_highbd_sad16x8_neon

unsigned int aom_highbd_sad16x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad16x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad16x8_avg aom_highbd_sad16x8_avg_neon

void aom_highbd_sad16x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x8x3d aom_highbd_sad16x8x3d_neon

void aom_highbd_sad16x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad16x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad16x8x4d aom_highbd_sad16x8x4d_neon

unsigned int aom_highbd_sad32x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad32x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad32x16 aom_highbd_sad32x16_neon

unsigned int aom_highbd_sad32x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad32x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad32x16_avg aom_highbd_sad32x16_avg_neon

void aom_highbd_sad32x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x16x3d aom_highbd_sad32x16x3d_neon

void aom_highbd_sad32x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x16x4d aom_highbd_sad32x16x4d_neon

unsigned int aom_highbd_sad32x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad32x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad32x32 aom_highbd_sad32x32_neon

unsigned int aom_highbd_sad32x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad32x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad32x32_avg aom_highbd_sad32x32_avg_neon

void aom_highbd_sad32x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x32x3d aom_highbd_sad32x32x3d_neon

void aom_highbd_sad32x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x32x4d aom_highbd_sad32x32x4d_neon

unsigned int aom_highbd_sad32x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad32x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad32x64 aom_highbd_sad32x64_neon

unsigned int aom_highbd_sad32x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad32x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad32x64_avg aom_highbd_sad32x64_avg_neon

void aom_highbd_sad32x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x64x3d aom_highbd_sad32x64x3d_neon

void aom_highbd_sad32x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x64x4d aom_highbd_sad32x64x4d_neon

unsigned int aom_highbd_sad32x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad32x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad32x8 aom_highbd_sad32x8_neon

unsigned int aom_highbd_sad32x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad32x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad32x8_avg aom_highbd_sad32x8_avg_neon

void aom_highbd_sad32x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x8x3d aom_highbd_sad32x8x3d_neon

void aom_highbd_sad32x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad32x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad32x8x4d aom_highbd_sad32x8x4d_neon

unsigned int aom_highbd_sad4x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad4x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad4x16 aom_highbd_sad4x16_neon

void aom_highbd_sad4x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x16x3d aom_highbd_sad4x16x3d_neon

void aom_highbd_sad4x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x16x4d aom_highbd_sad4x16x4d_neon

unsigned int aom_highbd_sad4x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad4x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad4x4 aom_highbd_sad4x4_neon

void aom_highbd_sad4x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x4x3d aom_highbd_sad4x4x3d_neon

void aom_highbd_sad4x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x4x4d aom_highbd_sad4x4x4d_neon

unsigned int aom_highbd_sad4x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad4x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad4x8 aom_highbd_sad4x8_neon

void aom_highbd_sad4x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x8x3d aom_highbd_sad4x8x3d_neon

void aom_highbd_sad4x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad4x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad4x8x4d aom_highbd_sad4x8x4d_neon

unsigned int aom_highbd_sad64x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad64x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad64x128 aom_highbd_sad64x128_neon

unsigned int aom_highbd_sad64x128_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad64x128_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad64x128_avg aom_highbd_sad64x128_avg_neon

void aom_highbd_sad64x128x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x128x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x128x3d aom_highbd_sad64x128x3d_neon

void aom_highbd_sad64x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x128x4d aom_highbd_sad64x128x4d_neon

unsigned int aom_highbd_sad64x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad64x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad64x16 aom_highbd_sad64x16_neon

unsigned int aom_highbd_sad64x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad64x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad64x16_avg aom_highbd_sad64x16_avg_neon

void aom_highbd_sad64x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x16x3d aom_highbd_sad64x16x3d_neon

void aom_highbd_sad64x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x16x4d aom_highbd_sad64x16x4d_neon

unsigned int aom_highbd_sad64x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad64x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad64x32 aom_highbd_sad64x32_neon

unsigned int aom_highbd_sad64x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad64x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad64x32_avg aom_highbd_sad64x32_avg_neon

void aom_highbd_sad64x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x32x3d aom_highbd_sad64x32x3d_neon

void aom_highbd_sad64x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x32x4d aom_highbd_sad64x32x4d_neon

unsigned int aom_highbd_sad64x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad64x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad64x64 aom_highbd_sad64x64_neon

unsigned int aom_highbd_sad64x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad64x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad64x64_avg aom_highbd_sad64x64_avg_neon

void aom_highbd_sad64x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x64x3d aom_highbd_sad64x64x3d_neon

void aom_highbd_sad64x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad64x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad64x64x4d aom_highbd_sad64x64x4d_neon

unsigned int aom_highbd_sad8x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad8x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad8x16 aom_highbd_sad8x16_neon

unsigned int aom_highbd_sad8x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad8x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad8x16_avg aom_highbd_sad8x16_avg_neon

void aom_highbd_sad8x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x16x3d aom_highbd_sad8x16x3d_neon

void aom_highbd_sad8x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x16x4d aom_highbd_sad8x16x4d_neon

unsigned int aom_highbd_sad8x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad8x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad8x32 aom_highbd_sad8x32_neon

unsigned int aom_highbd_sad8x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad8x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad8x32_avg aom_highbd_sad8x32_avg_neon

void aom_highbd_sad8x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x32x3d aom_highbd_sad8x32x3d_neon

void aom_highbd_sad8x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x32x4d aom_highbd_sad8x32x4d_neon

unsigned int aom_highbd_sad8x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad8x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad8x4 aom_highbd_sad8x4_neon

void aom_highbd_sad8x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x4x3d aom_highbd_sad8x4x3d_neon

void aom_highbd_sad8x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x4x4d aom_highbd_sad8x4x4d_neon

unsigned int aom_highbd_sad8x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad8x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad8x8 aom_highbd_sad8x8_neon

unsigned int aom_highbd_sad8x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_highbd_sad8x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_highbd_sad8x8_avg aom_highbd_sad8x8_avg_neon

void aom_highbd_sad8x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x8x3d aom_highbd_sad8x8x3d_neon

void aom_highbd_sad8x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad8x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad8x8x4d aom_highbd_sad8x8x4d_neon

unsigned int aom_highbd_sad_skip_128x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_128x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_128x128 aom_highbd_sad_skip_128x128_neon

void aom_highbd_sad_skip_128x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_128x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_128x128x4d aom_highbd_sad_skip_128x128x4d_neon

unsigned int aom_highbd_sad_skip_128x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_128x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_128x64 aom_highbd_sad_skip_128x64_neon

void aom_highbd_sad_skip_128x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_128x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_128x64x4d aom_highbd_sad_skip_128x64x4d_neon

unsigned int aom_highbd_sad_skip_16x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_16x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_16x16 aom_highbd_sad_skip_16x16_neon

void aom_highbd_sad_skip_16x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_16x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_16x16x4d aom_highbd_sad_skip_16x16x4d_neon

unsigned int aom_highbd_sad_skip_16x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_16x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_16x32 aom_highbd_sad_skip_16x32_neon

void aom_highbd_sad_skip_16x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_16x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_16x32x4d aom_highbd_sad_skip_16x32x4d_neon

unsigned int aom_highbd_sad_skip_16x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_16x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_16x64 aom_highbd_sad_skip_16x64_neon

void aom_highbd_sad_skip_16x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_16x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_16x64x4d aom_highbd_sad_skip_16x64x4d_neon

unsigned int aom_highbd_sad_skip_32x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_32x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_32x16 aom_highbd_sad_skip_32x16_neon

void aom_highbd_sad_skip_32x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_32x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_32x16x4d aom_highbd_sad_skip_32x16x4d_neon

unsigned int aom_highbd_sad_skip_32x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_32x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_32x32 aom_highbd_sad_skip_32x32_neon

void aom_highbd_sad_skip_32x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_32x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_32x32x4d aom_highbd_sad_skip_32x32x4d_neon

unsigned int aom_highbd_sad_skip_32x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_32x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_32x64 aom_highbd_sad_skip_32x64_neon

void aom_highbd_sad_skip_32x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_32x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_32x64x4d aom_highbd_sad_skip_32x64x4d_neon

unsigned int aom_highbd_sad_skip_4x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_4x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_4x16 aom_highbd_sad_skip_4x16_neon

void aom_highbd_sad_skip_4x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_4x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_4x16x4d aom_highbd_sad_skip_4x16x4d_neon

unsigned int aom_highbd_sad_skip_64x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_64x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_64x128 aom_highbd_sad_skip_64x128_neon

void aom_highbd_sad_skip_64x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_64x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_64x128x4d aom_highbd_sad_skip_64x128x4d_neon

unsigned int aom_highbd_sad_skip_64x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_64x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_64x16 aom_highbd_sad_skip_64x16_neon

void aom_highbd_sad_skip_64x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_64x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_64x16x4d aom_highbd_sad_skip_64x16x4d_neon

unsigned int aom_highbd_sad_skip_64x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_64x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_64x32 aom_highbd_sad_skip_64x32_neon

void aom_highbd_sad_skip_64x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_64x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_64x32x4d aom_highbd_sad_skip_64x32x4d_neon

unsigned int aom_highbd_sad_skip_64x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_64x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_64x64 aom_highbd_sad_skip_64x64_neon

void aom_highbd_sad_skip_64x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_64x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_64x64x4d aom_highbd_sad_skip_64x64x4d_neon

unsigned int aom_highbd_sad_skip_8x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_8x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_8x16 aom_highbd_sad_skip_8x16_neon

void aom_highbd_sad_skip_8x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_8x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_8x16x4d aom_highbd_sad_skip_8x16x4d_neon

unsigned int aom_highbd_sad_skip_8x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_highbd_sad_skip_8x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_highbd_sad_skip_8x32 aom_highbd_sad_skip_8x32_neon

void aom_highbd_sad_skip_8x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_highbd_sad_skip_8x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_highbd_sad_skip_8x32x4d aom_highbd_sad_skip_8x32x4d_neon

void aom_highbd_smooth_h_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_16x16 aom_highbd_smooth_h_predictor_16x16_neon

void aom_highbd_smooth_h_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_16x32 aom_highbd_smooth_h_predictor_16x32_neon

void aom_highbd_smooth_h_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_16x4 aom_highbd_smooth_h_predictor_16x4_neon

void aom_highbd_smooth_h_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_16x64 aom_highbd_smooth_h_predictor_16x64_neon

void aom_highbd_smooth_h_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_16x8 aom_highbd_smooth_h_predictor_16x8_neon

void aom_highbd_smooth_h_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_32x16 aom_highbd_smooth_h_predictor_32x16_neon

void aom_highbd_smooth_h_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_32x32 aom_highbd_smooth_h_predictor_32x32_neon

void aom_highbd_smooth_h_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_32x64 aom_highbd_smooth_h_predictor_32x64_neon

void aom_highbd_smooth_h_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_32x8 aom_highbd_smooth_h_predictor_32x8_neon

void aom_highbd_smooth_h_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_4x16 aom_highbd_smooth_h_predictor_4x16_neon

void aom_highbd_smooth_h_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_4x4 aom_highbd_smooth_h_predictor_4x4_neon

void aom_highbd_smooth_h_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_4x8 aom_highbd_smooth_h_predictor_4x8_neon

void aom_highbd_smooth_h_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_64x16 aom_highbd_smooth_h_predictor_64x16_neon

void aom_highbd_smooth_h_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_64x32 aom_highbd_smooth_h_predictor_64x32_neon

void aom_highbd_smooth_h_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_64x64 aom_highbd_smooth_h_predictor_64x64_neon

void aom_highbd_smooth_h_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_8x16 aom_highbd_smooth_h_predictor_8x16_neon

void aom_highbd_smooth_h_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_8x32 aom_highbd_smooth_h_predictor_8x32_neon

void aom_highbd_smooth_h_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_8x4 aom_highbd_smooth_h_predictor_8x4_neon

void aom_highbd_smooth_h_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_h_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_h_predictor_8x8 aom_highbd_smooth_h_predictor_8x8_neon

void aom_highbd_smooth_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_16x16 aom_highbd_smooth_predictor_16x16_neon

void aom_highbd_smooth_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_16x32 aom_highbd_smooth_predictor_16x32_neon

void aom_highbd_smooth_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_16x4 aom_highbd_smooth_predictor_16x4_neon

void aom_highbd_smooth_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_16x64 aom_highbd_smooth_predictor_16x64_neon

void aom_highbd_smooth_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_16x8 aom_highbd_smooth_predictor_16x8_neon

void aom_highbd_smooth_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_32x16 aom_highbd_smooth_predictor_32x16_neon

void aom_highbd_smooth_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_32x32 aom_highbd_smooth_predictor_32x32_neon

void aom_highbd_smooth_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_32x64 aom_highbd_smooth_predictor_32x64_neon

void aom_highbd_smooth_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_32x8 aom_highbd_smooth_predictor_32x8_neon

void aom_highbd_smooth_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_4x16 aom_highbd_smooth_predictor_4x16_neon

void aom_highbd_smooth_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_4x4 aom_highbd_smooth_predictor_4x4_neon

void aom_highbd_smooth_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_4x8 aom_highbd_smooth_predictor_4x8_neon

void aom_highbd_smooth_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_64x16 aom_highbd_smooth_predictor_64x16_neon

void aom_highbd_smooth_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_64x32 aom_highbd_smooth_predictor_64x32_neon

void aom_highbd_smooth_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_64x64 aom_highbd_smooth_predictor_64x64_neon

void aom_highbd_smooth_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_8x16 aom_highbd_smooth_predictor_8x16_neon

void aom_highbd_smooth_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_8x32 aom_highbd_smooth_predictor_8x32_neon

void aom_highbd_smooth_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_8x4 aom_highbd_smooth_predictor_8x4_neon

void aom_highbd_smooth_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_predictor_8x8 aom_highbd_smooth_predictor_8x8_neon

void aom_highbd_smooth_v_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_16x16 aom_highbd_smooth_v_predictor_16x16_neon

void aom_highbd_smooth_v_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_16x32 aom_highbd_smooth_v_predictor_16x32_neon

void aom_highbd_smooth_v_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_16x4 aom_highbd_smooth_v_predictor_16x4_neon

void aom_highbd_smooth_v_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_16x64 aom_highbd_smooth_v_predictor_16x64_neon

void aom_highbd_smooth_v_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_16x8 aom_highbd_smooth_v_predictor_16x8_neon

void aom_highbd_smooth_v_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_32x16 aom_highbd_smooth_v_predictor_32x16_neon

void aom_highbd_smooth_v_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_32x32 aom_highbd_smooth_v_predictor_32x32_neon

void aom_highbd_smooth_v_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_32x64 aom_highbd_smooth_v_predictor_32x64_neon

void aom_highbd_smooth_v_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_32x8 aom_highbd_smooth_v_predictor_32x8_neon

void aom_highbd_smooth_v_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_4x16 aom_highbd_smooth_v_predictor_4x16_neon

void aom_highbd_smooth_v_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_4x4 aom_highbd_smooth_v_predictor_4x4_neon

void aom_highbd_smooth_v_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_4x8 aom_highbd_smooth_v_predictor_4x8_neon

void aom_highbd_smooth_v_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_64x16 aom_highbd_smooth_v_predictor_64x16_neon

void aom_highbd_smooth_v_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_64x32 aom_highbd_smooth_v_predictor_64x32_neon

void aom_highbd_smooth_v_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_64x64 aom_highbd_smooth_v_predictor_64x64_neon

void aom_highbd_smooth_v_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_8x16 aom_highbd_smooth_v_predictor_8x16_neon

void aom_highbd_smooth_v_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_8x32 aom_highbd_smooth_v_predictor_8x32_neon

void aom_highbd_smooth_v_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_8x4 aom_highbd_smooth_v_predictor_8x4_neon

void aom_highbd_smooth_v_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_smooth_v_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_smooth_v_predictor_8x8 aom_highbd_smooth_v_predictor_8x8_neon

int64_t aom_highbd_sse_c(const uint8_t *a8, int a_stride, const uint8_t *b8,int b_stride, int width, int height);
int64_t aom_highbd_sse_neon(const uint8_t *a8, int a_stride, const uint8_t *b8,int b_stride, int width, int height);
#define aom_highbd_sse aom_highbd_sse_neon

void aom_highbd_ssim_parms_8x8_c(const uint16_t *s, int sp, const uint16_t *r, int rp, uint32_t *sum_s, uint32_t *sum_r, uint32_t *sum_sq_s, uint32_t *sum_sq_r, uint32_t *sum_sxr);
#define aom_highbd_ssim_parms_8x8 aom_highbd_ssim_parms_8x8_c

void aom_highbd_subtract_block_c(int rows, int cols, int16_t *diff_ptr, ptrdiff_t diff_stride, const uint8_t *src_ptr, ptrdiff_t src_stride, const uint8_t *pred_ptr, ptrdiff_t pred_stride);
void aom_highbd_subtract_block_neon(int rows, int cols, int16_t *diff_ptr, ptrdiff_t diff_stride, const uint8_t *src_ptr, ptrdiff_t src_stride, const uint8_t *pred_ptr, ptrdiff_t pred_stride);
#define aom_highbd_subtract_block aom_highbd_subtract_block_neon

void aom_highbd_v_predictor_16x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_16x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_16x16 aom_highbd_v_predictor_16x16_neon

void aom_highbd_v_predictor_16x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_16x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_16x32 aom_highbd_v_predictor_16x32_neon

void aom_highbd_v_predictor_16x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_16x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_16x4 aom_highbd_v_predictor_16x4_neon

void aom_highbd_v_predictor_16x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_16x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_16x64 aom_highbd_v_predictor_16x64_neon

void aom_highbd_v_predictor_16x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_16x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_16x8 aom_highbd_v_predictor_16x8_neon

void aom_highbd_v_predictor_32x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_32x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_32x16 aom_highbd_v_predictor_32x16_neon

void aom_highbd_v_predictor_32x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_32x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_32x32 aom_highbd_v_predictor_32x32_neon

void aom_highbd_v_predictor_32x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_32x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_32x64 aom_highbd_v_predictor_32x64_neon

void aom_highbd_v_predictor_32x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_32x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_32x8 aom_highbd_v_predictor_32x8_neon

void aom_highbd_v_predictor_4x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_4x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_4x16 aom_highbd_v_predictor_4x16_neon

void aom_highbd_v_predictor_4x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_4x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_4x4 aom_highbd_v_predictor_4x4_neon

void aom_highbd_v_predictor_4x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_4x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_4x8 aom_highbd_v_predictor_4x8_neon

void aom_highbd_v_predictor_64x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_64x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_64x16 aom_highbd_v_predictor_64x16_neon

void aom_highbd_v_predictor_64x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_64x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_64x32 aom_highbd_v_predictor_64x32_neon

void aom_highbd_v_predictor_64x64_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_64x64_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_64x64 aom_highbd_v_predictor_64x64_neon

void aom_highbd_v_predictor_8x16_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_8x16_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_8x16 aom_highbd_v_predictor_8x16_neon

void aom_highbd_v_predictor_8x32_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_8x32_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_8x32 aom_highbd_v_predictor_8x32_neon

void aom_highbd_v_predictor_8x4_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_8x4_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_8x4 aom_highbd_v_predictor_8x4_neon

void aom_highbd_v_predictor_8x8_c(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
void aom_highbd_v_predictor_8x8_neon(uint16_t *dst, ptrdiff_t y_stride, const uint16_t *above, const uint16_t *left, int bd);
#define aom_highbd_v_predictor_8x8 aom_highbd_v_predictor_8x8_neon

void aom_ifft16x16_float_c(const float *input, float *temp, float *output);
#define aom_ifft16x16_float aom_ifft16x16_float_c

void aom_ifft2x2_float_c(const float *input, float *temp, float *output);
#define aom_ifft2x2_float aom_ifft2x2_float_c

void aom_ifft32x32_float_c(const float *input, float *temp, float *output);
#define aom_ifft32x32_float aom_ifft32x32_float_c

void aom_ifft4x4_float_c(const float *input, float *temp, float *output);
#define aom_ifft4x4_float aom_ifft4x4_float_c

void aom_ifft8x8_float_c(const float *input, float *temp, float *output);
#define aom_ifft8x8_float aom_ifft8x8_float_c

void aom_int_pro_col_c(int16_t *vbuf, const uint8_t *ref, const int ref_stride, const int width, const int height, int norm_factor);
void aom_int_pro_col_neon(int16_t *vbuf, const uint8_t *ref, const int ref_stride, const int width, const int height, int norm_factor);
#define aom_int_pro_col aom_int_pro_col_neon

void aom_int_pro_row_c(int16_t *hbuf, const uint8_t *ref, const int ref_stride, const int width, const int height, int norm_factor);
void aom_int_pro_row_neon(int16_t *hbuf, const uint8_t *ref, const int ref_stride, const int width, const int height, int norm_factor);
#define aom_int_pro_row aom_int_pro_row_neon

void aom_lowbd_blend_a64_d16_mask_c(uint8_t *dst, uint32_t dst_stride, const CONV_BUF_TYPE *src0, uint32_t src0_stride, const CONV_BUF_TYPE *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, ConvolveParams *conv_params);
void aom_lowbd_blend_a64_d16_mask_neon(uint8_t *dst, uint32_t dst_stride, const CONV_BUF_TYPE *src0, uint32_t src0_stride, const CONV_BUF_TYPE *src1, uint32_t src1_stride, const uint8_t *mask, uint32_t mask_stride, int w, int h, int subw, int subh, ConvolveParams *conv_params);
#define aom_lowbd_blend_a64_d16_mask aom_lowbd_blend_a64_d16_mask_neon

void aom_lpf_horizontal_14_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_horizontal_14_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_horizontal_14 aom_lpf_horizontal_14_neon

void aom_lpf_horizontal_14_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_horizontal_14_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_horizontal_14_dual aom_lpf_horizontal_14_dual_neon

void aom_lpf_horizontal_14_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_horizontal_14_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_horizontal_14_quad aom_lpf_horizontal_14_quad_neon

void aom_lpf_horizontal_4_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_horizontal_4_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_horizontal_4 aom_lpf_horizontal_4_neon

void aom_lpf_horizontal_4_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_horizontal_4_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_horizontal_4_dual aom_lpf_horizontal_4_dual_neon

void aom_lpf_horizontal_4_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_horizontal_4_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_horizontal_4_quad aom_lpf_horizontal_4_quad_neon

void aom_lpf_horizontal_6_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_horizontal_6_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_horizontal_6 aom_lpf_horizontal_6_neon

void aom_lpf_horizontal_6_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_horizontal_6_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_horizontal_6_dual aom_lpf_horizontal_6_dual_neon

void aom_lpf_horizontal_6_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_horizontal_6_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_horizontal_6_quad aom_lpf_horizontal_6_quad_neon

void aom_lpf_horizontal_8_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_horizontal_8_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_horizontal_8 aom_lpf_horizontal_8_neon

void aom_lpf_horizontal_8_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_horizontal_8_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_horizontal_8_dual aom_lpf_horizontal_8_dual_neon

void aom_lpf_horizontal_8_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_horizontal_8_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_horizontal_8_quad aom_lpf_horizontal_8_quad_neon

void aom_lpf_vertical_14_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_vertical_14_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_vertical_14 aom_lpf_vertical_14_neon

void aom_lpf_vertical_14_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_vertical_14_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_vertical_14_dual aom_lpf_vertical_14_dual_neon

void aom_lpf_vertical_14_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_vertical_14_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_vertical_14_quad aom_lpf_vertical_14_quad_neon

void aom_lpf_vertical_4_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_vertical_4_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_vertical_4 aom_lpf_vertical_4_neon

void aom_lpf_vertical_4_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_vertical_4_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_vertical_4_dual aom_lpf_vertical_4_dual_neon

void aom_lpf_vertical_4_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_vertical_4_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_vertical_4_quad aom_lpf_vertical_4_quad_neon

void aom_lpf_vertical_6_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_vertical_6_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_vertical_6 aom_lpf_vertical_6_neon

void aom_lpf_vertical_6_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_vertical_6_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_vertical_6_dual aom_lpf_vertical_6_dual_neon

void aom_lpf_vertical_6_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_vertical_6_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_vertical_6_quad aom_lpf_vertical_6_quad_neon

void aom_lpf_vertical_8_c(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
void aom_lpf_vertical_8_neon(uint8_t *s, int pitch, const uint8_t *blimit, const uint8_t *limit, const uint8_t *thresh);
#define aom_lpf_vertical_8 aom_lpf_vertical_8_neon

void aom_lpf_vertical_8_dual_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
void aom_lpf_vertical_8_dual_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0, const uint8_t *blimit1, const uint8_t *limit1, const uint8_t *thresh1);
#define aom_lpf_vertical_8_dual aom_lpf_vertical_8_dual_neon

void aom_lpf_vertical_8_quad_c(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
void aom_lpf_vertical_8_quad_neon(uint8_t *s, int pitch, const uint8_t *blimit0, const uint8_t *limit0, const uint8_t *thresh0);
#define aom_lpf_vertical_8_quad aom_lpf_vertical_8_quad_neon

unsigned int aom_masked_sad128x128_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad128x128_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad128x128 aom_masked_sad128x128_neon

unsigned int aom_masked_sad128x64_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad128x64_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad128x64 aom_masked_sad128x64_neon

unsigned int aom_masked_sad16x16_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad16x16_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad16x16 aom_masked_sad16x16_neon

unsigned int aom_masked_sad16x32_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad16x32_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad16x32 aom_masked_sad16x32_neon

unsigned int aom_masked_sad16x4_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad16x4_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad16x4 aom_masked_sad16x4_neon

unsigned int aom_masked_sad16x64_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad16x64_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad16x64 aom_masked_sad16x64_neon

unsigned int aom_masked_sad16x8_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad16x8_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad16x8 aom_masked_sad16x8_neon

unsigned int aom_masked_sad32x16_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad32x16_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad32x16 aom_masked_sad32x16_neon

unsigned int aom_masked_sad32x32_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad32x32_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad32x32 aom_masked_sad32x32_neon

unsigned int aom_masked_sad32x64_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad32x64_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad32x64 aom_masked_sad32x64_neon

unsigned int aom_masked_sad32x8_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad32x8_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad32x8 aom_masked_sad32x8_neon

unsigned int aom_masked_sad4x16_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad4x16_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad4x16 aom_masked_sad4x16_neon

unsigned int aom_masked_sad4x4_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad4x4_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad4x4 aom_masked_sad4x4_neon

unsigned int aom_masked_sad4x8_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad4x8_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad4x8 aom_masked_sad4x8_neon

unsigned int aom_masked_sad64x128_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad64x128_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad64x128 aom_masked_sad64x128_neon

unsigned int aom_masked_sad64x16_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad64x16_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad64x16 aom_masked_sad64x16_neon

unsigned int aom_masked_sad64x32_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad64x32_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad64x32 aom_masked_sad64x32_neon

unsigned int aom_masked_sad64x64_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad64x64_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad64x64 aom_masked_sad64x64_neon

unsigned int aom_masked_sad8x16_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad8x16_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad8x16 aom_masked_sad8x16_neon

unsigned int aom_masked_sad8x32_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad8x32_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad8x32 aom_masked_sad8x32_neon

unsigned int aom_masked_sad8x4_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad8x4_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad8x4 aom_masked_sad8x4_neon

unsigned int aom_masked_sad8x8_c(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
unsigned int aom_masked_sad8x8_neon(const uint8_t *src, int src_stride, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask);
#define aom_masked_sad8x8 aom_masked_sad8x8_neon

unsigned int aom_masked_sub_pixel_variance128x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance128x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance128x128 aom_masked_sub_pixel_variance128x128_neon

unsigned int aom_masked_sub_pixel_variance128x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance128x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance128x64 aom_masked_sub_pixel_variance128x64_neon

unsigned int aom_masked_sub_pixel_variance16x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance16x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance16x16 aom_masked_sub_pixel_variance16x16_neon

unsigned int aom_masked_sub_pixel_variance16x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance16x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance16x32 aom_masked_sub_pixel_variance16x32_neon

unsigned int aom_masked_sub_pixel_variance16x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance16x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance16x4 aom_masked_sub_pixel_variance16x4_neon

unsigned int aom_masked_sub_pixel_variance16x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance16x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance16x64 aom_masked_sub_pixel_variance16x64_neon

unsigned int aom_masked_sub_pixel_variance16x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance16x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance16x8 aom_masked_sub_pixel_variance16x8_neon

unsigned int aom_masked_sub_pixel_variance32x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance32x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance32x16 aom_masked_sub_pixel_variance32x16_neon

unsigned int aom_masked_sub_pixel_variance32x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance32x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance32x32 aom_masked_sub_pixel_variance32x32_neon

unsigned int aom_masked_sub_pixel_variance32x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance32x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance32x64 aom_masked_sub_pixel_variance32x64_neon

unsigned int aom_masked_sub_pixel_variance32x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance32x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance32x8 aom_masked_sub_pixel_variance32x8_neon

unsigned int aom_masked_sub_pixel_variance4x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance4x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance4x16 aom_masked_sub_pixel_variance4x16_neon

unsigned int aom_masked_sub_pixel_variance4x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance4x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance4x4 aom_masked_sub_pixel_variance4x4_neon

unsigned int aom_masked_sub_pixel_variance4x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance4x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance4x8 aom_masked_sub_pixel_variance4x8_neon

unsigned int aom_masked_sub_pixel_variance64x128_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance64x128_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance64x128 aom_masked_sub_pixel_variance64x128_neon

unsigned int aom_masked_sub_pixel_variance64x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance64x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance64x16 aom_masked_sub_pixel_variance64x16_neon

unsigned int aom_masked_sub_pixel_variance64x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance64x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance64x32 aom_masked_sub_pixel_variance64x32_neon

unsigned int aom_masked_sub_pixel_variance64x64_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance64x64_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance64x64 aom_masked_sub_pixel_variance64x64_neon

unsigned int aom_masked_sub_pixel_variance8x16_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance8x16_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance8x16 aom_masked_sub_pixel_variance8x16_neon

unsigned int aom_masked_sub_pixel_variance8x32_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance8x32_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance8x32 aom_masked_sub_pixel_variance8x32_neon

unsigned int aom_masked_sub_pixel_variance8x4_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance8x4_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance8x4 aom_masked_sub_pixel_variance8x4_neon

unsigned int aom_masked_sub_pixel_variance8x8_c(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
unsigned int aom_masked_sub_pixel_variance8x8_neon(const uint8_t *src, int src_stride, int xoffset, int yoffset, const uint8_t *ref, int ref_stride, const uint8_t *second_pred, const uint8_t *msk, int msk_stride, int invert_mask, unsigned int *sse);
#define aom_masked_sub_pixel_variance8x8 aom_masked_sub_pixel_variance8x8_neon

void aom_minmax_8x8_c(const uint8_t *s, int p, const uint8_t *d, int dp, int *min, int *max);
void aom_minmax_8x8_neon(const uint8_t *s, int p, const uint8_t *d, int dp, int *min, int *max);
#define aom_minmax_8x8 aom_minmax_8x8_neon

unsigned int aom_mse16x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse16x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse16x16_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_mse16x16)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_mse16x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse16x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse16x8_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_mse16x8)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_mse8x16_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse8x16_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse8x16_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_mse8x16)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

unsigned int aom_mse8x8_c(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse8x8_neon(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
unsigned int aom_mse8x8_neon_dotprod(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_mse8x8)(const uint8_t *src_ptr, int  source_stride, const uint8_t *ref_ptr, int  recon_stride, unsigned int *sse);

uint64_t aom_mse_16xh_16bit_c(uint8_t *dst, int dstride,uint16_t *src, int w, int h);
uint64_t aom_mse_16xh_16bit_neon(uint8_t *dst, int dstride,uint16_t *src, int w, int h);
#define aom_mse_16xh_16bit aom_mse_16xh_16bit_neon

uint64_t aom_mse_wxh_16bit_c(uint8_t *dst, int dstride,uint16_t *src, int sstride, int w, int h);
uint64_t aom_mse_wxh_16bit_neon(uint8_t *dst, int dstride,uint16_t *src, int sstride, int w, int h);
#define aom_mse_wxh_16bit aom_mse_wxh_16bit_neon

uint64_t aom_mse_wxh_16bit_highbd_c(uint16_t *dst, int dstride,uint16_t *src, int sstride, int w, int h);
uint64_t aom_mse_wxh_16bit_highbd_neon(uint16_t *dst, int dstride,uint16_t *src, int sstride, int w, int h);
#define aom_mse_wxh_16bit_highbd aom_mse_wxh_16bit_highbd_neon

unsigned int aom_obmc_sad128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad128x128 aom_obmc_sad128x128_neon

unsigned int aom_obmc_sad128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad128x64 aom_obmc_sad128x64_neon

unsigned int aom_obmc_sad16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad16x16 aom_obmc_sad16x16_neon

unsigned int aom_obmc_sad16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad16x32 aom_obmc_sad16x32_neon

unsigned int aom_obmc_sad16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad16x4 aom_obmc_sad16x4_neon

unsigned int aom_obmc_sad16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad16x64 aom_obmc_sad16x64_neon

unsigned int aom_obmc_sad16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad16x8 aom_obmc_sad16x8_neon

unsigned int aom_obmc_sad32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad32x16 aom_obmc_sad32x16_neon

unsigned int aom_obmc_sad32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad32x32 aom_obmc_sad32x32_neon

unsigned int aom_obmc_sad32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad32x64 aom_obmc_sad32x64_neon

unsigned int aom_obmc_sad32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad32x8 aom_obmc_sad32x8_neon

unsigned int aom_obmc_sad4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad4x16 aom_obmc_sad4x16_neon

unsigned int aom_obmc_sad4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad4x4 aom_obmc_sad4x4_neon

unsigned int aom_obmc_sad4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad4x8 aom_obmc_sad4x8_neon

unsigned int aom_obmc_sad64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad64x128 aom_obmc_sad64x128_neon

unsigned int aom_obmc_sad64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad64x16 aom_obmc_sad64x16_neon

unsigned int aom_obmc_sad64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad64x32 aom_obmc_sad64x32_neon

unsigned int aom_obmc_sad64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad64x64 aom_obmc_sad64x64_neon

unsigned int aom_obmc_sad8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad8x16 aom_obmc_sad8x16_neon

unsigned int aom_obmc_sad8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad8x32 aom_obmc_sad8x32_neon

unsigned int aom_obmc_sad8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad8x4 aom_obmc_sad8x4_neon

unsigned int aom_obmc_sad8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
unsigned int aom_obmc_sad8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask);
#define aom_obmc_sad8x8 aom_obmc_sad8x8_neon

unsigned int aom_obmc_sub_pixel_variance128x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance128x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance128x128 aom_obmc_sub_pixel_variance128x128_neon

unsigned int aom_obmc_sub_pixel_variance128x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance128x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance128x64 aom_obmc_sub_pixel_variance128x64_neon

unsigned int aom_obmc_sub_pixel_variance16x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance16x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance16x16 aom_obmc_sub_pixel_variance16x16_neon

unsigned int aom_obmc_sub_pixel_variance16x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance16x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance16x32 aom_obmc_sub_pixel_variance16x32_neon

unsigned int aom_obmc_sub_pixel_variance16x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance16x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance16x4 aom_obmc_sub_pixel_variance16x4_neon

unsigned int aom_obmc_sub_pixel_variance16x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance16x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance16x64 aom_obmc_sub_pixel_variance16x64_neon

unsigned int aom_obmc_sub_pixel_variance16x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance16x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance16x8 aom_obmc_sub_pixel_variance16x8_neon

unsigned int aom_obmc_sub_pixel_variance32x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance32x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance32x16 aom_obmc_sub_pixel_variance32x16_neon

unsigned int aom_obmc_sub_pixel_variance32x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance32x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance32x32 aom_obmc_sub_pixel_variance32x32_neon

unsigned int aom_obmc_sub_pixel_variance32x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance32x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance32x64 aom_obmc_sub_pixel_variance32x64_neon

unsigned int aom_obmc_sub_pixel_variance32x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance32x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance32x8 aom_obmc_sub_pixel_variance32x8_neon

unsigned int aom_obmc_sub_pixel_variance4x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance4x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance4x16 aom_obmc_sub_pixel_variance4x16_neon

unsigned int aom_obmc_sub_pixel_variance4x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance4x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance4x4 aom_obmc_sub_pixel_variance4x4_neon

unsigned int aom_obmc_sub_pixel_variance4x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance4x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance4x8 aom_obmc_sub_pixel_variance4x8_neon

unsigned int aom_obmc_sub_pixel_variance64x128_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance64x128_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance64x128 aom_obmc_sub_pixel_variance64x128_neon

unsigned int aom_obmc_sub_pixel_variance64x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance64x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance64x16 aom_obmc_sub_pixel_variance64x16_neon

unsigned int aom_obmc_sub_pixel_variance64x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance64x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance64x32 aom_obmc_sub_pixel_variance64x32_neon

unsigned int aom_obmc_sub_pixel_variance64x64_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance64x64_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance64x64 aom_obmc_sub_pixel_variance64x64_neon

unsigned int aom_obmc_sub_pixel_variance8x16_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance8x16_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance8x16 aom_obmc_sub_pixel_variance8x16_neon

unsigned int aom_obmc_sub_pixel_variance8x32_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance8x32_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance8x32 aom_obmc_sub_pixel_variance8x32_neon

unsigned int aom_obmc_sub_pixel_variance8x4_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance8x4_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance8x4 aom_obmc_sub_pixel_variance8x4_neon

unsigned int aom_obmc_sub_pixel_variance8x8_c(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_sub_pixel_variance8x8_neon(const uint8_t *pre, int pre_stride, int xoffset, int yoffset, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_sub_pixel_variance8x8 aom_obmc_sub_pixel_variance8x8_neon

unsigned int aom_obmc_variance128x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance128x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance128x128 aom_obmc_variance128x128_neon

unsigned int aom_obmc_variance128x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance128x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance128x64 aom_obmc_variance128x64_neon

unsigned int aom_obmc_variance16x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance16x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance16x16 aom_obmc_variance16x16_neon

unsigned int aom_obmc_variance16x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance16x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance16x32 aom_obmc_variance16x32_neon

unsigned int aom_obmc_variance16x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance16x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance16x4 aom_obmc_variance16x4_neon

unsigned int aom_obmc_variance16x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance16x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance16x64 aom_obmc_variance16x64_neon

unsigned int aom_obmc_variance16x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance16x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance16x8 aom_obmc_variance16x8_neon

unsigned int aom_obmc_variance32x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance32x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance32x16 aom_obmc_variance32x16_neon

unsigned int aom_obmc_variance32x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance32x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance32x32 aom_obmc_variance32x32_neon

unsigned int aom_obmc_variance32x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance32x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance32x64 aom_obmc_variance32x64_neon

unsigned int aom_obmc_variance32x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance32x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance32x8 aom_obmc_variance32x8_neon

unsigned int aom_obmc_variance4x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance4x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance4x16 aom_obmc_variance4x16_neon

unsigned int aom_obmc_variance4x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance4x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance4x4 aom_obmc_variance4x4_neon

unsigned int aom_obmc_variance4x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance4x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance4x8 aom_obmc_variance4x8_neon

unsigned int aom_obmc_variance64x128_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance64x128_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance64x128 aom_obmc_variance64x128_neon

unsigned int aom_obmc_variance64x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance64x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance64x16 aom_obmc_variance64x16_neon

unsigned int aom_obmc_variance64x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance64x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance64x32 aom_obmc_variance64x32_neon

unsigned int aom_obmc_variance64x64_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance64x64_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance64x64 aom_obmc_variance64x64_neon

unsigned int aom_obmc_variance8x16_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance8x16_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance8x16 aom_obmc_variance8x16_neon

unsigned int aom_obmc_variance8x32_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance8x32_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance8x32 aom_obmc_variance8x32_neon

unsigned int aom_obmc_variance8x4_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance8x4_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance8x4 aom_obmc_variance8x4_neon

unsigned int aom_obmc_variance8x8_c(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
unsigned int aom_obmc_variance8x8_neon(const uint8_t *pre, int pre_stride, const int32_t *wsrc, const int32_t *mask, unsigned int *sse);
#define aom_obmc_variance8x8 aom_obmc_variance8x8_neon

void aom_paeth_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_16x16 aom_paeth_predictor_16x16_neon

void aom_paeth_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_16x32 aom_paeth_predictor_16x32_neon

void aom_paeth_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_16x4 aom_paeth_predictor_16x4_neon

void aom_paeth_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_16x64 aom_paeth_predictor_16x64_neon

void aom_paeth_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_16x8 aom_paeth_predictor_16x8_neon

void aom_paeth_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_32x16 aom_paeth_predictor_32x16_neon

void aom_paeth_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_32x32 aom_paeth_predictor_32x32_neon

void aom_paeth_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_32x64 aom_paeth_predictor_32x64_neon

void aom_paeth_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_32x8 aom_paeth_predictor_32x8_neon

void aom_paeth_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_4x16 aom_paeth_predictor_4x16_neon

void aom_paeth_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_4x4 aom_paeth_predictor_4x4_neon

void aom_paeth_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_4x8 aom_paeth_predictor_4x8_neon

void aom_paeth_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_64x16 aom_paeth_predictor_64x16_neon

void aom_paeth_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_64x32 aom_paeth_predictor_64x32_neon

void aom_paeth_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_64x64 aom_paeth_predictor_64x64_neon

void aom_paeth_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_8x16 aom_paeth_predictor_8x16_neon

void aom_paeth_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_8x32 aom_paeth_predictor_8x32_neon

void aom_paeth_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_8x4 aom_paeth_predictor_8x4_neon

void aom_paeth_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_paeth_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_paeth_predictor_8x8 aom_paeth_predictor_8x8_neon

void aom_quantize_b_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_quantize_b_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b aom_quantize_b_neon

void aom_quantize_b_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_quantize_b_32x32_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b_32x32 aom_quantize_b_32x32_neon

void aom_quantize_b_32x32_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b_32x32_adaptive aom_quantize_b_32x32_adaptive_c

void aom_quantize_b_64x64_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void aom_quantize_b_64x64_neon(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b_64x64 aom_quantize_b_64x64_neon

void aom_quantize_b_64x64_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b_64x64_adaptive aom_quantize_b_64x64_adaptive_c

void aom_quantize_b_adaptive_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define aom_quantize_b_adaptive aom_quantize_b_adaptive_c

unsigned int aom_sad128x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad128x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad128x128_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad128x128)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad128x128_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad128x128_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad128x128_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad128x128_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad128x128x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x128x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x128x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad128x128x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad128x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x128x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad128x128x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad128x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad128x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad128x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad128x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad128x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad128x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad128x64_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad128x64_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad128x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x64x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad128x64x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad128x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad128x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad128x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad16x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad16x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad16x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x16_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad16x16_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad16x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x16x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x16x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad16x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad16x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad16x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad16x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x32_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad16x32_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad16x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x32x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x32x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad16x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad16x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x4_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad16x4)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad16x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x4x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x4x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad16x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x4x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x4x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad16x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad16x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad16x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x64_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad16x64_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad16x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x64x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x64x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad16x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad16x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad16x8_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad16x8)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad16x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad16x8_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad16x8_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad16x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x8x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x8x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad16x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad16x8x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad16x8x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad32x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad32x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad32x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x16_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad32x16_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad32x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x16x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x16x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad32x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad32x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad32x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad32x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x32_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad32x32_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad32x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x32x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x32x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad32x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad32x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad32x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad32x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x64_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad32x64_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad32x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x64x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x64x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad32x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad32x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad32x8_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad32x8)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad32x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad32x8_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad32x8_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad32x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x8x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x8x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad32x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad32x8x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad32x8x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad4x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad4x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad4x16 aom_sad4x16_neon

void aom_sad4x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x16x3d aom_sad4x16x3d_neon

void aom_sad4x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x16x4d aom_sad4x16x4d_neon

unsigned int aom_sad4x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad4x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad4x4 aom_sad4x4_neon

void aom_sad4x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x4x3d aom_sad4x4x3d_neon

void aom_sad4x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x4x4d aom_sad4x4x4d_neon

unsigned int aom_sad4x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad4x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad4x8 aom_sad4x8_neon

void aom_sad4x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x8x3d aom_sad4x8x3d_neon

void aom_sad4x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad4x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad4x8x4d aom_sad4x8x4d_neon

unsigned int aom_sad64x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x128_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad64x128)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad64x128_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x128_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x128_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad64x128_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad64x128x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x128x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x128x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x128x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad64x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x128x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x128x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad64x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad64x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad64x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x16_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad64x16_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad64x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x16x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x16x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad64x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad64x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad64x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad64x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x32_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad64x32_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad64x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x32x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x32x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad64x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad64x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad64x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad64x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

unsigned int aom_sad64x64_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x64_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad64x64_avg_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
RTCD_EXTERN unsigned int (*aom_sad64x64_avg)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);

void aom_sad64x64x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x64x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x64x3d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x64x3d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

void aom_sad64x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad64x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad64x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad8x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad8x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad8x16 aom_sad8x16_neon

unsigned int aom_sad8x16_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad8x16_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_sad8x16_avg aom_sad8x16_avg_neon

void aom_sad8x16x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x16x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x16x3d aom_sad8x16x3d_neon

void aom_sad8x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x16x4d aom_sad8x16x4d_neon

unsigned int aom_sad8x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad8x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad8x32 aom_sad8x32_neon

unsigned int aom_sad8x32_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad8x32_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_sad8x32_avg aom_sad8x32_avg_neon

void aom_sad8x32x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x32x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x32x3d aom_sad8x32x3d_neon

void aom_sad8x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x32x4d aom_sad8x32x4d_neon

unsigned int aom_sad8x4_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad8x4_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad8x4 aom_sad8x4_neon

void aom_sad8x4x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x4x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x4x3d aom_sad8x4x3d_neon

void aom_sad8x4x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x4x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x4x4d aom_sad8x4x4d_neon

unsigned int aom_sad8x8_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad8x8_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad8x8 aom_sad8x8_neon

unsigned int aom_sad8x8_avg_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
unsigned int aom_sad8x8_avg_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride, const uint8_t *second_pred);
#define aom_sad8x8_avg aom_sad8x8_avg_neon

void aom_sad8x8x3d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x8x3d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x8x3d aom_sad8x8x3d_neon

void aom_sad8x8x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad8x8x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad8x8x4d aom_sad8x8x4d_neon

unsigned int aom_sad_skip_128x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_128x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_128x128_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_128x128)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_128x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_128x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_128x128x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_128x128x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_128x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_128x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_128x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_128x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_128x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_128x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_128x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_128x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_16x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_16x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_16x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_16x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_16x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_16x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_16x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_16x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_16x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_16x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_16x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_16x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_16x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_16x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_32x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_32x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_32x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_32x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_32x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_32x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_32x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_32x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_32x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_32x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_32x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_32x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_32x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_32x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_4x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_4x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad_skip_4x16 aom_sad_skip_4x16_neon

void aom_sad_skip_4x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_4x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad_skip_4x16x4d aom_sad_skip_4x16x4d_neon

unsigned int aom_sad_skip_64x128_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x128_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x128_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_64x128)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_64x128x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x128x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x128x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_64x128x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_64x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_64x16)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_64x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x16x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_64x16x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_64x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_64x32)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_64x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x32x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_64x32x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_64x64_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x64_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_64x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
RTCD_EXTERN unsigned int (*aom_sad_skip_64x64)(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);

void aom_sad_skip_64x64x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x64x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_64x64x4d_neon_dotprod(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
RTCD_EXTERN void (*aom_sad_skip_64x64x4d)(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);

unsigned int aom_sad_skip_8x16_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_8x16_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad_skip_8x16 aom_sad_skip_8x16_neon

void aom_sad_skip_8x16x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_8x16x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad_skip_8x16x4d aom_sad_skip_8x16x4d_neon

unsigned int aom_sad_skip_8x32_c(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
unsigned int aom_sad_skip_8x32_neon(const uint8_t *src_ptr, int src_stride, const uint8_t *ref_ptr, int ref_stride);
#define aom_sad_skip_8x32 aom_sad_skip_8x32_neon

void aom_sad_skip_8x32x4d_c(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
void aom_sad_skip_8x32x4d_neon(const uint8_t *src_ptr, int src_stride, const uint8_t * const ref_ptr[4], int ref_stride, uint32_t sad_array[4]);
#define aom_sad_skip_8x32x4d aom_sad_skip_8x32x4d_neon

int aom_satd_c(const tran_low_t *coeff, int length);
int aom_satd_neon(const tran_low_t *coeff, int length);
#define aom_satd aom_satd_neon

int aom_satd_lp_c(const int16_t *coeff, int length);
int aom_satd_lp_neon(const int16_t *coeff, int length);
#define aom_satd_lp aom_satd_lp_neon

void aom_scaled_2d_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const InterpKernel *filter, int x0_q4, int x_step_q4, int y0_q4, int y_step_q4, int w, int h);
void aom_scaled_2d_neon(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const InterpKernel *filter, int x0_q4, int x_step_q4, int y0_q4, int y_step_q4, int w, int h);
void aom_scaled_2d_neon_dotprod(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const InterpKernel *filter, int x0_q4, int x_step_q4, int y0_q4, int y_step_q4, int w, int h);
void aom_scaled_2d_neon_i8mm(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const InterpKernel *filter, int x0_q4, int x_step_q4, int y0_q4, int y_step_q4, int w, int h);
RTCD_EXTERN void (*aom_scaled_2d)(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const InterpKernel *filter, int x0_q4, int x_step_q4, int y0_q4, int y_step_q4, int w, int h);

void aom_smooth_h_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_16x16 aom_smooth_h_predictor_16x16_neon

void aom_smooth_h_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_16x32 aom_smooth_h_predictor_16x32_neon

void aom_smooth_h_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_16x4 aom_smooth_h_predictor_16x4_neon

void aom_smooth_h_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_16x64 aom_smooth_h_predictor_16x64_neon

void aom_smooth_h_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_16x8 aom_smooth_h_predictor_16x8_neon

void aom_smooth_h_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_32x16 aom_smooth_h_predictor_32x16_neon

void aom_smooth_h_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_32x32 aom_smooth_h_predictor_32x32_neon

void aom_smooth_h_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_32x64 aom_smooth_h_predictor_32x64_neon

void aom_smooth_h_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_32x8 aom_smooth_h_predictor_32x8_neon

void aom_smooth_h_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_4x16 aom_smooth_h_predictor_4x16_neon

void aom_smooth_h_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_4x4 aom_smooth_h_predictor_4x4_neon

void aom_smooth_h_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_4x8 aom_smooth_h_predictor_4x8_neon

void aom_smooth_h_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_64x16 aom_smooth_h_predictor_64x16_neon

void aom_smooth_h_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_64x32 aom_smooth_h_predictor_64x32_neon

void aom_smooth_h_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_64x64 aom_smooth_h_predictor_64x64_neon

void aom_smooth_h_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_8x16 aom_smooth_h_predictor_8x16_neon

void aom_smooth_h_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_8x32 aom_smooth_h_predictor_8x32_neon

void aom_smooth_h_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_8x4 aom_smooth_h_predictor_8x4_neon

void aom_smooth_h_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_h_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_h_predictor_8x8 aom_smooth_h_predictor_8x8_neon

void aom_smooth_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_16x16 aom_smooth_predictor_16x16_neon

void aom_smooth_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_16x32 aom_smooth_predictor_16x32_neon

void aom_smooth_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_16x4 aom_smooth_predictor_16x4_neon

void aom_smooth_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_16x64 aom_smooth_predictor_16x64_neon

void aom_smooth_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_16x8 aom_smooth_predictor_16x8_neon

void aom_smooth_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_32x16 aom_smooth_predictor_32x16_neon

void aom_smooth_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_32x32 aom_smooth_predictor_32x32_neon

void aom_smooth_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_32x64 aom_smooth_predictor_32x64_neon

void aom_smooth_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_32x8 aom_smooth_predictor_32x8_neon

void aom_smooth_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_4x16 aom_smooth_predictor_4x16_neon

void aom_smooth_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_4x4 aom_smooth_predictor_4x4_neon

void aom_smooth_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_4x8 aom_smooth_predictor_4x8_neon

void aom_smooth_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_64x16 aom_smooth_predictor_64x16_neon

void aom_smooth_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_64x32 aom_smooth_predictor_64x32_neon

void aom_smooth_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_64x64 aom_smooth_predictor_64x64_neon

void aom_smooth_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_8x16 aom_smooth_predictor_8x16_neon

void aom_smooth_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_8x32 aom_smooth_predictor_8x32_neon

void aom_smooth_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_8x4 aom_smooth_predictor_8x4_neon

void aom_smooth_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_predictor_8x8 aom_smooth_predictor_8x8_neon

void aom_smooth_v_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_16x16 aom_smooth_v_predictor_16x16_neon

void aom_smooth_v_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_16x32 aom_smooth_v_predictor_16x32_neon

void aom_smooth_v_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_16x4 aom_smooth_v_predictor_16x4_neon

void aom_smooth_v_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_16x64 aom_smooth_v_predictor_16x64_neon

void aom_smooth_v_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_16x8 aom_smooth_v_predictor_16x8_neon

void aom_smooth_v_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_32x16 aom_smooth_v_predictor_32x16_neon

void aom_smooth_v_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_32x32 aom_smooth_v_predictor_32x32_neon

void aom_smooth_v_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_32x64 aom_smooth_v_predictor_32x64_neon

void aom_smooth_v_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_32x8 aom_smooth_v_predictor_32x8_neon

void aom_smooth_v_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_4x16 aom_smooth_v_predictor_4x16_neon

void aom_smooth_v_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_4x4 aom_smooth_v_predictor_4x4_neon

void aom_smooth_v_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_4x8 aom_smooth_v_predictor_4x8_neon

void aom_smooth_v_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_64x16 aom_smooth_v_predictor_64x16_neon

void aom_smooth_v_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_64x32 aom_smooth_v_predictor_64x32_neon

void aom_smooth_v_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_64x64 aom_smooth_v_predictor_64x64_neon

void aom_smooth_v_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_8x16 aom_smooth_v_predictor_8x16_neon

void aom_smooth_v_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_8x32 aom_smooth_v_predictor_8x32_neon

void aom_smooth_v_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_8x4 aom_smooth_v_predictor_8x4_neon

void aom_smooth_v_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_smooth_v_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_smooth_v_predictor_8x8 aom_smooth_v_predictor_8x8_neon

int64_t aom_sse_c(const uint8_t *a, int a_stride, const uint8_t *b,int b_stride, int width, int height);
int64_t aom_sse_neon(const uint8_t *a, int a_stride, const uint8_t *b,int b_stride, int width, int height);
int64_t aom_sse_neon_dotprod(const uint8_t *a, int a_stride, const uint8_t *b,int b_stride, int width, int height);
RTCD_EXTERN int64_t (*aom_sse)(const uint8_t *a, int a_stride, const uint8_t *b,int b_stride, int width, int height);

void aom_ssim_parms_8x8_c(const uint8_t *s, int sp, const uint8_t *r, int rp, uint32_t *sum_s, uint32_t *sum_r, uint32_t *sum_sq_s, uint32_t *sum_sq_r, uint32_t *sum_sxr);
#define aom_ssim_parms_8x8 aom_ssim_parms_8x8_c

uint32_t aom_sub_pixel_avg_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance128x128 aom_sub_pixel_avg_variance128x128_neon

uint32_t aom_sub_pixel_avg_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance128x64 aom_sub_pixel_avg_variance128x64_neon

uint32_t aom_sub_pixel_avg_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance16x16 aom_sub_pixel_avg_variance16x16_neon

uint32_t aom_sub_pixel_avg_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance16x32 aom_sub_pixel_avg_variance16x32_neon

uint32_t aom_sub_pixel_avg_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance16x4 aom_sub_pixel_avg_variance16x4_neon

uint32_t aom_sub_pixel_avg_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance16x64 aom_sub_pixel_avg_variance16x64_neon

uint32_t aom_sub_pixel_avg_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance16x8 aom_sub_pixel_avg_variance16x8_neon

uint32_t aom_sub_pixel_avg_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance32x16 aom_sub_pixel_avg_variance32x16_neon

uint32_t aom_sub_pixel_avg_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance32x32 aom_sub_pixel_avg_variance32x32_neon

uint32_t aom_sub_pixel_avg_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance32x64 aom_sub_pixel_avg_variance32x64_neon

uint32_t aom_sub_pixel_avg_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance32x8 aom_sub_pixel_avg_variance32x8_neon

uint32_t aom_sub_pixel_avg_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance4x16 aom_sub_pixel_avg_variance4x16_neon

uint32_t aom_sub_pixel_avg_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance4x4 aom_sub_pixel_avg_variance4x4_neon

uint32_t aom_sub_pixel_avg_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance4x8 aom_sub_pixel_avg_variance4x8_neon

uint32_t aom_sub_pixel_avg_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance64x128 aom_sub_pixel_avg_variance64x128_neon

uint32_t aom_sub_pixel_avg_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance64x16 aom_sub_pixel_avg_variance64x16_neon

uint32_t aom_sub_pixel_avg_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance64x32 aom_sub_pixel_avg_variance64x32_neon

uint32_t aom_sub_pixel_avg_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance64x64 aom_sub_pixel_avg_variance64x64_neon

uint32_t aom_sub_pixel_avg_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance8x16 aom_sub_pixel_avg_variance8x16_neon

uint32_t aom_sub_pixel_avg_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance8x32 aom_sub_pixel_avg_variance8x32_neon

uint32_t aom_sub_pixel_avg_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance8x4 aom_sub_pixel_avg_variance8x4_neon

uint32_t aom_sub_pixel_avg_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
uint32_t aom_sub_pixel_avg_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse, const uint8_t *second_pred);
#define aom_sub_pixel_avg_variance8x8 aom_sub_pixel_avg_variance8x8_neon

uint32_t aom_sub_pixel_variance128x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance128x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance128x128 aom_sub_pixel_variance128x128_neon

uint32_t aom_sub_pixel_variance128x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance128x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance128x64 aom_sub_pixel_variance128x64_neon

uint32_t aom_sub_pixel_variance16x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance16x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance16x16 aom_sub_pixel_variance16x16_neon

uint32_t aom_sub_pixel_variance16x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance16x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance16x32 aom_sub_pixel_variance16x32_neon

uint32_t aom_sub_pixel_variance16x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance16x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance16x4 aom_sub_pixel_variance16x4_neon

uint32_t aom_sub_pixel_variance16x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance16x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance16x64 aom_sub_pixel_variance16x64_neon

uint32_t aom_sub_pixel_variance16x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance16x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance16x8 aom_sub_pixel_variance16x8_neon

uint32_t aom_sub_pixel_variance32x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance32x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance32x16 aom_sub_pixel_variance32x16_neon

uint32_t aom_sub_pixel_variance32x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance32x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance32x32 aom_sub_pixel_variance32x32_neon

uint32_t aom_sub_pixel_variance32x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance32x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance32x64 aom_sub_pixel_variance32x64_neon

uint32_t aom_sub_pixel_variance32x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance32x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance32x8 aom_sub_pixel_variance32x8_neon

uint32_t aom_sub_pixel_variance4x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance4x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance4x16 aom_sub_pixel_variance4x16_neon

uint32_t aom_sub_pixel_variance4x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance4x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance4x4 aom_sub_pixel_variance4x4_neon

uint32_t aom_sub_pixel_variance4x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance4x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance4x8 aom_sub_pixel_variance4x8_neon

uint32_t aom_sub_pixel_variance64x128_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance64x128_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance64x128 aom_sub_pixel_variance64x128_neon

uint32_t aom_sub_pixel_variance64x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance64x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance64x16 aom_sub_pixel_variance64x16_neon

uint32_t aom_sub_pixel_variance64x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance64x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance64x32 aom_sub_pixel_variance64x32_neon

uint32_t aom_sub_pixel_variance64x64_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance64x64_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance64x64 aom_sub_pixel_variance64x64_neon

uint32_t aom_sub_pixel_variance8x16_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance8x16_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance8x16 aom_sub_pixel_variance8x16_neon

uint32_t aom_sub_pixel_variance8x32_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance8x32_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance8x32 aom_sub_pixel_variance8x32_neon

uint32_t aom_sub_pixel_variance8x4_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance8x4_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance8x4 aom_sub_pixel_variance8x4_neon

uint32_t aom_sub_pixel_variance8x8_c(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
uint32_t aom_sub_pixel_variance8x8_neon(const uint8_t *src_ptr, int source_stride, int xoffset, int  yoffset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
#define aom_sub_pixel_variance8x8 aom_sub_pixel_variance8x8_neon

void aom_subtract_block_c(int rows, int cols, int16_t *diff_ptr, ptrdiff_t diff_stride, const uint8_t *src_ptr, ptrdiff_t src_stride, const uint8_t *pred_ptr, ptrdiff_t pred_stride);
void aom_subtract_block_neon(int rows, int cols, int16_t *diff_ptr, ptrdiff_t diff_stride, const uint8_t *src_ptr, ptrdiff_t src_stride, const uint8_t *pred_ptr, ptrdiff_t pred_stride);
#define aom_subtract_block aom_subtract_block_neon

uint64_t aom_sum_squares_2d_i16_c(const int16_t *src, int stride, int width, int height);
uint64_t aom_sum_squares_2d_i16_neon(const int16_t *src, int stride, int width, int height);
#define aom_sum_squares_2d_i16 aom_sum_squares_2d_i16_neon

uint64_t aom_sum_squares_i16_c(const int16_t *src, uint32_t N);
uint64_t aom_sum_squares_i16_neon(const int16_t *src, uint32_t N);
#define aom_sum_squares_i16 aom_sum_squares_i16_neon

uint64_t aom_sum_sse_2d_i16_c(const int16_t *src, int src_stride, int width, int height, int *sum);
uint64_t aom_sum_sse_2d_i16_neon(const int16_t *src, int src_stride, int width, int height, int *sum);
#define aom_sum_sse_2d_i16 aom_sum_sse_2d_i16_neon

void aom_v_predictor_16x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_16x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_16x16 aom_v_predictor_16x16_neon

void aom_v_predictor_16x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_16x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_16x32 aom_v_predictor_16x32_neon

void aom_v_predictor_16x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_16x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_16x4 aom_v_predictor_16x4_neon

void aom_v_predictor_16x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_16x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_16x64 aom_v_predictor_16x64_neon

void aom_v_predictor_16x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_16x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_16x8 aom_v_predictor_16x8_neon

void aom_v_predictor_32x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_32x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_32x16 aom_v_predictor_32x16_neon

void aom_v_predictor_32x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_32x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_32x32 aom_v_predictor_32x32_neon

void aom_v_predictor_32x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_32x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_32x64 aom_v_predictor_32x64_neon

void aom_v_predictor_32x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_32x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_32x8 aom_v_predictor_32x8_neon

void aom_v_predictor_4x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_4x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_4x16 aom_v_predictor_4x16_neon

void aom_v_predictor_4x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_4x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_4x4 aom_v_predictor_4x4_neon

void aom_v_predictor_4x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_4x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_4x8 aom_v_predictor_4x8_neon

void aom_v_predictor_64x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_64x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_64x16 aom_v_predictor_64x16_neon

void aom_v_predictor_64x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_64x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_64x32 aom_v_predictor_64x32_neon

void aom_v_predictor_64x64_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_64x64_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_64x64 aom_v_predictor_64x64_neon

void aom_v_predictor_8x16_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_8x16_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_8x16 aom_v_predictor_8x16_neon

void aom_v_predictor_8x32_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_8x32_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_8x32 aom_v_predictor_8x32_neon

void aom_v_predictor_8x4_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_8x4_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_8x4 aom_v_predictor_8x4_neon

void aom_v_predictor_8x8_c(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
void aom_v_predictor_8x8_neon(uint8_t *dst, ptrdiff_t y_stride, const uint8_t *above, const uint8_t *left);
#define aom_v_predictor_8x8 aom_v_predictor_8x8_neon

uint64_t aom_var_2d_u16_c(uint8_t *src, int src_stride, int width, int height);
uint64_t aom_var_2d_u16_neon(uint8_t *src, int src_stride, int width, int height);
#define aom_var_2d_u16 aom_var_2d_u16_neon

uint64_t aom_var_2d_u8_c(uint8_t *src, int src_stride, int width, int height);
uint64_t aom_var_2d_u8_neon(uint8_t *src, int src_stride, int width, int height);
uint64_t aom_var_2d_u8_neon_dotprod(uint8_t *src, int src_stride, int width, int height);
RTCD_EXTERN uint64_t (*aom_var_2d_u8)(uint8_t *src, int src_stride, int width, int height);

unsigned int aom_variance128x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance128x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance128x128_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance128x128)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance128x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance128x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance128x64_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance128x64)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance16x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x16_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance16x16)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance16x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x32_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance16x32)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance16x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x4_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance16x4)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance16x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x64_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance16x64)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance16x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance16x8_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance16x8)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance32x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x16_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance32x16)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance32x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x32_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance32x32)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance32x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x64_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance32x64)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance32x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance32x8_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance32x8)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance4x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x16_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance4x16)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance4x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x4_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance4x4)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance4x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance4x8_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance4x8)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance64x128_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x128_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x128_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance64x128)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance64x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x16_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance64x16)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance64x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x32_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance64x32)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance64x64_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x64_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance64x64_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance64x64)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance8x16_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x16_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x16_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance8x16)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance8x32_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x32_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x32_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance8x32)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance8x4_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x4_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x4_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance8x4)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

unsigned int aom_variance8x8_c(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x8_neon(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
unsigned int aom_variance8x8_neon_dotprod(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);
RTCD_EXTERN unsigned int (*aom_variance8x8)(const uint8_t *src_ptr, int source_stride, const uint8_t *ref_ptr, int ref_stride, unsigned int *sse);

int aom_vector_var_c(const int16_t *ref, const int16_t *src, int bwl);
int aom_vector_var_neon(const int16_t *ref, const int16_t *src, int bwl);
#define aom_vector_var aom_vector_var_neon

void aom_dsp_rtcd(void);

#include "config/aom_config.h"

#ifdef RTCD_C
#include "aom_ports/arm.h"
static void setup_rtcd_internal(void)
{
    int flags = aom_arm_cpu_caps();

    (void)flags;

    aom_convolve8_horiz = aom_convolve8_horiz_neon;
    if (flags & HAS_NEON_DOTPROD) aom_convolve8_horiz = aom_convolve8_horiz_neon_dotprod;
    if (flags & HAS_NEON_I8MM) aom_convolve8_horiz = aom_convolve8_horiz_neon_i8mm;
    aom_convolve8_vert = aom_convolve8_vert_neon;
    if (flags & HAS_NEON_DOTPROD) aom_convolve8_vert = aom_convolve8_vert_neon_dotprod;
    if (flags & HAS_NEON_I8MM) aom_convolve8_vert = aom_convolve8_vert_neon_i8mm;
    aom_get_var_sse_sum_16x16_dual = aom_get_var_sse_sum_16x16_dual_neon;
    if (flags & HAS_NEON_DOTPROD) aom_get_var_sse_sum_16x16_dual = aom_get_var_sse_sum_16x16_dual_neon_dotprod;
    aom_get_var_sse_sum_8x8_quad = aom_get_var_sse_sum_8x8_quad_neon;
    if (flags & HAS_NEON_DOTPROD) aom_get_var_sse_sum_8x8_quad = aom_get_var_sse_sum_8x8_quad_neon_dotprod;
    aom_highbd_8_mse16x16 = aom_highbd_8_mse16x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_highbd_8_mse16x16 = aom_highbd_8_mse16x16_neon_dotprod;
    aom_highbd_8_mse16x8 = aom_highbd_8_mse16x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_highbd_8_mse16x8 = aom_highbd_8_mse16x8_neon_dotprod;
    aom_highbd_8_mse8x16 = aom_highbd_8_mse8x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_highbd_8_mse8x16 = aom_highbd_8_mse8x16_neon_dotprod;
    aom_highbd_8_mse8x8 = aom_highbd_8_mse8x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_highbd_8_mse8x8 = aom_highbd_8_mse8x8_neon_dotprod;
    aom_mse16x16 = aom_mse16x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_mse16x16 = aom_mse16x16_neon_dotprod;
    aom_mse16x8 = aom_mse16x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_mse16x8 = aom_mse16x8_neon_dotprod;
    aom_mse8x16 = aom_mse8x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_mse8x16 = aom_mse8x16_neon_dotprod;
    aom_mse8x8 = aom_mse8x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_mse8x8 = aom_mse8x8_neon_dotprod;
    aom_sad128x128 = aom_sad128x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x128 = aom_sad128x128_neon_dotprod;
    aom_sad128x128_avg = aom_sad128x128_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x128_avg = aom_sad128x128_avg_neon_dotprod;
    aom_sad128x128x3d = aom_sad128x128x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x128x3d = aom_sad128x128x3d_neon_dotprod;
    aom_sad128x128x4d = aom_sad128x128x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x128x4d = aom_sad128x128x4d_neon_dotprod;
    aom_sad128x64 = aom_sad128x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x64 = aom_sad128x64_neon_dotprod;
    aom_sad128x64_avg = aom_sad128x64_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x64_avg = aom_sad128x64_avg_neon_dotprod;
    aom_sad128x64x3d = aom_sad128x64x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x64x3d = aom_sad128x64x3d_neon_dotprod;
    aom_sad128x64x4d = aom_sad128x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad128x64x4d = aom_sad128x64x4d_neon_dotprod;
    aom_sad16x16 = aom_sad16x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x16 = aom_sad16x16_neon_dotprod;
    aom_sad16x16_avg = aom_sad16x16_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x16_avg = aom_sad16x16_avg_neon_dotprod;
    aom_sad16x16x3d = aom_sad16x16x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x16x3d = aom_sad16x16x3d_neon_dotprod;
    aom_sad16x16x4d = aom_sad16x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x16x4d = aom_sad16x16x4d_neon_dotprod;
    aom_sad16x32 = aom_sad16x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x32 = aom_sad16x32_neon_dotprod;
    aom_sad16x32_avg = aom_sad16x32_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x32_avg = aom_sad16x32_avg_neon_dotprod;
    aom_sad16x32x3d = aom_sad16x32x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x32x3d = aom_sad16x32x3d_neon_dotprod;
    aom_sad16x32x4d = aom_sad16x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x32x4d = aom_sad16x32x4d_neon_dotprod;
    aom_sad16x4 = aom_sad16x4_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x4 = aom_sad16x4_neon_dotprod;
    aom_sad16x4x3d = aom_sad16x4x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x4x3d = aom_sad16x4x3d_neon_dotprod;
    aom_sad16x4x4d = aom_sad16x4x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x4x4d = aom_sad16x4x4d_neon_dotprod;
    aom_sad16x64 = aom_sad16x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x64 = aom_sad16x64_neon_dotprod;
    aom_sad16x64_avg = aom_sad16x64_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x64_avg = aom_sad16x64_avg_neon_dotprod;
    aom_sad16x64x3d = aom_sad16x64x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x64x3d = aom_sad16x64x3d_neon_dotprod;
    aom_sad16x64x4d = aom_sad16x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x64x4d = aom_sad16x64x4d_neon_dotprod;
    aom_sad16x8 = aom_sad16x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x8 = aom_sad16x8_neon_dotprod;
    aom_sad16x8_avg = aom_sad16x8_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x8_avg = aom_sad16x8_avg_neon_dotprod;
    aom_sad16x8x3d = aom_sad16x8x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x8x3d = aom_sad16x8x3d_neon_dotprod;
    aom_sad16x8x4d = aom_sad16x8x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad16x8x4d = aom_sad16x8x4d_neon_dotprod;
    aom_sad32x16 = aom_sad32x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x16 = aom_sad32x16_neon_dotprod;
    aom_sad32x16_avg = aom_sad32x16_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x16_avg = aom_sad32x16_avg_neon_dotprod;
    aom_sad32x16x3d = aom_sad32x16x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x16x3d = aom_sad32x16x3d_neon_dotprod;
    aom_sad32x16x4d = aom_sad32x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x16x4d = aom_sad32x16x4d_neon_dotprod;
    aom_sad32x32 = aom_sad32x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x32 = aom_sad32x32_neon_dotprod;
    aom_sad32x32_avg = aom_sad32x32_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x32_avg = aom_sad32x32_avg_neon_dotprod;
    aom_sad32x32x3d = aom_sad32x32x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x32x3d = aom_sad32x32x3d_neon_dotprod;
    aom_sad32x32x4d = aom_sad32x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x32x4d = aom_sad32x32x4d_neon_dotprod;
    aom_sad32x64 = aom_sad32x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x64 = aom_sad32x64_neon_dotprod;
    aom_sad32x64_avg = aom_sad32x64_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x64_avg = aom_sad32x64_avg_neon_dotprod;
    aom_sad32x64x3d = aom_sad32x64x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x64x3d = aom_sad32x64x3d_neon_dotprod;
    aom_sad32x64x4d = aom_sad32x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x64x4d = aom_sad32x64x4d_neon_dotprod;
    aom_sad32x8 = aom_sad32x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x8 = aom_sad32x8_neon_dotprod;
    aom_sad32x8_avg = aom_sad32x8_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x8_avg = aom_sad32x8_avg_neon_dotprod;
    aom_sad32x8x3d = aom_sad32x8x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x8x3d = aom_sad32x8x3d_neon_dotprod;
    aom_sad32x8x4d = aom_sad32x8x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad32x8x4d = aom_sad32x8x4d_neon_dotprod;
    aom_sad64x128 = aom_sad64x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x128 = aom_sad64x128_neon_dotprod;
    aom_sad64x128_avg = aom_sad64x128_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x128_avg = aom_sad64x128_avg_neon_dotprod;
    aom_sad64x128x3d = aom_sad64x128x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x128x3d = aom_sad64x128x3d_neon_dotprod;
    aom_sad64x128x4d = aom_sad64x128x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x128x4d = aom_sad64x128x4d_neon_dotprod;
    aom_sad64x16 = aom_sad64x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x16 = aom_sad64x16_neon_dotprod;
    aom_sad64x16_avg = aom_sad64x16_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x16_avg = aom_sad64x16_avg_neon_dotprod;
    aom_sad64x16x3d = aom_sad64x16x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x16x3d = aom_sad64x16x3d_neon_dotprod;
    aom_sad64x16x4d = aom_sad64x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x16x4d = aom_sad64x16x4d_neon_dotprod;
    aom_sad64x32 = aom_sad64x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x32 = aom_sad64x32_neon_dotprod;
    aom_sad64x32_avg = aom_sad64x32_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x32_avg = aom_sad64x32_avg_neon_dotprod;
    aom_sad64x32x3d = aom_sad64x32x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x32x3d = aom_sad64x32x3d_neon_dotprod;
    aom_sad64x32x4d = aom_sad64x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x32x4d = aom_sad64x32x4d_neon_dotprod;
    aom_sad64x64 = aom_sad64x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x64 = aom_sad64x64_neon_dotprod;
    aom_sad64x64_avg = aom_sad64x64_avg_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x64_avg = aom_sad64x64_avg_neon_dotprod;
    aom_sad64x64x3d = aom_sad64x64x3d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x64x3d = aom_sad64x64x3d_neon_dotprod;
    aom_sad64x64x4d = aom_sad64x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad64x64x4d = aom_sad64x64x4d_neon_dotprod;
    aom_sad_skip_128x128 = aom_sad_skip_128x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_128x128 = aom_sad_skip_128x128_neon_dotprod;
    aom_sad_skip_128x128x4d = aom_sad_skip_128x128x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_128x128x4d = aom_sad_skip_128x128x4d_neon_dotprod;
    aom_sad_skip_128x64 = aom_sad_skip_128x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_128x64 = aom_sad_skip_128x64_neon_dotprod;
    aom_sad_skip_128x64x4d = aom_sad_skip_128x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_128x64x4d = aom_sad_skip_128x64x4d_neon_dotprod;
    aom_sad_skip_16x16 = aom_sad_skip_16x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x16 = aom_sad_skip_16x16_neon_dotprod;
    aom_sad_skip_16x16x4d = aom_sad_skip_16x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x16x4d = aom_sad_skip_16x16x4d_neon_dotprod;
    aom_sad_skip_16x32 = aom_sad_skip_16x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x32 = aom_sad_skip_16x32_neon_dotprod;
    aom_sad_skip_16x32x4d = aom_sad_skip_16x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x32x4d = aom_sad_skip_16x32x4d_neon_dotprod;
    aom_sad_skip_16x64 = aom_sad_skip_16x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x64 = aom_sad_skip_16x64_neon_dotprod;
    aom_sad_skip_16x64x4d = aom_sad_skip_16x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_16x64x4d = aom_sad_skip_16x64x4d_neon_dotprod;
    aom_sad_skip_32x16 = aom_sad_skip_32x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x16 = aom_sad_skip_32x16_neon_dotprod;
    aom_sad_skip_32x16x4d = aom_sad_skip_32x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x16x4d = aom_sad_skip_32x16x4d_neon_dotprod;
    aom_sad_skip_32x32 = aom_sad_skip_32x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x32 = aom_sad_skip_32x32_neon_dotprod;
    aom_sad_skip_32x32x4d = aom_sad_skip_32x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x32x4d = aom_sad_skip_32x32x4d_neon_dotprod;
    aom_sad_skip_32x64 = aom_sad_skip_32x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x64 = aom_sad_skip_32x64_neon_dotprod;
    aom_sad_skip_32x64x4d = aom_sad_skip_32x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_32x64x4d = aom_sad_skip_32x64x4d_neon_dotprod;
    aom_sad_skip_64x128 = aom_sad_skip_64x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x128 = aom_sad_skip_64x128_neon_dotprod;
    aom_sad_skip_64x128x4d = aom_sad_skip_64x128x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x128x4d = aom_sad_skip_64x128x4d_neon_dotprod;
    aom_sad_skip_64x16 = aom_sad_skip_64x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x16 = aom_sad_skip_64x16_neon_dotprod;
    aom_sad_skip_64x16x4d = aom_sad_skip_64x16x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x16x4d = aom_sad_skip_64x16x4d_neon_dotprod;
    aom_sad_skip_64x32 = aom_sad_skip_64x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x32 = aom_sad_skip_64x32_neon_dotprod;
    aom_sad_skip_64x32x4d = aom_sad_skip_64x32x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x32x4d = aom_sad_skip_64x32x4d_neon_dotprod;
    aom_sad_skip_64x64 = aom_sad_skip_64x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x64 = aom_sad_skip_64x64_neon_dotprod;
    aom_sad_skip_64x64x4d = aom_sad_skip_64x64x4d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sad_skip_64x64x4d = aom_sad_skip_64x64x4d_neon_dotprod;
    aom_scaled_2d = aom_scaled_2d_neon;
    if (flags & HAS_NEON_DOTPROD) aom_scaled_2d = aom_scaled_2d_neon_dotprod;
    if (flags & HAS_NEON_I8MM) aom_scaled_2d = aom_scaled_2d_neon_i8mm;
    aom_sse = aom_sse_neon;
    if (flags & HAS_NEON_DOTPROD) aom_sse = aom_sse_neon_dotprod;
    aom_var_2d_u8 = aom_var_2d_u8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_var_2d_u8 = aom_var_2d_u8_neon_dotprod;
    aom_variance128x128 = aom_variance128x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance128x128 = aom_variance128x128_neon_dotprod;
    aom_variance128x64 = aom_variance128x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance128x64 = aom_variance128x64_neon_dotprod;
    aom_variance16x16 = aom_variance16x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance16x16 = aom_variance16x16_neon_dotprod;
    aom_variance16x32 = aom_variance16x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance16x32 = aom_variance16x32_neon_dotprod;
    aom_variance16x4 = aom_variance16x4_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance16x4 = aom_variance16x4_neon_dotprod;
    aom_variance16x64 = aom_variance16x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance16x64 = aom_variance16x64_neon_dotprod;
    aom_variance16x8 = aom_variance16x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance16x8 = aom_variance16x8_neon_dotprod;
    aom_variance32x16 = aom_variance32x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance32x16 = aom_variance32x16_neon_dotprod;
    aom_variance32x32 = aom_variance32x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance32x32 = aom_variance32x32_neon_dotprod;
    aom_variance32x64 = aom_variance32x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance32x64 = aom_variance32x64_neon_dotprod;
    aom_variance32x8 = aom_variance32x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance32x8 = aom_variance32x8_neon_dotprod;
    aom_variance4x16 = aom_variance4x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance4x16 = aom_variance4x16_neon_dotprod;
    aom_variance4x4 = aom_variance4x4_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance4x4 = aom_variance4x4_neon_dotprod;
    aom_variance4x8 = aom_variance4x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance4x8 = aom_variance4x8_neon_dotprod;
    aom_variance64x128 = aom_variance64x128_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance64x128 = aom_variance64x128_neon_dotprod;
    aom_variance64x16 = aom_variance64x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance64x16 = aom_variance64x16_neon_dotprod;
    aom_variance64x32 = aom_variance64x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance64x32 = aom_variance64x32_neon_dotprod;
    aom_variance64x64 = aom_variance64x64_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance64x64 = aom_variance64x64_neon_dotprod;
    aom_variance8x16 = aom_variance8x16_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance8x16 = aom_variance8x16_neon_dotprod;
    aom_variance8x32 = aom_variance8x32_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance8x32 = aom_variance8x32_neon_dotprod;
    aom_variance8x4 = aom_variance8x4_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance8x4 = aom_variance8x4_neon_dotprod;
    aom_variance8x8 = aom_variance8x8_neon;
    if (flags & HAS_NEON_DOTPROD) aom_variance8x8 = aom_variance8x8_neon_dotprod;
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AOM_DSP_RTCD_H_
