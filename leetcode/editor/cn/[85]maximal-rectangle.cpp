//给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
//
// 示例: 
//
// 输入:
//[
//  ["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]
//]
//输出: 6 
// Related Topics 栈 数组 哈希表 动态规划


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
    int maximalRectangle(vector<vector<char>> &matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int MAX = 0;
        vector<vector<int>> vec;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> heights(matrix[i].size() + 1, 0);
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    heights[j + 1] = heights[j] + 1;
                } else {
                    heights[j + 1] = 0;
                }
            }
            vec.push_back(heights);
        }

        for (int j = 0; j < vec[0].size(); j++) {
            vector<int> heights;
            for (int i = 0; i < vec.size(); i++) {
                heights.push_back(vec[i][j]);
            }
            MAX = max(MAX, largestRectangleArea(heights));
        }
        return MAX;
    }

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
        }
        return MAX;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<vector<char>>> matrices = {
            {
            },
            {
                    {'1', '0', '1', '0', '0'},
                    {'1', '0', '1', '1', '1'},
                    {'1', '1', '1', '1', '1'},
                    {'1', '0', '0', '1', '0'}
            },
            {
                    {'1'}
            },
            {
                    {'0'}
            }

    };
    for (int i = 0; i < matrices.size(); i++) {
        vector<vector<char>> matrix = matrices[i];
        cout << s->maximalRectangle(matrix) << endl;
    }
    cout << endl;
}