#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1026 _ ����

// ����
// ���� ������ ������ �׻� ū ��ĩ�Ÿ����� ���� �־���.
// �� ������ ���� �������� ������ ���� ������ ���� ū ����� �ɾ���.
// 
// ���̰� N�� ���� �迭 A�� B�� �ִ�.������ ���� �Լ� S�� ��������.
// 
// S = A[0] �� B[0] + ... + A[N - 1] �� B[N - 1]
// 
// S�� ���� ���� �۰� ����� ���� A�� ���� ��迭����.
// ��, B�� �ִ� ���� ��迭�ϸ� �� �ȴ�.
// 
// S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� N�� �־�����.
// ��° �ٿ��� A�� �ִ� N���� ���� ������� �־�����, ��° �ٿ��� B�� �ִ� ���� ������� �־�����.
// N�� 50���� �۰ų� ���� �ڿ����̰�, A�� B�� �� ���Ҵ� 100���� �۰ų� ���� ���� �ƴ� �����̴�.
// 
// ���
// ù° �ٿ� S�� �ּڰ��� ����Ѵ�.

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