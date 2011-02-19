#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

#ifndef DEBUG

const int N = 16;
const char a[][N+12] =
{
    "5616185650518293 ;2 correct",
    "3847439647293047 ;1 correct",
    "5855462940810587 ;3 correct",
    "9742855507068353 ;3 correct",
    "4296849643607543 ;3 correct",
    "3174248439465858 ;1 correct",
    "4513559094146117 ;2 correct",
    "7890971548908067 ;3 correct",
    "8157356344118483 ;1 correct",
    "2615250744386899 ;2 correct",
    "8690095851526254 ;3 correct",
    "6375711915077050 ;1 correct",
    "6913859173121360 ;1 correct",
    "6442889055042768 ;2 correct",
    "2321386104303845 ;0 correct",
    "2326509471271448 ;2 correct",
    "5251583379644322 ;2 correct",
    "1748270476758276 ;3 correct",
    "4895722652190306 ;1 correct",
    "3041631117224635 ;3 correct",
    "1841236454324589 ;3 correct",
    "2659862637316867 ;2 correct",
};

#else

const int N = 5;
const char a[][N+12] =
{
    "90342 ;2 correct",
    "70794 ;0 correct",
    "39458 ;2 correct",
    "34109 ;1 correct",
    "51545 ;2 correct",
    "12531 ;1 correct",
};

#endif

int L[N+1], R[N+1], candidate[N];
char res[N+1];
int cur[sizeof(a)/sizeof(a[0])];

void dfs(int k);

void dfs2(int k, int kk)
{
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        if (cur[i] > a[i][N+2]-'0')
            return;
    if (kk >= N) {
        if (cur[k] == a[k][N+2]-'0')
            dfs(k+1);
        return;
    }

    res[kk] = a[k][kk];
    L[R[kk]] = L[kk]; R[L[kk]] = R[kk];
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        if (a[i][kk] == res[kk])
            cur[i]++;
    dfs2(k, R[kk]);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        if (a[i][kk] == res[kk])
            cur[i]--;
    L[R[kk]] = R[L[kk]] = kk;
    res[kk] = '\0';

    candidate[kk] &= ~(1 << a[k][kk]-'0');
    if (candidate[kk])
        dfs2(k, R[kk]);
    candidate[kk] |= 1 << a[k][kk]-'0';
}

void dfs(int k)
{
    if (k == sizeof(a)/sizeof(a[0])) {
        for (int i = 0; i < N; i++)
            if (res[i] == '\0')
                for (int j = 0; j < 10; j++)
                    if (candidate[i] & 1 << j) {
                        res[i] = '0'+j;
                        break;
                    }
        puts(res);
        exit(0);
    }
    dfs2(k, R[N]);
}

int main()
{
    for (int i = 0; i <= N; i++)
        L[i] = i-1, R[i] = i+1;
    L[0] = N; R[N] = 0;
    for (int i = 0; i < N; i++)
        candidate[i] = (1 << 10) - 1;
    dfs(0);
    return 0;
}
