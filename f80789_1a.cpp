#include <cstdio>
#include <cstring>

using namespace std;

int binary_to_decimal(char * number)
{
  int result = 0;
  int power = 0;
  for (int i = strlen(number) - 1; i >= 0; i--)
  {
    int x = number[i] - '0';
    result +=  x * (1 << power);
    power++;
  }

  return result;
}

int octal_to_decimal(char * number)
{
  int result = 0;
  int number_length = strlen(number);
  for (int i = 0; i < number_length; i++)
  {
    result += number[i] - '0';
    if (i < number_length - 1)
    {
      result *= 8;
    }
  }

  return result;
}

int hexadecimal_to_decimal(char *number)
{
  int number_length = strlen(number);
  char result[100] = "";
  for (int i = 0; i < number_length; i++)
  {
    if (number[i] == '0') strcat(result, "0000");
    else if (number[i] == '1') strcat(result, "0001");
    else if (number[i] == '2') strcat(result, "0010");
    else if (number[i] == '3') strcat(result, "0011");
    else if (number[i] == '4') strcat(result, "0100");
    else if (number[i] == '5') strcat(result, "0101");
    else if (number[i] == '6') strcat(result, "0110");
    else if (number[i] == '7') strcat(result, "0111");
    else if (number[i] == '8') strcat(result, "1000");
    else if (number[i] == '9') strcat(result, "1001");
    else if (number[i] == 'A') strcat(result, "1010");
    else if (number[i] == 'B') strcat(result, "1011");
    else if (number[i] == 'C') strcat(result, "1100");
    else if (number[i] == 'D') strcat(result, "1101");
    else if (number[i] == 'E') strcat(result, "1110");
    else if (number[i] == 'F') strcat(result, "1111");
  }

  return binary_to_decimal(result);
}

int main()
{
  int numeral_system;
  char number[100];

  while (scanf("%d%s", &numeral_system, number) != EOF)
  {
    if (numeral_system == 2) printf("%d\n", binary_to_decimal(number));
    else if (numeral_system == 8) printf("%d\n", octal_to_decimal(number));
    else if (numeral_system == 16) printf("%d\n", hexadecimal_to_decimal(number));
  }

  return 0;
}
