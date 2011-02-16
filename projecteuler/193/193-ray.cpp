#include <cstdio>
using namespace std;
typedef long long ll;

bool sifted[1 << 25];
int np, primes[2100000];
ll ans;

void rec(int k, int x, int n, int odd)
{
    if (odd) ans -= (ll)n*n/x/x;
    else ans += (ll)n*n/x/x;
    for (int i = k; i < np && x <= n/primes[i]; i++)
        rec(i+1, x*primes[i], n, odd ^ 1);
}

int main()
{
    for (int i = 2; i < 1 << 25; i++) {
        if (!sifted[i]) primes[np++] = i;
        for (int j = 0; j < np && i*primes[j] < 1 << 25; j++) {
            sifted[i*primes[j]] = true;
            if (i%primes[j] == 0) break;
        }
    }
    rec(0, 1, 1 << 25, 0);
    printf("%lld\n", ans);
    return 0;
}
