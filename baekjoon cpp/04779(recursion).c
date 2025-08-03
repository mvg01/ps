#include <stdio.h>
#include <math.h>

void f(int n) {
	if (n == 0) {
		printf("-");
		return 0;
	}
	if (n == 1) {
		printf("- -");
		return;
	}
	
	f(n - 1);
	for (int j = 0; j < pow(3,n-1); j++)
		printf(" ");
	f(n - 1);
	return 0;
}

int main() 
{
	int x;
	while (scanf("%d", &x) != EOF) {
		f(x);
		printf("\n");
	}
}