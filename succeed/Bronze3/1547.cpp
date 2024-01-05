#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//�����̴� �� 3���� Ź�� ���� �Ϸķ� ������Ҵ�.
// ���� ��ȣ�� �� ���� �ź��� ������� 1��, 2�� 3���̰�, �����̴� �� ���� �̿��ؼ� ������ �Ϸ��� �Ѵ�.
//
//���� 1�� ���� �Ʒ��� ���� �ϳ� �ִ´�.�����̴� �� ���� ���� ����, �� ��ġ�� �¹ٲٷ��� �Ѵ�.
// ���� ���, ���� ���� 1���� 2���̶��, 1�� ���� �ִ� ��ġ�� 2�� ���� �̵���Ű��, ���ÿ� 2�� ���� �ִ� ��ġ�� 1�� ���� �̵����Ѿ� �Ѵ�.
// �̶� ���� �������� �ʱ� ������, ���� ��ġ�� �� ó�� 1�� ���� �ִ� ��ġ�� ����.
//
//�����̴� ���� ��ġ�� �� M�� �ٲ� ���̸�, ���� ��ġ�� �ٲ� ����� �Է����� �־�����.
// ��ġ�� M�� �ٲ� ���Ŀ� ���� ����ִ� ���� ��ȣ�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ���� ��ġ�� �ٲ� Ƚ�� M�� �־�����, M�� 50���� �۰ų� ���� �ڿ����̴�.
// ��° �ٺ��� M���� �ٿ��� ���� ��ġ�� �ٲ� ��� X�� Y�� �־�����, X�� �Ű� Y�� ���� ��ġ�� ���� �ٲٴ� ���� �ǹ��Ѵ�.
// X�� Y�� ���� 3���� �۰ų� ����, X�� Y�� ���� ���� �ִ�.
//
//���� �̵���Ų �Ŀ� ���� �� �ٱ��� �ִ� ���� ����.
//
//���
//ù° �ٿ� ���� ����ִ� ���� ��ȣ�� ����Ѵ�.���� ������� �� �ؿ� ���� ��쿡�� - 1�� ����Ѵ�.

void swap(int user1, int user2, int cup[]) {
	int temp;
	temp = cup[user1 - 1];
	cup[user1 - 1] = cup[user2 - 1];
	cup[user2 - 1] = temp;
}

// ���̵��
//���� �ű�ٰ� ������ ������ �Ǿ������� �ᱹ ���� �Űܵ� �Ȱ��� ����� ���� �ȴ�.
//cup�迭���� 0 �̸� ���̾��°�, 1�̸� ���� ������ �ִ� ���̴�.
//���� �� �ΰ��� �����Ͽ����� ���� ���ΰ� ���� �Űܵ� ���� �ű�� �Ͱ� �Ȱ���.
//swap �Լ��� ���� cup�� �迭���� ���� �ٲ۴ٸ� �Ÿ� �ű�� ȿ���� �� �� �ִ�.
//�������� ���� ������ �ִ� �� cup�� �迭���� 1�� ��쿡�� ����Ѵٸ� ������ Ȯ���� �� �ִ�.

int main() {
	int cup[3] = { 1,0,0 }; // 1�� ���� ��Ÿ��

	int T; // ����� �Է��� ���� ������

	int user1, user2; // ���� ��ȣ�� ��Ÿ��

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &user1);
		scanf("%d", &user2);
		swap(user1, user2, cup);
	}
	for (int i = 0; i < 3; i++) {
		if (cup[i] == 1) {
			printf("%d", i + 1);
		}
	}
}