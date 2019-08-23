//
// Created by Isaac Graham on 2019/8/23.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        do { s.insert(nums); } while (next_permutation(nums.begin(), nums.end()));
        vector<vector<int>> v;
        for (auto p = s.begin(); p != s.end(); p++) {
            v.push_back(*p);
        }
        return v;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> v = s->permuteUnique(nums);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}