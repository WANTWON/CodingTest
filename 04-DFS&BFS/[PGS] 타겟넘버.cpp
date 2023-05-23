#include <string>
#include <vector>

using namespace std;

int cnt =0;
int isize =0;
int sum =0;

void dfs(int level, int target, vector<int> numbers, int sum)
{
    if(level == isize)
    {
        if(sum == target)
            cnt ++;
        return;
    }
    
   dfs(level+1, target, numbers, sum + numbers[level]);
   dfs(level+1, target, numbers, sum - numbers[level]);
    
}

int solution(vector<int> numbers, int target) {
    isize = numbers.size();
    dfs(0, target, numbers, sum);

    return cnt;
}