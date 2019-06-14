#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // WHY??
    int lengthOfLongestSubstring(string s)
    {
        // 256 is for there are many different charactor in the string such as '%'
        vector<int> dic(256, -1);
        int start = -1, length = 0;
        for (int index = 0; index < s.length(); index++)
        {
            if (dic[s[index] - 97] > start)
                start = dic[s[index]];
            dic[s[index]] = index;
            length = length > (index - start) ? length : (index - start);
        }
        return length;
    }
};
int main()
{
    string str = "sss";
    Solution *s = new Solution();
    printf("%d\n", s->lengthOfLongestSubstring(str));
}