#include <stdio.h>
#include <string.h>
char stack[51];
char s[51];
int top = -1;

void push(char s)
{
	stack[top++] = s;
}

void pop(char s)
{
	stack[--top] = s;
}

int empty()
{
	if (top == -1)
		return 1;
	else
        return 0;
}

int main(void)
{
	int t, len, check = 0;
	scanf("%d", &t);
	while (t--)
	{
		top = -1;
		scanf("%s", s);
		len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			check = 0;
			if (s[i] == '(')  
				push(s[i]);

			if (empty() == 1) {  // '(' 가 없는데 ')' 이 먼저 나온 경우 check해주고 탈출한다.
				check=1;
				break;
			}

			if (s[i] == ')')
				pop(s[i]);
			
		}
		if (empty() && check == 0) //스택이 비어있고 check되어 탈출된 경우가 아니라면
			printf("YES\n"); 
		else if (empty() != 1 || check == 1) //스택에 pop 되지 못한게 남아있거나 ')'가 먼저나온 경우
			printf("NO\n");
	}
}