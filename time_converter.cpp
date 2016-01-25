#include <iostream>
#include <string>

using namespace std;

int main()
{
  string time12;

  cin >> time12;

  char p = time12[time12.size() - 2];
  if (p == 'P')
  {
    int t = (int)time12[0] - '0';
    t = t * 10;
    t += (int)time12[1] - '0';
    if (t < 12)
    {
      t += 12;
    }
    cout << t;
    for (int i = 2; i < time12.size() - 2; i++)
    {
      cout << time12[i];
    }
    cout << endl;
  }
  else
  {
    int t = (int)time12[0] - '0';
    t = t * 10;
    t += (int)time12[1] - '0';
    if (t == 12)
    {
      t = 0;
    }

    if (t < 10) cout << 0;
    cout << t;
    for (int i = 2; i < time12.size() - 2; i++)
    {
      cout << time12[i];
    }
    cout << endl;
  }

  return 0;
}
