#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 2304 _ â�� �ٰ���

// ����
// N ���� ���� ����� �Ϸķ� ������ �ִ�.
// ��յ��� ���� ��� 1 m�̸� ���̴� �ٸ� �� �ִ�.
// �� ��յ��� �̿��Ͽ� ��ö�� �� â�� �����Ϸ��� �Ѵ�.
// â���� ��� ����� ����.�� â���� ������ ������ ���� �����.
// 
// ������ ���� �κа� ���� �κ����� �����Ǹ�, ��� ����Ǿ�� �Ѵ�.
// ������ ���� �κ��� �ݵ�� � ����� ����� ��ƾ� �Ѵ�.
// ������ ���� �κ��� �ݵ�� � ����� ����� ��ƾ� �Ѵ�.
// ������ �����ڸ��� ���� ��ƾ� �Ѵ�.
// �� �� �� ���� ������ �ʵ��� ������ � �κе� �����ϰ� �� �κ��� ����� �Ѵ�.
// �׸� 1�� â�� ������ �� ����� �׸� ���̴�.
// �� �׸����� ���� ������ ǥ�õ� �κ��� ���ؿ� �ش�ǰ�, ���ذ� ������ �ѷ����� �ٰ����� â�� ������ �� ����̴�.
// �� �ٰ����� â�� �ٰ����̶�� ����.
// 
// â�� ������ â�� �ٰ����� ������ ���� ���� â�� ����⸦ ���Ѵ�.
// �׸� 1���� â�� �ٰ����� ������ 98 ���̰�, �� ��찡 ���� ���� â�� �ٰ����̴�.
// 
// ��յ��� ��ġ�� ���̰� �־��� ��, ���� ���� â�� �ٰ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù �ٿ��� ����� ������ ��Ÿ���� ���� N�� �־�����.
// N�� 1 �̻� 1, 000 �����̴�.
// �� ���� N ���� �ٿ��� �� �ٿ� �� ����� ���� ���� ��ġ�� ��Ÿ���� ���� L�� ���̸� ��Ÿ���� ���� H�� �� ���� �� ĭ�� ���̿� �ΰ� �־�����.
// L�� H�� �� �� 1 �̻� 1, 000 �����̴�.
// 
// ���
// ù �ٿ� â�� �ٰ����� ������ ��Ÿ���� ������ ����Ѵ�.

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