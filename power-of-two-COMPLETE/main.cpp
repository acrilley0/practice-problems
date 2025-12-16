#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
  bool isPowerOfTwo(int n)
  {
    if (n == 1) {
      return true;
    }

    long base = 1;
    while (base <= n) {
      if (base == n)
        break;
      base *= 2;
    }

    if (base == n) {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution sol;
  cout << sol.isPowerOfTwo(1) << endl;
  cout << sol.isPowerOfTwo(16) << endl;
  cout << sol.isPowerOfTwo(3) << endl;
  return 0;
}
