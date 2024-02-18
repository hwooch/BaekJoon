#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1124 _ 언더프라임

// 문제
// 자연수 X를 소인수분해하면, 곱해서 X가 되는 소수의 목록을 얻을 수 있다. 
// 예를 들어, 12 = 2 × 2 × 3이다. 1은 소수가 아니다.
// 
// 어떤 수 X를 소인수분해 해서 구한 소수의 목록의 길이가 소수이면, 그 수를 언더프라임 이라고 한다. 
// 12는 목록에 포함된 소수의 개수가 3개이고, 3은 소수이니 12는 언더프라임이다.
// 
// 두 정수 A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 정수 중에서 언더프라임인 것의 개수를 구해보자.
// 
// 입력
// 첫째 줄에 두 정수 A와 B가 주어진다.
// 
// 출력
// 첫째 줄에 A보다 크거나 같고, B보다 작거나 같은 언더프라임 개수를 출력한다.
// 
// 제한
// 2 ≤ A ≤ B ≤ 100, 000

int array[100000] = { 1, };

int main() {
    array[1] = 1;
    for (int i = 2; i <= sqrt(100000); i++) {
        if (array[i] == 0) {
            for (int j = i * 2; j <= 100000; j = j + i) {
                array[j] = 1;
            }
        }
    } // array 가 0이면 소수

    int x, y;
    scanf("%d %d", &x, &y);

    int count = 0;
    int temp = 0;
    int answer = 0;

    for (int k = x; k <= y; k++) {
        int memoryi = 2;
        temp = k;
        count = 0;

        while (temp != 1) {
            for (int i = memoryi; i <= sqrt(temp); i++) {
                if (array[i] == 0 && temp % i == 0) {// i가 소수이고 나누어서 떨어지는지 확인
                    while (temp % i == 0) { // 나눌수있으면 나눠지지 않을때까지 나눈다.
                        temp = temp / i;
                        count++;
                        memoryi = i + 1;
                    }
                    break;
                }
            }
            if (temp > 1 && array[temp] == 0) { // 나눠진 후의 숫자가 소수라면
                temp = temp / temp; // temp는 자기자신으로 나누고 1이된다
                count++;
            }
        }
        if (array[count] == 0) {
            answer++;
        }
    }
    printf("%d", answer);
}