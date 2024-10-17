#include <stdio.h>
#define MAX_SIZE 100001

char res[MAX_SIZE*2];  //결과는 한개의 수 마다 pop과 push를 최대 2번씩 할 수 있기 때문에 2배를 잡아준다.
typedef struct {
	int data[MAX_SIZE];
	int top;
}STACK;

void init_stack(STACK* s)
{
	s->top = -1;
}

int isempty(STACK* s)  //비어있을 시 1 return
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void push(STACK* s, int n) 
{
	s->data[++(s->top)] = n;
}

int peek(STACK* s)
{
	if (isempty(s) == 1)
		return -1;
	else
		return s->data[s->top];
}

void pop(STACK* s) {
	(s->top)--;
}

int empty(STACK* s) {
	if (s->top == -1)
		return 1;
}


int main(void)
{
	STACK s;
	init_stack(&s);
	int i, n, x, idx = 0, num = 0; //idx는 결과의 배열인덱스, num은 스택에 오름차순으로 들어가는 숫자
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (peek(&s) < x)  //top 원소보다 작으면
		{
			while (peek(&s) < x) {  //top원소가 x가 될 때 까지 push
				push(&s, ++num);
				res[idx++] = '+';
			}
		}
		else if (peek(&s) > x)   //top원소가 x보다 작다면
		{
			while (peek(&s) != x) { //top원소가 x가 될 때까지 pop
				pop(&s);
				res[idx++] = '-';
			}
		}

		if (peek(&s) != x)  //push or pop을 해준결과가 top의 원소와 다르다면
		{
			printf("NO");  //만들 수 없는 수열
			return 0; 
		}
		else {   //pop 연산을 한번 해주면서 수열생성
			pop(&s);
			res[idx++] = '-';
		}
	}
	
	for (i = 0; i < idx; i++)
		printf("%c\n", res[i]);

	return 0;
}