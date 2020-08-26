//
// Created by Isc on 2020/8/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100010;
int n;
int sa[maxn], x[maxn], c[maxn], y[maxn], height[maxn];
char s[maxn];
ll sum[maxn];

void SA() //O(nlogn)
{
    int m = 128;
    for (int i = 0; i <= m; i++)
        c[i] = 0;
    for (int i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i >= 1; i--)
        sa[c[x[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = 0; i <= m; i++)
            y[i] = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++p] = sa[i] - k;

        for (int i = 0; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[y[i]]]++;
        for (int i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i >= 1; i--)
            sa[c[x[y[i]]]--] = y[i];

        swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (int i = 2; i <= n; ++i)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p : ++p;
        if (p >= n)
            break;
        m = p;
    }
}

void get_height() {
    int k = 0;
    //for (int i=1; i<=n; ++i) rk[sa[i]]=i; x数组即为rank数组
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 1)
            continue; //第一名height为0
        if (k)
            --k; //h[i]>=h[i-1]-1;
        int j = sa[x[i] - 1];
        while (j + k <= n && i + k <= n && s[i + k] == s[j + k])
            ++k;
        height[x[i]] = k;
    }
}

int main() {
    while (~scanf("%s", s + 1)) {
        n = strlen(s + 1);
        SA();
        get_height();
        height[1] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = n - sa[i] + 1 - height[i] + sum[i - 1];
        }
        ll v, l = 0, r = 0;
        scanf("%lld", &v);
        v = (l ^ r ^ v) + 1;
        if (v > sum[n])
            l = r = 0;
        else {
            int pos = lower_bound(sum + 1, sum + 1 + n, v) - sum;
            v -= sum[pos - 1];
            l = sa[pos];
            r = sa[pos] + v + height[pos] - 1;
            int len = r - l + 1;
            pos++;
            while (height[pos] >= len) {
                if (l > sa[pos]) {
                    l = sa[pos];
                    r = l + len - 1;
                }
                pos++;
            }
        }

        for (int index = l; index < r; index++) {
            printf("%c", s[index]);
        }
    }
    return 0;
}