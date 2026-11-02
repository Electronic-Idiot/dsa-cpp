/**
// PIVOT:Same principle as 'Container with Most water' problem but instead of
one context (the largest one) ,here we have to keep track of all the possible
water containers,which is difficult with just two pointer,store all the possible
contexts you can find in your travels (in both directions) in essence use
dynamic programming;refer prefix sum for more info
// SYNTAX:preGreater[i] = max(preGreater[i - 1], height[i]);
//        postGreater[startBehind - i] =
            max(postGreater[startBehind - i + 1], height[startBehind - i]);
        water += min(preGreater[i], postGreater[i]) - height[i];
 * Problem: Trapping Rain Water
 * Platform: LeetCode / GfG
 * Pattern:Arrays, Two Pointers, Dynamic Programming
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
  int solve(vector<int> &height) {
    // Implementation
    vector<int> preGreater(height.size(), 0);
    vector<int> postGreater(height.size(), 0);
    // int front = 0;
    int startBehind = height.size() - 1;
    // int rear = startBehind;
    for (int i = 0; i < startBehind; i++) {
      if (i == 0) {
        preGreater[i] = height[i];
        postGreater[startBehind] = height[startBehind];
      } else {
        preGreater[i] = max(preGreater[i - 1], height[i]);
        postGreater[startBehind - i] =
            max(postGreater[startBehind - i + 1], height[startBehind - i]);
      }
    }
    // for (auto num : preGreater) {
    //   cout << num << endl;
    // }
    // int i = 0;
    // for (auto num : postGreater) {
    //   cout << i++ << '\t' << num << endl;
    // }
    int water = 0;
    for (int i = 1; i < height.size() - 1; i++) {
      water += min(preGreater[i], postGreater[i]) - height[i];
      //   cout << "water" << water << endl;
    }
    return water;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[4,2,0,3,2,5]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  cout << sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
