#include <cstdio>
#include <vector>

using namespace std;

struct Edge
{
  int v, d;

  Edge() {}
  Edge(int v, int d)
  {
    this -> v = v;
    this -> d = d;
  }
};

const int N = 1 << 10;
const int INF = 1 << 30;

int m;
int n = 0;
vector <Edge> g[N];
vector <int> cycle;
vector <int> min_cycle;
bool used[N];
int current_sum;
int min_sum;

void input()
{
  for (int i = 0; i < m; i++)
  {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    g[u].push_back(Edge(v, d));
    g[v].push_back(Edge(u, d));
    if (u > n) n = u;
    if (v > n) n = v;
  }
}

void clean_graph()
{
  for (int i = 1; i <= n; i++)
  {
    g[i].clear();
    used[i] = 0;
  }
  n = 0;
}

void hamilton(int u, int level)
{
  if (u == 1 && level > 0)
  {
    if (level == n)
    {
      min_sum = current_sum;
      min_cycle.clear();
      for (int i = 0; i < cycle.size(); i++)
      {
        min_cycle.push_back(cycle[i]);
      }
    }
    return;
  }

  if (used[u]) return;

  used[u] = 1;

  for (int i = 0; i < g[u].size(); i++)
  {
    Edge e = g[u][i];
    cycle.push_back(e.v);
    current_sum += e.d;

    if (current_sum < min_sum)
    {
      hamilton(e.v, level + 1);
    }
    cycle.pop_back();
    current_sum -= e.d;
  }
  used[u] = 0;
}

void print_cycle()
{
  if (min_cycle.size() > 2)
  {
    for (int i = 0; i < min_cycle.size() - 1; i++)
    {
      printf("%d ", min_cycle[i]);
    }
    printf("\n");
  }
  else
  {
    printf("-1\n");
  }
}

int main()
{
  while (scanf("%d", &m) != EOF)
  {
    input();
    current_sum = 0;
    min_sum = INF;
    cycle.clear();
    min_cycle.clear();
    cycle.push_back(1);
    hamilton(1, 0);
    print_cycle();
    clean_graph();
  }

  return 0;
}
