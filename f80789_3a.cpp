#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int taken[22];
int n, k;
bool found = false;
vector<int> numbers;

void rec(int i)
{
  if (found) return;
  if (i == n)
  {
    int sum = 0;
     for (int j = 0; j < n; j++)
     {
      // cout << taken[j] << " ";
       if (taken[j] == 0)
       {
         sum += numbers[j];
       }
       else
       {
         sum -= numbers[j];
       }
     }
    //cout << " - " << sum << endl;
    if (sum == k)
    {
      for (int j = 0; j < n; j++)
      {
        if (taken[j] == 1)
        {
          cout << -numbers[j];
        }
        else
        {
          if (j > 0) cout << '+';

          cout << numbers[j];
        }
      }
      cout << "=" << k << endl;
      found = true;
    }

    return;
  }

    rec(i + 1);
    taken[i] = 1;
    rec(i + 1);
    taken[i] = 0;
}


int main()
{
  string line;
  int enterNumber;
  while (getline(cin, line))
  {
    istringstream iss(line);
    while (iss >> enterNumber)
    {
      numbers.push_back(enterNumber);
    }
    k = numbers[numbers.size() - 1];
    numbers.pop_back();
    n = numbers.size();

    rec(1);

    if (!found) cout << endl;
    found = false;

    numbers.clear();
    for (int i = 0; i < 22; i++) taken[i] = 0;
  }

  return 0;
}
