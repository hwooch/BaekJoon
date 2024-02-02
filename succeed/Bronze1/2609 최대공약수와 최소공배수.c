#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 2609 _ �ִ������� �ּҰ����

// ����
// �� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10, 000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.
//
// ���
// ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.


int main() {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    int* table1 = (int*)malloc(sizeof(int) * N);
    int* table2 = (int*)malloc(sizeof(int) * M);

    for (int i = 0; i < N; i++) { // �ʱ�ȭ
        table1[i] = 0;
    }
    for (int i = 0; i < M; i++) { // �ʱ�ȭ
        table2[i] = 0;
    }

    int count = 0;
    for (int i = 1; i <= N / 2; i++) { // ���÷� 11�̶�� 1~5�����߿��� ������� �迭�� ����
        if (N % i == 0) {
            table1[count] = i;
            count++;
        }
    }
    table1[count] = N; // �ڱ� �ڽ��� 11�� ����̹Ƿ� �迭�� ����
    count++;
    int len1 = count; // ����� ����

    count = 0;
    for (int i = 1; i <= M / 2; i++) {
        if (M % i == 0) {
            table2[count] = i;
            count++;
        }
    }
    table2[count] = M;
    count++;
    int len2 = count;


    int remember = 0; // �ִ����� ����
    for (int i = len1 - 1; i >= 0; i--) { // ���� ���� ������� ���س����鼭
        for (int j = len2 - 1; j >= 0; j--) { // ���� ó�� �Ȱ��� ����� ��������
            if (table1[i] == table2[j]) {
                remember = table1[i]; // �ִ������� ����
                break;
            }
        }
        if (remember != 0) {
            break;
        }
    }
    printf("%d\n", remember); // �ִ����� ���

    int sum = (N / remember) * (M / remember);
    printf("%d", sum * remember); // �ּҰ���� ���

    free(table1);
    free(table2);
}