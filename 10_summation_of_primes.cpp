#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>
#include <functional>

using namespace std;

typedef uint64_t ans_t;

vector< pair<ans_t, ans_t> > primes = {{2, 2}, {3, 5}};

size_t bs(const ans_t& N, const vector< pair<ans_t, ans_t> >& nums, size_t b, size_t e) {
    size_t mid = (b + e)/2;
    if (e - b  == 1) return nums[b].first <= N &&  N <= nums[e].first ? b : e;
    if (nums[mid].first <= N) 
        return bs(N, nums, mid, e);
    else 
        return bs(N, nums, b, mid);
} 

void genPrimes(const ans_t& N) {
    for (ans_t i  = primes.back().first + 2; primes.back().first <= N; i += 2) {
        bool good = true;
        for (size_t j = 0, e = primes.size(), eN = (ans_t)sqrt(N) + 1; j < e && primes[j].first < eN; ++j) {
            if (i % primes[j].first == 0) {
                good = false;
                break;
            }
        }
        if (good) {
            primes.push_back(make_pair(i, primes.back().second + i));

        }
    }
}

ans_t sol(const ans_t& N) {
    genPrimes(N);
    return primes[bs(N, primes, 0, primes.size()-1)].second;
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

