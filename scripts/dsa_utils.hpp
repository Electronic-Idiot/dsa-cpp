#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// --- LeetCode Structs ---
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};
namespace dsa {

// --- 1D Array Parser ---
inline std::vector<int> parseVector(std::string s) {
  std::vector<int> res;
  for (char &c : s) {
    if (c == '[' || c == ']' || c == ',')
      c = ' ';
  }
  std::stringstream ss(s);
  int temp;
  while (ss >> temp) {
    res.push_back(temp);
  }
  return res;
}

inline void printVector(const std::vector<int> &vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
  }
  std::cout << "]\n";
}

// --- 2D Matrix Parser ---
inline std::vector<std::vector<int>> parseMatrix(const std::string &s) {
  std::vector<std::vector<int>> matrix;
  std::vector<int> row;
  std::string num = "";
  int depth = 0;

  for (char c : s) {
    if (c == '[')
      depth++;
    else if (c == ']') {
      if (!num.empty()) {
        row.push_back(std::stoi(num));
        num = "";
      }
      if (depth == 2) {
        matrix.push_back(row);
        row.clear();
      }
      depth--;
    } else if (c == ',') {
      if (!num.empty()) {
        row.push_back(std::stoi(num));
        num = "";
      }
    } else if (c != ' ' && c != '\n') {
      num += c;
    }
  }
  return matrix;
}

inline void printMatrix(const std::vector<std::vector<int>> &mat) {
  std::cout << "[\n";
  for (const auto &row : mat) {
    std::cout << "  ";
    printVector(row);
  }
  std::cout << "]\n";
}

// --- Linked List Parser ---
inline ListNode *parseLinkedList(std::string s) {
  std::vector<int> vals = parseVector(s);
  if (vals.empty())
    return nullptr;
  ListNode *dummy = new ListNode(0);
  ListNode *curr = dummy;
  for (int v : vals) {
    curr->next = new ListNode(v);
    curr = curr->next;
  }
  return dummy->next;
}

inline void printLinkedList(ListNode *head) {
  std::cout << "[";
  while (head) {
    std::cout << head->val << (head->next ? ", " : "");
    head = head->next;
  }
  std::cout << "]\n";
}

} // namespace dsa
