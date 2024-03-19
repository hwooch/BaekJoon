#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 16200 _ ��Ŀ��

// ����
// �˹�Ʈ�� �ٴϴ� �б����� �� ��Ŀ���� ������.�� ��Ŀ�濡�� N���� �л��� ���� �ǻ縦 ������.
// ���ǻ� �л��� ��ȣ�� �Ű��, ��ȣ�� 1���� N�����̴�.
// 
// ��Ŀ�濡 �����ϴ� N���� �� ���� ������ ������ �ϴµ�, ��ȸ ���� �������� ���� ������ �ּҷ� �ϰ�;� �Ѵ�.
// ��, i�� �л��� �ڽ��� ���� ���� ���� ���� �ڱ� �ڽ��� �����ؼ� Xi�� ������ ���� �����Ѵٰ� �Ѵ�.
// ���� ���� ���� �ǻ縦 ���� N���� ��� ������ �� �ֵ��� ���� ������ �����̸�, �� �� ���� ���� �ּҷ� �Ϸ��� �Ѵ�.
// 
// ���� ������ ��� �����ϰ� ���� ������ �Ѵ�.
// 
// �� �л��� �ϳ��� ���� �ҼӵǾ�� �Ѵ�.
// �� ���� �ּ� �� ���� �л��� �����Ѵ�.
// ��� i�� ���ؼ�, i�� �л��� ���� ���� ���� ���� Xi�� �����̾�� �Ѵ�.
// ���� ������ �����ϸ鼭 N���� ������ ������ ��, ���� ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ��� �л��� �� N(1 �� N �� 100, 000)�� �־�����.
// 
// ��° �ٿ��� N���� ������ �־�����, ������� X1, X2, ..., XN�� �ǹ��Ѵ�.��� i�� ���ؼ�, 1 �� Xi �� N�� �����Ѵ�.
// 
// ���
// ù° �ٿ� ���� ���� �ּڰ��� ����Ѵ�.

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