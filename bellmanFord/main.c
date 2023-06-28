#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int n, m;
int dist[1001];
int edges[2001][3];

int bf(int start) {
    // ���� ��忡 ���ؼ� �ʱ�ȭ
    dist[start] = 0;

    // ��ü N���� ���� �ݺ�
    for (int i = 0; i < n; i++) {
        // ��� ���� Ȯ���ϱ�
        for (int j = 0; j < m; j++) {
            int now = edges[j][0];
            int next_node = edges[j][1];
            int cost = edges[j][2];
            // ���� ������ ���ļ� �ٸ� ���� �̵��ϴ°� �� ª�� ���
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
        // ���� ������ ��ȯ�� �����ϴ� ���
        printf("-1\n");
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                // ������ �� ���� ���
                printf("-1\n");
            }
            else {
                // ������ �� �ִ� ���
                printf("%d\n", dist[i]);
            }
        }
    }

    return 0;
}
