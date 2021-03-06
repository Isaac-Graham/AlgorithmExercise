//
// Created by Isc on 2020/9/7.
//

/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len) {
        for (int i = len - 1; i >= 0; i--) {
            if(array[i] == i) {
                continue;
            }
            int val = array[i];
            while(array[val] != val && array[val] != i) {
                val = array[val];
            }
            swap_with_zero(array, len, array[i]);
            swap_with_zero(array, len, array[val]);
        }
    }
};

