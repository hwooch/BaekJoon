#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 2675 _ ���ڿ� �ݺ�

// ����
// ���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�.
// S���� QR Code "alphanumeric" ���ڸ� ����ִ�.
//
// QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$ % *+-. / : �̴�.
//
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1, 000)�� �־�����.
// �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����.
// S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.
//
// ���
// �� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.

int main() {
	int T;
	scanf("%d", &T);

	int repeat;
	char user[21];

	while (T--) {
		scanf("%d", &repeat); // ���ڸ� ��� �ݺ�����ϰ� ������ �Է�
		scanf("%s", user); // ���ڿ� �Է�


		for (int i = 0; i < strlen(user); i++) { 
			for (int j = 0; j < repeat; j++) { 
				printf("%c", user[i]);
			}
		}
		printf("\n");
	}
}