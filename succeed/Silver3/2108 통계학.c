#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 2108 _ 통계학

// 문제
// 수를 처리하는 것은 통계학에서 상당히 중요한 일이다.
// 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다.
// 단, N은 홀수라고 가정하자.
// 
// 산술평균 : N개의 수들의 합을 N으로 나눈 값
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
// N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500, 000)이 주어진다. 단, N은 홀수이다.
// 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4, 000을 넘지 않는다.
// 
// 출력
// 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
// 
// 둘째 줄에는 중앙값을 출력한다.
// 
// 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
// 
// 넷째 줄에는 범위를 출력한다.

int number[500000];
int count[8001] = { 0, };

//셸 정렬에 필요한 삽입정렬
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
//셸 정렬
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
            countmax = count[i]; // 빈도수 제일 큰것 저장
        }
    }
    int rememberi = 0;

    for (int i = 0; i < 8001; i++) {
        if (countmax == count[i]) { // 빈도수가 똑같다면
            rememberi = i; // i 기억 (만약 하나라면 i기억해야하므로)
            check++; // 제일 큰 빈도수의 출현 횟수
        }
        if (check == 2) { // 만약 두번째라면
            rememberi = i; // 두번째로 나온 i 기억
            break;
        }

    }
    shell_sort(number, N); // 셸 정렬

    printf("%d\n", (int)round(sum / N)); // 완성
    printf("%d\n", number[N / 2]); // 완성
    printf("%d\n", rememberi - 4000);
    printf("%d\n", max - min); // 완성
}