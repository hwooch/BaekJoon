#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2738 _ ��� ����

// ����
// N* Mũ���� �� ��� A�� B�� �־����� ��, �� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ����� ũ�� N �� M�� �־�����.��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ���ʴ�� �־�����.
// �̾ N���� �ٿ� ��� B�� ���� M���� ���ʴ�� �־�����.
// N�� M�� 100���� �۰ų� ����, ����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.
// 
// ���
// ù° �ٺ��� N���� �ٿ� ��� A�� B�� ���� ����� ����Ѵ�.����� �� ���Ҵ� �������� �����Ѵ�.

int table1[100][100];
int table2[100][100];
int answer[100][100];

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &table1[i][j]);
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &table2[i][j]);
			answer[i][j] = table1[i][j] + table2[i][j];
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
}