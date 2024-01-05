#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        int m = nums[0].size();

        for(auto q: queries) {
            vector<pair<string, int> > pq;

            for(int i = 0; i < n; i++) {
                pq.push_back({nums[i].substr(m - q[1]), i});
            }
            sort(pq.begin(), pq.end());
            res.push_back(pq[q[0]-1].second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> nums{"102","473","251","814"};
    vector<vector<int> >queries{{1,1},{2,3},{4,2},{1,2}};
    vector<int> result = s.smallestTrimmedNumbers(nums, queries);

    for(auto i : result) {
        cout<<i<<" ";
    }

    return 0;
}