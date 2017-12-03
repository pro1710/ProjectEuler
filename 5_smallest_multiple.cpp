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

ans_t brute(const ans_t& N) {
    vector<unsigned> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    ans_t res = 1;
    vector<unsigned> nums;
    for (int i = 1; i <= N; ++i) {
        nums.push_back(i);
    }
    unsigned max = 0;
    bool end = false;
    while (!end) {
        for (auto& p: primes) {
            bool m = false;
            end = true;
            max = 0;
            for (size_t i = 0, e = nums.size(); i < e; ++i) {
                if (nums[i] != 1) {
                    end = false;
                    if (nums[i] > max) max = nums[i];
                    if (nums[i] % p == 0) {
                        nums[i] /= p;
                        m = true;
                    }
                }
            }
            if (m) {
                res *= p;
            }
            if (max == 0 || p > max || end) 
                break;
        }
    }
    return res;
}

ans_t sol(const ans_t& N) {
    
    std::function<ans_t (const ans_t&, const ans_t&)> gcd = [&](const ans_t& a, const ans_t& b) {
        return b == 0 ? a : gcd(b, a%b);
    };
    auto lcm = [&](const ans_t& a, const ans_t& b)->ans_t {
        return a / gcd(a, b) * b;  
    }; 
    
    ans_t res = 1;
    for (ans_t i = 2; i <= N; ++i) {
        res = lcm(res, i);
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
        ans.push_back(sol(num));
    }
    copy(ans.begin(), ans.end(), ostream_iterator<ans_t>(cout, "\n"));
    return 0;
}