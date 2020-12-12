#include <stdio.h>

int main() {
	int a, b, c, d;

	for (int loop1 = 0; loop1 < 3; loop1++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int sum = a + b + c + d;

		if (sum == 0)
			printf("D\n");
		else if (sum == 1)
			printf("C\n");
		else if (sum == 2)
			printf("B\n");
		else if (sum == 3)
			printf("A\n");
		else
			printf("E\n");
	}
}