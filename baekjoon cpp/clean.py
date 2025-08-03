import os
import re

algo_map = {
    'floyd': 'floyd_warshall',
    'Floyd': 'floyd_warshall',
    'Dijkstra': 'dijkstra',
    '브루트포스': 'brute_force',
    '구현': 'implementation',
    'implementation': 'implementation',
    '문자열': 'string',
    'String': 'string',
    'string': 'string',
    '그리디': 'greedy',
    'Greedy': 'greedy',
    'greedy': 'greedy',
    'DP': 'dp',
    'BFS': 'bfs',
    'DFS': 'dfs',
    '다이나믹프로그래밍':'dp',
    '다이나믹 프로그래밍':'dp',
    '투포인터': 'two_pointer',
    'twoPointer': 'two_pointer',
    '백트래킹': 'backtracking',
    'backtracking': 'backtracking',
    '시뮬레이션': 'simulation',
    'simulation': 'simulation',
    '그래프': 'graph',
    'Graph': 'graph',
    'graph': 'graph',
    '정렬': 'sorting',
    '정수론': 'number_theory',
    '이분탐색': 'binary_search',
    'binarysearch': 'binary_search',
    '스택': 'stack',
    '큐': 'queue',
    '덱': 'deque',
    '우선순위큐': 'priority_queue',
    '우선순위 큐': 'priority_queue',
    '트리': 'tree',
    '그리디알고리즘': 'greedy',
    '탐욕법': 'greedy',
    '조합론': 'combinatorics',
    '조합': 'combinatorics',
    '수학': 'math',
    '최단경로': 'shortest_path',
    '누적합': 'prefix_sum',
    '슬라이딩윈도우': 'sliding_window',
    '슬라이딩 윈도우': 'sliding_window',
    '분할정복': 'divide_and_conquer',
    '분할 정복': 'divide_and_conquer',
    '확률론': 'probability',
    'map': 'map',
    '재귀': 'recursion',
    'Knapsack': 'knapsack',
    'union_find': 'union_find',
    'UnionFind': 'union_find',
    '연결리스트': 'linked_list',
    'MST': 'mst',
    '위상정렬': 'topological_sort',
    '벨만포드': 'bellman_ford',
    '비트마스킹': 'bitmask',
    'SCC': 'scc',
    'LCA': 'lca',
    '퀵정렬': 'quick_sort',
    '스위핑': 'sweeping',
    '누적합': 'prefix_sum',
    '누적 합': 'prefix_sum',
    'dijkstra': 'dijkstra',
    'deque': 'deque',
    '해구성하기': 'construct_solution',
    '해 구성하기': 'construct_solution',
}

exception_list = []

for f in os.listdir('.'):
    if os.path.isdir(f):
        continue

    m = re.match(r'^(\d{4,5})\(([^)]+)\)\.(cpp|c|txt)$', f, re.IGNORECASE)
    if m:
        num = int(m.group(1))
        raw_algo = m.group(2).strip()
        ext = m.group(3)
    else:
        m2 = re.match(r'^(\d{4,5})[_\.]?([A-Za-z가-힣 ]+)?\.(cpp|c|txt)$', f, re.IGNORECASE)
        if m2:
            num = int(m2.group(1))
            raw_algo = (m2.group(2) or '').replace('_','').replace('.','').strip()
            ext = m2.group(3)
        else:
            exception_list.append(f + ' (파일명 패턴 불일치)')
            continue

    if not (1000 <= num <= 50000):
        exception_list.append(f + ' (문제번호 범위 밖)')
        continue

    algo = algo_map.get(raw_algo)
    if not algo:
        exception_list.append(f + f" (알고리즘명 매핑없음: '{raw_algo}')")
        continue

    newfname = f"{num:05d}({algo}).{ext}"
    if f != newfname:
        os.rename(f, newfname)

if exception_list:
    print("==== 알고리즘 분류표에 없는(또는 처리 예외) 파일 목록 ====")
    for x in exception_list:
        print(x)
    print("------------------------------------------------------------")
else:
    print("모든 파일이 정상 정리되었습니다.")
