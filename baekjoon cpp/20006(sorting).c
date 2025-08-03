#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
	int level;
	char name[16];
}user;

user room[301][301];

int static compare(user* a, user* b)
{
	if (strcmp(a->name, b->name) > 0)
		return 1;
	else if (strcmp(a->name, b->name) < 0)
		return -1;
	else
		return 0;
}

int main()
{
	int p, m, roomnum = 0;  //roomnum 방 개수
	scanf("%d %d", &p, &m);
    user list[301];
    int idx[301]={0};  //방마다 있는 유저의 수

	for (int i = 0; i < p; i++)
		scanf("%d %s", &list[i].level, list[i].name);

	for (int i = 0; i < p; i++) {
		int chk = 0;
		if (i == 0) {  //첫번째 입장
			room[0][0].level = list[0].level;
			strcpy(room[0][0].name, list[0].name);
			idx[0]++;
			roomnum++;
			continue;
		}

		for (int j = 0; j < roomnum; j++)
		{
			if (room[j][0].level >= list[i].level - 10 && room[j][0].level <= list[i].level + 10)
			{
				if (idx[j] == m) //레벨은 맞지만 이미 꽉찬 방일 경우
					continue;

				//자리가 남고 레벨이 맞는 방을 찾은 경우
				room[j][idx[j]].level = list[i].level;
				strcpy(room[j][idx[j]++].name, list[i].name);
				chk = 1;
				break;
			}
		}

		if (!chk) //레벨에 맞는 방이 없다면 방 생성
		{
			room[roomnum][0].level = list[i].level;
			strcpy(room[roomnum][0].name, list[i].name);
			idx[roomnum]++;
			roomnum++;
		}
	}


	for (int i = 0; i < roomnum; i++)
	{
		if (idx[i] == m)
			printf("Started!\n");
		else
			printf("Waiting!\n");

		qsort(room[i], idx[i], sizeof(room[0][0]), compare); //구조체 내에서 name만 따로 정렬
		for (int j = 0; j < idx[i]; j++)
		{
			printf("%d", room[i][j].level);
			printf(" %s\n", room[i][j].name);
		}
	}
}
