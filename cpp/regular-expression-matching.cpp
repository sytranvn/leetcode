#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool match(char a, char b) { return a == b || b == '.'; }
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    bool lastMatched = false;
    char exp;
    while (i < s.length() && j < p.length()) {
      if (p[j] != '*') {
        exp = p[j];
        if (match(s[i], exp)) {
          i++;
        } else {
          return false;
        }
      } else {
        while (match(s[i], exp)) {
          i++;
        }
        j++;
      }
    }

    return true;
  }
};

int main() {
  Solution s = Solution();
  string s1, s2;
  while (true) {
    getline(cin, s1);
    if (s1.empty())
      break;
    getline(cin, s2);
    s.isMatch(s1, s2);
  }
}
