#include <cstdio>

using namespace std;

const int MOVE_X[] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int MOVE_Y[] = { 1,  2, 2, 1, -1, -2, -2, -1};

int table[12][12];
int n, x, y;
bool solution_found;

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

  for (int i = 0; i < 8; i++)
  {
    int next_x = x + MOVE_X[i];
    int next_y = y + MOVE_Y[i];

    if (next_x > 0 && next_x <= n && next_y > 0 && next_y <= n && table[next_x][next_y] == 0)
    {
      dfs(next_x, next_y, d + 1);
    }

  }

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
