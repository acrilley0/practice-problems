#include <iostream>
#include <string>
#include <map>

std::map<char, int> numerals = {
{'I', 1},
{'V', 5},
{'X', 10},
{'L', 50},
{'C', 100},
{'D', 500},
{'M', 1000},
};

int romanToInt(std::string s)
{
  int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    if (i + 1 < s.length()) {
      if (s[i] == 'I' && s[i + 1] == 'V') {
        sum += 4;
        i++;
        continue;
      } else if (s[i] == 'I' && s[i + 1] == 'X') {
        sum += 9;
        i++;
        continue;
      } else if (s[i] == 'X' && s[i + 1] == 'L') {
        sum += 40;
        i++;
        continue;
      } else if (s[i] == 'X' && s[i + 1] == 'C') {
        sum += 90;
        i++;
        continue;
      } else if (s[i] == 'C' && s[i + 1] == 'D') {
        sum += 400;
        i++;
        continue;
      } else if (s[i] == 'C' && s[i + 1] == 'M') {
        sum += 900;
        i++;
        continue;
      }
      sum += numerals[s[i]];
    } else {
      sum += numerals[s[i]];
    }
  }

  return sum;
}

int main()
{
  std::string test1 = "IV";
  std::cout << "IV: " << romanToInt(test1) << std::endl;

  std::string test2 = "III";
  std::cout << "III: " << romanToInt(test2) << std::endl;

  std::string test3 = "LVIII";
  std::cout << "LVIII: " << romanToInt(test3) << std::endl;

  std::string test4 = "MCMXCIV";
  std::cout << "MCMXCIV: " << romanToInt(test4) << std::endl;

  return 0;
}

