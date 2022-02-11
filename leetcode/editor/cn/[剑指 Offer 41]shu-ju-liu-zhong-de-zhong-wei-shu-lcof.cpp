//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数
//值排序之后中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例 1： 
//
// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
//
// 限制： 
//
// 
// 最多会对 addNum、findMedian 进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-
//stream/ 
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 240 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
public:
    priority_queue<int> large; // 大顶堆， 存小的一半
    priority_queue<int, vector<int>, greater<int>> small; // 小顶堆，存大的一半
    // 当偶数时，large.size == small.size.
    // 当奇数时，large.size == small.suze() + 1

    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (large.empty()) {
            large.push(num);
            return;
        }
        if (num >= large.top()) {
            // 比小的一半中最大的要大于等于，需要放到大的一半中
            small.push(num);
        } else {
            // 比小的一半中最大的要小，说明当前应该扔到小的一半中
            large.push(num);
        }
        adjust();
    }

    void adjust() {
        if (large.size() == small.size() || large.size() == small.size() + 1) return;
        if (large.size() > small.size()) {
            // >= 2
            small.push(large.top());
            large.pop();
        } else {
            large.push(small.top());
            small.pop();
        }
        adjust();
    }


    double findMedian() {
        int curSize = large.size() + small.size();
        if (curSize == 0) return 0;
        else if (curSize == 1) return large.top();

        if (curSize % 2 == 0) {
            return (large.top() + small.top()) / 2.0;
        } else {
            return large.top();
        }
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
}