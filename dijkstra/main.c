#include <stdio.h>
# define INF 1000000000
int number = 6; //정점의 개수

//전체 그래프 초기화
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

int v[5]; //방문한 노드
int d[5]; //최단거리

//가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {	//방문하지 않은 노드중에서 최소거리 갖는 정점 반환
			min = d[i];
			index = i;
		}
	}
	return index;
}

//다익스트라 수행 함수
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = 1;	//방문노드 체크
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = 1;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {	//방문하지 않은 노드 중에서
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}