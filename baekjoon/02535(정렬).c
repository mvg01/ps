#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num1, num2, score;
}ll;

int static com(ll* a, ll *b)
{
	if (a->score < b->score)
		return 1;
	else if (a->score > b->score)
		return -1;
}

int main()
{
	int n;
	ll list[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d %d", &list[i].num1, &list[i].num2, &list[i].score);
	
	qsort(list, n, sizeof(ll), com);

	int count[101] = { 0 };
	printf("%d %d\n", list[0].num1, list[0].num2);
	count[list[0].num1]++;
	printf("%d %d\n", list[1].num1, list[1].num2);
	count[list[1].num1]++;
	int i;
	for (i = 2; i < n; i++) {
		if (count[list[i].num1] < 2)
			break;
	}
	printf("%d %d", list[i].num1, list[i].num2);
}