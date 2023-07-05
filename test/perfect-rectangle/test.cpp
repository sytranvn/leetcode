#include "../../cpp/perfect-rectangle.cpp"
#include <fstream>
#include <vector>

int main() {
  Solution s = Solution();
  vector<vector<int>> rectangles;
  // s.isRectangleCover(rectangles);
  ifstream input_stream("test.inp");
  ifstream output_stream("test.inp");
  int v, n;
  if (!input_stream)
    cerr << "Cannot open file";

  while (input_stream >> n) {
    cout << n;
    rectangles.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; i < 4; j++) {
        input_stream >> v;
        rectangles[i].push_back(v);
      }
    }
    for (auto r : rectangles) {
      for (auto x : r) {
        cout << x << ", ";
      }
      cout << endl;
    }
  }
}
