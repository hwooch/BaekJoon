#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1051 _ ���� ���簢��

// ����
// N��Mũ���� ���簢���� �ִ�.
// �� ĭ���� �� �ڸ� ���ڰ� ���� �ִ�.
// �� ���簢������ �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã�� ���α׷��� �ۼ��Ͻÿ�.
// �̶�, ���簢���� �� �Ǵ� ���� �����ؾ� �Ѵ�.
// 
// �Է�
// ù° �ٿ� N�� M�� �־�����.
// N�� M�� 50���� �۰ų� ���� �ڿ����̴�.
// ��° �ٺ��� N���� �ٿ� ���� �־�����.
// 
// ���
// ù° �ٿ� ���� ���簢���� ũ�⸦ ����Ѵ�.

int table[50][50] = { 0 };

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	char user[51];
	for (int i = 0; i < x; i++) {
		scanf("%s", user);
		for (int j = 0; j < strlen(user); j++) {
			table[i][j] = user[j] - '0';
		}
	}

	int min = (x < y ? x : y) + 1;
	//printf("%d\n\n", min);

	while (min--) {
		//printf("%d\n", min);
		for (int i = 0; i <= x - min; i++) {
			for (int j = 0; j <= y - min; j++) {
				if (table[i][j] == table[i + min - 1][j + min - 1] && table[i][j] == table[i + min - 1][j] && table[i][j] == table[i][j + min - 1]) {
					printf("%d", min * min);
					return 0;
				}
			}
		}
	}
	printf("1");
}