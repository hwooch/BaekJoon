#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//������ ���� �� ���� �����ؼ� �־����� �� �� ���� ���� ��ȣ�� �� ���� ������ 
// ��ȣ�� �̿��Ͽ� ���� �� �� ���� ū ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. (�� ���� ������ ������ �ʴ´�.)
//
//32 �� 16 �� 8
//
//�Է�
//ù° �ٿ� �� �� ���� A, B, C(1 �� A, B, C �� 1, 000, 000)�� �־�����.���� int������ ����� �ʴ´�.
//
//���
//���� �� �ִ� ���� ū ���� ����Ѵ�.��, �Ҽ��� �Ʒ��� ������. 1e-9 ������ ������ ���� ����� �޶����� �Է��� �־����� �ʴ´�.

int main() {

	double number[3];
	double user;
	double sum = 0;
	int change;

	for (int i = 0; i < 3; i++) {
		scanf("%lf", &user);
		number[i] = user;
	}


	sum = number[0] * number[1] / number[2];
	if ((number[0] / number[1] * number[2]) > sum) {
		sum = number[0] / number[1] * number[2];
	}

	change = sum;


	printf("%d", change);
	return 0;
}