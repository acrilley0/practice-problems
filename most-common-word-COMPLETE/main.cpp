#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

class Solution {
public:
  std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
    auto space_idx   = paragraph.find(' ');
    int word_start_idx = 0;

    if (std::ispunct(paragraph[paragraph.size() - 1])) {
      paragraph.erase(paragraph.size() - 1);
    }

    std::map<std::string,int> word_counts;

    std::replace_if(paragraph.begin(), paragraph.end(), [&paragraph](unsigned char c) {
      return std::ispunct(c);
    }, ' ');
    paragraph.erase(
      std::unique(paragraph.begin(), paragraph.end(), [](char a, char b) {
        return (a == ' ') && (b == ' ');
      }),
      paragraph.end()
    );

    bool stop_flag = false;
    while (true) {
      std::string word = paragraph.substr(word_start_idx, space_idx - word_start_idx);
      std::transform(word.begin(), word.end(), word.begin(),
                     [&word](char c) { return std::tolower(c); });

      // We only want to count the word if it is not banned
      if (std::find(banned.begin(), banned.end(), word) == banned.end()) {
        word_counts[word]++;
      }

      word_start_idx = space_idx + 1;
      space_idx = paragraph.find(' ', word_start_idx);

      if (stop_flag) {
        break;
      }

      if (space_idx == std::string::npos) {
        stop_flag = true;
      }
    }

    std::pair<std::string, int> count_of_word = {"", 0};
    for (auto iter = word_counts.begin(); iter != word_counts.end(); ++iter) {
      if (iter->second > count_of_word.second) {
        count_of_word.first  = iter->first;
        count_of_word.second = iter->second;
      }
    }

    return count_of_word.first;
  }
};

int main() {
  Solution sol;

  std::string p1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
  std::vector<std::string> b1 = {"hit"};
  std::cout << "Most common word: " << sol.mostCommonWord(p1, b1) << std::endl;
  // sol.mostCommonWord(p1, b1);

  std::string p2 = "a b.b";
  std::vector<std::string> b2 = {};
  std::cout << "Most common word: " << sol.mostCommonWord(p2, b2) << std::endl;
  // sol.mostCommonWord(p2, b2);

  std::string p3 = "a.";
  std::vector<std::string> b3 = {};
  std::cout << "Most common word: " << sol.mostCommonWord(p3, b3) << std::endl;
  // sol.mostCommonWord(p3, b3);

  return 0;
}
