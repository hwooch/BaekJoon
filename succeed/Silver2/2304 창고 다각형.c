#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 2304 _ 창고 다각형

// 문제
// N 개의 막대 기둥이 일렬로 세워져 있다.
// 기둥들의 폭은 모두 1 m이며 높이는 다를 수 있다.
// 이 기둥들을 이용하여 양철로 된 창고를 제작하려고 한다.
// 창고에는 모든 기둥이 들어간다.이 창고의 지붕을 다음과 같이 만든다.
// 
// 지붕은 수평 부분과 수직 부분으로 구성되며, 모두 연결되어야 한다.
// 지붕의 수평 부분은 반드시 어떤 기둥의 윗면과 닿아야 한다.
// 지붕의 수직 부분은 반드시 어떤 기둥의 옆면과 닿아야 한다.
// 지붕의 가장자리는 땅에 닿아야 한다.
// 비가 올 때 물이 고이지 않도록 지붕의 어떤 부분도 오목하게 들어간 부분이 없어야 한다.
// 그림 1은 창고를 옆에서 본 모습을 그린 것이다.
// 이 그림에서 굵은 선으로 표시된 부분이 지붕에 해당되고, 지붕과 땅으로 둘러싸인 다각형이 창고를 옆에서 본 모습이다.
// 이 다각형을 창고 다각형이라고 하자.
// 
// 창고 주인은 창고 다각형의 면적이 가장 작은 창고를 만들기를 원한다.
// 그림 1에서 창고 다각형의 면적은 98 ㎡이고, 이 경우가 가장 작은 창고 다각형이다.
// 
// 기둥들의 위치와 높이가 주어질 때, 가장 작은 창고 다각형의 면적을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫 줄에는 기둥의 개수를 나타내는 정수 N이 주어진다.
// N은 1 이상 1, 000 이하이다.
// 그 다음 N 개의 줄에는 각 줄에 각 기둥의 왼쪽 면의 위치를 나타내는 정수 L과 높이를 나타내는 정수 H가 한 개의 빈 칸을 사이에 두고 주어진다.
// L과 H는 둘 다 1 이상 1, 000 이하이다.
// 
// 출력
// 첫 줄에 창고 다각형의 면적을 나타내는 정수를 출력한다.

int sorted[1001];
int sorted2[1001];

int listx[1001];
int listy[1001];

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

    int maxy = -1;
    int maxx = -1;
    int memoryi = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &listx[i], &listy[i]);
        if (maxy < listy[i]) {
            maxy = listy[i];
            maxx = listx[i];
        }
    }

    merge_sort(listx, 0, N - 1);

    int check = listx[0];

    int top = 0;
    int bot = 0;
    int size;

    for (int i = 1; i < N; i++) {
        //printf("%d %d\n", listx[i], listy[i]);

        if (listx[top] == listx[i]) {
            top = i;
        }
        else {
            size = top - bot + 1;
            if (size != 1) {
                merge_sort2(listy, bot, top);
            }
            top = i;
            bot = i;
        }
    }
    size = top - bot + 1;
    if (size != 1) {
        merge_sort2(listy, bot, top);
    }

    for (int i = 0; i < N; i++) {
        //printf("%d %d\n", listx[i], listy[i]);
        if (listx[i] == maxx && listy[i] == maxy) {
            memoryi = i;
        }
    }
    //printf("\n%d %d", maxx, maxy);

    int tempx;
    int answer = 0;
    int current_max = listy[0];

    for (int i = 0; i < memoryi; i++) {

        tempx = listx[i + 1] - listx[i];
        if (current_max < listy[i]) {
            current_max = listy[i];
        }

        answer = answer + tempx * current_max;
    }
    //printf("\n%d\n", answer);

    current_max = listy[N - 1];
    for (int i = N - 1; i > memoryi; i--) {

        tempx = listx[i] - listx[i - 1];
        if (current_max < listy[i]) {
            current_max = listy[i];
        }

        answer = answer + tempx * current_max;
    }
    //printf("\n%d\n", answer);
    answer = answer + maxy;
    printf("%d", answer);
}