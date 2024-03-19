#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 16200 _ 해커톤

// 문제
// 알버트가 다니는 학교에서 곧 해커톤이 열린다.이 해커톤에는 N명의 학생이 참가 의사를 밝혔다.
// 편의상 학생에 번호를 매겼고, 번호는 1부터 N까지이다.
// 
// 해커톤에 참가하는 N명을 몇 개의 팀으로 나눠야 하는데, 대회 주최 측에서는 팀의 개수를 최소로 하고싶어 한다.
// 단, i번 학생은 자신이 속한 팀의 팀원 수가 자기 자신을 포함해서 Xi명 이하일 때만 참가한다고 한다.
// 주최 측은 참가 의사를 밝힌 N명이 모두 참여할 수 있도록 팀을 배정할 생각이며, 이 때 팀의 수를 최소로 하려고 한다.
// 
// 다음 조건을 모두 만족하게 팀을 만들어야 한다.
// 
// 한 학생은 하나의 팀에 소속되어야 한다.
// 각 팀은 최소 한 명의 학생을 포함한다.
// 모든 i에 대해서, i번 학생이 속한 팀의 팀원 수는 Xi명 이하이어야 한다.
// 위의 조건을 만족하면서 N명을 팀으로 나눴을 때, 팀의 수의 최솟값을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에는 학생의 수 N(1 ≤ N ≤ 100, 000)이 주어진다.
// 
// 둘째 줄에는 N개의 정수가 주어지고, 순서대로 X1, X2, ..., XN을 의미한다.모든 i에 대해서, 1 ≤ Xi ≤ N을 만족한다.
// 
// 출력
// 첫째 줄에 팀의 수의 최솟값을 출력한다.

int list[100000];
int sorted[100000];
int trash[100000];

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

    merge_sort(list, 0, N - 1);

    int count = 0;
    int standard = list[0];
    int team = 0;
    int check = 0;

    for (int i = 0; i < N; i++) {
        if (standard == list[i]) {
            count++;
            if (count == standard) {
                count = 0;
                team++;
            }
        }
        if (standard != list[i]) {
            if (count != 0) {
                for (int j = i - count; j < i; j++) {
                    trash[check] = list[j];
                    check++;
                }
            }
            standard = list[i];
            count = 1;
        }
    }
    if (count != 0) {
        for (int j = N - count; j < N; j++) {
            trash[check] = list[j];
            check++;
        }
    }
    int answer_check = 0;
    for (int i = 0; i < check; i++) {
        answer_check = 1;
        if ((i + trash[i] - 1) < check) {
            i = i + trash[i] - 1;
            team++;
            if (i == check - 1) {
                answer_check = 0;
            }
        }
    }
    if (answer_check == 1) {
        team++;
    }
    printf("%d", team);
    return 0;
}