#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����
// �� ���� A�� B�� �Է¹��� ����, A + B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
//
// �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)
//
// ���
// �� �׽�Ʈ ���̽����� A + B�� ����Ѵ�.


int main() {
	int T;
	scanf("%d", &T);

	int a, b;
	while (T--) {
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", a + b);
	}
}