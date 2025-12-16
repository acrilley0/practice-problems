#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    bool is_positive =
        (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

    if (dividend == divisor) {
      return 1;
    }

    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    if (divisor == 1) {
      return dividend;
    }

    dividend = dividend < 0 ? dividend : -dividend;
    divisor = divisor < 0 ? divisor : -divisor;

    int count = 0;
    while (dividend - divisor <= 0) {
      dividend -= divisor;
      count++;
    }

    if (!is_positive) {
      count *= -1;
    }

    return count;
  }
};

int main() {
  Solution sol;
  cout << sol.divide(10, 3) << endl;
  cout << sol.divide(7, -3) << endl;
  cout << sol.divide(1, 1) << endl;
  cout << sol.divide(-2147483648, 1) << endl;
  cout << sol.divide(-2147483648, 2) << endl;

  return 0;
}
