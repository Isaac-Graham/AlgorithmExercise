#include <bits/stdc++.h>

using namespace std;

long count_bit(const unsigned int val) {
    long num = 0;
    for (int i = 16; i >= 0; i--) {
        if (val & (1 << i))
            num++;
    }
    return num;
}

int main() {
    int testCase;
    cin >> testCase;
    for (int loop = 1; loop <= testCase; loop++) {
        int N, Q;
        cin >> N >> Q;
        vector<int> array(N);
        for (int index = 0; index < N; index++) {
            cin >> array[index];
        }
        cout << "Case #" << loop << ":";
        for (int count = 0; count < Q; count++) {
            int index, val;
            cin >> index >> val;
            array[index] = val;
            int bit_val = 0;
            int bit_index = 0;
            for (int i = 0; i < array.size(); i++) {
                bit_val = bit_val ^ array[i];
                long tmp = count_bit(bit_val);
                if (tmp % 2 == 0) {
                    bit_index = i + 1;
                }
            }
            cout << " " << bit_index;
        }
        cout << endl;
    }
}