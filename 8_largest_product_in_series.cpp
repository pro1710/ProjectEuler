#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>
#include <functional>

using namespace std;

typedef int ans_t;

ans_t sol(const string& str, const int& K) {
    vector<int> num = {};
    for_each(str.begin(), str.end(), [&num](char c){num.push_back((int)c - int('0'));});
    
    ans_t res = 1, max = 0;
    
    int len = 0;
    for (size_t i = 0; i < num.size(); ++i) {
        auto n = num[i];
       
        if (n == 0) {
            len = 0;
            res = 1;
            continue;
        }
        
        if (len < K) {
            res *= n;
            ++len;
            if (len == K) {
                if (res > max) max = res;
            }
            continue;
        }
        
        res /= num[i-K];
        res *= num[i];
        if (res > max) max = res;
        
    }
    if (len >= K && res > max) max = res;

    return max;
}

int main() {
    ans_t T, K, N;
    string num_str;
    vector<ans_t> ans;
    cin >> T;
    while (T) {
        --T;
        cin >> N >> K;
        cin >> num_str;
        ans.push_back(sol(num_str, K));
    }
    copy(ans.begin(), ans.end(), ostream_iterator<ans_t>(cout, "\n"));
    return 0;
}

