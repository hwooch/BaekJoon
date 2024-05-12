#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1026 _ 보물

// 문제
// 옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다.
// 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.
// 
// 길이가 N인 정수 배열 A와 B가 있다.다음과 같이 함수 S를 정의하자.
// 
// S = A[0] × B[0] + ... + A[N - 1] × B[N - 1]
// 
// S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자.
// 단, B에 있는 수는 재배열하면 안 된다.
// 
// S의 최솟값을 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 N이 주어진다.
// 둘째 줄에는 A에 있는 N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 순서대로 주어진다.
// N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.
// 
// 출력
// 첫째 줄에 S의 최솟값을 출력한다.

#define MAX_SIZE 500
int sorted[MAX_SIZE];
int list[MAX_SIZE];
int sorted2[MAX_SIZE];
int list2[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

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

    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &list2[i]);
    }

    merge_sort(list, 0, N - 1);
    merge_sort(list2, 0, N - 1);

    int answer = 0;

    for (int i = 0; i < N; i++) {
        //printf("%d %d\n", list[i], list2[N - 1 - i]);
        answer = answer + list[i] * list2[N - i - 1];
    }

    printf("%d", answer);
}