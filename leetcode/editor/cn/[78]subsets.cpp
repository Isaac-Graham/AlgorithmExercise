//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
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

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        res.push_back(*new vector<int>());
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
                res.push_back(v);
                if (vec[k - 1] == n) {
                    if (!call_back(vec, n)) {
                        break;
                    }
                } else {
                    vec[k - 1]++;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s->subsets(nums);
    for (auto r : res) {
        for (auto c: r) {
            cout << c << " ";
        }
        cout << endl;
    }
}