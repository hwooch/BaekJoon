#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 10866 _ ��

// ����
// ������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// ����� �� ���� �����̴�.
// 
// push_front X : ���� X�� ���� �տ� �ִ´�.
// push_back X : ���� X�� ���� �ڿ� �ִ´�.
// pop_front : ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
// pop_back : ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
// size : ���� ����ִ� ������ ������ ����Ѵ�.
// empty : ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
// front : ���� ���� �տ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
// back : ���� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
// 
// �Է�
// ù° �ٿ� �־����� ����� �� N(1 �� N �� 10, 000)�� �־�����.
// ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.
// �־����� ������ 1���� ũ�ų� ����, 100, 000���� �۰ų� ����.
// ������ �������� ���� ����� �־����� ���� ����.
// 
// ���
// ����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

int arr[20002] = { 0, };

int main() {

	int N;
	scanf("%d", &N);
	int size = 0;
	int top = 10001;
	int bot = 10000;

	char command[15];
	int number;

	while (N--) {
		scanf("%s", command);
		if (strcmp(command, "push_front") == 0) {
			scanf("%d", &number);
			arr[top] = number;
			top++;

			size++;
		}
		else if (strcmp(command, "push_back") == 0) {
			scanf("%d", &number);
			arr[bot] = number;
			bot--;

			size++;
		}
		else if (strcmp(command, "pop_front") == 0) {
			if (size > 0) {
				top--;

				printf("%d\n", arr[top]);

				size--;
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp(command, "pop_back") == 0) {
			if (size > 0) {
				bot++;

				printf("%d\n", arr[bot]);

				size--;
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", size);
		}
		else if (strcmp(command, "empty") == 0) {
			if (size == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(command, "front") == 0) {
			if (size > 0) {
				printf("%d\n", arr[top - 1]);
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp(command, "back") == 0) {
			if (size > 0) {
				printf("%d\n", arr[bot + 1]);
			}
			else {
				printf("-1\n");
			};
		}
	}
}