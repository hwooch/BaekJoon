#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����
// "OOXXOXXOOO"�� ���� OX������ ����� �ִ�.
// O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�.
// ������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.
// ���� ���, 10�� ������ ������ 3�� �ȴ�.
//
//"OOXXOXXOOO"�� ������ 1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10���̴�.
//
// OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.
// �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����.
// ���ڿ��� O�� X������ �̷���� �ִ�.
//
// ���
// �� �׽�Ʈ ���̽����� ������ ����Ѵ�.


int main() {
	int T;
	scanf("%d", &T);
	char user[82];
	int check = 0;
	int count = 0;
	int len = 0;

	while (T--) {
		scanf("%s", user);

		count = 0;
		check = 0;
		len = strlen(user);

		if (user[0] == 'O') { // ���� ù ���ڰ� O���
			count++;
			if (check == 0) {
				check = 1;
			}
		}

		for (int i = 1; i < len; i++) { // �ι�° ���ں��� �ݺ��Ѵ�
			if (user[i] == 'O') { // �ι�° ���ڰ� O���
				count++;
				if (check == 0) {
					check = 1;
				}
			}
			else if (user[i] == 'X') {
				check = 0;
			}

			if (user[i] == 'O' && user[i - 1] == 'O' && check > 0) { // �������� O�� ��������

				count = count + check;
				check++;
			}
		}
		printf("%d\n", count);
	}
}