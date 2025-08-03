#include <stdio.h>

int main()
{
	int list[55];
	int n, s, p, i, res = 1, chk = 0; //chk는 같은 점수가 나왔을 때 등수 처리를 위한 변수
	scanf("%d %d %d", &n, &s, &p);
	for (i = 1; i <= n; i++) {
		scanf("%d", &list[i]);

		if (i < p) {
			if (s >= list[i]) { 
				if (s != list[i]) { 
					res = i;
					res -= chk;
					break;
				}
				else {  //태수 점수와 list 점수가 같다면 chk를 증가시키고 더 해본다.
					chk++;
				}
			}
			else {  //p가 n보다 클 경우를 대비
				res++;
			}
		}

		else if (i == p) { //마지막 등수 처리 10등이냐로 -1이냐 로 갈림
			if (s > list[i]) {
				res = i;
				res -= chk;
				break;
			}
			else {
				printf("-1");
				return 0;
			}
		}


		if (s != list[i])  //다른 점수라면 
			chk = 0;
	}

	printf("%d", res);
}

/*
반례가 정말 많았던 문제.. 나는 첫번째와 두번째 반례가 계속 걸렸었다.

10 1 11
1 1 1 1 1 1 1 1 1 1
ans: 1

10 1 10
1 1 1 1 1 1 1 1 1 1
ans: -1

5 2 5
6 5 4 3 1
ans: 5

9 5 10
10 10 10 9 9 8 7 6 6
ans: 10

*/