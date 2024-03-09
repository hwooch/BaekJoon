#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 20153 _ 영웅이는 2의 거듭 제곱을 좋아해!

// 문제
// 영웅이는 2의 거듭제곱을 좋아해서 A를 최대한 많은 항의 2의 거듭제곱의 합으로 표현한다.
// 표현된 2의 거듭제곱은 지수가 0 이상의 서로 다른 정수이다.
// 
// 예를 들어 31은 5개의 항으로 표현된다. 우리는 이것을 영웅이의 표현법이라고 부를 것이다.
// 
// N개의 자연수 A1, A2, ..., AN이 주어진다. 
// 이 중 최대 한 개의 자연수를 제거하고, 나머지를 영웅이의 표현법으로 나타내자.
// 
// 그 후 각 정수 x에 대해 2x가 홀수 개 존재하면 2x를 더하고, 짝수 개 존재하면 더하지 않는다.
// 이렇게 했을 때 얻을 수 있는 최대 합을 2번 출력하라.
// 
// 입력
// 첫째 줄에 자연수 N(1 ≤ N ≤ 2, 222, 222)이 주어지고, 둘째 줄에는 N개의 자연수 A(1 ≤ A ≤ 2, 222, 222)가 주어진다.
// 
// 출력
// 최댓값을 2번 연속해서 출력한다.

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
    scanf("%d", &T); // 숫자의 개수
    int user; // 입력받는 숫자
    int max = -1; // 2진수의 최대 길이 저장
    int answer[22] = { 0, }; // 모든 숫자의 각 비트 개수 저장

    int count = 0;
    for (int K = 0; K < T; K++) {
        scanf("%d", &user);
        user_number[count++] = user;

        int binary[22] = { 0, };

        int position = 0;
        while (1)
        {
            binary[position] = user % 2;// 2로 나누었을 때 나머지를 배열에 저장
            user = user / 2;// 2로 나눈 몫을 저장
            position++;// 자릿수 변경
            if (user == 0)// 몫이 0이 되면 반복을 끝냄
                break;
        }
        if (max < position) { // 최대비트 길이 갱신
            max = position;
        }
        for (int i = 0; i < position; i++)
        {
            if (binary[i] == 1) {
                answer[i]++;
            }
        }
    }
    merge_sort(user_number, 0, T - 1); // 입력받은 수들을 정렬
    int check = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        if (answer[i] % 2 == 0) { // 합중에서 각 비트가 짝수인것이 처음 나오면 멈추기
            check = pow(2, i);
            break;
        }
    }
    int temp = 0;
    int memoryi = 0;
    int sum = 0;
    if (check != 0) { // 짝수가 있다면
        for (int i = 0; i < T; i++) {
            if (user_number[i] >= check) { // 처음 나온것보다 크거가 같은게 나올때까지 증가시키고
                memoryi = i; // i도 저장
                break;
            }
        }
    }
    else { // 짝수가 없다면 바로 출력
        for (int i = 0; i < max; i++) {
            if (answer[i] % 2 == 1) {
                sum = sum + pow(2, i);
            }
        }
        printf("%d%d", sum, sum);
        return 0;
    }
    int asdf = pow(2, max); // 최대 비트수만큼 만약 max가 3이었다면 2의3제곱인 8까지 검사한다.
    int max_answer = 0;
    while ((user_number[memoryi] <= asdf) && (memoryi < T)) {
        sum = 0;
        int binary[22] = { 0, };
        int position = 0;
        temp = user_number[memoryi];
        while (1)
        {
            binary[position] = temp % 2;    // 2로 나누었을 때 나머지를 배열에 저장
            temp = temp / 2;             // 2로 나눈 몫을 저장
            position++;    // 자릿수 변경
            if (temp == 0)    // 몫이 0이 되면 반복을 끝냄
                break;
        }

        for (int i = 0; i < max; i++)
        {
            if (binary[i] == 1) { // 빼려는 숫자가 있다면 뺀 후에
                answer[i]--;
            }
            if (answer[i] % 2 == 1) { // 홀수인 숫자들을 다 더함
                sum = sum + pow(2, i);
            }
            if (binary[i] == 1) { // 원래상태로 복구
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
        if (answer[i] % 2 == 1) { // 모든 합인 숫자가 홀수인것들을 다 더함
            sum = sum + pow(2, i); // 아무 숫자도 빼지않은게 최대값인지를 검사
        }
    }
    if (max_answer < sum) {
        max_answer = sum;
    }
    printf("%d%d", max_answer, max_answer);
}