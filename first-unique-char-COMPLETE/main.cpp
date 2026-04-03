#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::unordered_map<char,int> freqs = {}; // This does not preserve insertion order so we can't use this to find the FIRST uniq char
    std::vector<char> ordered_chars = {}; // Keep track of the order that chars are added

    std::for_each(s.begin(), s.end(), [&freqs, &ordered_chars](char let) {
      freqs[let]++;
      ordered_chars.push_back(let);
    });

    int idx = 0;
    for (const auto & let : ordered_chars) {
      if (freqs[let] == 1) {
        return idx;
      }
      idx++;
    }

    return -1;
  }
};

int main() {
  Solution sol;

  std::string test1 = "leetcode";
  std::cout << sol.firstUniqChar(test1) << std::endl;

  std::string test2 = "loveleetcode";
  std::cout << sol.firstUniqChar(test2) << std::endl;

  std::string test3 = "aabb";
  std::cout << sol.firstUniqChar(test3) << std::endl;

  return 0;
}
