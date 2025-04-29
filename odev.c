#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int enKisaSureyiHesapla(int n, int m, int time[MAX_N][MAX_M], int cost[MAX_M][MAX_M]) {
    int dp[MAX_N][MAX_M];

    for (int j = 0; j < m; j++) {
        dp[0][j] = time[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 0; k < m; k++) {

                int suanki = dp[i - 1][k] + cost[k][j] + time[i][j];
                dp[i][j] = min(dp[i][j], suanki);
            }
        }
    }

    int sonuc = INT_MAX;
    for (int j = 0; j < m; j++) {
        sonuc = min(sonuc, dp[n - 1][j]);
    }

    return sonuc;
}
int main() {
    int n = 3;
    int m = 3;

    int time[MAX_N][MAX_M] = {
        {4, 2, 3},
        {2, 1, 3},
        {3, 2, 1}
    };

    int cost[MAX_M][MAX_M] = {
        {0, 1, 2},
        {1, 0, 2},
        {2, 1, 0}
    };

    int sonuc = enKisaSureyiHesapla(n, m, time, cost);
    printf("Minimum toplam sure: %d\n", sonuc);

    return 0;
}