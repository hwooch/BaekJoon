#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1564 _ ���丮��5

// ����
// ���丮��5��, N!�� 0�� �ƴ� �� 5�ڸ��� ���Ѵ�.
// 
// N�� �־����� ��, ���丮��5�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ���� N�� �־�����.N�� 1, 000, 000���� �۰ų� ����.��, 9���� ũ�ų� ����.
// 
// ���
// ù° �ٿ� N�� ���丮��5�� ����Ѵ�.

int main() {

	int N;
	scanf("%d", &N);

	long long int answer = 36288;

	int zero = 0;

	if (N == 9) {
		printf("36288");
	}
	else {
		for (int i = 10; i <= N; i++) {
			answer = answer * i;
			while (answer % 10 == 0) {
				answer = answer / 10;
			}

			if (answer >= 1000000000000) {
				answer = answer % 1000000000000;
			}
		}
		if ((answer % 100000) / 10000 == 0) {
			printf("%d%d", zero, answer % 100000);
		}
		else {
			printf("%d", answer % 100000);
		}
	}
}