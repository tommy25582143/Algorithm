#include <iostream>
#include <vector>	
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;


int main() {

	char day[3];
	int date;
	char month[3];
	int year;
	int hour, minute, second;
	char time_zone[3];

	scanf("%3s, %2d %3s %d %d:%d:%d %s", day, date, month, year, hour, minute, second, time_zone);

	int day_number;
	if (strcmp(day, "MON") == 0) {
		day_number = 1;
	}
	else if (strcmp(day, "TUE") == 0) {
		day_number = 2;
	}
	else if (strcmp(day, "WED") == 0) {
		day_number = 3;
	}
	else if(strcmp(day, "THU") == 0){
		day_number = 4;
	}
	else if (strcmp(day, "FRI") == 0) {
		day_number = 5;
	}
	else if (strcmp(day, "SAT") == 0) {
		day_number = 6;
	}
	else {
		day_number = 7;
	}

	int month_number;
	if (strcmp(month, "JAN") == 0) {
		month_number = 1;
	}
	else if (strcmp(month, "FEB") == 0) {
		month_number = 2;
	}
	else if (strcmp(month, "MAR") == 0) {
		month_number = 3;
	}
	else if (strcmp(month, "APR") == 0) {
		month_number = 4;
	}
	else if (strcmp(month, "MAY") == 0) {
		month_number = 5;
	}
	else if (strcmp(month, "JUN") == 0) {
		month_number = 6;
	}
	else if (strcmp(month, "JUL") == 0) {
		month_number = 7;
	}
	else if (strcmp(month, "AUG") == 0) {
		month_number = 8;
	}
	else if (strcmp(month, "SEP") == 0) {
		month_number = 9;
	}
	else if (strcmp(month, "OCT") == 0) {
		month_number = 10;
	}
	else if (strcmp(month, "NOV") == 0) {
		month_number = 11;
	}
	else {
		month_number = 12;
	}
	return 0;
}
