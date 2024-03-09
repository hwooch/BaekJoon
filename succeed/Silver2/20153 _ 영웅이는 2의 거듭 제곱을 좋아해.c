#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 20153 _ �����̴� 2�� �ŵ� ������ ������!

// ����
// �����̴� 2�� �ŵ������� �����ؼ� A�� �ִ��� ���� ���� 2�� �ŵ������� ������ ǥ���Ѵ�.
// ǥ���� 2�� �ŵ������� ������ 0 �̻��� ���� �ٸ� �����̴�.
// 
// ���� ��� 31�� 5���� ������ ǥ���ȴ�. �츮�� �̰��� �������� ǥ�����̶�� �θ� ���̴�.
// 
// N���� �ڿ��� A1, A2, ..., AN�� �־�����. 
// �� �� �ִ� �� ���� �ڿ����� �����ϰ�, �������� �������� ǥ�������� ��Ÿ����.
// 
// �� �� �� ���� x�� ���� 2x�� Ȧ�� �� �����ϸ� 2x�� ���ϰ�, ¦�� �� �����ϸ� ������ �ʴ´�.
// �̷��� ���� �� ���� �� �ִ� �ִ� ���� 2�� ����϶�.
// 
// �Է�
// ù° �ٿ� �ڿ��� N(1 �� N �� 2, 222, 222)�� �־�����, ��° �ٿ��� N���� �ڿ��� A(1 �� A �� 2, 222, 222)�� �־�����.
// 
// ���
// �ִ��� 2�� �����ؼ� ����Ѵ�.

int sorted[2222223];

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
int user_number[2222223];

int main() {
    int T;
    scanf("%d", &T); // ������ ����
    int user; // �Է¹޴� ����
    int max = -1; // 2������ �ִ� ���� ����
    int answer[22] = { 0, }; // ��� ������ �� ��Ʈ ���� ����

    int count = 0;
    for (int K = 0; K < T; K++) {
        scanf("%d", &user);
        user_number[count++] = user;

        int binary[22] = { 0, };

        int position = 0;
        while (1)
        {
            binary[position] = user % 2;// 2�� �������� �� �������� �迭�� ����
            user = user / 2;// 2�� ���� ���� ����
            position++;// �ڸ��� ����
            if (user == 0)// ���� 0�� �Ǹ� �ݺ��� ����
                break;
        }
        if (max < position) { // �ִ��Ʈ ���� ����
            max = position;
        }
        for (int i = 0; i < position; i++)
        {
            if (binary[i] == 1) {
                answer[i]++;
            }
        }
    }
    merge_sort(user_number, 0, T - 1); // �Է¹��� ������ ����
    int check = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        if (answer[i] % 2 == 0) { // ���߿��� �� ��Ʈ�� ¦���ΰ��� ó�� ������ ���߱�
            check = pow(2, i);
            break;
        }
    }
    int temp = 0;
    int memoryi = 0;
    int sum = 0;
    if (check != 0) { // ¦���� �ִٸ�
        for (int i = 0; i < T; i++) {
            if (user_number[i] >= check) { // ó�� ���°ͺ��� ũ�Ű� ������ ���ö����� ������Ű��
                memoryi = i; // i�� ����
                break;
            }
        }
    }
    else { // ¦���� ���ٸ� �ٷ� ���
        for (int i = 0; i < max; i++) {
            if (answer[i] % 2 == 1) {
                sum = sum + pow(2, i);
            }
        }
        printf("%d%d", sum, sum);
        return 0;
    }
    int asdf = pow(2, max); // �ִ� ��Ʈ����ŭ ���� max�� 3�̾��ٸ� 2��3������ 8���� �˻��Ѵ�.
    int max_answer = 0;
    while ((user_number[memoryi] <= asdf) && (memoryi < T)) {
        sum = 0;
        int binary[22] = { 0, };
        int position = 0;
        temp = user_number[memoryi];
        while (1)
        {
            binary[position] = temp % 2;    // 2�� �������� �� �������� �迭�� ����
            temp = temp / 2;             // 2�� ���� ���� ����
            position++;    // �ڸ��� ����
            if (temp == 0)    // ���� 0�� �Ǹ� �ݺ��� ����
                break;
        }

        for (int i = 0; i < max; i++)
        {
            if (binary[i] == 1) { // ������ ���ڰ� �ִٸ� �� �Ŀ�
                answer[i]--;
            }
            if (answer[i] % 2 == 1) { // Ȧ���� ���ڵ��� �� ����
                sum = sum + pow(2, i);
            }
            if (binary[i] == 1) { // �������·� ����
                answer[i]++;
            }
        }
        if (max_answer < sum) {
            max_answer = sum;
        }
        memoryi++;
    }

    sum = 0;
    for (int i = 0; i < max; i++)
    {
        if (answer[i] % 2 == 1) { // ��� ���� ���ڰ� Ȧ���ΰ͵��� �� ����
            sum = sum + pow(2, i); // �ƹ� ���ڵ� ���������� �ִ밪������ �˻�
        }
    }
    if (max_answer < sum) {
        max_answer = sum;
    }
    printf("%d%d", max_answer, max_answer);
}