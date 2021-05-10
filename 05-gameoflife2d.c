#include <stdio.h>
#include <unistd.h>

#define MAXROW 20  
#define MAXCOL 45 
#define WRAP 0 
#define ITER 200 

void main() {
	char arr[MAXROW][MAXCOL], duparr[MAXROW][MAXCOL];
	int i, j, iter, neighbors, x, y;
	char c;
	
	printf("\033[2J"); 		// clear screen
	printf("\033[1;1H"); 		// go to first row

	// read data through stdin redirection
	for(i = 0; i < MAXROW; i++) {
		for(j = 0; j < MAXCOL; j++) {
			scanf("%c", &arr[i][j]);
			printf("%c", arr[i][j]);
		}

		// read extra columns in row
		while(1) {
			scanf("%c", &c);
			if(c == '\n') {
				break;
			}
		}
		printf("\n");
	}

	// perform iterations on each state
	for(iter = 0; iter < ITER; iter++) {
		printf("\033[1;1H"); 		// go back to first row
		//		printf("--------------------------------\n");

		for(i = 0; i < MAXROW; i++) {
			for(j = 0; j < MAXCOL; j++) {
				// find count of neighbors for each cell
				neighbors = 0;
				for(y = i - 1; y <= i + 1; y++) {
					for(x = j - 1; x <= j + 1; x++) {
						if(x == j && y == i)
							continue;

						if(WRAP) {
							if(arr[(y + MAXROW) % MAXROW][(x + MAXCOL) % MAXCOL] != ' ')
								neighbors++;
						}
						else {
							if(x >= 0 && y >= 0 && x < MAXCOL && y < MAXROW) {
								if(arr[y][x] == '*')
									neighbors++;
							}
						}
					}
				}

				// compute next state for cell, save in a duplicate array duparr
				if(arr[i][j] == '*' && (neighbors < 2 || neighbors > 3)) {
					duparr[i][j] = ' ';
				}
				else if(arr[i][j] == '*' && (neighbors == 2 || neighbors == 3)) {
				 	duparr[i][j] = '*';
				}
				else if(arr[i][j] == ' ' && neighbors == 3) {
					duparr[i][j] = '*';
				}
				else {
					duparr[i][j] = arr[i][j];
				}
				printf("%c", duparr[i][j]);
			}
			printf("\n");
		}

		// copy duparr into arr
		for(i = 0; i < MAXROW; i++) {
			for(j = 0; j < MAXCOL; j++) {
				arr[i][j] = duparr[i][j];
			}
		}

		usleep(150000);			// pause for 150ms after each iteration
	}
}
