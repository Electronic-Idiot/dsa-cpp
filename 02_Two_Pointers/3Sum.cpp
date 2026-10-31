/**
 * Problem: 3Sum
 * Platform: LeetCode / GfG
 * Pattern:
 * Complexity:
 *   - Time:  O()
 *   - Space: O()
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

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int fixer = i;
      int low = fixer + 1;
      int high = nums.size() - 1;
      while (low < high) {
        if (nums[fixer] > 0) {
          return res;
        } else {
          sum = nums[fixer] + nums[low] + nums[high];
          cout << sum << endl;
        }
        if (sum == 0) {
          res.push_back({nums[fixer], nums[low], nums[high]});
          //   while (nums[low] == nums[low + 1])
          //     low++;
          //   while (nums[high] == nums[high - 1])
          //     high--;
          break;
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
  vector<int> nums = dsa::parseVector("[-1,0,1,2,-1,-4]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<vector<int>> res = sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  dsa::printMatrix(res);
  // dsa::printLinkedList(head);

  return 0;
}
