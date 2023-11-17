#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[200001] = { 0 };

int bfs(int start) {
	//오름차순 최소 거리와 이동위치 정보를 가진 pair
	//cur(현재 초) 기준으로 오름차순 정렬이라고 생각하면 쉽게 풀린다.
	//우선순위 큐로 현재 초가 짧은 위치 기준으로 탐색을 하게 한다.
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	visited[start] = 1;
	pq.push({ 0,start });
	while (!pq.empty()) {

		if (pq.top().second == k) 
			return pq.top().first;
		
		int cur = pq.top().first; //현재 초
		int a[3];  //이동 가능한 위치들
		a[0] = pq.top().second * 2;  //순간이동 하는 경우
		a[1] = pq.top().second + 1;  //앞으로 1칸
		a[2] = pq.top().second - 1;  //뒤로 1칸
		pq.pop();

		for (int i = 0; i < 3; i++) {
			if (!visited[a[i]] && a[i] <= 100000 && a[i] >= 0) {
				visited[a[i]] = 1;
				if (i == 0) 
					pq.push({ cur,a[i] });
				
				else if (i == 1) 
					pq.push({ cur + 1,a[i] });
				
				else if (i == 2) 
					pq.push({ cur + 1,a[i] });
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> k;
	cout << bfs(n);
}