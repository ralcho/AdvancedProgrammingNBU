#include <cstdio>
#include <queue>
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

void bfs(int u)
{
  queue <int> q;
  q.push(u);
  visited[u] = 1;

  while (q.size() > 0)
  {
    int front = q.front();
    q.pop();

    printf("%d ", front);

    for (int i = 0; i < graph[front].size(); i++)
    {
      int v = graph[front][i];
      if (!visited[v])
      {
        q.push(v);
        visited[v] = 1;
      }
    }
  }
}

int main()
{
  input();
  bfs(1);
  printf("\n");
  
  return 0;
}
