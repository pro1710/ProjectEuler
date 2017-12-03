#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdint.h>

using namespace std;

typedef uint64_t ans_t;

ans_t brute (const ans_t& N) {
    ans_t sum = 0;
    for (ans_t a = 0, b = 1, next = a + b; next < N; next = a + b) {
        if (!(next & 1)) {
        sum += next;
        }
        a = b, b = next;
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ans_t T, num;
    vector<ans_t>ans;
    cin >> T;
    while (T) {
        --T;
        cin >> num;
        ans.push_back(brute(num));
    }
    
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<ans_t>(std::cout, "\n"));
    return 0;
}
