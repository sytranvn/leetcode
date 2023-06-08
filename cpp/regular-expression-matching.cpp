#ifdef DEBUG
#include<bits/stdc++.h>
using namespace std;
#endif

class Solution {
public:
    bool match(char a, char b) {
        return a == b || b == '.';
    }
    bool isMatch(string s, string p) {
        int i = 0 , j = 0;
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

#ifdef DEBUG
int main() {
    Solution s = Solution();
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("ab", "a*") << endl;
    cout << s.isMatch("abb", ".*b") << endl;
}
#endif
