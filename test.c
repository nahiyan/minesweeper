#include <stdio.h>

int main () {
	int map[2][2][4], i, j, k, x = 1;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 4; k++) {
				map[i][j][k] = 0;
				printf("%d.\t%p\t%d\n", x, &map[i][j][k], map[i][j][k]);
				x++;
			}
		}
	}

	int* mp = &map[0][0][0];


	return 0;
}