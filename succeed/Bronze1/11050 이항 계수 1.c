#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11050 _ ���� ��� 1

// ����
// �ڿ��� n�� ���� k�� �־����� �� ���� ��� nCk �� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� n�� k�� �־�����. (1<=n<=10,0<=k<=n)
// 
// ���
//  
// nCk �� ���� ����Ѵ�.

int main() {

	int N;
	scanf("%d", &N);

	int K;
	scanf("%d", &K);

	int answer = 1;

	for (int i = N; i > K; i--) {
		answer = answer * i;
	}
	for (int i = N - K; i > 1; i--) {
		answer = answer / i;
	}
	printf("%d", answer);
}