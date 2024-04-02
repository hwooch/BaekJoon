#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 9237 _ 이장님 초대

// 문제
// 농부 상근이는 마당에 심기 위한 나무 묘목 n개를 구입했다.
// 묘목 하나를 심는데 걸리는 시간은 1일이고, 상근이는 각 묘목이 다 자라는데 며칠이 걸리는지 정확하게 알고 있다.
// 
// 상근이는 마을 이장님을 초대해 자신이 심은 나무를 자랑하려고 한다.
// 이장님을 실망시키면 안되기 때문에, 모든 나무가 완전히 자란 이후에 이장님을 초대하려고 한다.
// 즉, 마지막 나무가 다 자란 다음날 이장님을 초대할 것이다.
// 
// 상근이는 나무를 심는 순서를 신중하게 골라 이장님을 최대한 빨리 초대하려고 한다.
// 이장님을 며칠에 초대할 수 있을까 ?
// 
// 입력
// 입력은 두 줄로 이루어져 있다.
// 첫째 줄에는 묘목의 수 N(1 ≤ N ≤ 100, 000)이 주어진다.
// 둘째 줄에는 각 나무가 다 자라는데 며칠이 걸리는지를 나타낸 ti가 주어진다. (1 ≤ t_i ≤ 1, 000, 000)
// 
// 출력
// 첫째 줄에 며칠에 이장님을 초대할 수 있는지 출력한다.
// 답이 여러 가지인 경우에는 가장 작은 값을 출력한다.묘목을 구입한 날이 1일이다.

int list[101000];

int sorted[101000]; // 추가적인 공간이 필요
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
    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }
    merge_sort(list, 0, N - 1);

    int count = 1;
    for (int i = N - 1; i >= 0; i--) {
        list[i] = list[i] + count++;
        //printf("%d ", list[i]);
    }

    int max = list[0];
    for (int i = 1; i < N; i++) {
        if (max < list[i]) {
            max = list[i];
        }
    }
    printf("%d", max + 1);
}