#include <vector>
#include <iostream>

class Solution {
public:
  char nextGreatestLetter(std::vector<char>& letters, char target) {
    for (char let : letters) {
      if (let > target) {
        return let;
      }
    }

    return letters[0];
  }
};

int main() {
  Solution sol;

  std::vector<char> t1 = {'c','f','j'};
  std::cout << sol.nextGreatestLetter(t1, 'a') << std::endl;

  std::vector<char> t2 = {'c','f','j'};
  std::cout << sol.nextGreatestLetter(t2, 'c') << std::endl;

  std::vector<char> t3 = {'x','x','y','y'};
  std::cout << sol.nextGreatestLetter(t3, 'z') << std::endl;

  return 0;
}
