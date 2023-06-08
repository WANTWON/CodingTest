#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	
	int n, k;
	
	scanf("%d %d", &n, &k);//n명 k번째 
	
	queue<int> q;
	
	for(int i=1; i<=n; i++)
	    q.push(i);
	
	printf("<");
	
	while(q.size()){
		
		if(q.size()==1){
			printf("%d>", q.front());
			q.pop();
			break;
		}
		
		for(int i=1; i<k; i++){
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
		
	}
	
	
	
	return 0;
}
