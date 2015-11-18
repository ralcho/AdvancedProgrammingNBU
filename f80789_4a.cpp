#include <cstdio>
#include <cstring>

using namespace std;

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
  char s[256];
  int a[10];
  for (int i = 0; i < 10; i++) a[i] = 0;
  while (scanf("%s", s) != EOF)
  {
    for (int i = 0; i < strlen(s); i++)
    {
      a[s[i] - '0']++;
    }
    print_number(a);
    for (int j = 0; j < 10; j++) a[j] = 0;
  }

  return 0;
}
