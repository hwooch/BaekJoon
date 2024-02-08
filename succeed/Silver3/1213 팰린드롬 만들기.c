#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1213 _ �Ӹ���� �����

// ����
// ���Ѽ��� �ӹ����� ���� ����ϴ� �����̴�.
// 
// ���Ѽ��� ���󿡼� �Ӹ������ ���ڿ��� �ʹ� �����ϱ� ������, ���� ������ ����ؼ� �ӹ����� �Ӹ������ �������ַ��� �Ѵ�.
// 
// �ӹ����� ���Ѽ��� ���� �̸����� �Ӹ������ ������� �ϴµ�, ���Ѽ��� ���� �̸��� ���ĺ� ������ ������ �ٲ㼭 �Ӹ������ ������� �Ѵ�.
// 
// �ӹ����� ���� ���Ѽ��� ���� �̸��� �Ӹ�������� �ٲٴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ���Ѽ��� ���� �̸��� �ִ�.���ĺ� �빮�ڷθ� �� �ִ� 50�����̴�.
// 
// ���
// ù° �ٿ� ������ ������ ����Ѵ�.
// ���� �Ұ����� ���� "I'm Sorry Hansoo"�� ����Ѵ�.������ ���� ���� ��쿡�� ���������� �ռ��� ���� ����Ѵ�.

int main() {
	char name[51];
	int alpha[26] = { 0, };
	char answer_name[51];
	scanf("%s", name);

	int len = strlen(name);

	for (int i = 0; i < len; i++) {
		alpha[name[i] - 'A']++;
	}

	int count = 0;
	int wrong_count = 0;
	if (len % 2 == 1) { // ���̰� Ȧ�����
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 == 1) { // ���ĺ� ������ Ȧ���ΰ��� �߰����ٰ� ����
				wrong_count++;
				answer_name[len / 2] = i + 'A';
				alpha[i]--; // Ȧ�������� �Ѱ��� ���������� 1�� ��
			}
			if (alpha[i] % 2 == 0) { // ���ĺ� ������ ¦�������
				for (int j = 0; j < alpha[i] / 2; j++) { // �� ���� ����
					answer_name[count] = i + 'A';
					answer_name[len - count - 1] = i + 'A';
					count++;
				}
			}
			if (wrong_count > 1) {
				printf("I'm Sorry Hansoo"); // ���� ���ĺ� ���� �߿� Ȧ���� 2�� �̻��̸� ��Ī�� ������� ����
				return 0;
			}
		}
	}
	else { // ���̰� ¦������
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 == 0) { // ���ĺ� ������ ¦�������
				for (int j = 0; j < alpha[i] / 2; j++) { // �� ���� ����
					answer_name[count] = i + 'A';
					answer_name[len - count - 1] = i + 'A';
					count++;
				}
			}
			else if (alpha[i] % 2 == 1) {
				printf("I'm Sorry Hansoo"); // ���� ���ĺ� ���� �߿� Ȧ���� ���´ٸ� ��Ī �Ұ�
				return 0;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%c", answer_name[i]);
	}
}