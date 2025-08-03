#include <stdio.h>
#include <string.h>
int main()
{
	while (1) {
		char str[21];
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
			break;
		int len, i;
		len = strlen(str);
		char check = '.';       //연속적으로 나오는게 있나 체크해주는 문자
		int aeiou_check = 0;    //모음이 한번 나왔는지 체크
		int three_count_a = 0;  //모음 카운트
		int three_count_b = 0;  //자음 카운트
		int twice = 0;
		for (i = 0; i < len; i++)
		{
			if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u') {

				if (str[i] == check) {  //전과 같은 문자라면 not acceptable 이 나오는 조건을 안고 탈출시킴
					aeiou_check = 0;
					break;
				}
				aeiou_check = 1;
				check = str[i]; 
				three_count_a++; //모음 카운트
				three_count_b = 0;  //자음 연속 3번 초기화
			}

			else if(str[i]=='e'||str[i]=='o') {
				aeiou_check = 1;
				check = str[i];
				three_count_a++; //모음 카운트
				three_count_b = 0;  //자음 연속 3번 초기화
			}

			else
			{
				if (str[i] == check) {
					aeiou_check = 0;
					break;
				}
				check = str[i];
				three_count_a = 0;  //모음 3번 연속 초기화
				three_count_b++;  //자음 카운트
			}


			if (three_count_a == 3 || three_count_b == 3) {
				aeiou_check = 0; //자음 혹은 모음이 3번 연속 나오면 not acceptable 이 나오는 조건을 안고 탈출시킴
				break;
			}
		}
	
		if (aeiou_check == 1)
			printf("<%s> is acceptable.\n", str);
		else
			printf("<%s> is not acceptable.\n", str);
	}
	return 0;
}