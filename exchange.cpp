#include <iostream>
#include <string>

using namespace std;

void exchange(string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (isalpha(s[i]))
    {
      if (isupper(s[i])) cout << (char)tolower(s[i]);
      else cout << (char)toupper(s[i]);
    }
    else if (isdigit(s[i]))
    {
      if (s[i] == '1') cout << (char)'O';
      else if (s[i] == '2' || s[i] == '3') cout << (char)'T';
      else if (s[i] == '4' || s[i] == '5') cout << (char)'F';
      else if (s[i] == '6' || s[i] == '7') cout << (char)'S';
      else if (s[i] == '8') cout << (char)'E';
      else if (s[i] == '9') cout << (char)'N';
      else cout << (char)'Z';
    }
    else
    {
      cout << s[i];
    }
  }
  cout << endl;
}

int main()
{
  string line;

  while (getline(cin, line))
  {
    exchange(line);
  }

  return 0;
}
