#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string a, b;
  getline(cin, a);
  getline(cin, b);
  vector <int> x;
  vector <int> y;

  for (int i = a.size() - 1; i >= 0; i--)
  {
    x.push_back(a[i] - '0');
  }

  for (int i = b.size() - 1; i >= 0; i--)
  {
    y.push_back(b[i] - '0');
  }

  for (int i = 0; i < a.size() - b.size(); i++)
  {
    y.push_back(0);
  }

  vector<int> r;

  for (int i = 0; i < x.size(); i++)
  {
    int t = 0;

    if (x[i] >= y[i]) t = x[i] - y[i];
    else
    {
      t = 10 + x[i] - y[i];
      x[i + 1]--;
    }

    r.push_back(t);
  }

  int i = r.size() - 1;

  while (r[i] == 0) i--;
  while (i >= 0)
  {
    cout << r[i];
    i--;
  }

  cout << endl;

  return 0;
}
