// Test.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int prime[100000] = { 2 };
	int prime_number = 1;
	for (int i = 3; i * i <= 1000000000; i+=2) {

		bool is_prime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j != 0) {
				continue;
			}
			else {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			prime[prime_number++] = i;
		}
	}
	int input;
	vector<int>ans_list;
	while (cin >> input) {
		if (input == 0) {
			break;
		}

		int ans = input;
		for (int i = 0; input >= prime[i] && i < prime_number; i++) {
			if (input % prime[i] == 0) {
				while (input % prime[i] == 0) {
					input /= prime[i];
				}
				ans /= prime[i];
				ans *= prime[i] - 1;
			}
		}
		if (input != 1) {
			ans /= input;
			ans *= (input - 1);
		}
		cout << ans << '\n';
	}
	
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
