#include <vector>
#include <print>

class Solution {
public:
    static std::vector<int> decompressRLElist(std::vector<int>& nums) {
        std::vector<int> result;
        for (size_t i = 0; i < nums.size(); i+=2) {
            result.insert(result.end(), nums[i], nums[i+1]);
        }

        return result;
    }
};

int main() {
    std::vector<int> test_1 = {1,2,3,4};
    std::vector<int> result_1 = Solution::decompressRLElist(test_1); // Expected return is {2,4,4,4}
    for (const int& num : result_1) {
        std::printf("%d ", num);
    }

    return 0;
}
