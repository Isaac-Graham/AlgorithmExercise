//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: [1,2,2]
//输出:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//] 
// Related Topics 数组 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool call_back(vector<int> &vec, int n) {
        int pointer = vec.size() - 1;
        int limit = n;
        while (vec[pointer] == limit) {
            if (pointer == 0) {
                return false;
            }
            pointer--;
            limit--;
        }
        vec[pointer++]++;
        while (pointer < vec.size()) {
            vec[pointer] = vec[pointer - 1] + 1;
            pointer++;
        }
        return true;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        s.insert(*new vector<int>());
        int n = nums.size();
        for (int k = 1; k <= nums.size(); k++) {
            vector<int> vec(k);
            for (int i = 0; i < vec.size(); i++) {
                vec[i] = i + 1;
            }
            while (true) {
                vector<int> v(k);
                for (int i = 0; i < vec.size(); i++) {
                    v[i] = nums[vec[i] - 1];
                }
                s.insert(v);
                if (vec[k - 1] == n) {
                    if (!call_back(vec, n)) {
                        break;
                    }
                } else {
                    vec[k - 1]++;
                }
            }
        }
        vector<vector<int>> res;
        for (const auto &it: s) {
            res.push_back(it);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {1, 2, 2};
    vector<vector<int>> res = s->subsetsWithDup(vec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}