#include <stdio.h>
#define MAX 10
#define INF 999
int parent[MAX];
int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
void Kruskal(int n, int cost[MAX][MAX]) {
    int ne = 1, mincost = 0;
    int u, v, a, b, min,i,j;

    for (i = 0; i < MAX; i++) {
        parent[i] = 0;  
    }

    printf("Edges in the minimum spanning tree:\n");
    while (ne < n) {
        min = INF;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d-%d: Cost = %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total minimum cost = %d\n", mincost);
}

int main() {
    int n,i,j, cost[MAX][MAX];

    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    
    printf("Enter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    
    Kruskal(n, cost);

    return 0;
}
