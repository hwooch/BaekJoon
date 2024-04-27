#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 2312 _ �� �����ϱ�

// ����
// ���� ���� N�� �־����� ��, �� ���� ���μ����� �� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����.
// �� �׽�Ʈ ���̽����� ���� ���� N(2 �� N �� 100, 000)�� �־�����.
// 
// ���
// �� �׽�Ʈ ���̽����� �� �μ��� �� �μ��� ������ Ƚ���� �� �پ� ����Ѵ�.
// ��� ������ �μ��� �����ϴ� ������ �Ѵ�.

#define SIZE 100001

int main(void)
{
    int a[SIZE] = { 0 };
    int arr[SIZE] = { 0 }; // �Ҽ����� ���ʷ� ���ִ� �迭
    int i, j;
    int count = 0;

    for (i = 2; i <= sqrt(SIZE); i++) {
        if (a[i] == 0) {
            for (j = 2; i * j < SIZE; j++) {
                a[i * j] = 1;
            }
        }
    }

    for (i = 2; i < SIZE; i++) {
        if (a[i] == 0) {
            arr[count++] = i;
        }
    }

    int N;
    scanf("%d", &N);
    int user;
    while (N--) {
        scanf("%d", &user);

        for (i = 0; i < count && user > 1; i++) {
            int number = arr[i]; // ���� �Ҽ�
            int number_count = 0; // �� �Ҽ��� ������ Ƚ��
            while (user % number == 0) { // user�� ���� �Ҽ��� ������ ��������
                user /= number;
                number_count++;
            }
            if (number_count > 0) { // ���� �μ��� �� �� �̻� �������ٸ�
                printf("%d %d\n", number, number_count);
            }
        }
        if (user > 1) { // �ݺ����� ���� �� user�� 1���� ũ�ٸ� user ��ü�� �Ҽ�
            printf("%d 1\n", user);
        }
    }
}
