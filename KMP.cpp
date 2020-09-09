#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<stdio.h>
#include<cstdlib>

using namespace std;

//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

int* made_failure(string& pattern) {

	int m = pattern.size();
	int *failure;
	failure = (int*)calloc(m, sizeof(int));
	failure[0] = 0;
	int len = 0;
	int i = 1;
	while (i < m) {
		
		if (pattern[len] == pattern[i]) {
			len++;
			failure[i] = len;
			i++;
		}
		else {

			if (len != 0) {
				len = failure[len - 1];
			}
			else{
				
				failure[i] = 0;
				i++;

			}
		}
	}
	return failure;
}

void KMP_search(string& target, string& pattern) {

	int n = target.size();
	int m = pattern.size();
	int *failure = made_failure(pattern);
	int i = 0;
	int j = 0;
	while( i < n ){
		
		if (target[i] == pattern[j]) {
			i++;
			j++;
		}

		if (j == m) {

			cout << "Found pattern at index " << i - j << endl;
			j = failure[j - 1];
		}
		else if (i < n && target[i] != pattern[j]) {

			if (j != 0) {
				j = failure[j - 1];
			}
			else {
				i = i + 1;
			}
		}
	
	}
	return;
}

int main() {
	
	string target, pattern;
	cin >> target;
	cin >> pattern;
	KMP_search(target, pattern);

	return 0;
}