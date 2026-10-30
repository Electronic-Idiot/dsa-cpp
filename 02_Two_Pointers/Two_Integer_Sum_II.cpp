/**
// PIVOT: The Two Pointer idea:start comparing things from the two extremes in
one reducing both complexities,two pointers work on this variant of two sum
since the inpuut is sorted
// SYNTAX: int frwd = 0;
    int bkwd = numbers.size() - 1;
    while (frwd < bkwd)
 * Problem: Two Integer Sum II
 * Platform: LeetCode / GfG
 * Pattern:Arrays,Two Pointers
 * Complexity:
 *   - Time:  O(N)
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
  vector<int> solve(vector<int> &numbers, int target) {
    // Implementation
    int frwd = 0;
    int bkwd = numbers.size() - 1;
    while (frwd < bkwd) {
      //     while (numbers[bkwd] >= target && target > 0)
      //     bkwd--; //optimization to skip through numbers larger than the
      //     target but breaks when negatve number are involved
      int sum = numbers[frwd] + numbers[bkwd];
      if (sum == target) {
        return {frwd + 1, bkwd + 1};
      }

      if (sum > target)
        bkwd--;
      else
        frwd++;
    }
    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[-5,-3,0,2,4,6,8]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<int> res = sol.solve(nums, 5);

  // Example Printers:
  dsa::printVector(res);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
