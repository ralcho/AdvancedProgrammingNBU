#include <cstdio>

using namespace std;

const int MOVE_X[] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int MOVE_Y[] = { 1,  2, 2, 1, -1, -2, -2, -1};
const int INF = 1 << 10;

int table[12][12];
int n, x, y;
bool solution_found;

bool check(int x, int y)
{
  return x > 0 && x <= n && y > 0 && y <= n && table[x][y] == 0;
}

int count_conflicts(int x, int y)
{
  int cnt = 0;

  for (int i = 0; i < 8; i++)
  {
    int next_x = x + MOVE_X[i];
    int next_y = y + MOVE_Y[i];

    if (check(next_x, next_y)) cnt++;
  }

  return cnt;
}

void dfs(int x, int y, int d)
{
  if (solution_found == true) return;

  table[x][y] = d;
  if (n * n == d)
  {
    solution_found = true;
    for (int i = 1; i <= n; i++)
    {
      printf("%d", table[i][1]);
      for (int j = 2; j <= n; j++)
      {
        printf(" %d", table[i][j]);
      }
      printf("\n");
    }

    return;
  }

  int best = 10;
  int best_x = INF, best_y = INF;

  for (int i = 0; i < 8; i++)
  {
    int next_x = x + MOVE_X[i];
    int next_y = y + MOVE_Y[i];

    if (check(next_x, next_y))
    {
      int cnt = count_conflicts(next_x, next_y);
      if (best > cnt)
      {
        best = cnt;
        best_x = next_x;
        best_y = next_y;
      }
    }
  }

  if (best < INF) dfs(best_x, best_y, d + 1);

  table[x][y] = 0;
}

int main()
{
  while (scanf("%d%d%d", &n, &x, &y) != EOF)
  {
    for (int i = 1; i <= 10; i++)
      for (int j = 1; j <= 10; j++)
        table[i][j] = 0;

    solution_found = false;
    dfs(x, y, 1);
  }

  return 0;
}
