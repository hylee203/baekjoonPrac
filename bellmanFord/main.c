#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int n, m;
int dist[1001];
int edges[2001][3];

int bf(int start) {
    // 시작 노드에 대해서 초기화
    dist[start] = 0;

    // 전체 N번의 라운드 반복
    for (int i = 0; i < n; i++) {
        // 모든 간선 확인하기
        for (int j = 0; j < m; j++) {
            int now = edges[j][0];
            int next_node = edges[j][1];
            int cost = edges[j][2];
            // 현재 간선을 거쳐서 다른 노드로 이동하는게 더 짧은 경우
            if (dist[now] != INF && dist[next_node] > dist[now] + cost) {
                dist[next_node] = dist[now] + cost;
                if (i == n - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    if (bf(1)) {
        // 음수 간선의 순환이 존재하는 경우
        printf("-1\n");
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                // 도달할 수 없는 경우
                printf("-1\n");
            }
            else {
                // 도달할 수 있는 경우
                printf("%d\n", dist[i]);
            }
        }
    }

    return 0;
}
