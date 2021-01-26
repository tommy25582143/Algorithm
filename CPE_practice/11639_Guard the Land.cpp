#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
#include<algorithm>

using namespace std;

int main() {


	//FILE* output;
	//output = fopen("output.txt", "w");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int input;
	cin >> input;
	int night = 1;
	while (night <= input) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x3, x4, y3, y4;
		cin >> x3 >> y3 >> x4 >> y4;
		
		int i = max(x1, x3);
		int k = min(x2, x4);
		int j = max(y1, y3);
		int l = min(y2, y4);

		int highly_secured = -1;
		int secured = -1;
		int unsecured = -1;

		if (i >= k || j >= l) {
			highly_secured = 0;
		}
		else {
			highly_secured = (i - k) * (j - l);
		}
		secured = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3) - 2 * highly_secured;
		unsecured = 100 * 100 - highly_secured - secured;
		printf("Night %d: %d %d %d\n", night, highly_secured, secured, unsecured);
		//fprintf(output, "Night %d: %d %d %d\n", i, highly_secured, secured, unsecured);
		night++;
	}	
	//fclose(output);
	return 0;
}