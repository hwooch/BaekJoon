#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 11650 _ ��ǥ �����ϱ�

// ����
// 2���� ��� ���� �� N���� �־�����.
// ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ���� ���� N(1 �� N �� 100, 000)�� �־�����.
// ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. 
// (-100, 000 �� xi, yi �� 100, 000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.
// 
// ���
// ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.

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
            size = top - bot + 1; // ���ӵ� ���� ����
            if (size != 1) { // ���ڰ� �ٲ������ �� ���� ������ ������ 1�� �ƴ϶��
                merge_sort2(listy, bot, top); // �� ���ڵ鿡 ���ؼ� ����
            }
            top = i;
            bot = i;

        }

    }
    size = top - bot + 1; // �ݺ����� ������ ������ ���ڿ� ���ؼ��� �Ǵ��ؼ� ����
    if (size != 1) {
        merge_sort2(listy, bot, top);
    }
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", listx[i], listy[i]);
    }
}