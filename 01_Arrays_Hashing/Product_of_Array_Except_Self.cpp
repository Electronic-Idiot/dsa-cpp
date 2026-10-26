/**
// PIVOT: Store the previous product and reuse it to reduce calculation overhead
//prefix sum (here product) is reusing the predecessor or successor calculated
// value to calulate the same for current ,instead of starting from scratch
everytime
// SYNTAX: prefixSum[i] = nums[i - 1] * prefixSum[i - 1];
 * Problem: Product of Array Except Self
 * Platform: LeetCode / GfG
 * Pattern:Array ,Prefix Sum
 * Complexity:
 *   - Time:  O(n)
 *   - Space: O(n)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &nums) {
    // Implementation
    vector<int> prefixSum(nums.size(), 1);
    vector<int> suffixSum(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
      prefixSum[i] = nums[i - 1] * prefixSum[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
      suffixSum[i] = nums[i + 1] * suffixSum[i + 1];
    }
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      res[i] = prefixSum[i] * suffixSum[i];
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[1,2,4,6]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<int> res = sol.solve(nums);

  // Example Printers:
  dsa::printVector(res);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
