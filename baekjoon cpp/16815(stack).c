#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
typedef struct STACK {
	char data[105];
}S;

void push(S* s,char ele)
{
	s->data[++top] = ele;
}

void pop(S* s)
{
	top--;
}

char peek(S* s)
{
	return s->data[top];
}

int main()
{
	S s;
	char str[105];
	int i, len;
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '(')
			push(&s, '(');

		else if (str[i] == ')')
			pop(&s);

		else if (str[i] == '*')
		{
			printf("%d", top + 1);
			break;
		}
	}
}