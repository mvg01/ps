#include <stdio.h>
#include <string.h>
char stack[101];
int top = -1;
void push(char s)
{
	stack[++top] = s;
}
void pop(void)
{
	top--;
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
	while (1) {
		top = -1;     //top 전역변수 초기화
		char s[101];
		int i, len, check = 0;
		scanf("%[^\n]s", s);   //엔터 입력까지 문자열 받기
		getchar();    //문자열 버퍼 비워주기
		if (s[0] == '.')
			break;
		len = strlen(s);
		for (i = 0; i < len; i++)
		{
			if (s[i] == '(' || s[i] == '[') 
				push(s[i]);
			if (s[i] == ')' || s[i] == ']')
			{
				if (empty()) {
					check = 1;
					break;
				}
				if (s[i] == ')') {
					if (stack[top] == '(')
						pop();
					else {
						check = 1;
						break;
					}
				}
				else if (s[i] == ']') {
					if (stack[top] == '[')
						pop();
					else {
						check = 1;
						break;
					}
				}
			}
		}
		if (check == 1||empty()==0)
			printf("no\n");
		else if (empty())
			printf("yes\n");
	}
}	

//반례 input [. 였습니다. ---->59번째 조건문 변경