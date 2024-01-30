#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1236 _ �� ��Ű��

// ����
// �����̴� ���簢�� ����� ���� ������ �ִ�.
// ���� 1���� �� ���� ������ ���ؼ� ��ȣ�ǰ� �ִ�.
// �����̴� ��� ��� ��� ���� �� �� �̻��� ������ ������ ���ڴٰ� �����ߴ�.
//
// ���� ũ��� ������ ����ִ��� �־����� ��, �� ���� ������ �ּҷ� �߰��ؾ� �����̸� ������Ű���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� ���� ���� ũ�� N�� ���� ũ�� M�� �־�����.N�� M�� 50���� �۰ų� ���� �ڿ����̴�.
// ��° �ٺ��� N���� �ٿ��� ���� ���°� �־�����.���� ���´�.�� ��ĭ, X�� ������ �ִ� ĭ�̴�.
//
// ���
// ù° �ٿ� �߰��ؾ� �ϴ� ������ �ּڰ��� ����Ѵ�.

void check(char castle[][50], int height, int width) {
	// ���� ���� �����ϴ���
	int empty = 0;
	int count = 0;
	for (int i = 0; i < height; i++) {
		count = 0;
		for (int j = 0; j < width; j++) {
			if (castle[i][j] == 'X') { // x�� �ִٸ�
				count++;
			}
		}
		if (count == 0) { // x�� ���ٴ� ���̹Ƿ�
			empty++; // ���� �߰�
		}
	}


	// ���� ���� �����ϴ���
	int empty2 = 0;
	count = 0;
	for (int i = 0; i < width; i++) {
		count = 0;
		for (int j = 0; j < height; j++) {
			if (castle[j][i] == 'X') { // x�� �ִٸ�
				count++;
			}
		}
		if (count == 0) { // x�� ���ٴ� ���̹Ƿ�
			empty2++; // ���� �߰�
		}
	}
	printf("%d", empty > empty2 ? empty : empty2);
}

char castle[50][50];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", castle[i]);
	}
	check(castle, N, M);
}