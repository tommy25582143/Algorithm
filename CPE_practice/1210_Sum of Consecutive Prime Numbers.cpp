#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;



bool not_prime[10001] = { true, true, false };
vector<int>prime;
vector<int>sum_arr(10001);
void build_prime(){
	for (int i = 2; i <= 10000; i++) {
		if (!not_prime[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= 10000; j += i) {
				not_prime[j] = true;
			}
		}
	}
}
int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build_prime();
	for (int i = 0; i < prime.size(); i++) {
		int sum = prime[i];
		sum_arr[sum]++;
		for (int j = i + 1; j < prime.size(); j++) {
			sum += prime[j];
			if (sum > 10000) {
				break;
			}
			sum_arr[sum]++;
		}
	}
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << sum_arr[n] << '\n';
	}
	//output.close();
	return 0;
}