#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 11720 _ ������ ��

// ����
// N���� ���ڰ� ���� ���� �����ִ�.
// �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� ������ ���� N(1 �� N �� 100)�� �־�����.
// ��° �ٿ� ���� N���� ������� �־�����.
//
// ���
// �Է����� �־��� ���� N���� ���� ����Ѵ�.


int main() {
	int T;
	scanf("%d", &T);

	char user[101];
	scanf("%s", user);

	int sum = 0;
	for (int i = 0; i < T; i++) {
		sum = sum + (user[i] - '0');
	}
	printf("%d", sum);
}