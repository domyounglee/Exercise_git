#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int n, m, a, b;
vector<vector<int> > graph;
bool visited[32123];
vector<int> ans;
 
void dfs(int here)
{
    //탈출조건 
    if (visited[here]) return;
    visited[here] = true;
 
    for (int i = 0; i<graph[here].size(); i++) {
        dfs(graph[here][i]);
    }
 
    ans.push_back(here); // 재귀 탈출 하면서 현재 정점을 넣어준다.
}
 
int main()
{
    scanf("%d %d", &n, &m);
    graph.resize(n + 1);
    for (int i = 0; i<m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b); // a가 b앞에 
    }
 
    for (int i = 1; i <= n; i++)
        dfs(i);
 
    reverse(ans.begin(), ans.end()); // 결과를 뒤집어 준다.
    for (int i = 0; i<ans.size(); i++) printf("%d ", ans[i]);

    return 0;
}



