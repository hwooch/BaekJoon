#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 9765 _ 여섯 방정식

// 문제
// 여섯 개의 간단한 방정식이 주어진다.
// 이때, x1, x2, x3, x5, x6, x7를 찾는 프로그램을 작성하시오.
// x1, x2, x3, x5, x6, x7은 2보다 크거나 같고, 20, 000, 000보다 작거나 같은 소수이다.
// 여섯 방정식은 아래와 같다.
// 
// c1 = x1x2
// x4 = c4x1
// c3 = x6x7
// x8 = x7c2
// c5 = x2x3
// c6 = x6x5
// c1, c2, c3, c4, c5, c6은 양의 정수로(20, 000, 000)2을 넘지 않는다.
// c1, c2, c3, c4, c5, c6이 주어졌을 때, x1, x2, x3, x5, x6, x7을 푸는 프로그램을 작성하시오.
// 항상 풀 수 있는 방정식만 입력으로 주어진다.
// 
// 입력
// 첫째 줄에 c1, c2, c3, c4, c5, c6이 주어진다. (c1 ≠ c5, c3 ≠ c6)
// 
// 출력
// x1, x2, x3, x5, x6, x7 를 공백으로 구분해 출력한다.
// 가능한 답이 여러 가지인 경우, 아무거나 출력한다.

long long int number[7][60] = { 0, };
int a[20000000] = { 1,1, };

void find(long long int n, long long int number[], int* count) {
    long long int temp[30]; // 큰 약수를 임시로 저장할 배열
    int smallCount = 0, largeCount = 0; // 작은 약수의 개수, 큰 약수의 개수

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            number[smallCount++] = i; // 작은 약수 저장
            if (i != n / i) { // i와 n/i가 같지 않을 때만 큰 약수를 임시 배열에 저장
                temp[largeCount++] = n / i;
            }
        }
    }

    // 큰 약수를 역순으로 number 배열에 추가
    for (int i = largeCount - 1; i >= 0; i--) {
        number[smallCount++] = temp[i];
    }

    *count = smallCount; // 약수의 총 개수를 저장
}



int main() {
	long long int c1, c2, c3, c4, c5, c6;
    int x1, x2, x3, x5, x6, x7;
	scanf("%lld %lld %lld %lld %lld %lld", &c1, &c2, &c3, &c4, &c5, &c6);

    
    int count1 = 0; // 약수의 개수
    int count3 = 0;
    int count5 = 0;
    int count6 = 0;

    for (int i = 2; i <= sqrt(20000000); i++) { // 소수판정 a[i]가 0이면 소수
        if (a[i] == 0) {
            for (int j = 2; i * j < 20000000; j++) {
                a[i * j] = 1;
            }
        }
    } //a[i]==0 소수 i
    
    find(c6, number[6], &count6); // c6의 숫자에서 number[6]에 약수를 순서대로 저장
    // count6에 약수의 개수 저장
    find(c3, number[3], &count3);
    int check = 0;
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count3; j++) {

            if (number[6][i] == number[3][j]) { // 약수들 중에 같은것이 나왔을때

                if (a[number[6][i]] == 0) { // 그 같은 숫자가 소수여야하고
                    if (a[c3 / number[6][i]] == 0 && a[c6 / number[6][i]] == 0) {
                        // c3과 c6을 둘다 나눴을때도 소수여야한다
                        x6 = number[6][i];
                        x7 = c3 / x6;
                        x5 = c6 / x6;
                        check = 1;
                        break;
                    }
                }
            }
        }
        if (check == 1) {
            break;
        }
    }

    find(c1, number[1], &count1);
    find(c5, number[5], &count5);

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count5; j++) {


            if (number[1][i] == number[5][j]) {
                if (a[number[1][i]] == 0) {
                    if (a[c5 / number[1][i]] == 0 && a[c1 / number[1][i]] == 0) {
                        x2 = number[1][i];
                        x3 = c5 / x2;
                        x1 = c1 / x2;
                        printf("%d %d %d %d %d %d", x1, x2, x3, x5, x6, x7);
                        return 0;
                    }
                }
            }
        }
    }
}