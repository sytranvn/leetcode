#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (visited[nums[i]]) 
            {
                return true;
            }
            if (visited.size() == k) visited.erase(nums[i-k+1]);
            visited[nums[i]] = true;
        }
        for (auto &v:visited) {
            if (v.second)
            printf("%d ", v.first);
        }
        return false;
    }
};


int main() {
    Solution sol = Solution();
    vector<int>v {1,2,3,1};
    sol.containsNearbyDuplicate(v, 3);
    return 0;
}
