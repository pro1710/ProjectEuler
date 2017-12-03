#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>
#include <functional>

using namespace std;

typedef uint64_t ans_t;

std::function<ans_t (const ans_t& a, const ans_t& b)> sap = [&](const ans_t& a, const ans_t& b) {
    if (a < b) return sap(b, a);
    return ((a + b)*(a - b + 1))/2;
};

ans_t pairProduct(const ans_t& a, const ans_t& b) {
    if (a - b == 0) return 0;
    auto mid = (a + b) / 2;
    return pairProduct(mid, b) + pairProduct(a, mid + 1) + 2*sap(mid, b)*sap(a, mid + 1);
}

ans_t sol(const ans_t& N) {
    return pairProduct(N, 1);
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