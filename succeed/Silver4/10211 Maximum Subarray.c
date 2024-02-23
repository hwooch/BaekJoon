#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 10211 _ Maximum Subarray

// ����
// ũ�� N�� ������ �迭 X�� ���� ��, X�� �κ� �迭(X�� ������ �Ϻκ�) �� �� ������ ���� 
// ���� ū �κ� �迭�� ã�� Maximum subarray problem(�ִ� �κй迭 ����)�� ��ǻ�� ���п��� �ſ� �� �˷��� �ִ�.
// 
// �������� N�� �迭 X�� �־����� ��, X�� maximum subarray�� ���� ������. 
// ��, max1 �� i ��  j �� N(X[i] + ... + X[j])�� ������.
// 
// �Է�
// �Է� ������ ù ��° �ٿ� �׽�Ʈ ���̽��� ���� �ǹ��ϴ� �ڿ��� T�� �־�����.
// �� �������� T���� �׽�Ʈ ���̽��� �־�����.
// 
// �� �׽�Ʈ���̽� ���� ù ��° �ٿ� �迭�� ũ�� N�� �־�����. (1 �� N �� 1, 000)
// 
// �׸��� �� ��° �ٿ� �迭 X�� ������ ��Ÿ���� N���� ������ �������� ���еǾ� �־�����.
// �̶� �־����� ���� ������ 1, 000���� ���� �����̴�.
// 
// ���
// �� �׽�Ʈ���̽� ���� maximum subarray�� ���� �ٷ� �����Ͽ� ����Ѵ�.

int main() {

    int N;
    scanf("%d", &N);
    int T;

    while (N--) {
        scanf("%d", &T);

        int max_sum = -1000;
        int current_sum = 0;

        for (int i = 0; i < T; i++) {
            int num;
            scanf("%d", &num);

            if (current_sum < 0) { // ���� ���ϴٰ� ������ �Ǹ� �� ���� ������ ���� �����Ѵ�
                current_sum = num;
            }
            else { // ���� ������ �ƴ϶�� ��� ���س�����
                current_sum = current_sum + num;
            }

            if (current_sum > max_sum) { // ���س����鼭 �ִ밪�� ���Ž�Ų��
                max_sum = current_sum;
            }
        }
        printf("%d\n", max_sum);
    }
}