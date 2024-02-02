#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 2609 _ 최대공약수와 최소공배수

// 문제
// 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10, 000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
//
// 출력
// 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.


int main() {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    int* table1 = (int*)malloc(sizeof(int) * N);
    int* table2 = (int*)malloc(sizeof(int) * M);

    for (int i = 0; i < N; i++) { // 초기화
        table1[i] = 0;
    }
    for (int i = 0; i < M; i++) { // 초기화
        table2[i] = 0;
    }

    int count = 0;
    for (int i = 1; i <= N / 2; i++) { // 예시로 11이라면 1~5까지중에서 약수들을 배열에 저장
        if (N % i == 0) {
            table1[count] = i;
            count++;
        }
    }
    table1[count] = N; // 자기 자신인 11도 약수이므로 배열에 저장
    count++;
    int len1 = count; // 약수의 개수

    count = 0;
    for (int i = 1; i <= M / 2; i++) {
        if (M % i == 0) {
            table2[count] = i;
            count++;
        }
    }
    table2[count] = M;
    count++;
    int len2 = count;


    int remember = 0; // 최대공약수 변수
    for (int i = len1 - 1; i >= 0; i--) { // 제일 높은 약수부터 비교해나가면서
        for (int j = len2 - 1; j >= 0; j--) { // 가장 처음 똑같은 약수가 나왔을때
            if (table1[i] == table2[j]) {
                remember = table1[i]; // 최대공약수로 저장
                break;
            }
        }
        if (remember != 0) {
            break;
        }
    }
    printf("%d\n", remember); // 최대공약수 출력

    int sum = (N / remember) * (M / remember);
    printf("%d", sum * remember); // 최소공배수 출력

    free(table1);
    free(table2);
}