#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 17390 _ 이건 꼭 풀어야 해!

// 숭실골 높은 언덕 깊은 골짜기에 출제로 고통 받는 욱제가 살고 있다!
// 
// 욱제는 또 출제를 해야 해서 단단히 화가 났다.
// 그래서 욱제는 길이 N짜리 수열 A를 만들고, A를 비내림차순으로 정렬해서 수열 B를 만들어 버렸다!!
// 여기서 B를 출력하기만 하면 문제가 너무 쉬우니까 하나만 더 하자. 아래와 같은 질문이 무려 Q개나 주어진다!!(ㅎㅎ;; ㅈㅅ..ㅋㅋ!!)
// 
// L R : BL + BL + 1 + ... + BR - 1 + BR 을 출력한다.
// 욱제의 질문에 답하고 함께 엠티를 떠나자!!
// 
// 입력
// 첫 번째 줄에 수열 A의 길이 N과 질문의 개수 Q가 공백으로 구분되어 주어진다. (1 ≤ N, Q ≤ 300, 000)
// 
// 두 번째 줄에 N개의 정수 A1, A2, ..., AN 이 공백으로 구분되어 주어진다.Ai 는 수열 A의 i 번째 수이다. (1 ≤ Ai ≤ 1, 000)
// 
// 세 번째 줄부터 Q개의 줄에 걸쳐 욱제의 질문을 의미하는 두 수 L, R이 공백으로 구분되어 주어진다. (1 ≤ L ≤ R ≤ N)
// 
// 주어지는 모든 입력은 자연수이다.
// 
// 출력
// Q개의 줄에 걸쳐, 질문의 답을 순서대로 각각 출력한다.

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

// 합병 정렬
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