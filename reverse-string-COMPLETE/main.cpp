#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void printVec(vector<char> s)
    {
      for (vector<char>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
      }
      cout << endl;
    }

    void reverseString(vector<char>& s)
    {
      char *fp = &s[0];
      char *lp = &s[s.size() - 1];

      while (fp <= lp) {
        char tmp = *fp;
        *fp = *lp;
        *lp = tmp;
        fp++, lp--;
      }
    }
};

int main()
{
  Solution solution;

  vector<char> test1 = { 'H', 'e', 'l', 'l', 'o' };
  solution.printVec(test1);
  solution.reverseString(test1);
  solution.printVec(test1);

  return 0;
}
