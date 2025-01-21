#include <algorithm>
class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (sx == fx && sy == fy && t == 1)
      return false;
    int dx = abs(sx - fx), dy = abs(sy - fy);
    return t >= dx > dy ? dx : dy;
  }
};
