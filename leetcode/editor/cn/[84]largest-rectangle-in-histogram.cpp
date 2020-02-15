//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 
//
// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。 
//
// 
//
// 
//
// 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。 
//
// 
//
// 示例: 
//
// 输入: [2,1,5,6,2,3]
//输出: 10 
// Related Topics 栈 数组


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Item {
    int index;
    int val;

    Item(int index, int val) {
        this->index = index;
        this->val = val;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<Item *> s;
        s.push(new Item(-1, -1));
        int MAX = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] < s.top()->val) {
                while (s.top()->val > heights[i]) {
                    Item *top = s.top();
                    s.pop();

                    MAX = max(MAX, top->val * (i - s.top()->index - 1));
                }
            }
            s.push(new Item(i, heights[i]));
        }
        Item *last = nullptr;
        while (!s.empty()) {
            if (last == nullptr) {
                last = s.top();
                s.pop();
                MAX = max(MAX, last->val);
                continue;
            }
            Item *top = s.top();
            MAX = max(MAX, ((int) heights.size() - 1 - top->index) * last->val);
            last = top;
            s.pop();

//            MAX = max(MAX, s.top()->val * ((int) heights.size() - s.top()->index));
//            s.pop();
        }
        return MAX;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<int>> height = {
            {5, 4, 1, 2},
            {2, 1, 2},
            {1, 2, 3, 4, 5, 6, 7},
            {2, 1, 5, 6, 2, 3},
            {},
            {1},
            {10, 1}
    };
    for (auto vec : height) {
        cout << s->largestRectangleArea(vec) << endl;
    }
}