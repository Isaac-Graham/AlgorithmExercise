//
// Created by Isc on 2020/7/23.
//

#include<bits/stdc++.h>

using namespace std;

struct Item {
public:
    int value;
    int count;

    Item(int value, int count) : value(value), count(count) {}
};

int main() {
    int arraySize = 0;
    int minTime = 0;
    cin >> arraySize >> minTime;
    vector<int> inputArray;
    for (int i = 0; i < arraySize; i++) {
        int value = 0;
        cin >> value;
        inputArray.push_back(value);
    }
    vector<int> numberArray(4000001, 0);
    int leftPointer = 0;
    int rightPointer = 0;
    int lastSatisfied = -1;
    int res = 0;
    while (rightPointer < inputArray.size()) {
        int newElement = inputArray[rightPointer];
        numberArray[newElement]++;
        if (numberArray[newElement] >= minTime) {
            // 说明新加入的符合条件，移动左指针
            while (inputArray[leftPointer] != newElement ||
                   (inputArray[leftPointer] == newElement && numberArray[newElement] > minTime)) {
                numberArray[inputArray[leftPointer]]--;
                leftPointer++;
            }
            res += leftPointer + 1;
            cout << leftPointer << " " << rightPointer << endl;
            lastSatisfied = newElement;
        } else {
            if (lastSatisfied != -1) {
                res += leftPointer + 1;
                cout << leftPointer << " " << rightPointer << endl;
            }
        }
        rightPointer++;
    }
    cout << res << endl;
}