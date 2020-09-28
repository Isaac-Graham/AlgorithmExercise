//
// Created by Isaac_Chen on 2020/9/24.
//


/**
 *
 * 1.unsigned int 数据范围为2 ** 32 - 1，可以开辟一个512MB的内存空间，使用bitmap的算法实现。
 * 512MB计算方式： 2 ** 32 / 1024 / 1024 / 1024 / 8 -> 0.5GB -> 512 MB
 * 准备工作：依次遍历数组，获得unsigned int，将对应的bit位置1
 * 判断：访问第k位的bit，判断是否为1.如果是: yes; else: no
 *
 *
 * 2.如果数组有序->二分找答案。首先可以确定的是数组一定是奇数个元素，假设数组长度为2n+1， 那么第一次二分之后获得到的数组的长度为n， 且n一定是个偶数
 * 比较arr[n]与arr[n + 1]的值，如果arr[n] == arr[n+1]，那么说明在arr[0], arr[1]....arr[n - 1]这些数字一定都是成对出现的数字，即单个数字肯定出现在后半部分
 * 持续上述步骤即可
 *
 * 如果数组无序->异或。 对于任何一个数字x, x^x == 0. 因为所有相同的数字必然出现偶数次，那么将一个数组的所有元素依次异或剩下来的一定是唯一出现的那个数字。
 * 且异或位运算在CPU层面会比四则运算快。
 */
#include <bits/stdc++.h>

using namespace std;

void twoSum(int &index1, int &index2, const vector<int> &vec, int target) {
    if (vec.size() < 2) {
        cerr << "Error occurs: invalid input vector" << endl;
        return;
    }
    int beginIndex = 0;
    int endIndex = vec.size() - 1;
    while (beginIndex < endIndex) {
        int sum = vec[beginIndex] + vec[endIndex];
        if (sum == target) {
            index1 = beginIndex + 1;
            index2 = endIndex + 1;
            return;
        } else if (sum < target) {
            beginIndex++;
        } else {
            endIndex--;
        }
    }
}

int main() {


    int index1 = -1;
    int index2 = -1;
    vector<int> vec = {5, 6};
    twoSum(index1, index2, vec, 11);
    cout << index1 << " " << index2 << endl;
}
