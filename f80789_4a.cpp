#include <cstdio>
#include <cctype>

using namespace std;

int a[10];

void print_number(int a[])
{
  for (int i = 9; i >= 0; i--)
  {
    while (a[i] > 0)
    {
      printf("%d", i);
      a[i]--;
    }
  }
  printf("\n");
}

int main()
{
  char x;

  while (scanf("%c", &x) != EOF)
  {
    if (x == ' ')
    {
      print_number(a);
    }
    else if (isdigit(x))
    {
      a[x - '0']++;
    }
  }
  print_number(a);

  return 0;
}
