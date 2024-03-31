#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 11650 _ 좌표 정렬하기

// 문제
// 2차원 평면 위의 점 N개가 주어진다.
// 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 점의 개수 N(1 ≤ N ≤ 100, 000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. 
// (-100, 000 ≤ xi, yi ≤ 100, 000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
// 
// 출력
// 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

int sorted[100001];
int sorted2[100001];

int listx[100001];
int listy[100001];

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            sorted2[k] = listy[i];
            sorted[k++] = list[i++];
        }

        else {
            sorted2[k] = listy[j];
            sorted[k++] = list[j++];
        }
    }

    if (i > mid) {
        for (l = j; l <= right; l++) {
            sorted2[k] = listy[l];
            sorted[k++] = list[l];
        }
    }
    else {
        for (l = i; l <= mid; l++) {
            sorted2[k] = listy[l];
            sorted[k++] = list[l];
        }
    }

    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
        listy[l] = sorted2[l];
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

void merge2(int list[], int left, int mid, int right) {
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

void merge_sort2(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort2(list, left, mid);
        merge_sort2(list, mid + 1, right);
        merge2(list, left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &listx[i], &listy[i]);
    }

    merge_sort(listx, 0, N - 1);


    int check = listx[0];

    int top = 0;
    int bot = 0;
    int size;

    for (int i = 1; i < N; i++) {
        if (listx[top] == listx[i]) {
            top = i;
        }
        else {
            size = top - bot + 1; // 연속된 숫자 개수
            if (size != 1) { // 숫자가 바뀌었을때 그 전의 숫자의 개수가 1이 아니라면
                merge_sort2(listy, bot, top); // 그 숫자들에 대해서 정렬
            }
            top = i;
            bot = i;

        }

    }
    size = top - bot + 1; // 반복문이 끝나고 마지막 숫자에 대해서도 판단해서 정렬
    if (size != 1) {
        merge_sort2(listy, bot, top);
    }
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", listx[i], listy[i]);
    }
}