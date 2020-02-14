//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 示例 1: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 13
//输出: false 
// Related Topics 数组 二分查找


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRow(vector<vector<int>> &matrix, int begin, int end, int target) {
        while (begin < end) {
            if (end - begin == 1 || begin == end) {
                if (matrix[end][0] <= target) {
                    return end;
                } else {
                    return begin;
                }
            }
            int mid = (begin + end) / 2;
            if (matrix[mid][0] == target) {
                return mid;
            } else if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                begin = mid;
            }
        }
        return begin;
    }

    bool findCol(vector<int> &vec, int begin, int end, int target) {
        while (begin < end) {
            if (end == begin) {
                return vec[begin] == target;
            } else if (end - begin == 1) {
                return vec[begin] == target || vec[end] == target;
            }
            int mid = (end + begin) / 2;
            if (vec[mid] == target) {
                return true;
            } else if (vec[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return vec[begin] == target;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        } else if (matrix[0].empty()) {
            return false;
        } else if (matrix[0][0] > target) {
            return false;
        }
        int row = findRow(matrix, 0, matrix.size() - 1, target);
        cout << row << endl;
        return findCol(matrix[row], 0, matrix[row].size() - 1, target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<int>> matrix = {
            {1},
            {3}
    };
    cout << s->searchMatrix(matrix, 3) << endl;
}