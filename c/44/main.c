<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool checkMatch(int ** match, char *s, int slen, char *p, int plen, int i, int j);

bool isMatch(char* s, char* p) {
    // match[i][j] indicates if string s at position i can match pattern p up to position j,
    // if match and p[j] is alphabet or '?', match = 1
    // if match and p[j] is '*', match = amount of consumed character in s
    int **match;
    int slen = strlen(s);
    int plen = strlen(p);
    match = calloc(0, slen * plen * sizeof(match));
    // match[i][j] = match[i-1][j-1] & (s[i]==p[j] | p[j] == '?' | p[j] == '*')
    // if not match, how can we backtrack
    checkMatch(match, s, slen, p, plen, 0, 0);
    return true;
}

bool checkMatch(int ** match, char *s, int slen, char *p, int plen, int i, int j) {
    return true;
};
int main(void) {
assert(!isMatch("aa","a"));
assert(isMatch("aa","*"));
assert(!isMatch("cb","?a"));
assert(isMatch("caaaaaab","*ab"));
assert(!isMatch("acdcb","a*c?b"));
assert(isMatch("",""));
    return 0;
=======
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool checkMatch(int **match, char *s, int slen, char *p, int plen, int i,
                int j);

bool isMatch(char *s, char *p) {
  // match[i][j] indicates if string s at position i can match pattern p up to
  // position j, if match and p[j] is alphabet or '?', match = 1 if match and
  // p[j] is '*', match = amount of consumed character in s
  int **match;
  int slen = strlen(s);
  int plen = strlen(p);
  match = calloc(0, slen * plen * sizeof(match));
  // match[i][j] = match[i-1][j-1] & (s[i]==p[j] | p[j] == '?' | p[j] == '*')
  // if not match, how can we backtrack
  checkMatch(match, s, slen, p, plen, 0, 0);
  return true;
}

bool checkMatch(int **match, char *s, int slen, char *p, int plen, int i,
                int j) {
  return true;
};
int main(void) {
  assert(!isMatch("aa", "a"));
  assert(isMatch("aa", "*"));
  assert(!isMatch("cb", "?a"));
  assert(isMatch("caaaaaab", "*ab"));
  assert(!isMatch("acdcb", "a*c?b"));
  assert(isMatch("", ""));
  return 0;
>>>>>>> 92a073f (refactor)
}
