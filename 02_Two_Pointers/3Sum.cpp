/**
// PIVOT: Extension of 2 sum,fix the 3rd number and try to make the sum of other
2 cancel out the 3rd number,if the fixed number is already greater than zero ,it
becomes impossible
// SYNTAX:if (nums[fixer] > 0) {
        return res;
      }
 * Problem: 3Sum
 * Platform: LeetCode / GfG
 * Pattern:Array ,Two Pointer
 * Complexity:
 *   - Time:  O(N^2)
 *   - Space: O(1)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> solve(vector<int> &nums) {
    // Implementation
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    // int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int fixer = i;
      if (nums[fixer] > 0) {
        return res;
      }
      int low = fixer + 1;
      int high = nums.size() - 1;
      if (i > 0 && nums[fixer] == nums[fixer - 1])
        continue;
      while (low < high) {

        int sum = nums[fixer] + nums[low] + nums[high];
        // cout << sum << endl;

        if (sum == 0) {
          res.push_back({nums[fixer], nums[low], nums[high]});

          while (low < high)
            if (nums[low + 1] == nums[low])
              low++;
            else {
              low++;
              break;
            }
          while (low < high)
            if (nums[high] == nums[high - 1])
              high--;
            else {
              high--;
              break;
            }
        } else if (sum > 0) {
          high--;
        } else {
          low++;
        }
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[0, 0, 0, 0]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<vector<int>> res = sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  dsa::printMatrix(res);
  // dsa::printLinkedList(head);

  return 0;
}
