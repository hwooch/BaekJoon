#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// 9237 _ ����� �ʴ�

// ����
// ��� ����̴� ���翡 �ɱ� ���� ���� ���� n���� �����ߴ�.
// ���� �ϳ��� �ɴµ� �ɸ��� �ð��� 1���̰�, ����̴� �� ������ �� �ڶ�µ� ��ĥ�� �ɸ����� ��Ȯ�ϰ� �˰� �ִ�.
// 
// ����̴� ���� ������� �ʴ��� �ڽ��� ���� ������ �ڶ��Ϸ��� �Ѵ�.
// ������� �Ǹ���Ű�� �ȵǱ� ������, ��� ������ ������ �ڶ� ���Ŀ� ������� �ʴ��Ϸ��� �Ѵ�.
// ��, ������ ������ �� �ڶ� ������ ������� �ʴ��� ���̴�.
// 
// ����̴� ������ �ɴ� ������ �����ϰ� ��� ������� �ִ��� ���� �ʴ��Ϸ��� �Ѵ�.
// ������� ��ĥ�� �ʴ��� �� ������ ?
// 
// �Է�
// �Է��� �� �ٷ� �̷���� �ִ�.
// ù° �ٿ��� ������ �� N(1 �� N �� 100, 000)�� �־�����.
// ��° �ٿ��� �� ������ �� �ڶ�µ� ��ĥ�� �ɸ������� ��Ÿ�� ti�� �־�����. (1 �� t_i �� 1, 000, 000)
// 
// ���
// ù° �ٿ� ��ĥ�� ������� �ʴ��� �� �ִ��� ����Ѵ�.
// ���� ���� ������ ��쿡�� ���� ���� ���� ����Ѵ�.������ ������ ���� 1���̴�.

int list[101000];

int sorted[101000]; // �߰����� ������ �ʿ�
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
    // �պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
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