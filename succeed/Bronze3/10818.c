#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����
// N���� ������ �־�����.�̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� ������ ���� N(1 �� N �� 1, 000, 000)�� �־�����.
// ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����.
// ��� ������ - 1, 000, 000���� ũ�ų� ����, 1, 000, 000���� �۰ų� ���� �����̴�.
//
// ���
// ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.

int user[1000000];
int main() {
	int T;
	scanf("%d", &T);

	scanf("%d", &user[0]);
	int min = user[0];
	int max = user[0];

	for (int i = 1; i < T; i++) {
		scanf("%d", &user[i]);
		if (min >= user[i]) {
			min = user[i];
		}
		if (max <= user[i]) {
			max = user[i];
		}
	}
	printf("%d %d", min, max);
}