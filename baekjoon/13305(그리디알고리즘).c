#include <stdio.h>

long long road[100001]; //도로의 길이
long long oil[100001];  //기름값
int main(void)
{
	unsigned long long n, i, price = 0;  //100점을 맞으려면 자료형을 longlong으로 해주어야 함
	scanf("%lld", &n);
	for (i = 0; i < n - 1; i++)
		scanf("%lld", &road[i]);
	for (i = 0; i < n; i++)
		scanf("%lld", &oil[i]);

	price += oil[0] * road[0];  //확정적으로 더해줘야 함
	int minprice = oil[0];  //가장 싼 기름의 가격을 저장해서 사용
	for (i = 1; i < n; i++)
	{
		if (oil[i] > minprice) //새로운 도시에 도착했을 때 그 도시의 기름이 더 비싸면
			price += minprice * road[i];  //가장 싼 도시에서 가야할 만큼 기름값을 넣은 것으로 하자
		else {   //새로운 도시에 도착했는데 그 도시의 기름이 전에 넣은 기름보다 싸면 
    		price += oil[i] * road[i]; //이 도시에서 일단 가야하는 만큼 넣고
			minprice = oil[i];  //싼 기름 가격을 기억하자.
		}
	}
	printf("%lld", price);
}