#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1085 _ ���簢������ Ż��

// ����
// �Ѽ��� ����(x, y)�� �ִ�.���簢���� �� ���� ��ǥ�࿡ �����ϰ�, ���� �Ʒ� ��������(0, 0), ������ �� ��������(w, h)�� �ִ�.
//  ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� x, y, w, h�� �־�����.
// 
// ���
// ù° �ٿ� ������ ������ ����Ѵ�.
// 
// ����
// 1 �� w, h �� 1, 000
// 1 �� x �� w - 1
// 1 �� y �� h - 1
// x, y, w, h�� ����

int compare(int x, int y) { // �� �������� ��ȯ���ִ� �Լ�
	if (x > y) {
		return y;
	}
	return x;
}

int main() {
	int userx, usery;
	int x, y;

	scanf("%d", &userx);
	scanf("%d", &usery);
	scanf("%d", &x);
	scanf("%d", &y);


	int answerx, answery;

	answerx = compare(userx, x - userx);
	answery = compare(usery, y - usery);
	printf("%d", compare(answerx, answery));
}