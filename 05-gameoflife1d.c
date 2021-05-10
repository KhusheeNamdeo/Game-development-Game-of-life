#include <stdio.h>
#define ROWSIZE 40 
#define ITER 100 

void main() {
	char arr[ROWSIZE], duparr[ROWSIZE];
	int i, iter;
	unsigned char x, y;

	// read data through stdin redirection
	for(i = 0; i < ROWSIZE; i++) {
		scanf("%c", &arr[i]);
		printf("%c", arr[i]);
	}
	printf("\n");

	// start iterations, print row by row
	for(iter = 0; iter < ITER; iter++) {
		duparr[0] = arr[0];
		printf("%c", duparr[0]);
		// compute next state in a new array: duparr
		for(i = 1; i < ROWSIZE - 1; i++) {
			// xor condition
			x = (arr[i - 1] == ' ') ? 0 : 1;
			y = (arr[i + 1] == ' ') ? 0 : 1;
			duparr[i] = (x ^ y == 0) ? ' ' : '*';		// note: conditional operator
			printf("%c", duparr[i]);
		}
		duparr[i] = arr[i];
		printf("%c", duparr[i]);
		printf("\n");

		// copy duparr back to arr
		for(i = 0; i < ROWSIZE; i++) {
			arr[i] = duparr[i];
		}
	}
}
