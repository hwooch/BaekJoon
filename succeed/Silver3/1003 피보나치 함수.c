#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1003 _ �Ǻ���ġ �Լ�

// ����
// ���� �ҽ��� N��° �Ǻ���ġ ���� ���ϴ� C++ �Լ��̴�.
// 
// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     }
//     else if (n == 1) {
//         printf("1");
//         return 1;
//     }
//     else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }
//
// fibonacci(3)�� ȣ���ϸ� ������ ���� ���� �Ͼ��.
// 
// fibonacci(3)�� fibonacci(2)�� fibonacci(1) (ù ��° ȣ��)�� ȣ���Ѵ�.
// fibonacci(2)�� fibonacci(1) (�� ��° ȣ��)�� fibonacci(0)�� ȣ���Ѵ�.
// �� ��° ȣ���� fibonacci(1)�� 1�� ����ϰ� 1�� �����Ѵ�.
// fibonacci(0)�� 0�� ����ϰ�, 0�� �����Ѵ�.
// fibonacci(2)�� fibonacci(1)�� fibonacci(0)�� ����� ���, 1�� �����Ѵ�.
// ù ��° ȣ���� fibonacci(1)�� 1�� ����ϰ�, 1�� �����Ѵ�.
// fibonacci(3)�� fibonacci(2)�� fibonacci(1)�� ����� ���, 2�� �����Ѵ�.
// 1�� 2�� ��µǰ�, 0�� 1�� ��µȴ�.N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
// 
// �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, N�� �־�����.N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
// 
// ���
// �� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.

int main() {
    int N;
    scanf("%d", &N);
    long long int dp1[50] = { 0,1 };
    long long int dp0[50] = { 1,0 };
    
    for (int i = 2; i < 50; i++) {
        dp1[i] = dp1[i - 2] + dp1[i - 1];
        dp0[i] = dp0[i - 2] + dp0[i - 1];
    }
    int user;
    for (int i = 0; i < N; i++) {
        scanf("%d", &user);
        printf("%lld %lld\n", dp0[user], dp1[user]);
    }
}