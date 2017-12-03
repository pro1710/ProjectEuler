#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <iterator>
#include <functional>

using namespace std;

typedef int64_t ans_t;

ans_t brute(const ans_t& N) { 
    ans_t res = -1;
    ans_t c = 0, r = 0;
    
    for (ans_t b  = 2; b <= N/2; ++b) {
        for (ans_t a = 1; a < N; ++a) {
            c = N - a - b;
            if (c <= b) break;

            r = a*a + b*b - c*c;
            if (r > 0) 
                break;
            else if (r < 0) {
                continue;
            }
            r = a*b*c;
            if (r > res) res = r;
        }
    }
    return res;
}

ans_t sol(const ans_t& N) {
    ans_t res = -1;
    if (N < 6) return res;
    ans_t sqN = N*N, m = 0, a = 0, c = 0;
    for (ans_t b = 1, e = (sqN-2*N)/(2*(N-1)); b <= e && b < N/2; ++b) {
        m = sqN - 2*b*N;
        if (m % (2*(N-b)) == 0) {
            a = m / (2*(N-b));
            if (a > b) continue;
            c =  N - a - b;
            if (a*a + b*b == c*c) {
                m = a*b*c;
                if (m > res) res = m;
            }
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
        ans.push_back(sol(num));
    }
    copy(ans.begin(), ans.end(), ostream_iterator<ans_t>(cout, "\n"));
    return 0;
}

