#include <cstdio>
using namespace std;
typedef long long ll;

bool sifted[1 << 25];
int np, primes[2100000];
ll ans;

void rec(int k, ll x, ll n, int odd)
{
    if (x > n) return;
    if (k == np || (double)x*primes[k]*primes[k] > n) {
        if (odd) ans -= n/x;
        else ans += n/x;
        return;
    }
    rec(k+1, x, n, odd);
    rec(k+1, x*primes[k]*primes[k], n, odd ^ 1);
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

    printf("%lld\n", (rec(0, 1, 1LL << 50, 0), ans));
    return 0;
}
