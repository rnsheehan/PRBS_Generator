#ifndef ATTACH_H
#include "Attach.h"
#endif

// Implementation of a code needed to generate PRBS sequences of various lengths
// R. Sheehan 12 - 2 - 2026


int main()
{

	uint8_t start = 0x02;
	uint8_t a = start;
	int i; 
	for (i = 1;; i++) {
		int newbit = (((a >> 6) ^ (a >> 5)) & 1);
		a = ((a << 1) | newbit) & 0x7f;
		printf("%x\n", a);
		if (a == start) {
			printf("repetition period is %d\n", i);
			break;
		}
	}


	return 0;
}