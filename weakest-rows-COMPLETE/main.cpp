#include <vector>
#include <queue>

class Solution {
public:
    static std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        // The min heap will hold the indices of the weakest rows (rows with least num of soldiers or '1' values)
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> min_heap;
        for (size_t row = 0; row < mat.size(); row++) {
            int count = 0;
            for (size_t i = 0; i < mat[row].size(); i++) {
                if (mat[row][i] == 1) {
                    count++;
                }
            }
            min_heap.push({count, row});
        }

        std::vector<int> result = {};
        size_t i = 0;
        while (i < k) {
            std::pair<int,int> data = min_heap.top();
            result.push_back(data.second);
            min_heap.pop();
            i++;
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<int>> mat1 =
    {{1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1, }};
    int k1 = 3;
    std::vector<int> result1 = Solution::kWeakestRows(mat1, k1);
    for (const int& num : result1) {
        std::printf("%d ", num);
    }
    std::printf("\n");

    return 0;
}
