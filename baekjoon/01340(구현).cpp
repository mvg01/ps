#include <iostream>
#include <string>
#include <map>
using namespace std;

char mth[12][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int main()
{
	map<string, int>m;
	m.insert({ "January" , 31 });
	m.insert({ "February" , 28 });
	m.insert({ "March" , 31 });
	m.insert({ "April" , 30 });
	m.insert({ "May", 31 });
	m.insert({ "June" , 30 });
	m.insert({ "July" , 31 });
	m.insert({ "August" , 31 });
	m.insert({ "September" , 30 });
	m.insert({ "October" , 31 });
	m.insert({ "November" , 30 });
	m.insert({ "December" , 31 });
	int day = 0, year, hour = 0, min = 0;
	double res = 0;
	string mon, d, c;
	cin >> mon;
	cin >> d;
	day += (d.at(0) - '0') * 10;
	day += d.at(1) - '0';

	cin >> year;
	cin >> c;
	hour += (c.at(0) - '0') * 10;
	hour += c.at(1) - '0';
	min += (c.at(3) - '0') * 10;
	min += c.at(4) - '0';
	
	//cout << m << ' ' << day << ' ' << year << ' ' << hour << ' ' << min << '\n';

	double day_year = 365;
	double pp = 0, tt = 0;
	if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) {  //윤년인 경우
		day_year++;
		m["February"]++;
		for (int i = 0; i < 12; i++) {
			if (mon == mth[i]) {
				pp += day - 1;
				break;
			}
			else
				pp += m[mth[i]];
		}
		res += pp / day_year;

		tt += hour * 60 + min;
		tt /= (day_year * 60 * 24);

		res += tt;
		res *= 100;
	}
	else {
		for (int i = 0; i < 12; i++) {
			if (mon == mth[i]) {
				pp += day - 1;
				break;
			}
			else
				pp += m[mth[i]];
		}
		res += pp / day_year;

		tt += hour * 60 + min;
		tt /= (day_year * 60 * 24);

		res += tt;
		res *= 100;
	}
	printf("%2.10lf", res);
}