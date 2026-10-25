/**
// PIVOT: Encode by adding markers ,Decode based on the boundries ,
// strings can be appended unlike java
// SYNTAX:  for (auto word : strs) {
//    enc_data += word;
//    enc_data += '\1';
 * Problem: Encode and Decode Strings
 * Platform: LeetCode / GfG
 * Pattern: Array, String , Design
 * Complexity:
 *   - Time:  O()
 *   - Space: O()
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string enc_data;
    for (auto word : strs) {
      enc_data += word;
      enc_data += '\1';
    }
    return enc_data;
  }

  vector<string> decode(string s) {
    vector<string> res;
    string word;
    for (auto letter : s) {

      if (letter != '\1') {
        word += letter;
      } else {
        res.push_back(word);
        word.clear();
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
  //   vector<int> nums = dsa::parseVector("[2,7,11,15]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<string> input = {"Hello", "World"};
  vector<string> output = sol.decode(sol.encode(input));

  for (string res : output) {
    cout << res << '\n';
  }

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
