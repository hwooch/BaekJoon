#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1049 _ ��Ÿ��

// ����
// Day Of Mourning�� ��Ÿ����Ʈ ���䰡 ����ϴ� ��Ÿ���� N���� ���� ��������.
// ���� ���ο� ���� ��ų� ��ü�ؾ� �Ѵ�. ����� �ǵ����̸� ���� ���� ������ �Ѵ�. 
// 6�� ��Ű���� �� ���� �ְ�, 1�� �Ǵ� �� �̻��� ���� ������ �� ���� �ִ�.
// 
// ������ ��Ÿ���� ���� N�� ��Ÿ�� �귣�� M���� �־�����, 
// ������ �귣�忡�� �Ĵ� ��Ÿ�� 6���� ����ִ� ��Ű���� ����, ������ �� ���� ������ �־��� ��, 
// ��� N���� ��� ���� �ʿ��� ���� ���� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� N�� M�� �־�����.
// N�� 100���� �۰ų� ���� �ڿ����̰�, M�� 50���� �۰ų� ���� �ڿ����̴�.
// ��° �ٺ��� M���� �ٿ��� �� �귣���� ��Ű�� ���ݰ� ������ ������ �������� �����Ͽ� �־�����.
// ������ 0���� ũ�ų� ����, 1, 000���� �۰ų� ���� �����̴�.
// 
// ���
// ù° �ٿ� ��Ÿ���� ��� N�� ��� ���� �ʿ��� ���� �ּڰ��� ����Ѵ�.

int main() {
	int N, M;
	scanf("%d %d", &N, &M);


	int store_bundle[50];
	int store_each[50];
	int min_bundle = 1001;
	int min_each = 1001;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &store_bundle[i], &store_each[i]);
		if (min_bundle > store_bundle[i]) {
			min_bundle = store_bundle[i];
		}
		if (min_each > store_each[i]) {
			min_each = store_each[i];
		}
	}

	int count = 0;
	int answer = 0;

	if (min_each * 6 < min_bundle) { // ���� ���� 6���� �������� �δٸ�

		printf("%d", min_each * N); // ������ �� ���
	}
	else { // ���� 6���� �������� �Ѱ� ���ٸ�

		// �ϴ� ���� �� �������� �ִ��� ���� ��� 
		while (N >= 6) {
			count++;
			N = N - 6;
		}
		answer = count * min_bundle;

		// �� ���� ���Ͻ� ������������ �������� ������ �������� ���Ѵ�

		if (N * min_each < min_bundle) { // ���� ������ �� ���� �� �δٸ�
			answer = answer + N * min_each;
		}
		else { // �׷��� �ʴٸ� �������� ���
			answer = answer + min_bundle;
		}
		printf("%d", answer);
	}
}