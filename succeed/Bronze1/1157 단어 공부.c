#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1157 _ �ܾ� ����

// ����
// ���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
// ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.
//
// �Է�
// ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����.�־����� �ܾ��� ���̴� 1, 000, 000�� ���� �ʴ´�.
//
// ���
// ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�.
// ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ? �� ����Ѵ�.

char user[1000001];

int main() {
	int alpha[26];
	scanf("%s", &user);

	for (int i = 0; i < 26; i++) {
		alpha[i] = 0; // ���ĺ� �󵵼� �迭
	}

	int len = strlen(user);

	for (int i = 0; i < len; i++) {
		if ('a' <= user[i] && user[i] <= 'z') { // �ҹ��ڶ��
			alpha[user[i] - 'a']++;
		}
		else if ('A' <= user[i] && user[i] <= 'Z') { // �׷��� �ʰ� �빮�ڶ��
			alpha[user[i] - 'A']++;
		}
	}


	int max = 0; // �迭�� �ְ�
	int check = 0;
	int memoryi = 0;

	for (int i = 0; i < 26; i++) { // ���ĺ� �迭�� �ݺ��ϸ鼭
		if (max < alpha[i]) { // �ְ��� �� ū�� ���Դٸ�
			max = alpha[i];  // ���� �Ŀ�
			check = 0;     // �ְ��� �ߺ������� �˻��� �� �ִ� ����
			memoryi = i; // ���ĺ� ����
		}
		else if (max == alpha[i]) { // �� ũ�� �ʰ� �ְ��� �Ȱ��ٸ�
			check++; // �ߺ����� �߰�
		}
	}

	if (check > 0) { // �ߺ��� �־��ٸ� ? ���
		printf("?");
	}
	else { // �ߺ��� �����ٸ� ���ĺ� ���
		printf("%c", memoryi + 65);
	}
}