#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int top;
	int* data;
}Stack;
void init(Stack* s, int size) {
	s->top = 0;
	s->data = (int*)malloc(sizeof(int) * size);
}
int pop(Stack* s) {
	return s->data[--s->top];
}
void push(Stack* s, int e) {
	s->data[s->top++] = e;
}
int peek(Stack* s) {
	return s->data[s->top - 1];
}
int empty(Stack* s) {
	return (s->top == 0);
}

int main()
{
	Stack s;
	int n, x, idx = 0;
	int* res, * arr;
	scanf("%d", &n);
	init(&s, n);
	res = (int*)calloc(n, sizeof(int));
	arr = (int*)calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		res[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		while (!empty(&s)) {
			if (arr[peek(&s)] < arr[i]) //오큰수가 나왔다면
				res[pop(&s)] = arr[i];
			else
				break;
		}
		push(&s, i);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", res[i]);

	free(s.data);
	free(res);
	free(arr);
}