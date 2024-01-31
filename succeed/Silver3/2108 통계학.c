#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 2108 _ �����

// ����
// ���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�.
// ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�.
// ��, N�� Ȧ����� ��������.
// 
// ������ : N���� ������ ���� N���� ���� ��
// �߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
// �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
// ���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
// N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ���� ���� N(1 �� N �� 500, 000)�� �־�����. ��, N�� Ȧ���̴�.
// �� ���� N���� �ٿ��� �������� �־�����. �ԷµǴ� ������ ������ 4, 000�� ���� �ʴ´�.
// 
// ���
// ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.
// 
// ��° �ٿ��� �߾Ӱ��� ����Ѵ�.
// 
// ��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
// 
// ��° �ٿ��� ������ ����Ѵ�.

int number[500000];
int count[8001] = { 0, };

//�� ���Ŀ� �ʿ��� ��������
void shell_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}
//�� ����
void shell_sort(int list[], int n) {
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) {
            gap++;
        }
        for (i = 0; i < gap; i++) {
            shell_insertion_sort(list, i, n - 1, gap);
        }
    }
}


int main() {
    int N;
    scanf("%d", &N);

    double sum = 0;
    int min = 5000;
    int max = -5000;
    int countmax = 0;
    int check = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &number[i]);
        sum += number[i];
        if (number[i] < min) {
            min = number[i];
        }
        if (number[i] > max) {
            max = number[i];
        }
        count[number[i] + 4000]++;
    }
    for (int i = 0; i < 8001; i++) {
        if (countmax < count[i]) {
            countmax = count[i]; // �󵵼� ���� ū�� ����
        }
    }
    int rememberi = 0;

    for (int i = 0; i < 8001; i++) {
        if (countmax == count[i]) { // �󵵼��� �Ȱ��ٸ�
            rememberi = i; // i ��� (���� �ϳ���� i����ؾ��ϹǷ�)
            check++; // ���� ū �󵵼��� ���� Ƚ��
        }
        if (check == 2) { // ���� �ι�°���
            rememberi = i; // �ι�°�� ���� i ���
            break;
        }

    }
    shell_sort(number, N); // �� ����

    printf("%d\n", (int)round(sum / N)); // �ϼ�
    printf("%d\n", number[N / 2]); // �ϼ�
    printf("%d\n", rememberi - 4000);
    printf("%d\n", max - min); // �ϼ�
}