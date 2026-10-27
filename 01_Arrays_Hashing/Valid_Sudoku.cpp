/**
// PIVOT: store the 3 required conditions in validity for all 3 different 2d
arrays(one of the axes contain the numbers and other whether they already
satisfy the condition)
//thus when collision happens->two update for the same value->condition for
failure
// SYNTAX:if (rowCheck[i][curr] || colCheck[j][curr] ||
            subMatrix[subMatrixCalc][curr]) {return false;}
 * Problem: Valid_Sudoku
 * Platform: LeetCode / GfG
 * Pattern:
 * Complexity:
 *   - Time:  O(N^2)
 *   - Space: O(N^2)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool solve(vector<vector<char>> &board) {
    // Implementation
    bool rowCheck[9][10] = {false};
    bool colCheck[9][10]{false}; // column 0 is unused ,1-9 is useful to
    // us,avoid extra manipluation this way,
    // array index and element value matches this way
    bool subMatrix[9][10] = {false};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;

        int curr = board[i][j] - '0';
        int subMatrixCalc = (i / 3) * 3 + (j / 3);

        if (rowCheck[i][curr] || colCheck[j][curr] ||
            subMatrix[subMatrixCalc][curr])
          return false;

        rowCheck[i][curr] = true;
        colCheck[j][curr] = true;
        subMatrix[subMatrixCalc][curr] = true;
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  // vector<int> nums = dsa::parseVector("[2,7,11,15]");
  //   vector<vector<char>> mat = dsa::parseMatrix();
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  //   sol.solve();// test case in neet code needs to sanitized to be used here

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
