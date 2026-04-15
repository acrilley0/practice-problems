#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
  std::vector<int> findDegrees(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result(matrix.size(), 0);

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j]) {
          result[i]++;
        }
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> t1 = {{0,1,1},{1,0,1},{1,1,0}};
  auto result1 = sol.findDegrees(t1);

  std::for_each(result1.begin(), result1.end(), [](int num){
    std::cout << num << " ";
  });
  std::cout << std::endl;

  std::vector<std::vector<int>> t2 = {{0,1,0},{1,0,0},{0,0,0}};
  auto result2 = sol.findDegrees(t2);

  std::for_each(result2.begin(), result2.end(), [](int num){
    std::cout << num << " ";
  });
  std::cout << std::endl;

  return 0;
}
