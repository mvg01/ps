#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;  //데이터의 자료형
typedef struct {
	element* data;  //스택 배열
	int capacity;  //스택 배열의 크기
	int top; 
}STACK;

void init_stack(STACK* s)  //스택 생성 함수
{
	s->top = -1;
	s->capacity = 1;  //크기 1부터 시작, 크기 모자라면 push 함수에서 배열 크기를 동적할당 해줍니다.
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int isfull(STACK* s)
{
	if (s->top == (s->capacity - 1))  //꽉 차버리면 1 return
		return 1;
}

int isempty(STACK* s)  //비어있을 시 1 return
{
	if (s->top == -1)
		return 1;
}

void push(STACK *s,element n) {
	if (isfull(s)) {  // 스택 배열이 꽉 차면 스택 배열 크기를 직접 할당으로 늘려줌
		s->capacity +=10;  //꽉 찰 때마다 10씩 늘려줌
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));  //이미 할당한 공간의 크기를 바꿀 때 realloc 사용
	}
	s->data[++(s->top)] = n;
}

void pop(STACK *s) {
	if (s->top == -1)
		printf("-1\n");
	else if (s->top > -1)
		printf("%d\n", s->data[(s->top)--]);
}

void size(STACK *s) {
	printf("%d\n", s->top + 1);
}

void empty(STACK *s) {
	if (s->top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void TOP(STACK *s) {
	if (s->top == -1)
		printf("-1\n");
	else
		printf("%d\n", s->data[s->top]);
}


int main()
{
	STACK s;
	init_stack(&s);
	int n, i, num;
	char str[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &num);
			push(&s,num);
		}
		if (strcmp(str, "pop") == 0) {
			pop(&s);
		}
		if (strcmp(str, "size") == 0) {
			size(&s);
		}
		if (strcmp(str, "empty") == 0) {
			empty(&s);
		}
		if (strcmp(str, "top") == 0) {
			TOP(&s);
		}
	}
	free(s.data);
}

/*  스택 배열을 전역변수로 두고 했던 첫 풀이

#include <stdio.h>
#include <string.h>

int stack[10001] = { 0 };
int idx = 0;

void push(int n) {
	stack[idx] = n;
	idx++;
}
void pop(void) {
	if (idx == 0)
		printf("-1\n");
	else if (idx > 0) {
		idx--;
		printf("%d\n", stack[idx]);
		stack[idx] = 0;
	}
}
void size(void) {
	printf("%d\n", idx);
}
void empty(void) {
	if (idx == 0)
		printf("1\n");
	else
		printf("0\n");
}
void top(void) {
	if (idx == 0)
		printf("-1\n");
	else
		printf("%d\n", stack[idx - 1]);
}


int main()
{
	int n, i, num;
	char s[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &num);
			push(num);
		}
		if (strcmp(s, "pop") == 0) {
			pop();
		}
		if (strcmp(s, "size") == 0) {
			size();
		}
		if (strcmp(s, "empty") == 0) {
			empty();
		}
		if (strcmp(s, "top") == 0) {
			top();
		}
	}
}

*/