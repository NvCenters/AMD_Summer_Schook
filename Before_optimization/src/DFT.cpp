#include<math.h>
#include "dft.h"
#include"coefficients1024.h"

void dft (DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE], DTYPE real_op[SIZE], DTYPE imag_op[SIZE]) {
	int i, j;
	DTYPE w;
	DTYPE c, s;
	DTYPE temp_r, temp_i;

	/*#pragma HLS array_partition variable=real_sample cyclic factor=8
	#pragma HLS array_partition variable=imag_sample cyclic factor=8
	#pragma HLS array_partition variable=real_op cyclic factor=8
	#pragma HLS array_partition variable=imag_op cyclic factor=8
	#pragma HLS array_partition variable=cos_coefficients_table cyclic factor=8
	#pragma HLS array_partition variable=sin_coefficients_table cyclic factor=8*/
	#pragma HLS RESOURCE variable=sin_coefficients_table core=ROM_1P_LUTRAM
	#pragma HLS RESOURCE variable=cos_coefficients_table core=ROM_1P_LUTRAM
	#pragma HLS INTERFACE m_axi depth=1024 port=real_sample offset=slave
	#pragma HLS INTERFACE m_axi depth=1024 port=imag_sample offset=slave
	#pragma HLS INTERFACE m_axi depth=1024 port=real_op offset=slave
	#pragma HLS INTERFACE m_axi depth=1024 port=imag_op offset=slave
	for (i = 0; i < 1024; i += 1) {
		temp_r = 0;
		temp_i = 0;
		#pragma HLS unroll factor=32
		for (j = 0; j < 1024; j += 1) {
			#pragma HLS PIPELINE II=1
			int index = (i*j)%SIZE;
			c = cos_coefficients_table[index];
			s = sin_coefficients_table[index];

			real_op[i] += (real_sample[j] * c - imag_sample[j] * s);
			imag_op[i] += (real_sample[j] * s + imag_sample[j] * c);
		}

	}
}
