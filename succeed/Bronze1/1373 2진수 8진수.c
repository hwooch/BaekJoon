#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1373 _ 2���� 8����

// ����
// 2������ �־����� ��, 8������ ��ȯ�ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� 2������ �־�����.�־����� ���� ���̴� 1, 000, 000�� ���� �ʴ´�.
// 
// ���
// ù° �ٿ� �־��� ���� 8������ ��ȯ�Ͽ� ����Ѵ�.

char number[1000001];
int main() {
	scanf("%s", number);

	int len = strlen(number);
	int answer = 0;

	int count = 4;

	if (len % 3 == 0) {
		for (int i = 0; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
	else if (len % 3 == 1) {
		printf("%d", number[0] - 48);
		for (int i = 1; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
	else if (len % 3 == 2) {
		printf("%d", (number[0] - 48) * 2 + (number[1] - 48));
		for (int i = 2; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
}