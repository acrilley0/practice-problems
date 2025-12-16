#include <iostream>
using namespace std;

class Solution {
public:
  /* n = 2
   * output = 2
   * 1. 1 step + 1 step
   * 2. 2 setps
   *
   * n = 3
   * output = 3
   * 1. 1 step + 1 step + 1 step
   * 2. 1 step + 2 steps
   * 3. 2 steps + 1 step
   *
   * n = 4
   * output = 5
   * 1. 1 step + 1 step + 1 step + 1 step
   * 2. 1 step + 1 step + 2 steps
   * 3. 1 step + 2 steps + 1 step
   * 4. 2 steps + 1 step + 1 step
   * 5. 2 steps + 2 steps
   */
  int climbStairs(int n) {
    // This problem represents the Fibonacci sequence which has the equation
    // F(i) = F(i-1) + F(i-2)
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 0; i < n; i++) {
      int current = prev2 + prev1;
      prev2 = prev1;
      prev1 = current;
    }

    return prev1;
  }
};

int main() {
  Solution sol;
  cout << sol.climbStairs(2);
}
