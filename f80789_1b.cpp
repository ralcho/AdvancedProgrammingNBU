#include <cstdio>
#include <cmath>

using namespace std;

int a[1000010];

bool is_prime(int number)
{
  if (number < 2) return false;
  double root = sqrt(number);
  for (int i = 2; i <= root; i++)
  {
    if (number % i == 0) return false;
  }

  return true;
}

int main()
{
  for (int i = 1; i <= 1000000; i++)
  {
    if (is_prime(i)) a[i] = 1;
  }

  for (int i = 1; i <= 1000000; i++)
  {
    a[i] += a[i - 1];
  }

  int tests;
  scanf("%d", &tests);

  while (tests--)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", a[y] - a[x - 1]);
  }

  return 0;
}
