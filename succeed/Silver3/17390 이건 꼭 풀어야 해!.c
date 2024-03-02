#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 17390 _ �̰� �� Ǯ��� ��!

// ���ǰ� ���� ��� ���� ��¥�⿡ ������ ���� �޴� ������ ��� �ִ�!
// 
// ������ �� ������ �ؾ� �ؼ� �ܴ��� ȭ�� ����.
// �׷��� ������ ���� N¥�� ���� A�� �����, A�� �񳻸��������� �����ؼ� ���� B�� ����� ���ȴ�!!
// ���⼭ B�� ����ϱ⸸ �ϸ� ������ �ʹ� ����ϱ� �ϳ��� �� ����. �Ʒ��� ���� ������ ���� Q���� �־�����!!(����;; ����..����!!)
// 
// L R : BL + BL + 1 + ... + BR - 1 + BR �� ����Ѵ�.
// ������ ������ ���ϰ� �Բ� ��Ƽ�� ������!!
// 
// �Է�
// ù ��° �ٿ� ���� A�� ���� N�� ������ ���� Q�� �������� ���еǾ� �־�����. (1 �� N, Q �� 300, 000)
// 
// �� ��° �ٿ� N���� ���� A1, A2, ..., AN �� �������� ���еǾ� �־�����.Ai �� ���� A�� i ��° ���̴�. (1 �� Ai �� 1, 000)
// 
// �� ��° �ٺ��� Q���� �ٿ� ���� ������ ������ �ǹ��ϴ� �� �� L, R�� �������� ���еǾ� �־�����. (1 �� L �� R �� N)
// 
// �־����� ��� �Է��� �ڿ����̴�.
// 
// ���
// Q���� �ٿ� ����, ������ ���� ������� ���� ����Ѵ�.

int arr[300001] = { 0, };
int temp[300001] = { 0, };
int sum[300001] = { 0, };

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			temp[k++] = list[i++];
		else
			temp[k++] = list[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			temp[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			temp[k++] = list[l];
	}

	for (l = left; l <= right; l++) {
		list[l] = temp[l];
	}
}

// �պ� ����
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}


int main() {


	int N;
	scanf("%d", &N);

	int T;
	scanf("%d", &T);


	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, N - 1);

	sum[1] = arr[0];
	for (int i = 2; i < N + 1; i++) {
		sum[i] = arr[i - 1] + sum[i - 1];
	}

	int x, y;
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", sum[y] - sum[x - 1]);
	}
}