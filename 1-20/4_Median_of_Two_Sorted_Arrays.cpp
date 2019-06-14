#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int nums1[maxn];
int nums2[maxn];

int length1, length2;

int main() {
    scanf("%d%d", &length1, &length2);
    for (int index = 0; index < length1; index++) {
        scanf("%d", &nums1[index]);
    }
    for (int index = 0; index < length2; index++) {
        scanf("%d", &nums2[index]);
    }
    sort(nums1, nums1 + length1);
    sort(nums2, nums2 + length2);
    for (int index = 0; index < length1; index++) {
        printf("%d\n", nums1[index]);
    }
}

int binary_search(int begin, int end) {
    int mid = (begin + end) / 2;
    int length = length1 + length2;
}