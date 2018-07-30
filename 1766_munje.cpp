

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 99999
using namespace std;
int n, m, a, b;
vector< vector<int> > graph;
int indegree[MAX]={0,};



int bfs(){
	priority_queue<int, vector<int>, greater<int> > q;

	for(int i=1;i<=n;i++){
		if (indegree[i]==0){
			q.push(i);
		
		
		}
	}


	//iterate until the queue gets empty 
	while(!q.empty()){
		int val = q.top();
		q.pop();
		printf("%d ",val);

		for(int j=0; j< graph[val].size();j++){
			
			//reduce the indegree of the child node 
			indegree[graph[val][j]]--;

			if (indegree[graph[val][j]]==0){
				q.push(graph[val][j]);

				
			}
		}
	}
	return 0;
}	


int main(){
	scanf("%d %d",&n, &m);
	graph.resize(n+1);

	for(int i=0; i < m; i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		indegree[b]++;

	}


	bfs();

}
