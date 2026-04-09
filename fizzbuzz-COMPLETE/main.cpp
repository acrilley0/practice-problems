#include <vector>
#include <string>
#include <iostream>

// Given an integer n, return a string array answer (1-indexed) where:
// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.

class Solution {
public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);

    for (int i = 1; i <= n; i++) {
      if (!(i % 3) && !(i % 5)) {
        result[i-1] = "FizzBuzz";
      } else if (!(i % 3)) {
        result[i-1] = "Fizz";
      } else if (!(i % 5)) {
        result[i-1] = "Buzz";
      } else {
        result[i-1] = std::to_string(i);
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto t1 = sol.fizzBuzz(3);
  for (auto & num : t1) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  auto t2 = sol.fizzBuzz(5);
  for (auto & num : t2) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  auto t3 = sol.fizzBuzz(15);
  for (auto & num : t3) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
