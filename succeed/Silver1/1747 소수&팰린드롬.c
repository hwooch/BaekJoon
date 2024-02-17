#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1747 _ �Ҽ�&�Ӹ����

// ����
// � ���� �� ���� ���� ������ ������ ���� ��ġ�ϴ� ���� �Ӹ�����̶� �θ���.
// ���� ��� 79, 197�� 324, 423 ���� �Ӹ���� ���̴�.
// 
// � �� N(1 �� N �� 1, 000, 000)�� �־����� ��, N���� ũ�ų� ����, �Ҽ��̸鼭 �Ӹ������ �� �߿���, ���� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� N�� �־�����.
// 
// ���
// ù° �ٿ� ������ �����ϴ� ���� ����Ѵ�.

int array[1200001] = { 0, };

int check(int N) {
    char number[10];       // ��ȯ�� ���ڿ��� ������ �迭

    sprintf(number, "%d", N);    // ������ ���ڿ��� ����
    int len = strlen(number);    // ���ڿ��� ����

    for (int i = 0; i < len / 2; i++) {
        if (number[i] != number[len - i - 1]) { //����������
            return 0; //�ٷ� 0 ����
        }
    }

    return 1; //�縰��Ҽ��̴�.
}

int main() {
    array[1] = 1;
    for (int i = 2; i <= sqrt(1200000); i++) {
        if (array[i] == 0) {
            for (int j = i * 2; j <= 1200000; j = j + i) {
                array[j] = 1;
            }
        }
    }

    int N;
    scanf("%d", &N);
    int count = 0;
    for (int i = N; i <= 1200000; i++) {
        if (array[i] == 0) {
            if (check(i)) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
}
