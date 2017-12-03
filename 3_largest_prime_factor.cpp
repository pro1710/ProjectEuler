#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>

using namespace std;

typedef uint64_t ans_t;

ans_t sol(ans_t& num) {
    ans_t res = 0;
    while (num % 2 == 0) {
        res = 2;
        num /= 2;
    }
    
    for (ans_t i = 3, e = sqrt(num); i <= e ;i += 2) {
       while (num % i == 0) {
           num /= i;
           res = i;
       }
    }
    
    res = num > res ? num : res;
    
    return res;
}

int main() {
    ans_t T, num;
    vector<ans_t> ans;
    cin >> T;
    while (T) {
        --T;
        cin >> num;
        ans.push_back(sol(num));
    }
    copy(ans.begin(), ans.end(), ostream_iterator<ans_t>(cout, "\n"));
    return 0;
}
