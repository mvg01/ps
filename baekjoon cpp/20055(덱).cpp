#include <iostream>
#include <deque>
using namespace std;

deque<int> a;       //내구도
deque<bool> robot;  //로봇이 있는지

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, x, res = 1;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> x;
		a.push_back(x);
		robot.push_back(false);
	}
	
	while (1) {
		//1. 벨트 회전(내구도 감소 없음)
		a.push_front(a.back());
		a.pop_back();
		robot.push_front(robot.back());
		robot.pop_back();

		if (robot.at(n - 1) == true)      //n번위치 벨트에서 내린다.
			robot.at(n - 1) = false;

		//2. 로봇 이동
		/* 컨베이어 벨트 뒤에서부터(n-1) 로봇이 있는지 체크할 것임
		* 로봇이 있다면 거기서부터 1번위치까지 가면서 로봇 이동해준다.
		* 로봇 이동조건 = 이동할 벨트의 내구도가 1이상 && 이동할 벨트에 로봇이 없어야함 */

		for (int i = n - 2; i >= 0; i--) {
			if (robot.at(i) == true && a.at(i + 1) > 0 && robot.at(i + 1) == false) {
				robot.at(i + 1) = true;
				robot.at(i) = false;  
				a.at(i + 1)--;        //이동할 곳의 내구도 감소
			}
		}
		if (robot.at(n - 1) == true)  //로봇이 n번에 있다면 추가 내구도 감소없이 내림
			robot.at(n - 1) = false;

		//3. 로봇을 벨트의 1번 위치에 두기
		if (a.at(0) > 0) {
			robot.at(0) = true;
			a.at(0)--;
		}

		//4. 탈출조건
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (a.at(i) == 0)
				cnt++;
		}
		if (cnt >= k)
			break;

		res++;
	}
	cout << res;
}