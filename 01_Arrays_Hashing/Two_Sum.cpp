// PIVOT: Hash map stores {value : index}. Check if (target - current) exists.
// SYNTAX: int comp = target - nums[i]; if (map.find(comp) != map.end()) return
// {map[comp], i};

/**
 * Problem: Two SUm
 * Platform: LeetCode / GfG
 * Pattern:Array,Searching,Unordered maps,hashing
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(N)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &nums, int target) {
    // Implementation
    int comp = 0;
    unordered_map<int, int> copy;
    for (int i = 0; i < nums.size(); i++) {
      comp = target - nums[i];
      auto it = copy.find(comp);
      if (it != copy.end())
        return {copy[comp], i};
      else
        copy.insert({nums[i], i});
    }
    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[2,7,11,15]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<int> res = sol.solve(nums, 9);

  // Example Printers:
  dsa::printVector(res);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
