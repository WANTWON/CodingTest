#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[201] = {0,};
int cnt =0;

void dfs(vector<vector<int>> computers, int index, int n)
{
    visited[index] = 1;
    for(int i =0; i < n; i++)
    {
        if(computers[index][i] == 1 && visited[i] == 0)
            dfs(computers, i, n);
    }
}


int solution(int n, vector<vector<int>> computers) {
    
    for(int i =0; i <n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(computers, i, n);
            cnt++;
        }
             
    }
    return cnt;
}
