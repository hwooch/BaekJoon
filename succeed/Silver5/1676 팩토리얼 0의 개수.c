#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1676 _ 팩토리얼 0의 개수

// 문제
// N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)
// 
// 출력
// 첫째 줄에 구한 0의 개수를 출력한다.

int main() {
    int n;
    scanf("%d", &n); // N 팩토리얼의 숫자 N 입력

    int result[5000] = { 0 };
    result[0] = 1; // 0! = 1
    int size = 1; // 자릿수변수 현재 1자리

    for (int i = 2; i <= n; i++) { // 1이라면 for문을 돌지 않고 바로 결과로
        int over = 0; // 올림수

        for (int j = 0; j < size; j++) {
            int product = result[j] * i + over; // 결과값을 집어넣는데 만약 24가 되었다
            result[j] = product % 10; // result[0]에 4를 집어넣고
            over = product / 10; // 올림자리수에 2를 집어넣는다.
        }

        while (over) { // 올림자리수가 있다면
            result[size] = over % 10;
            over = over / 10; // 올림자리수가 3자리라면 한번더 해야하니까
            size++; // 자리수를 하나 늘린다.
        }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (result[i] == 0) { // 0의 개수를 세다가
            count++;
        }
        else {
            printf("%d", count); // 0이 아니면 개수 출력하고 프로그램 종료
            return 0;
        }
    }
}