#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//���Դ� ������ �ϴٰ� ������ �ϰ� �;�����.
//
//���� �� ���� ������ �ڿ�, �̸� ������������ �����ϰ� �;�����.
//
//���� �� ���� �־����� ��, ���� ���� ��, �� ���� ��, ���� ū ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//���� �� ���� �־�����.�� ���� 1���� ũ�ų� ����, 1, 000, 000���� �۰ų� ����.�� ���� ��� �ٸ���.
//
//���
//���� ���� ��, �� ���� ��, ���� ū ���� ���ʴ�� ����Ѵ�.

int main() {

	int number[3];
	int user;
	int min;
	int temp;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &user);
		number[i] = user;
	}


	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			if (number[i] > number[i + 1]) {
				temp = number[i];
				number[i] = number[i + 1];
				number[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", number[i]);
	}
}