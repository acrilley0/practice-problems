#include <iostream>
#include <stdint.h>
#include <stack>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::map;

class Solution {
private:
    bool isOpening(char c)
    {
      return (c == '(' || c == '{' || c == '[');
    }

    bool isClosing(char c)
    {
      return (c == ')' || c == '}' || c == ']');
    }

public:
    bool isValid(string s)
    {
      if (!s.length() % 2 || s.length() < 2)
        return false;

      map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}};

      stack<char> values;
      int countOpen = 0;
      int countClose = 0;
      for (char c : s) {
        if (isOpening(c)) {
          values.push(c);
          countOpen++;
        } else if (isClosing(c)) {
          if (values.empty())
            return false;

          if (values.top() != pairs[c])
            return false;

          values.pop();
          countClose++;
        }
      }

      return countOpen == countClose;
    }
};

int main()
{
  string s1 = "()";
  string s2 = "()[]{}";
  string s3 = "(]";
  string s4 = "([])";
  string s5 = "([)]";
  string s6 = "){";

  Solution sol;
  cout << "s1: " << s1 << " Valid? " << sol.isValid(s1) << endl;
  cout << "s2: " << s2 << " Valid? " << sol.isValid(s2) << endl;
  cout << "s3: " << s3 << " Valid? " << sol.isValid(s3) << endl;
  cout << "s4: " << s4 << " Valid? " << sol.isValid(s4) << endl;
  cout << "s5: " << s5 << " Valid? " << sol.isValid(s5) << endl;
  cout << "s6: " << s6 << " Valid? " << sol.isValid(s6) << endl;

  return 0;
}
