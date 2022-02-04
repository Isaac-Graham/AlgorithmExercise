//给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。 
//
// 如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 
//4 的正方形。 
//
// 设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。 
//
// 请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。 
//
// 
//
// 示例 1： 
//
// 
//输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
//输出：3
//解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
//最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
// 
//
// 示例 2： 
//
// 
//输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= rectangles.length <= 1000 
// rectangles[i].length == 2 
// 1 <= li, wi <= 10⁹ 
// li != wi 
// 
// Related Topics 数组 👍 43 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        if (rectangles.size() <= 0) {
            return 0;
        }
        int maxLen = INT_MIN;
        int cnt = 0;
        for (auto vec: rectangles) {
            int minLen = min<int>(vec[0], vec[1]);
            if (minLen > maxLen) {
                maxLen = minLen;
                cnt = 1;
            } else if (minLen < maxLen) {
                continue;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
}