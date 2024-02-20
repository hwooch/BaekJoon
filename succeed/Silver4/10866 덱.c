#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 10866 _ 덱

// 문제
// 정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 
// 명령은 총 여덟 가지이다.
// 
// push_front X : 정수 X를 덱의 앞에 넣는다.
// push_back X : 정수 X를 덱의 뒤에 넣는다.
// pop_front : 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// pop_back : 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// size : 덱에 들어있는 정수의 개수를 출력한다.
// empty : 덱이 비어있으면 1을, 아니면 0을 출력한다.
// front : 덱의 가장 앞에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// back : 덱의 가장 뒤에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// 
// 입력
// 첫째 줄에 주어지는 명령의 수 N(1 ≤ N ≤ 10, 000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
// 주어지는 정수는 1보다 크거나 같고, 100, 000보다 작거나 같다.
// 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
// 
// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

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