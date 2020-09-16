﻿#include <iostream>
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
	else if (strcmp(day, "THU") == 0) {
		day_number = 4;
	}
	else if (strcmp(day, "FRI") == 0) {
		day_number = 5;
	}
	else if (strcmp(day, "SAT") == 0) {
		day_number = 6;
	}
	else if (strcmp(day, "SUN") == 0) {
		day_number = 7;
	}
	else {
		cout << "day error" << endl;
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
	else if (strcmp(month, "DEC") == 0) {
		month_number = 12;
	}
	else {
		cout << "month error" << endl;
	}
	int year_number;

	if (year < 100) {
		year_number = year + 1900;
	}
	else
	{
		year_number = year;
	}

	int time_zone_number;
	if (strcmp(time_zone, "UT") == 0) {
		time_zone_number = 0;
	}
	else if (strcmp(time_zone, "GMT") == 0) {
		time_zone_number = 0;
	}
	else if (strcmp(time_zone, "EDT") == 0) {
		time_zone_number = -4;
	}
	else if (strcmp(time_zone, "CDT") == 0) {
		time_zone_number = -5;
	}
	else if (strcmp(time_zone, "MDT") == 0) {
		time_zone_number = -6;
	}
	else if (strcmp(time_zone, "PDT") == 0) {
		time_zone_number = -7;
	}
	else {
		cout << "time_zone_error" << endl;
	}

	/*start calculating*/

	hour += (3 - time_zone_number);
	if (hour >= 24) {
		day_number += 1;
		date += 1;
		hour -= 24;
	}
	else if (hour < 0) {
		day_number -= 1;
		hour += 24;
		date -= 1;
	}
	else {

	}

	if (day_number > 7) {
		day_number -= 7;
	}
	else if (day_number < 1) {
		day_number += 7;
	}
	else {

	}

	int month_total_date;
	if (month_number == 1 || month_number == 3 || month_number == 5
		|| month_number == 7 || month_number == 8 || month_number == 10
		|| month_number == 12) {

		month_total_date = 31;

	}
	else if (month_number == 2) {

		if (year % 4 == 0 && year % 100 != 0) {
			month_total_date == 29;
		}
		else if (year % 400 == 0) {
			month_total_date = 29;
		}
		else {
			month_total_date = 28;
		}

	}
	else {

		month_total_date = 30;

	}

	if (date > month_total_date) {
		date -= month_total_date;
		month_number++;
		if (month_number > 12) {

			month_number -= 12;
			year += 1;

		}
	}
	else if (date < 1) {

		month_number--;
		if (month_number < 1) {

			month_number += 12;
			year -= 1;

		}

		if (month_number == 1 || month_number == 3 || month_number == 5
			|| month_number == 7 || month_number == 8 || month_number == 10
			|| month_number == 12) {

			date = 31;

		}
		else if (month_number == 2) {

			if (year % 4 == 0 && year % 100 != 0) {
				date == 29;
			}
			else if (year % 400 == 0) {
				date = 29;
			}
			else {
				date = 28;
			}

		}
		else {

			date = 30;

		}
	}
	else {

	}

	/*starting output*/
	switch (month_number)
	{
	case 1:
		cout << "MON";
		break;

	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 7:
		cout << "SUN";
		break;
	default:
		cout << "error";
		break;
	}

	cout << ", ";
	return 0;
}