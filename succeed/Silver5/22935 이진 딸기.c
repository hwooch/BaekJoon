#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 22935 _ 이진 딸기

// 문제
// 딸기가 좋아!딸기가 좋아!
// 
// 앙중대학교 신입생 환영회에 참석한 해강이는 술게임에서 살아남아야 한다.
// 순간 이진딸기가 시작되고, 이진딸기의 규칙을 모르는 해강이는 곤란해졌다!
// 해강이에게 어떻게 말해야 하는지 알려주어 해강이를 구해주자!
// 
// 이진딸기의 규칙은 다음과 같다. 4박자(한박에 1비트)를 사용하며, 1~15의 수를 이진법으로 나타내어 0에서는 박자를 비우고 1에서만 딸기를 외치게 된다.
// 비는(침묵하는) 박자는 "V"를 사용하여 나타낸다. 1부터 5까지는 다음과 같이 외치게 된다.
// 
// VVV딸기
// VV딸기V
// VV딸기딸기
// V딸기VV
// V딸기V딸기
// 15 이후 다시 14, 13으로 내려오고 1에 도달하면 다시 2, 3으로 올라가게 되며 이를 반복한다.
// 
// 입력
// 첫 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1, 000)가 주어진다.
// 
// 이후 T개의 줄에 걸쳐 이진 딸기를 처음 시작한 사람으로부터 몇 차례 후에 해강이가 말해야 하는지 N(1 ≤ N ≤ 1, 000, 000, 000) 이 정수로 주어진다.
// 
// 출력
// 해강이가 해야하는 말을 출력한다.쉬는 박자는 V로 한다.

int main() {
	int T;
	scanf("%d", &T);
	int user;
	for (int K = 0; K < T; K++) {
		int number[4] = { 0, };
		scanf("%d", &user);
		int check = user / 28;
		
		if (check > 2) {
			user = user - check * 28 + 28;
		}
		while (user > 29) {
			user = user - 28;
		}
		if (user > 15) {
			user = 30 - user;
		}
		int count = 0;
		while (user > 1) {
			number[count] = user % 2;
			user = user / 2;
			count++;
		}
		number[count] = user;
		for (int i = 3; i >=0; i--) {
			if (number[i] == 0) {
				printf("V");
			}
			else {
				printf("딸기");
			}
		}
		printf("\n");
	}
}