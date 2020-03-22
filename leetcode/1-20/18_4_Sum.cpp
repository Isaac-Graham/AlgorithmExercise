//
// Created by Isaac Graham on 7/30/2019.
//

#include <bits/stdc++.h>

using namespace std;

struct Sum {
    int left_index;
    int right_index;
    int sum;

    Sum(int l, int r, int s) : left_index(l), right_index(r), sum(s) {}

    // 运算符重载，用于sort函数
    bool operator<(const Sum s) const {
        return this->sum < s.sum;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> v;
        if (nums.size() < 4)
            return v;
        sort(nums.begin(), nums.end());
        vector<Sum> two_sum;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                two_sum.push_back(*new Sum(i, j, nums[i] + nums[j]));
            }
        }

        sort(two_sum.begin(), two_sum.end());
        set<vector<int>> set1;
        for (int index = 0; index < two_sum.size(); index++) {
            int left_num = target - two_sum[index].sum;
            int begin = index + 1, end = (int) two_sum.size() - 1;
            // 找到第一个sum为left_sum的对象
            while (begin < end) {
                int mid = (begin + end) / 2;
                if (two_sum[mid].sum < left_num)
                    begin = mid + 1;
                else if (two_sum[mid].sum > left_num)
                    end = mid - 1;
                else {
                    if (two_sum[mid].sum == two_sum[mid - 1].sum)
                        end = mid - 1;
                    else {
                        begin = mid;
                        break;
                    }
                }
            }
            // 从begin开始遍历
            while (two_sum[begin].sum == left_num) {
                if (two_sum[begin].left_index != two_sum[index].left_index &&
                    two_sum[begin].right_index != two_sum[index].right_index &&
                    two_sum[begin].left_index != two_sum[index].right_index &&
                    two_sum[begin].right_index != two_sum[index].left_index) {
                    vector<int> v = {nums[two_sum[index].left_index], nums[two_sum[index].right_index],
                                     nums[two_sum[begin].left_index], nums[two_sum[begin].right_index]};
                    sort(v.begin(), v.end());
                    set1.insert(v);
                }
                begin++;
            }
        }

        for (auto p = set1.begin(); p != set1.end(); p++) {
            v.push_back(*p);
        }
        return v;


//        for (int index = 0; index < two_sum.size(); index++)
//            cout << two_sum[index].sum << " ";
//        cout << endl;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {0, 0};
    vector<vector<int>> v = s->fourSum(nums, 10);
}