#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1978 _ �Ҽ� ã��
// 
// ����
// �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù �ٿ� ���� ���� N �� �־�����. 
// N�� 100 �����̴�. 
// �������� N���� ���� �־����µ� ���� 1000 ������ �ڿ����̴�.
// 
// ���
// �־��� ���� �� �Ҽ��� ������ ����Ѵ�.

int number[100];

int main() {
    int N;
    scanf("%d", &N);
    int answer = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &number[i]);
        int count = 0;
        int devide = 1;
        while (devide <= number[i]) {
            if (number[i] % devide == 0) {
                count++;
            }
            devide++;
            if (count > 2) {
                break;
            }
        }
        if (count == 2) {
            answer++;
        }
    }
    printf("%d", answer);
}