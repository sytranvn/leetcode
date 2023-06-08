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
                    j++;
                } else {
                    return false;
                }
            } else {
                while (match(s[i], exp) && i < s.length()) {
                    i++;
                }
                j++;
            }
        }

        return i >= s.length() && j >= p.length();
    }
};

#ifdef DEBUG
int main() {
    Solution s = Solution();
    while (true) {
        string s1, s2;
        getline(cin, s1);
        if (s1.empty()) break;
        getline(cin, s2);
        cout << s.isMatch(s1, s2) << endl;
    }
}
#endif
