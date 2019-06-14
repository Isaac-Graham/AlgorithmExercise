#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length = 0;
    vector<int> array;
    for (int index = 0; index < 5; index++)
    {
        scanf("%d ", &array[index]);
    }
    for (int index = 0; index < sizeof(array) / sizeof(array[0]); index++)
    {
        printf("%d ", array[index]);
    }
}