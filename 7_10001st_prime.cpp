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

vector<ans_t> primes = {2, 3, 5};

ans_t sol(const ans_t& N) {
    ans_t res = 0;
    if (primes.size() >= N) return primes[N-1];
    
    for (ans_t i  = primes[primes.size() - 1] + 1; primes.size() < N; ++i) {
        bool good = true;
        for (auto& p: primes) {
            if (i % p == 0) {
                good = false;
                break;
            }
        }
        if (good) {
            primes.push_back(i);
        }
    }
    return primes[N-1];
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

