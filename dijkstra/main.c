#include <stdio.h>
# define INF 1000000000
int number = 6; //������ ����

//��ü �׷��� �ʱ�ȭ
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

int v[5]; //�湮�� ���
int d[5]; //�ִܰŸ�

//���� �ּ� �Ÿ��� ������ ������ ��ȯ
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {	//�湮���� ���� ����߿��� �ּҰŸ� ���� ���� ��ȯ
			min = d[i];
			index = i;
		}
	}
	return index;
}

//���ͽ�Ʈ�� ���� �Լ�
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = 1;	//�湮��� üũ
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = 1;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {	//�湮���� ���� ��� �߿���
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