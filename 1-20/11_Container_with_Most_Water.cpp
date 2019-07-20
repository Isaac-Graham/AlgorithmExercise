//
// Created by Isaac Graham on 7/20/2019.
/**
 * 双指针法
 * 通过移动较短的那一根指针
 * 这样子虽然有可能会使得面积变小，但是也是唯一的可能让面积变大的方法
 * 所以这样子一定可以获得最大的面积
 */
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = -1;
        int lp = 0;
        int rp = (int) height.size() - 1;
        while (lp <= rp) {
            if (min(height[lp], height[rp]) * (rp - lp) > max_area) {
                max_area = min(height[lp], height[rp]) * (rp - lp);
            }
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return max_area;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s->maxArea(height) << endl;
}