#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef union {
	float floating_value_in_32_bits;
	struct sign_exp_mantissa {
		unsigned mantissa : 23;
		unsigned exponent : 8;
		unsigned sign : 1;
	} f_bits;
	struct single_bits {
		unsigned  b0 : 1;
		unsigned  b1 : 1;
		unsigned  b2 : 1;
		unsigned  b3 : 1;
		unsigned  b4 : 1;
		unsigned  b5 : 1;
		unsigned  b6 : 1;
		unsigned  b7 : 1;
		unsigned  b8 : 1;
		unsigned  b9 : 1;
		unsigned  b10 : 1;
		unsigned  b11 : 1;
		unsigned  b12 : 1;
		unsigned  b13 : 1;
		unsigned  b14 : 1;
		unsigned  b15 : 1;
		unsigned  b16 : 1;
		unsigned  b17 : 1;
		unsigned  b18 : 1;
		unsigned  b19 : 1;
		unsigned  b20 : 1;
		unsigned  b21 : 1;
		unsigned  b22 : 1;
		unsigned  b23 : 1;
		unsigned  b24 : 1;
		unsigned  b25 : 1;
		unsigned  b26 : 1;
		unsigned  b27 : 1;
		unsigned  b28 : 1;
		unsigned  b29 : 1;
		unsigned  b30 : 1;
		unsigned  b31 : 1;
	}bit;
}FLOAT_UN;

