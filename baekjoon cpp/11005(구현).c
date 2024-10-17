#include <stdio.h>
#include <string.h>

void rev(char str[])
{
	int i, len;
	char rev[40];
	len = strlen(str);
	for (i = 0; i < len; i++)
		rev[i] = str[len - 1 - i];

	rev[len] = '\0';
	printf("%s", rev);
}

int main()
{
	char s[40];
	int n, b, idx = 0;
	scanf("%d %d", &n, &b);
	while (n != 0) 
	{
		int x;
		x = n % b;
		if (x >= 10)   //10 이상 숫자가 아니므로 x를 문자로 만들어준다. 
		{
			x += 'A' - 10; 
		}
		else
		{
			x += '0';
		}
		s[idx++] = x;
		n /= b;
	}
	s[idx] = '\0';
	rev(s);
}