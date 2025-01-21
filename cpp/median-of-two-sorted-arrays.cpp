#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int size = m + n;
    int med = (m + n) / 2;
    vector<int> a(nums1.begin(), nums1.end());
    vector<int> b(nums2.begin(), nums2.end());

    while (a.size() && b.size()) {
      acout(a);
      acout(b);
      cout << ">>>>\n";
      if (a.size() < b.size())
        swap(a, b);
      auto it = upper_bound(a.begin(), a.end(), b[0]);
      int k = it - a.begin();
      if (k >= med)
        break;
      med = med - k;
      a = vector<int>(it, a.end());
    }
    acout(a);
    acout(b);
    cout << ">>>>\n";
    cout << med;
    return 0;
  }

  void acout(vector<int> &a) {
    for (auto a2 : a)
      cout << a2 << ", ";
    cout << endl;
  }
};

int main() { return 0; }
