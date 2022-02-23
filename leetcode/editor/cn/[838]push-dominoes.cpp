//n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。 
//
// 每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。 
//
// 如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。 
//
// 就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。 
//
// 给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中： 
//
// 
// dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧， 
// dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧， 
// dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。 
// 
//
// 返回表示最终状态的字符串。 
// 
//
// 示例 1： 
//
// 
//输入：dominoes = "RR.L"
//输出："RR.L"
//解释：第一张多米诺骨牌没有给第二张施加额外的力。
// 
//
// 示例 2： 
//
// 
//输入：dominoes = ".L.R...LR..L.."
//输出："LL.RR.LLRRLL.."
// 
//
// 
//
// 提示： 
//
// 
// n == dominoes.length 
// 1 <= n <= 10⁵ 
// dominoes[i] 为 'L'、'R' 或 '.' 
// 
// Related Topics 双指针 字符串 动态规划 👍 185 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string pushDominoes(string dominoes) {
        if (dominoes.length() <= 1) return dominoes;
        int l = 0;

        while (l < dominoes.length()) {
            int r = l + 1;
            while (r < dominoes.length() && dominoes[r] == '.') r++;
            // .. => return
            // .l => 遍历
            // .r => 下一个
            // l. => 下一个
            // ll => 遍历
            // lr => 下一个
            // r. => 遍历
            // rl => 遍历，判断
            // rr => 遍历

            if (r >= dominoes.length()) {
                if (dominoes[l] == 'R') {
                    for (int i = l; i < r; i++) dominoes[i] = 'R';
                }
                return dominoes;
            }

            char left = dominoes[l];
            char right = dominoes[r];
            if ((left == '.' && right == 'R')
                || (left == 'L' && right == '.')
                || (left == 'L' && right == 'R')) {
                // 变更下一个
            } else if ((right == 'L') && (left == '.' || left == 'L')) {
                for (int i = l; i < r; i++) {
                    dominoes[i] = 'L';
                }
            } else if ((left == 'R') && (right == '.' || right == 'R')) {
                for (int i = l; i < r; i++) {
                    dominoes[i] = 'R';
                }
            } else {
                for (int i = l, j = r; i < j; i++, j--) {
                    dominoes[i] = 'R';
                    dominoes[j] = 'L';
                }
            }

            l = r;

        }
        return dominoes;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->pushDominoes("RR.L") << endl;
    cout << s->pushDominoes(".L.R...LR..L..") << endl;
    cout << s->pushDominoes(".........") << endl;
    cout << s->pushDominoes(".......L") << endl;
}