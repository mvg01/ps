//1. 시작 날짜와 현재 날짜의 총 일수를 구하고 현재날짜에서 시작날짜를 빼준다.
//2. 캠프가 천년이상 지속된다면 의 의미가 애매했는데 day1과 day2를 비교하면 안되고
//   년 비교하고 월 비교하고 일 비교하는 방식으로 해줘야한다. <- 이 조건문에서 조금 해맸던 문제..
//  (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) 윤년의 조건을 한줄로 
#include <stdio.h>

int main()
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int mon_2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 }; //윤년
	int y1, m1, d1;
	int y2, m2, d2;
	int day1 = 0, day2 = 0, i;
	scanf("%d %d %d", &y1, &m1, &d1);
	scanf("%d %d %d", &y2, &m2, &d2);
	for (i = 1; i < y1; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			day1 += 366;
		else
			day1 += 365;
	}
	if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
	{
		for (i = 0; i < m1 - 1; i++)
			day1 += mon_2[i];
	}
	else
	{
		for (i = 0; i < m1 - 1; i++)
			day1 += mon[i];
	}
	day1 += d1;

	for (i = 1; i < y2; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) 
			day2 += 366;
		else
			day2 += 365;
	}
	if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0)
	{
		for (i = 0; i < m2 - 1; i++)
			day2 += mon_2[i];
	}
	else
	{
		for (i = 0; i < m2 - 1; i++)
			day2 += mon[i];
	}
	day2 += d2;


	if (y2 - y1 > 1000) //차이가 1000 이상나면 볼 것도 없이 gg
		printf("gg");
	else if (y2 - y1 == 1000)  //차이가 1000 일 때는 월, 월도 같다면 일을 봐줘야한다.
	{
		if (m1 > m2)
			printf("D-%d", day2 - day1);
		else if (m1 == m2)
		{
			if (d1 <= d2)  //년,월,일이 같아도 gg 이다. (문제를 잘 읽었어야지..)
				printf("gg");
			else
				printf("D-%d", day2 - day1);
		}
		else
			printf("gg");
	}
	else
		printf("D-%d", day2 - day1);
}