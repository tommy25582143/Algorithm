// Test.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{

	Graph() {};
	Graph(int n) :n(n), distance(n, n+1), color(n, 0), predecessor(n, -1), adjlist(n) {};
	~Graph() {};
	void AddEdgeList(int from, int to) {
		adjlist[from].push_back(to);
		return;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			cout << predecessor[i] << " ";
		}
	}
	void BFS(int start);
	int n;
	vector<vector<int>>adjlist;
	vector<int>distance;
	vector<int>color;
	vector<int>predecessor;
};

void Graph::BFS(int start) {

	int i = start;
	queue<int>q;
	for (int j = 0; j < n; j++) {

		if (color[i] == 0) {

			distance[i] = 0;
			color[i] = 1;
			predecessor[i] = -1;
			q.push(i);
			
			while (!q.empty()) {
				
				int u = q.front();
				for (vector<int>::iterator itr = adjlist[u].begin(); itr != adjlist[u].end(); itr++) {

					if (color[*itr] == 0) {

						distance[*itr] = distance[u] + 1;
						color[*itr] = 1;
						predecessor[*itr] = u;
						q.push(*itr);

					}

				}
				color[u] = -1;
				q.pop();
			}

		}

		i = j;

	}

}

int main()
{
	Graph g1(9);
	g1.AddEdgeList(0, 1);
	g1.AddEdgeList(0, 2); 
	g1.AddEdgeList(0, 3);
	g1.AddEdgeList(1, 0); 
	g1.AddEdgeList(1, 4);
	g1.AddEdgeList(2, 0); 
	g1.AddEdgeList(2, 4); 
	g1.AddEdgeList(2, 5);
	g1.AddEdgeList(2, 6);
	g1.AddEdgeList(2, 7);
	g1.AddEdgeList(3, 0); 
	g1.AddEdgeList(3, 7);
	g1.AddEdgeList(4, 1); 
	g1.AddEdgeList(4, 2); 
	g1.AddEdgeList(4, 5);
	g1.AddEdgeList(5, 2); 
	g1.AddEdgeList(5, 4);
	g1.AddEdgeList(5, 8);
	g1.AddEdgeList(6, 2);
	g1.AddEdgeList(6, 7);
	g1.AddEdgeList(6, 8);
	g1.AddEdgeList(7, 2); 
	g1.AddEdgeList(7, 3);
	g1.AddEdgeList(7, 6);
	g1.AddEdgeList(8, 5); 
	g1.AddEdgeList(8, 6);
	g1.BFS(0);
	g1.print();
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
