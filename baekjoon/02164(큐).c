//첫번째 풀이 원형 큐 구조 

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500001
typedef int element; 
element data[MAX_SIZE];  //이 문제에서는 구조체 안에 큐 배열을 만들면 스택오버플로우. 따라서 전역배열로 선언

typedef struct {
	int front; 
	int rear;  
}Queue;

void init_queue(Queue* q)  //큐를 초기화
{
	q->front = 0;
	q->rear = 0;
}

int isfull(Queue* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

int isempty(Queue* q)
{
	return (q->front == q->rear);
}

void enqueue(Queue* q, element item)
{
	if (isfull(q)) {
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	data[q->rear] = item;
}

element dequeue(Queue* q)
{
	if (isempty(q)) {
		exit(1);
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return data[q->front];
}

element peek(Queue* q)  //다음 dequeue 될 카드를 의미한다.
{
	if (!isempty(q))
		return data[q->front + 1];
	else
		return 0;
}

int main()
{
	Queue q;
	init_queue(&q);
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)  //카드 수 만큼 enqueue
		enqueue(&q, i);

	int card = 0;   //버릴 카드를 의미하는 변수

	while (!isempty(&q))  //큐가 빌 때 까지
	{
		card = dequeue(&q);  //가장 위의 카드를 버린다 -> dequeue
		enqueue(&q, peek(&q));  //버린 후 가장 위의 카드를 가장 밑에 넣는다. -> peek 을 enqueue 해준다.
		dequeue(&q);   //가장 밑에 깔아준 카드를 dequeue한다. (이미 밑으로 보냈으니)

		/*printf("버린 카드 : %d ", card);
		printf("가장 밑으로 까는 카드 : %d ", peek(&q));
		printf("\n");*/
	}
	printf("%d ", card);
	return 0;
}


//2번째 풀이 선형큐로 좀 더 간단히 구현 (enqueue와 dequeue, peek 코드 수정, max size를 2배 해줘야함)
//maxsize 2배의 이유는 선형큐에서 enqueue를 N번 하면 N+1번부터 enqueue 혹은 dequeue 가 시작되게 된다.   +원형큐는 이러한 문제를 잡아준다.
#include <stdio.h>
#define MAX_SIZE 500001*2

int data[MAX_SIZE];
typedef struct {
	int front;
	int rear;
}Queue;

void init_queue(Queue* q)
{
	q->front = -1;
	q->rear = -1;
}

int isempty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(Queue* q, int item)
{
	data[++(q->rear)] = item;
}

int dequeue(Queue* q)
{
	return data[++(q->front)];
}

int peek(Queue* q)
{
	return data[q->front + 1];
}

int main()
{
	Queue q;
	init_queue(&q);
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		enqueue(&q, i);

	int card = 0;
	while (!isempty(&q))
	{
		card = dequeue(&q);
		enqueue(&q, peek(&q));
		dequeue(&q);
	}
	printf("%d ", card);
	return 0;
}