#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1193 _ �м�ã��

// ����
// ������ ū �迭�� ������ ���� �м����� �����ִ�.
//
//	1 / 1	1 / 2	1 / 3	1 / 4	1 / 5	��
//	2 / 1	2 / 2	2 / 3	2 / 4	��	��
//	3 / 1	3 / 2	3 / 3	��	��	��
//	4 / 1	4 / 2	��	��	��	��
//	5 / 1	��	��	��	��	��
//  ��	��	��	��	��	��
// 
// �̿� ���� ������ �м����� 1 / 1 �� 1 / 2 �� 2 / 1 �� 3 / 1 �� 2 / 2 �� �� �� ���� ������� ������ ���ʴ�� 1��, 2��, 3��, 4��, 5��, �� �м���� ����.
//
// X�� �־����� ��, X��° �м��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� X(1 �� X �� 10, 000, 000)�� �־�����.
//
// ���
// ù° �ٿ� �м��� ����Ѵ�.

int main() {
	int user;
	scanf("%d", &user);


	int count = 1;
	int count_add = 2;
	int count_number = 2;

	if (user == 1) {
		printf("1/1");
		exit(0);
	}
	while (1) { // �Է� ���� ������ ���� ���� �����ϱ� ���� ���ѷ���
		if (user > count) { // ex) �Է¹��� ���� 10�̶�� 1+2+3+4���� ���� ��
			count += count_add;
			count_add++;
		}
		if (user <= count) { // 1+2+3+4���� 4�� ���� ����
			count -= count_add - 1;
			break;
		}
		count_number++;
	}
	int sum = count_number + 1; //sum ���� ���ڿ� �и��� ���Ѱ��� ��Ÿ��

	if (sum % 2 == 0) { // sum�� ¦����� ū ���� ����
		printf("%d/%d", sum - (user - count), user - count);
	}
	else { // Ȧ����� ū ���� �����ʺ��� ����
		printf("%d/%d", user - count, sum - (user - count));
	}
}