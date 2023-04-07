#include <stdio.h>

int plusdp[100001];
int minusdp[100001];
int a[100001];
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	plusdp[0] = 1;  //시작 수열은 1개 이므로
	minusdp[0] = 1;

	for (i = 1; i < n; i++) {  //같거나 증가하는 것 중 가장 긴 수열개수
		if (a[i] >= a[i - 1]) 
			plusdp[i] = plusdp[i - 1] + 1;
		else
			plusdp[i] = 1;
	}

	for (i = 1; i < n; i++) {  //같거나 감소하는 것 중 가장 긴 수열개수
		if (a[i] <= a[i - 1]) 
			minusdp[i] = minusdp[i - 1] + 1;
		else
			minusdp[i] = 1;
	}

	int max = 0;
	for (i = 0; i < n; i++) { 
		if (max < plusdp[i])
			max = plusdp[i];
		if (max < minusdp[i])
			max = minusdp[i];
	}
	printf("%d", max);
}