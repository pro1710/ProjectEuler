#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdint.h>

using namespace std;

typedef uint64_t ans_t;

ans_t bruteForce(const ans_t& N) {
    ans_t sum = 0;
    for (ans_t i = 1; i <= N; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

ans_t calc(const ans_t& N) {
    // ((a_n + a_1) * n) / 2
    
    ans_t num_3 = N/3, num_5 = N/5, num_15 = N/15;
    return ((3 + 3 * num_3)*num_3 + (5 + 5 * num_5)*num_5 - (15 + 15 * num_15)*num_15)/2;
}

int main() {
    ans_t T = 0, num = 0;
    vector<ans_t> ans;
    cin >> T;
    while (T) {
        --T;
        cin >> num;
        ans.push_back(calc(num-1));
    }
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<ans_t>(std::cout, "\n"));
    return 0;
}
