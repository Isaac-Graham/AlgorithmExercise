//
// Created by Isaac Graham on 2019/8/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> s;
        int water = 0;
        for (int index = 0; index < height.size(); index++) {
            while (!s.empty() && height[index] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int dis = index - s.top() - 1;
                // 这里的top代表的是中间凹进去的那一块，s.top()和index分别代表着两边的凸起
                int diff_hei = min(height[index], height[s.top()]) - height[top];
                water += dis * diff_hei;
            }
            s.push(index);
        }
        return water;
    }
};

int main() {
    vector<int> v = {4, 2, 0, 3, 2, 5};
    Solution *s = new Solution();
    cout << s->trap(v) << endl;
}