#include <iostream>

using namespace std;

int main()
{
  int tests;
  cin >> tests;

  while (tests--)
  {
    int m, n;

    cin >> m >> n;

    int a[n + 1];

    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    int x, y;
    for (int i = 1; i < n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        int sum = a[i] + a[j];
        if (sum == m)
        {
          x = i;
          y = j;
        }
      }
    }

    cout << x << " " << y << endl;
  }

  return 0;
}
