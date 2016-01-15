#include <cstdio>
#include <vector>

using namespace std;

const int N = 1 << 10;
vector <int> graph[N];
bool visited[N];
int m;

void input()
{
  scanf("%d\n", &m);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
  }
}

void dfs(int u)
{
  visited[u] = 1;
  printf("%d ", u);
  for (int i = 0; i < graph[u].size(); i++)
  {
    int v = graph[u][i];
    if (!visited[v])
    {
      dfs(v);
    }
  }
}

int main()
{
  input();
  dfs(1);
  printf("\n");

  return 0;
}
