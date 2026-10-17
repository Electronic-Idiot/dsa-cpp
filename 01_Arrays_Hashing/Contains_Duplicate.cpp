/**
 * Problem: Contains Duplicate
 * Platform: LeetCode / GfG
 * Pattern: Duplicate detection,compare,hashing
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(N)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasDuplicate(vector<int> &nums) {
    unordered_set<int> checker;
    for (auto num : nums) {
      if (checker.find(num) == checker.end())
        checker.insert(num);
      else
        return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[2,7,11,15,15]");
  //   vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  if (sol.hasDuplicate(nums) == true)
    cout << "true";
  else
    cout << "false";

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
