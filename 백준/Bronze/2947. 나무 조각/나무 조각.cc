#include <stdio.h>

int main()
{
	int b[5] = { 0 };
	for (int i = 0; i < 5; i++) scanf("%d", &b[i]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (b[j] > b[j + 1]) {
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				for (int k = 0; k < 5; k++) printf("%d ", b[k]);
				printf("\n");
			}
		}
	}
	return 0;
}