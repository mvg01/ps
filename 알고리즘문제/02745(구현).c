#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[38];
	int n, i, len;
	double sum = 0;
	scanf("%s %d", s, &n);
	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			sum += ((s[i] - '0') * pow(n, len - 1 - i));
            
		else
			sum += ((s[i] - 'A' + 10) * pow(n, len - 1 - i));
	}
	printf("%.0lf", sum);
}