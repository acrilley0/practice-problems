#include <iostream>
#include <numeric>

class Solution {
public:
  int gcdOfOddEvenSums(int n) {
    int sum_odds  = 0;
    int sum_evens = 0;

    for (int i = 0; i < 2*n; i++) {
      if (i % 2) {
        sum_odds += i;
      } else {
        sum_evens += i;
      }
    }

    return std::gcd(sum_odds, sum_evens);
  }
};

int main() {
  Solution sol;

  std::cout << sol.gcdOfOddEvenSums(4);

  return 0;
}
