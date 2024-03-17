#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 17214�� _ ���� �Լ��� ����

// ����
// ���׽�(polynomial)�� ������ �ŵ������� ��� ����� ���� ǥ���ϴ� �����̴�.
// ���� ��� x^2 + 2x + 3 ���� ���� �ǹ��Ѵ�.
// ���� ������ �ϳ��� ���� �Ϻ��� ���׽��̶�� �ϰ� �̴� ������ ���� ǥ���Ѵ�.
// 
// f(x) = ax^n + bx^(n - 1) + ... + cx + d
// 
// �ִ� ���� �Ϻ��� ���׽��� �־����� �� �� �Լ��� ������ ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� �ִ� ���� �Ϻ��� ���׽��� �־�����.
// ���� ������ �ִ� 2���̰�, ������ �׻� x�� �־�����, �� ���� ���� ���ڷ� ���е��� �ʴ´�.
// �־����� ����� ������ 10, 000�� ���� �ʴ� 0�� �ƴ� 2�� ����̰� �־����� ����� ������ 10, 000�� ���� �ʴ� �����̴�.
// ������ ���� ���� �� ���� �־�����.
// ��, ����� ������ 1�� ��쿡�� 1�� �����Ѵ�.
// ���׽��� ������ ū �ͺ��� �۾����� ������� �־�����.
// 
// ���
// �־��� �Ϻ��� ���׽��� ������ ����� �Է� ���İ� �����ϰ� ����Ѵ�.
// ���л���� "W"�� x^2�� "xx"�� ǥ���Ѵ�.

char fx[20];

int main() {
	scanf("%s", fx);
	int len = strlen(fx);
	int memoryi = -1;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < len; i++) { // x�� ���ö����� �ݺ�
		if (fx[i] == 'x') {
			memoryi = i;
			break;
		}
	}
	if (memoryi == -1) { // x�� ������ ���� ������̶��
		if (fx[0] == '0') { // ������� 0�̶��
			printf("W");
		}
		else {
			if (fx[0] == '-') { // ������� �������
				for (int i = 1; i < len; i++) {
					sum = sum + pow(10, count++) * (fx[i] - '0');
				}
				if (sum == 1) {
					printf("-x+W");
				}
				else {
					printf("%sx+W", fx);
				}
			}
			else { // ������� ������
				for (int i = 0; i < len; i++) {
					sum = sum + pow(10, count++) * (fx[i] - '0');
				}
				if (sum == 1) {
					printf("x+W");
				}
				else {
					printf("%sx+W", fx);
				}
			}
		}
		return 0;
	}

	sum = 0;
	count = 0;
	//printf("memoryi = %d\n", memoryi); // x�� �ִ� ��ġ
	if (fx[0] == '-') {
		printf("-");
		for (int i = memoryi - 1; i >= 1; i--) { // x�� �ִ� ��ġ���� - �ٷ� ���� ��ġ���� ���ڵ��� ����
			sum = sum + pow(10, count++) * (fx[i] - '0');
		}
	}
	else {
		for (int i = memoryi - 1; i >= 0; i--) { // x�� �ִ� ��ġ���� ���ڵ��� ����
			sum = sum + pow(10, count++) * (fx[i] - '0');
		}

	}
	sum = sum / 2;
	if (sum == 1) {
		printf("xx");
	}
	else {
		printf("%dxx", sum);
	}
	// ������, ����ױ��� �Ϸ�

	sum = 0;
	count = 0;

	for (int i = len - 1; i >= memoryi + 2; i--) { // ������ �ڿ� ����� ���ϱ�
		sum = sum + pow(10, count++) * (fx[i] - '0');
	}
	if (sum == 0) { // ������ �ڿ� ������� 0�̶��
		printf("+W");
	}
	else {
		if (fx[memoryi + 1] == '-') { // ����� �κ��� �������
			if (sum == 1) {
				printf("-x");
			}
			else {
				printf("-%dx", sum);
			}
		}
		else {  // ����� �κ��� ������
			if (sum == 1) {
				printf("+x");
			}
			else {
				printf("+%dx", sum);
			}
		}
		printf("+W"); // �������� ���л�� ���
	}
}