#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 27866 _ ���ڿ� ���ڿ�

// ����
// �ܾ� S�� ���� i�� �־����� ��, S�� i��° ���ڸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� ���� �ҹ��ڿ� �빮�ڷθ� �̷���� �ܾ� S�� �־�����.�ܾ��� ���̴� �ִ� 1000�̴�.
// ��° �ٿ� ���� i�� �־�����. ( 1 <= i <= |s| )
//
//	���
//
//	S��	i��° ���ڸ� ����Ѵ�.


int main() {
	char user[1001];
	scanf("%s", user);

	int number;
	scanf("%d", &number);

	printf("%c", user[number - 1]);
}