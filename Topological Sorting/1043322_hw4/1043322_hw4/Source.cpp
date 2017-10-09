#include <iostream>
//#include <algorithm>

using namespace std;

bool graph[51][51]; // adjacency matrix
//bool x[51];
int visit[51];       // �O��DFS�M���L���I
int order[51], n, num;   // �x�s�@�ӦX�z���ƦC����
int st1 = -998;   //�Ĥ@�ӼƦr

bool cycle;         // �O��DFS���L�{���O�_��������

void read(){
	int a, b;
	cout << "Please input the total node number:";
	cin >> num;
	cout << "Please input the vertex.\n";
	cout <<"Enter '-100' ,if you don't want to enter anymore.\n";
	cout << "Input: ";
	while (true){
		cin >> a;
		if (a == -100){ break; }
		cin	>> b;
		if (b == -100){ break; }
		graph[a][b] = true;
	}
}
/*
void DFS(int s)
{
	// back edge�A�����C
	if (visit[s] == 1) { cycle = true; return; }
	// forward edge�Bcross edge�C
	if (visit[s] == 2) return;

	visit[s] = 1;
	for (int t = st1; t<=num; t++)
	if (graph[s][t]) 
		DFS(t);
	visit[s] = 2;

	order[n--] = s;     // �O���X�z���ƦC����
	//n--;
}

void topological_sort()
{
	// ��l��
	for (int i = 0; i <= num; i++) visit[i] = 0;
	cycle = false;
	n = num;

	// �i��DFS
	for (int s = st1; s <= num; s++)
	if (!visit[s])
		DFS(s);

	// ��X���G
	if (cycle)
		cout << "Error!! It got a cycle!!";
	else
		// �L�X�@�ӦX�z���ƦC����
	for (int i = st1; i <= num ; ++i)
		cout << order[i];
}
*/

void DFS(int s)
{
	// back edge�A�����C
	if (visit[s] == 1) { cycle = true; return; }
	// forward edge�Bcross edge�C
	if (visit[s] == 2) return;

	visit[s] = 1;
	for (int i = 0; i < num; i++)
	if (graph[s][i])
		DFS(i);
	visit[s] = 2;

	order[n--] = s;     // �O���X�z���ƦC����
	//n--;
}

void topological_sort()
{
	// ��l��
	for (int i = 0; i < num; i++) visit[i] = 0;
	cycle = false;
	n = num-1;

	// �i��DFS
	for (int s = 0; s < num; s++)
	if (!visit[s])
		DFS(s);

	// ��X���G
	if (cycle)
		cout << "Error!! It got a cycle!!";
	else
		// �L�X�@�ӦX�z���ƦC����
	for (int i = 0; i < num; ++i)
		cout << order[i];
}

int main()
{
	for (int i = 0; i < 51; i++)
	{
		//x[i] = false;
		for (int j = 0; j < 51; j++)
		{
			graph[i][j] = false;
		} 
	}
	read();
	/*
	for (int i = 0; i < 50; i++){ 
		for (int j = 0; j < 50; j++){
			if (st1 == -998 && graph[i][j] == true){ st1 = i; }
		}
	}
	*/
	//order[st1] = st1;
	cout << "Ans: ";
	topological_sort();
	cout << endl;

	system("pause");
	return 0;
}