#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 1929 _ �Ҽ� ���ϱ�
// 
// ����
// M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����.
// (1 �� M �� N �� 1, 000, 000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.
//
// ���
// �� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.

int main() {

	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = N; i <= M; i++) {
		if (i == 1) {
			continue;
		}
		int count = 0;
		for (int j = 1; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				count++;
				if (count > 1) {
					break;
				}
			}
		}
		if (count == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}