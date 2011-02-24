#include <climits>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
const int N = 4000000, M = sizeof(primes)/sizeof(*primes);
ll dp[2][2*N-1];

int main()
{
    ll ans = LLONG_MAX;
    memset(dp[0], 0x77, sizeof(dp[0]));
    dp[0][1] = 1;
    for (int i = 0; i < M; i++) {
        memcpy(dp[i+1&1], dp[i&1], sizeof(dp[0]));
        for (int j = 1; j < 2*N-1; j++)
            if (dp[i&1][j] < LLONG_MAX/4) {
                ll v = dp[i&1][j];
                for (int k = 1; k <= 3; k++) {
                    int jj = j*(2*k+1);
                    if (v > LLONG_MAX/primes[i]) break;
                    v *= primes[i];
                    if (jj >= 2*N-1)
                        ans = min(ans, v);
                    else {
                        ll &t = dp[i+1&1][jj];
                        t = min(t, v);
                    }
                }
            }
    }
    printf("%lld\n", ans);
    return 0;
}
