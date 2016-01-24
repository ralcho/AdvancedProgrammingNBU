#include <iostream>
#include <string>

using namespace std;

int frequencies[26];

int main()
{
  string message;

  getline(cin, message);

  for (int i = 0; i < message.size(); i++)
  {
    char letter = message[i];
    if (isalpha(letter))
    {
      if (isupper(letter))
      {
        frequencies[(int)(letter - 'A')]++;
      }
      else
      {
        frequencies[(int)(letter - 'a')]++;
      }
    }
  }

  string result_message = "pangram";
  for (int i = 0; i < 26; i++)
  {
    if (frequencies[i] == 0)
    {
      result_message = "not pangram";
    }
  }

  cout << result_message << endl;

  return 0;
}
