#include <stdio.h>
#include <stdlib.h>

long long a[100001];
int main()
{	
	long long n, k, res = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	scanf("%lld", &k);

	long long start = 0, end = n, sum = 0, idx = 0;
	while (start<end)
	{
		if (idx > n)
			break;

		if (sum > k) {
			res += n - idx + 1;  
			sum -= a[start];
			start++;
		}
		else {
			sum += a[idx++];
		}
	}
	printf("%lld", res);
}