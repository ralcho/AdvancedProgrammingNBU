#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;

int n, k;
int c[N];
int x[N];

bool compare(int a, int b)
{
  return a > b;
}

int main()
{
  cin >> n >> k;

  //(x[i] + 1)*c[i]
  for (int i = 1; i <= n; i++)
  {
    cin >> c[i];
  }

  sort(c + 1, c + n + 1, compare);

  int answer = 0;
  for (int i = 1; i <= n; i++)
  {
    // answer += c[i] * (n / k + 1);
    int t = i / k;
    if (i % k == 0) t--;
    // cout << c[i] << " " << t + 1 << endl;
    answer += c[i] * (t + 1);
  }
  cout << answer << endl;

  return 0;
}
