#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_VERTEX 100

typedef vector < int > Graph;

Graph g[MAX_VERTEX];
bool visited[MAX_VERTEX];

void read(){
	int num, a, b;
	cout << "Please input the total node number:";
	cin >> num;
	cout << "Please input the vertex.\n";
	cout << "Enter '-100' ,if you don't want to enter anymore.\n";
	cout << "Input: ";
	while (true){
		cin >> a;
		if (a == -100){ break; }
		cin >> b;
		if (b == -100){ break; }
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int j = 0; j < MAX_VERTEX; ++j)
		sort(g[j].begin(), g[j].end());
}

void DFS(int v){
	visited[v] = true;
	cout << v << " ";
	for (int j = 0; j < g[v].size(); ++j){
		if (!visited[g[v][j]])
			DFS(g[v][j]);
	}
}

void BFS(int v){
	queue < int > s;
	visited[v] = true;
	cout << v << " ";
	s.push(v);
	while (!s.empty()){
		v = s.front();
		s.pop();
		for (int j = 0; j < g[v].size(); ++j){
			if (!visited[g[v][j]]){
				cout << g[v][j] << " ";
				s.push(g[v][j]);
				visited[g[v][j]] = true;
			}
		}
	}
}

int main(){
	for (int i = 0; i < MAX_VERTEX; ++i)
		g[i].clear();

	read();

	cout << "Right now output DFS: ";

	for (int i = 0; i < MAX_VERTEX; ++i)
		visited[i] = false;

	DFS(0);

	cout << "\nRight now output BFS: ";

	for (int i = 0; i < MAX_VERTEX; ++i)
		visited[i] = false;

	BFS(0);

	system("pause");
}