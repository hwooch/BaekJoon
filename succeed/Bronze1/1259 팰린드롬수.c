#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1259 _ �Ӹ���Ҽ�

// ����
// � �ܾ �ڿ������� �о �Ȱ��ٸ� �� �ܾ �Ӹ�����̶�� �Ѵ�. 'radar', 'sees'�� �Ӹ�����̴�.
// 
// ���� �Ӹ�������� ����� �� �ִ�.
// ���� ���ڵ��� �ڿ������� �о ���ٸ� �� ���� �Ӹ���Ҽ���. 
// 121, 12421 ���� �Ӹ���Ҽ���. 123, 1231�� �ڿ������� ������ �ٸ��Ƿ� �Ӹ���Ҽ��� �ƴϴ�.
// ���� 10�� �Ӹ���Ҽ��� �ƴѵ�, �տ� ���ǹ��� 0�� �� �� �ִٸ� 010�� �Ǿ� �Ӹ���Ҽ��� ����� ���� ������, 
// Ư���� �̹� ���������� ���ǹ��� 0�� �տ� �� �� ���ٰ� ����.
// 
// �Է�
// �Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� ������, �� �ٸ��� 1 �̻� 99999 ������ ������ �־�����.
// �Է��� ������ �ٿ��� 0�� �־�����, �� ���� ������ ���Ե��� �ʴ´�.
// 
// ���
// �� �ٸ��� �־��� ���� �Ӹ���Ҽ��� 'yes', �ƴϸ� 'no'�� ����Ѵ�.

int len_number(int N, int number[]) {
	int Ncopy = N;
	int count = 0;
	while (1) {
		if (Ncopy > 0) {
			Ncopy = Ncopy / 10;
			count++;
		}
		if (Ncopy == 0) {
			break;
		}
	}
	for (int i = count - 1; i >= 0; i--) {
		number[i] = N % 10;
		N = N / 10;
	}
	return count;
}

int main() {

	int N;
	int number[5];
	while (1) {
		int check = 0;
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		else {
			int len = len_number(N, number);

			for (int i = 0; i < len / 2; i++) {
				if (number[i] != number[len - 1 - i]) {
					check++;
				}
			}
			if (check > 0) {
				printf("no\n");
			}
			else {
				printf("yes\n");
			}
		}
	}
}