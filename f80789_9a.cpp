#include <cstdio>

using namespace std;

const int N = 1 << 10;
int a[N][N], m;
int INF = 1 << 20;
int n = 0;

void input()
{
  for (int i = 0; i < m; i++)
  {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    a[u][v] = d;
    if (u > n) n = u;
    if (v > n) n = v;
  }
}

void floyd()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (a[i][j] == 0) a[i][j] = INF;
    }
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (a[i][j] > (a[i][k] + a[k][j]))
        {
          a[i][j] = a[i][k] + a[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    a[i][i] = 0;
  }
}

void print_graph()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (a[i][j] == INF) printf("-1 ");
      else printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

void clear_graph()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      a[i][j] = 0;
    }
  }
  n = 0;
}

int main()
{
  while (scanf("%d", &m) != EOF)
  {
    input();
    floyd();
    print_graph();
    clear_graph();
  }
  return 0;
}
