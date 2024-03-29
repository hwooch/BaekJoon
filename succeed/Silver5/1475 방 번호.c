#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1475 _ 방 번호

// 문제
// 다솜이는 은진이의 옆집에 새로 이사왔다.
// 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
//
//다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.
// 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
// 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
// (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
//
// 입력
// 첫째 줄에 다솜이의 방 번호 N이 주어진다.N은 1, 000, 000보다 작거나 같은 자연수이다.
//
// 출력
// 첫째 줄에 필요한 세트의 개수를 출력한다.


int main() {
	char user[1000001];
	scanf("%s", user);

	int check[10]; // 0~9 빈도 저장 배열
	for (int i = 0; i < 10; i++) { // 초기화
		check[i] = 0;
	}

	for (int i = 0; i < strlen(user); i++) { // 문자열의 길이만큼 반복
		check[user[i] - '0']++; // 빈도수 체크
	}

	int sum = 0;
	for (int i = 0; i < 6; i++) {
		if (sum < check[i]) {
			sum = check[i];
		}
	}
	for (int i = 7; i < 9; i++) {
		if (sum < check[i]) {
			sum = check[i];
		}
	} // sum은 결국 1,2,3,4,5,7,8 중에 제일 많이 나온 횟수를 저장하게 됨

	int sum2 = 0;
	sum2 = check[6] + check[9];// sum2는 6과 9의 빈도 수를 더한 후
	if (sum2 % 2 == 1) { // 그 빈도가 홀수라면 
		sum2 = (sum2 + 1) / 2;
		// 1을 더해준 후 2로 나눔 -> 이 이유는 만약 3이라면 2개까지는 1세트로 만들수 있지만 총 필요한건 1세트를 더 산 2세트이기 때문
	}
	else { // 짝수라면
		sum2 = sum2 / 2; // 그냥 2로 나눠줌 -> 이 이유는 짝수라면 2개를 1세트로 만들 수 있기 때문
	}
	printf("%d", sum >= sum2 ? sum : sum2); // sum의 세트가 더 많은지, sum2의 세트가 더 많은지 비교 후 큰쪽을 구매.
}