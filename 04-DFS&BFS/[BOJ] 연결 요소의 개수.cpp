#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int Vertex[1001];
vector<int> Edge[1001];


void DFS(int Index)
{
	Vertex[Index]++;

	if (Edge[Index].size() == 0)
		return;

	for (int i = 0; i < Edge[Index].size() ; i++)
	{
		if (Vertex[Edge[Index][i]] != 0)
			continue;

		DFS(Edge[Index][i]);
	}
	return;
}



int main(void)
{
	int V, E;
	int cnt = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int j = 1; j <= V; j++)
		Vertex[j] = 0;

	for (int i = 0; i < E; i++)
	{
		int E1, E2;
		cin >> E1 >> E2;
		Edge[E1].push_back(E2); //무방향 그래프여서 두번
		Edge[E2].push_back(E1);
	}

	for (int j = 1; j <= V; j++)
	{
		if (Vertex[j] == 0)
		{
			DFS(j);
			cnt++;
		}
			
	}
	
	cout << cnt;
	return 0;
}
