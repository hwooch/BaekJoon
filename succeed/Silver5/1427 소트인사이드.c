#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// 1427 _ ��Ʈ�λ��̵�

// ����
// �迭�� �����ϴ� ���� ����.���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.
//
// �Է�
// ù° �ٿ� �����Ϸ��� �ϴ� �� N�� �־�����.N�� 1, 000, 000, 000���� �۰ų� ���� �ڿ����̴�.
//
// ���
// ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.

void sort(int box[], int size) {
	int temp = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (box[j] < box[j + 1]) {
				temp = box[j];
				box[j] = box[j + 1];
				box[j + 1] = temp;
			}
		}
	}
}

int main() {
	int user;
	scanf("%d", &user);
	int count = 0; // �ڸ���

	int box[SIZE];
	for (int i = 0; i < SIZE; i++) {
		box[i] = user % 10;
		user = user / 10; // box �迭�� user ���ڸ� �������� ����
		if (user != 0) {
			count++;
		}
	}

	sort(box, SIZE);

	for (int i = 0; i < count + 1; i++) {
		printf("%d", box[i]);
	}
}