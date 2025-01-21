#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static bool bottomleft(vector<int> &a, vector<int> &b) {
    // x[0,1]
    if (a[1] < b[1])
      return true;
    return a[1] == b[1] && a[0] < b[0];
  }
  static bool bottomright(vector<int> &a, vector<int> &b) {
    // x[2,1]
    if (a[1] < b[1])
      return true;
    return a[1] == b[1] && a[2] > b[2];
  }

  static bool topright(vector<int> &a, vector<int> &b) {
    // x[2,3]
    if (a[3] > b[3])
      return true;
    return a[3] == b[3] && a[2] > b[2];
  }
  static bool topleft(vector<int> &a, vector<int> &b) {
    // x[0,3]
    if (a[3] > b[3])
      return true;
    return a[3] == b[3] && a[2] < b[2];
  }

  bool isRectangleCover(vector<vector<int>> &rectangles) {
    sort(rectangles.begin(), rectangles.end(), bottomleft);
    vector<int> bl = rectangles[0];
    printf("%d, %d, %d, %d\n", bl[0], bl[1], bl[2], bl[3]);
    sort(rectangles.begin(), rectangles.end(), topright);
    vector<int> tr = rectangles[0];
    printf("%d, %d, %d, %d\n", tr[0], tr[1], tr[2], tr[3]);

    sort(rectangles.begin(), rectangles.end(), bottomright);
    vector<int> br = rectangles[0];
    printf("%d, %d, %d, %d\n", br[0], br[1], br[2], br[3]);

    sort(rectangles.begin(), rectangles.end(), topleft);
    vector<int> tl = rectangles[0];
    printf("%d, %d, %d, %d\n", tl[0], tl[1], tl[2], tl[3]);

    int area = abs(tr[2] - bl[0]) * abs(tr[3] - bl[1]);
    int area2 = abs(br[2] - tl[0]) * abs(br[1] - tl[3]);
    //         w                  * h
    int total_area = 0;
    for (vector<int> r : rectangles) {
      total_area += (r[2] - r[0]) * (r[3] - r[1]);
    }
    printf("%d %d %d", area, area2, total_area);
    return area == area2 && area == total_area;
  }
};
int main() { return 0; }
