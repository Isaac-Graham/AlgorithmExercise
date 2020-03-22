#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int length1 = nums1.size(), length2 = nums2.size(), half = (length1 + length2 + 1) / 2;
        if (length1 > length2) { // to ensure m<=n
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = length1;
            length1 = length2;
            length2 = tmp;
        }

        int begin = 0, end = length1;
        while (begin <= end) {
            int median1 = (begin + end) / 2;// 计算出长度比较短的那个数组的中点
            int median2 = half - median1; // 这里用减法的原因是为了保证两个点的左边之和要=half
            if (median1 < end && nums2[median2 - 1] > nums1[median1]) {
                begin = median1 + 1; // median1小了
            } else if (median1 > begin && nums1[median1 - 1] > nums2[median2]) {
                end = median1 - 1; // median1大了
            } else {

                // 获取左边部分的最大值，这里做了边界处理，考虑了median等于0的情况
                int max_left = 0;
                if (median1 == 0) { max_left = nums2[median2 - 1]; }
                else if (median2 == 0) { max_left = nums1[median1 - 1]; }
                else { max_left = max(nums1[median1 - 1], nums2[median2 - 1]); }
                if ((length1 + length2) % 2 == 1) { return max_left; }

                // 获取右边部分的最小值，这里做了边界处理，考虑了median等于最大值的情况
                int min_right = 0;
                if (median1 == length1) { min_right = nums2[median2]; }
                else if (median2 == length2) { min_right = nums1[median1]; }
                else { min_right = min(nums2[median2], nums1[median1]); }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;

    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}


int main() {
    // 获取输入，输入的形式为
    //[1,2]
    //[3,4]
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);


        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}