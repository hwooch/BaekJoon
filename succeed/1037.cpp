#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�.
// � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� N�� ��¥ ����� ������ �־�����.�� ������ 50���� �۰ų� ���� �ڿ����̴�.
// ��° �ٿ��� N�� ��¥ ����� �־�����. 1, 000, 000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.
//
//���
//ù° �ٿ� N�� ����Ѵ�.N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.

int main() {
	int number[50] = { 0 };
	int T;
	int min, max;
	int user;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &user);
		number[i] = user;
	}
	if (T == 1) {
		printf("%d", number[0] * number[0]); //����� 1�����̹Ƿ� ������ ��� ���
	}
	else {
		min = number[0];
		max = number[0];
		for (int i = 1; i < T; i++) {
			if (min > number[i]) {
				min = number[i];// ���� ������
			}
			if (max < number[i]) {
				max = number[i];// ���� ū��
			}
		}
		printf("%d", min * max);
	}

}