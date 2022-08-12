#include "dft.h"
#include"coefficients1024.h"
#include"ap_int.h"
void dft (DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE], DTYPE real_op[SIZE], DTYPE imag_op[SIZE]) {
#pragma HLS INTERFACE m_axi port=imag_op bundle=out depth=1024
#pragma HLS INTERFACE m_axi port=real_op bundle=out depth=1024
#pragma HLS INTERFACE m_axi port=imag_sample bundle=in depth=1024
#pragma HLS INTERFACE m_axi port=real_sample bundle=in depth=1024

#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

	int j, i;
	DTYPE c;
	DTYPE s;
	DTYPE t_real[SIZE];
	DTYPE t_imag[SIZE];


	for (i = 0; i < SIZE; i += 1) {
		#pragma HLS unroll factor=2
		for (j = 0; j < SIZE; j += 1) {
			#pragma HLS PIPELINE II=1
			c = cos_coefficients_table[(ap_uint<10>)(i * j)];
			s = sin_coefficients_table[(ap_uint<10>)(i * j)];

			t_real[j] += (real_sample[i] * c - imag_sample[i] * s);
			t_imag[j] += (real_sample[i] * s + imag_sample[i] * c);
		}
	}
	for (j = 0; j < SIZE; j += 1) {
		#pragma HLS PIPELINE II=1
		real_op[j] = t_real[j];
		imag_op[j] = t_imag[j];
	}
	}

