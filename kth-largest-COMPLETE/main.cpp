#include <vector>
#include <queue>
#include <print>

class KthLargest {
public:
    int k;
    std::vector<int> nums;
    std::priority_queue<int, std::vector<int>, std::greater<int>> scores;

    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        this->nums = std::move(nums); // Move ownership to the KthLargest obj

        for (const int& num : this->nums) {
            this->scores.push(num);
        }
    }
    
    int add(int val) {
        scores.push(val);
        while (scores.size() > k) {
            scores.pop();
        }

        return scores.top();
    }
};

int main() {
    int k1 = 3;
    std::vector<int> nums1 = {4, 5, 8, 2};
    KthLargest kth_largest = KthLargest(k1, nums1);

    std::println("{}", kth_largest.add(3)); // return 4
    std::println("{}", kth_largest.add(5)); // return 5
    std::println("{}", kth_largest.add(10)); // return 5
    std::println("{}", kth_largest.add(9)); // return 8
    std::println("{}", kth_largest.add(4)); // return 8

    return 0;
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
