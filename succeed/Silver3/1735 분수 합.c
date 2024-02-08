#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1735 _ �м� ��

// ����
// �м� A / B�� ���ڰ� A, �и� B�� �м��� �ǹ��Ѵ�.A�� B�� ��� �ڿ������ ����.
// 
// �� �м��� �� ���� �м��� ǥ���� �� �ִ�.
// �� �м��� �־����� ��, �� ���� ���м��� ���·� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.���м��� �� �̻� ��е��� �ʴ� �м��� �ǹ��Ѵ�.
// 
// �Է�
// ù° �ٰ� ��° �ٿ�, �� �м��� ���ڿ� �и� ���ϴ� �� ���� �ڿ����� ������� �־�����.�ԷµǴ� �� �ڿ����� ��� 30, 000 �����̴�.
// 
// ���
// ù° �ٿ� ���ϰ��� �ϴ� ���м��� ���ڿ� �и� ���ϴ� �� ���� �ڿ����� �� ĭ�� ���̿� �ΰ� ������� ����Ѵ�.

int gcd(int a, int b) { // �ִ����� ���ϴ� �Լ�
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int leftx;  // ����
    int lefty;  // �к�
    int rightx; // ����
    int righty; // �и�

    scanf("%d %d %d %d", &leftx, &lefty, &rightx, &righty);

    int answerx = leftx * righty + lefty * rightx; // ����
    int answery = lefty * righty; // �и�

    int remember = gcd(answerx, answery);

    printf("%d ", answerx / remember);
    printf("%d", answery / remember);
}