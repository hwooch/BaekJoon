#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 2231 _ ������

// ����
// � �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�.
// � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�.
// ���� ���, 245�� �������� 256(= 245 + 2 + 4 + 5)�� �ȴ�.
// ���� 245�� 256�� �����ڰ� �ȴ�.����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�.
// �ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.
//
// �ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� �ڿ��� N(1 �� N �� 1, 000, 000)�� �־�����.
//
// ���
// ù° �ٿ� ���� ����Ѵ�.�����ڰ� ���� ��쿡�� 0�� ����Ѵ�.

int len_number(int N) {
	int Ncopy = N;
	int count = 0;
	while (1) {
		if (Ncopy > 0) {
			Ncopy = Ncopy / 10;
			count++;
		}
		if (Ncopy == 0) {
			break;
		}
	}
	return count;
}

int main() {

	int N;
	scanf("%d", &N);

	int answer = 0;

	int temp = 0;
	int test = 0;

	while (1) {
		test = temp; // 0���� 1�� ������Ű�� ���س���
		test++;
		temp = test;

		int len = len_number(test); // �ڸ����� ���ϰ�

		answer = temp; // ������ �� �� ���� ��
		for (int i = 0; i < len; i++) { // �� �ڸ��� ���ڸ� ���س���
			answer = answer + test % 10;
			test = test / 10;
		}
		if (answer == N) { // ���� �����ڰ� ó�� ��Ÿ���ٸ� ������ ����ϰ� ���α׷� ����
			printf("%d", temp);
			return 0;
		}
		if (temp == N) { // �����ڰ� ��Ÿ���� �ʾҴٸ� 0��� �� ���α׷� ����
			printf("0");
			return 0;
		}
	}
}