int main(int argc, char* argv[]) {
	FLOAT_UN float_32_s1, float_32_s2, float_32_result, fun_arg;

	float hardwareResult;
	int mantS1, mantS2, mantResult, expS1, expS2;
	int i, j, k, a, b, shiftCount;
	char bit_string_S1[43];
	char bit_string_S2[43];
	char bit_string_result[43];
	bool denomS1 = true;
	bool denomS2 = true;

	printf("Please enter two positive floating point values each with:\n");
	printf("\t- no more than 6 significant digits\n");
	printf("\t- a value between + 10**37 and 10**-37\n\n");
	printf("Enter Float 1: ");
	scanf_s("%g", &float_32_s1.floating_value_in_32_bits);

	for (a = 0; a < 42; a++) {
		bit_string_S1[a] = ' ';
	}
	bit_string_S1[42] = '\0';

	bit_string_S1[0] = float_32_s1.bit.b31 ? '1' : '0';

	bit_string_S1[2] = float_32_s1.bit.b30 ? '1' : '0';
	bit_string_S1[3] = float_32_s1.bit.b29 ? '1' : '0';
	bit_string_S1[4] = float_32_s1.bit.b28 ? '1' : '0';
	bit_string_S1[5] = float_32_s1.bit.b27 ? '1' : '0';

	bit_string_S1[7] = float_32_s1.bit.b26 ? '1' : '0';
	bit_string_S1[8] = float_32_s1.bit.b25 ? '1' : '0';
	bit_string_S1[9] = float_32_s1.bit.b24 ? '1' : '0';
	bit_string_S1[10] = float_32_s1.bit.b23 ? '1' : '0';

	bit_string_S1[12] = float_32_s1.bit.b22 ? '1' : '0';
	bit_string_S1[13] = float_32_s1.bit.b21 ? '1' : '0';
	bit_string_S1[14] = float_32_s1.bit.b20 ? '1' : '0';

	bit_string_S1[16] = float_32_s1.bit.b19 ? '1' : '0';
	bit_string_S1[17] = float_32_s1.bit.b18 ? '1' : '0';
	bit_string_S1[18] = float_32_s1.bit.b17 ? '1' : '0';
	bit_string_S1[19] = float_32_s1.bit.b16 ? '1' : '0';

	bit_string_S1[21] = float_32_s1.bit.b15 ? '1' : '0';
	bit_string_S1[22] = float_32_s1.bit.b14 ? '1' : '0';
	bit_string_S1[23] = float_32_s1.bit.b13 ? '1' : '0';
	bit_string_S1[24] = float_32_s1.bit.b12 ? '1' : '0';

	bit_string_S1[26] = float_32_s1.bit.b11 ? '1' : '0';
	bit_string_S1[27] = float_32_s1.bit.b10 ? '1' : '0';
	bit_string_S1[28] = float_32_s1.bit.b9 ? '1' : '0';
	bit_string_S1[29] = float_32_s1.bit.b8 ? '1' : '0';

	bit_string_S1[31] = float_32_s1.bit.b7 ? '1' : '0';
	bit_string_S1[32] = float_32_s1.bit.b6 ? '1' : '0';
	bit_string_S1[33] = float_32_s1.bit.b5 ? '1' : '0';
	bit_string_S1[34] = float_32_s1.bit.b4 ? '1' : '0';

	bit_string_S1[36] = float_32_s1.bit.b3 ? '1' : '0';
	bit_string_S1[37] = float_32_s1.bit.b2 ? '1' : '0';
	bit_string_S1[38] = float_32_s1.bit.b1 ? '1' : '0';
	bit_string_S1[39] = float_32_s1.bit.b0 ? '1' : '0';

	printf("Enter Float 2: ");
	scanf_s("%g", &float_32_s2.floating_value_in_32_bits);

	for (a = 0; a < 42; a++) {
		bit_string_S2[a] = ' ';
	}
	bit_string_S2[42] = '\0';

	bit_string_S2[0] = float_32_s2.bit.b31 ? '1' : '0';

	bit_string_S2[2] = float_32_s2.bit.b30 ? '1' : '0';
	bit_string_S2[3] = float_32_s2.bit.b29 ? '1' : '0';
	bit_string_S2[4] = float_32_s2.bit.b28 ? '1' : '0';
	bit_string_S2[5] = float_32_s2.bit.b27 ? '1' : '0';

	bit_string_S2[7] = float_32_s2.bit.b26 ? '1' : '0';
	bit_string_S2[8] = float_32_s2.bit.b25 ? '1' : '0';
	bit_string_S2[9] = float_32_s2.bit.b24 ? '1' : '0';
	bit_string_S2[10] = float_32_s2.bit.b23 ? '1' : '0';

	bit_string_S2[12] = float_32_s2.bit.b22 ? '1' : '0';
	bit_string_S2[13] = float_32_s2.bit.b21 ? '1' : '0';
	bit_string_S2[14] = float_32_s2.bit.b20 ? '1' : '0';

	bit_string_S2[16] = float_32_s2.bit.b19 ? '1' : '0';
	bit_string_S2[17] = float_32_s2.bit.b18 ? '1' : '0';
	bit_string_S2[18] = float_32_s2.bit.b17 ? '1' : '0';
	bit_string_S2[19] = float_32_s2.bit.b16 ? '1' : '0';

	bit_string_S2[21] = float_32_s2.bit.b15 ? '1' : '0';
	bit_string_S2[22] = float_32_s2.bit.b14 ? '1' : '0';
	bit_string_S2[23] = float_32_s2.bit.b13 ? '1' : '0';
	bit_string_S2[24] = float_32_s2.bit.b12 ? '1' : '0';

	bit_string_S2[26] = float_32_s2.bit.b11 ? '1' : '0';
	bit_string_S2[27] = float_32_s2.bit.b10 ? '1' : '0';
	bit_string_S2[28] = float_32_s2.bit.b9 ? '1' : '0';
	bit_string_S2[29] = float_32_s2.bit.b8 ? '1' : '0';

	bit_string_S2[31] = float_32_s2.bit.b7 ? '1' : '0';
	bit_string_S2[32] = float_32_s2.bit.b6 ? '1' : '0';
	bit_string_S2[33] = float_32_s2.bit.b5 ? '1' : '0';
	bit_string_S2[34] = float_32_s2.bit.b4 ? '1' : '0';

	bit_string_S2[36] = float_32_s2.bit.b3 ? '1' : '0';
	bit_string_S2[37] = float_32_s2.bit.b2 ? '1' : '0';
	bit_string_S2[38] = float_32_s2.bit.b1 ? '1' : '0';
	bit_string_S2[39] = float_32_s2.bit.b0 ? '1' : '0';
	printf("\nOriginal pattern of Float 1: %s\n", bit_string_S1);
	printf("Original pattern of Float 2: %s\n", bit_string_S2);

	hardwareResult = float_32_s2.floating_value_in_32_bits + float_32_s1.floating_value_in_32_bits;

	mantS1 = float_32_s1.f_bits.mantissa;
	mantS2 = float_32_s2.f_bits.mantissa;
	expS1 = float_32_s1.f_bits.exponent;
	expS2 = float_32_s2.f_bits.exponent;

	if (expS1) {
		mantS1 |= (1 << 23);
		denomS1 = false;
	}
	if (expS2) {
		mantS2 |= (1 << 23);
		denomS2 = false;
	}

	if ((shiftCount = expS1 - expS2) < 0) {
		shiftCount = -(shiftCount); /* keep diff + */
		if (shiftCount > 24)shiftCount = 24;
		if (shiftCount >= 1 && denomS1) {
			mantS1 = (mantS1 >> shiftCount - 1);
		}
		else {
			mantS1 = mantS1 >> shiftCount;
		}
		float_32_result.f_bits.exponent = expS2;
	}
	else {
		if (shiftCount > 24)shiftCount = 24;
		if (shiftCount >= 1 && denomS2) {
			mantS2 = (mantS2 >> shiftCount - 1);
		}
		else {
			mantS2 = mantS2 >> shiftCount;
		}
		float_32_result.f_bits.exponent = expS1;
	}

	mantResult = mantS1 + mantS2;

	if (mantResult & (1 << 24)) {
		mantResult >>= 1;
		float_32_result.f_bits.exponent++;
		printf("\n2 HIDDEN BITS, MUST INCREMENT EXPONENT\n");
			float_32_result.f_bits.mantissa = (mantResult & ~(1 << 23));
	}
	else {
		float_32_result.f_bits.mantissa = (mantResult & ~(1 << 23));
	}

	for (a = 0; a < 42; a++) {
		bit_string_result[a] = ' ';
	}
	bit_string_result[42] = '\0';

	bit_string_result[0] = float_32_result.bit.b31 ? '1' : '0';

	bit_string_result[2] = float_32_result.bit.b30 ? '1' : '0';
	bit_string_result[3] = float_32_result.bit.b29 ? '1' : '0';
	bit_string_result[4] = float_32_result.bit.b28 ? '1' : '0';
	bit_string_result[5] = float_32_result.bit.b27 ? '1' : '0';

	bit_string_result[7] = float_32_result.bit.b26 ? '1' : '0';
	bit_string_result[8] = float_32_result.bit.b25 ? '1' : '0';
	bit_string_result[9] = float_32_result.bit.b24 ? '1' : '0';
	bit_string_result[10] = float_32_result.bit.b23 ? '1' : '0';

	bit_string_result[12] = float_32_result.bit.b22 ? '1' : '0';
	bit_string_result[13] = float_32_result.bit.b21 ? '1' : '0';
	bit_string_result[14] = float_32_result.bit.b20 ? '1' : '0';

	bit_string_result[16] = float_32_result.bit.b19 ? '1' : '0';
	bit_string_result[17] = float_32_result.bit.b18 ? '1' : '0';
	bit_string_result[18] = float_32_result.bit.b17 ? '1' : '0';
	bit_string_result[19] = float_32_result.bit.b16 ? '1' : '0';

	bit_string_result[21] = float_32_result.bit.b15 ? '1' : '0';
	bit_string_result[22] = float_32_result.bit.b14 ? '1' : '0';
	bit_string_result[23] = float_32_result.bit.b13 ? '1' : '0';
	bit_string_result[24] = float_32_result.bit.b12 ? '1' : '0';

	bit_string_result[26] = float_32_result.bit.b11 ? '1' : '0';
	bit_string_result[27] = float_32_result.bit.b10 ? '1' : '0';
	bit_string_result[28] = float_32_result.bit.b9 ? '1' : '0';
	bit_string_result[29] = float_32_result.bit.b8 ? '1' : '0';

	bit_string_result[31] = float_32_result.bit.b7 ? '1' : '0';
	bit_string_result[32] = float_32_result.bit.b6 ? '1' : '0';
	bit_string_result[33] = float_32_result.bit.b5 ? '1' : '0';
	bit_string_result[34] = float_32_result.bit.b4 ? '1' : '0';

	bit_string_result[36] = float_32_result.bit.b3 ? '1' : '0';
	bit_string_result[37] = float_32_result.bit.b2 ? '1' : '0';
	bit_string_result[38] = float_32_result.bit.b1 ? '1' : '0';
	bit_string_result[39] = float_32_result.bit.b0 ? '1' : '0';

	if (bit_string_result[0] == '1') {
		bit_string_result[0] = '0';
		float_32_result.floating_value_in_32_bits = float_32_result.floating_value_in_32_bits * -1;
	}
	else {
		bit_string_result[0] = '1';
		float_32_result.floating_value_in_32_bits = float_32_result.floating_value_in_32_bits * -1;
	}
	//printf("mantResult: %c\n", bit_string_result[0]);
	printf("Bit pattern of result      : %s\n", bit_string_result);
	printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %g\n", float_32_result.floating_value_in_32_bits);
	printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> %f\n", hardwareResult);
}
