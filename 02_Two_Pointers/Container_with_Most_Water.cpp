/**
// PIVOT: Use two pointers to traverse the possible containers from both
sides,each time you find a container update the maximum volume of the possible
container (use the distance between the walls of the container) ,use greedy
method (move the shorter wall inward) to optimise the traversal
// SYNTAX:int currWater = min(heights[front], heights[rear]) * (rear - front);
            maxWater = max(currWater, maxWater);
 * Problem: Container with Most Water
 * Platform: LeetCode / GfG
 * Pattern:Array,Two pointer,Greedy
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
  int solve(vector<int> &heights) {
    // Implementation
    int front = 0;
    int rear = heights.size() - 1;
    int maxWater = 0;
    while (front < rear) {
      int currWater = min(heights[front], heights[rear]) * (rear - front);
      maxWater = max(currWater, maxWater);
      if (heights[front] > heights[rear]) {
        rear--;
      } else {
        front++;
      }
    }
    return maxWater;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[1,7,2,5,4,7,3,6]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  cout << sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
