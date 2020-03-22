#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // The following function use map to solve. 
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> arr(2, 0);
        map<int, int> m;
        for (int index = 0; index < nums.size(); index++)
        {
            int current = nums[index];
            int partial = target - current;
            if (m.find(partial) != m.end())
            {
                arr[0] = min(index, m.at(partial));
                arr[1] = max(index, m.at(partial));
                break;
            }
            m.insert(make_pair(nums[index], index));
        }
        return arr;
    }
};

int main()
{
    int length;
    scanf("%d", &length);
    vector<int> nums(length, 0);
    for (int index = 0; index < length; index++)
    {
        scanf("%d", &nums[index]);
    }
    Solution *s = new Solution();
    vector<int> arr = (*s).twoSum(nums, 6);
    for (int index = 0; index < 2; index++)
    {
        printf("%d ", arr[index]);
    }
}