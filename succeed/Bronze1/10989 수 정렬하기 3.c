#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 10989 _ 수 정렬하기 3

// 문제
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10, 000, 000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 수가 주어진다.이 수는 10, 000보다 작거나 같은 자연수이다.
// 
// 출력
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.


int main() {

    int N;
    scanf("%d", &N);

    int table[10000] = { 0, }; // 입력의 범위에서 빈도수를 확인하는 배열
    int user;

    for (int i = 0; i < N; i++) {
        scanf("%d", &user); // 입력받은 자연수가 몇번 나왔는지 저장하기 위해
        table[user - 1]++; // 1을 입력받았을때 table[0]에 저장한다. (1~10000 은 배열에 0~9999 로 저장된다)
    }

    int count = 1; // 출력될 자연수
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < table[i]; j++) { // table[i]의 빈도수만큼 반복하면서 자연수 출력
            printf("%d\n", count);
        }
        count++; // 출력이 끝나면 다음 자연수로 넘어간다.
    }
}