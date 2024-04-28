#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1915 _ ���� ū ���簢��

// ����
// n��m�� 0, 1�� �� �迭�� �ִ�.
// �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// 0    1	 0	  0
// 0    1	 1	  1
// 1    1	 1	  0
// 0    0	 1	  0
// ���� ���� ���������� ����� 2��2 �迭�� ���� ū ���簢���̴�.
// 
// �Է�
// ù° �ٿ� n, m(1 �� n, m �� 1, 000)�� �־�����.
// ���� n���� �ٿ��� m���� ���ڷ� �迭�� �־�����.
// 
// ���
// ù° �ٿ� ���� ū ���簢���� ���̸� ����Ѵ�.

int arr[1001][1001];
int dp[1001][1001];

int min(int a, int b, int c) { // �� ���� ���� ������ ����
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

int main() {
    int n, m;
    char temp[1002];
    scanf("%d %d", &n, &m);

    int max = 0; // ���� ū ���簢���� ũ�⸦ ����

    // �迭 �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
            dp[i][j] = arr[i][j]; // dp �迭 �ʱ�ȭ
            if (dp[i][j] > max) {
                max = dp[i][j];
            }// �ִ� ���簢�� ũ�� ����
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
    }
    printf("%d", max * max); // ���� ū ���簢���� ���� ���
    return 0;
}
