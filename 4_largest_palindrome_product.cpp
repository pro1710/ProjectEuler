#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>

using namespace std;

typedef uint64_t ans_t;

bool palindrom(const ans_t& num) {
    string str = to_string(num);
    for (int i = 0, j = str.size()-1; i <= j; ++i, --j) {
        if (str[i] != str[j]) return false;
    }
    return true;
}

ans_t brute(const ans_t& num) {
    ans_t e_max = 999, res = 0;
    for (ans_t i = 100; i < e_max; ++i) {
        for (ans_t j = 100; j < e_max; ++j) {
            ans_t m = i * j;
            if (m >= num) 
                break;
            res = m > res && palindrom(m) ? m : res;
        }
    }
    return res;
}

int main() {
    ans_t T, num;
    vector<ans_t> ans;
    cin >> T;
    while (T) {
        --T;
        cin >> num;
        ans.push_back(brute(num));
    }
    copy(ans.begin(), ans.end(), ostream_iterator<ans_t>(cout, "\n"));
    return 0;
}