#include <stdio.h>
#define INF 999999
#define N 5

int main() {
    int n = N;
    int cost[N][N] = {
        {0, 2, INF, 6, INF},
        {2, 0, 3, 8, 5},
        {INF, 3, 0, INF, 7},
        {6, 8, INF, 0, 9},
        {INF, 5, 7, 9, 0}
    };

    int selected[N];
    for (int i = 0; i < n; i++) selected[i] = 0;
    selected[0] = 1;

    int edges = 0, mincost = 0;
    while (edges < n - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j]) {
                        if (min > cost[i][j]) {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("Aresta (%d, %d) incluida de custo %d\n", x, y, min);
        mincost += min;
        selected[y] = 1;
        edges++;
    }
    printf("Custo minimo = %d\n", mincost);
    return 0;
}
