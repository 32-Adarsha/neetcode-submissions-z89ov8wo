#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> valueCount;          // val -> current freq
    unordered_map<int, stack<int>> freqStacks;   // freq -> stack of vals
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        int freq = ++valueCount[val];
        if (freq > maxFreq) maxFreq = freq;
        freqStacks[freq].push(val);
    }

    int pop() {
        stack<int>& top = freqStacks[maxFreq];
        int val = top.top();
        top.pop();
        if (top.empty()) {
            freqStacks.erase(maxFreq);
            maxFreq--;
        }
        valueCount[val]--;
        return val;
    }
};