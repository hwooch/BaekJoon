#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1212 _ 8���� 2����

// ����
// 8������ �־����� ��, 2������ ��ȯ�ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� 8������ �־�����.�־����� ���� ���̴� 333, 334�� ���� �ʴ´�.
// 
// ���
// ù° �ٿ� �־��� ���� 2������ ��ȯ�Ͽ� ����Ѵ�.
//  ���� 0�� ��츦 �����ϰ�� �ݵ�� 1�� �����ؾ� �Ѵ�.

int main() {
	char user[333335];
	scanf("%s", &user);

	for (int i = 0; user[i] != '\0'; i++) {
		switch (user[i])
		{
		case '0': if (i == 0) { printf(""); break; }
				else { printf("000"); break; }
		case '1': if (i == 0) { printf("1"); break; }
				else { printf("001"); break; }
		case '2': if (i == 0) { printf("10"); break; }
				else { printf("010"); break; }
		case '3': if (i == 0) { printf("11"); break; }
				else { printf("011"); break; }
		case '4': printf("100"); break;
		case '5': printf("101"); break;
		case '6': printf("110"); break;
		case '7': printf("111"); break;
		}
	}
	if (strlen(user) == 1 && user[0] == '0') {
		printf("0");
	}

}