#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 14719 _ ����

// ����
// 2���� ���迡 ����� �׿��ִ�.
// �� ���� ��� ���̿� ������ ���δ�.
// 
// ��� ����� ���� �´�.���̴� ������ �ѷ��� ���ϱ� ?
// 
// �Է�
// ù ��° �ٿ��� 2���� ������ ���� ���� H�� 2���� ������ ���� ���� W�� �־�����. (1 �� H, W �� 500)
// 
// �� ��° �ٿ��� ����� ���� ���̸� �ǹ��ϴ� 0�̻� H������ ������ 2���� ������ �� ���� ��ġ���� ���ʴ�� W�� �־�����.
// 
// ���� ��� ������ �� ������ ���� �� ����.
// �� 2���� ������ �ٴ��� �׻� �����ִٰ� �����Ͽ��� ����.
// 
// ���
// 2���� ���迡���� �� ĭ�� �뷮�� 1�̴�.���̴� ������ �ѷ��� ����Ͽ���.
// 
// ������ ���� ������ ���� ��� 0�� ����Ͽ���.

int sorted[501];
int sorted2[501];

int listx[501];
int listy[501];

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
    int trash;
    int N;
    scanf("%d %d", &trash, &N);

    int maxy = -1;
    int maxx = -1;
    int memoryi = 0;
    for (int i = 0; i < N; i++) {
        listx[i] = i + 1;
        scanf("%d", &listy[i]);
        if (maxy < listy[i]) {
            maxy = listy[i];
            maxx = listx[i];
        }
    }

    //merge_sort(listx, 0, N - 1);


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
            size = top - bot + 1; // ���ӵ� ����
            if (size != 1) {
                // �����ؾ���
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

    //printf("\n\n%d %d", maxx, maxy);

    /*for (int i = 0; i < N; i++) {
        printf("%d %d\n", listx[i], listy[i]);
    }*/

    int tempx;
    int answer = 0;
    int current_max = listy[0];

    for (int i = 0; i < memoryi; i++) {

        tempx = listx[i + 1] - listx[i];
        if (current_max <= listy[i]) {
            current_max = listy[i];
        }
        else {
            answer = answer + tempx * (current_max - listy[i]);
            //printf("%d %d\n", answer,i);
        }
    }
    //printf("\n\n%d\n\n", answer);

    current_max = listy[N - 1];
    for (int i = N - 1; i > memoryi; i--) {

        tempx = listx[i] - listx[i - 1];
        if (current_max <= listy[i]) {
            current_max = listy[i];
        }
        else {
            answer = answer + tempx * (current_max - listy[i]);
            //printf("%d %d\n", answer, i);
        }
    }
    //printf("\n\n%d\n\n", answer);
    printf("%d", answer);
}