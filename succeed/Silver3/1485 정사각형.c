#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1485 _ 정사각형

// 문제
// 네 점이 주어졌을 때, 네 점을 이용해 정사각형을 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스는 네 줄로 이루어져 있으며, 점의 좌표가 한 줄에 하나씩 주어진다.
// 점의 좌표는 - 100, 000보다 크거나 같고, 100, 000보다 작거나 같은 정수이다.
// 같은 점이 두 번 이상 주어지지 않는다.
// 
// 출력
// 각 테스트 케이스마다 입력으로 주어진 네 점을 이용해서 정사각형을 만들 수 있으면 1을, 없으면 0을 출력한다.

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		long long x[4], y[4];
		long long distance[3];
		long long max = 0;
		int memoryi = -1;
		long long distance_test = 0;
		int count = 0;

		for (int i = 0; i < 4; i++) {
			scanf("%lld %lld", &x[i], &y[i]); // 4개의 점을 입력받는다
		}
		for (int i = 0; i < 3; i++) {
			distance[i] = (x[i] - x[3]) * (x[i] - x[3]) + (y[i] - y[3]) * (y[i] - y[3]);
			// 4번째로 입력받은 점과 나머지 3개의 점 사이의 거리를 저장한다.
			if (distance[i] > max) { // 그 중 가장 긴 거리를 max 변수에 저장하고
				max = distance[i];
				memoryi = i; // i를 기억함으로써 몇번째로 입력받은 점이 4번째로 입력받은점으로부터 가장 멀리있는 점인지도 기억한다
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i != memoryi) {
				distance_test = (x[i] - x[memoryi]) * (x[i] - x[memoryi]) + (y[i] - y[memoryi]) * (y[i] - y[memoryi]);
				// 가장 멀리있는 점에서 나머지 3개의 점 사이의 거리도 구한다
				for (int j = 0; j < 3; j++) {
					if (distance_test == distance[j]) { // 만약 4번째로 입력받은 거리와 전부 같다면
						count++; // 총 5번이 똑같을 것이다.
					}
				}
			}
		}
		long long compare_x1, compare_x2;
		long long compare_y1, compare_y2;
		int count2 = 0;
		for (int i = 0; i < 3; i++) { // 4번째 입력받은 점을 제외하고
			if (i != memoryi && count2 == 0) { // 4번째 입력받은 점과 가장 멀리 있는 점까지 제외한 나머지 두 점을 구한다.
				compare_x1 = x[i];
				compare_y1 = y[i];
				count2++;
			}
			else if (i != memoryi && count2 == 1) {
				compare_x2 = x[i];
				compare_y2 = y[i];
			}
		}

		if (max != (compare_x1 - compare_x2) * (compare_x1 - compare_x2) + (compare_y1 - compare_y2) * (compare_y1 - compare_y2)) {
			// 그 나머지 두 점 사이의 거리가 만약 가장 긴 거리와 똑같지 않다면 정사각형이 아니다.
			// ex) (0.1),(3.0),(3.2),(6.1)
			printf("0\n");
		}
		else if (count == 5) { // 똑같고 count가 5라면 정사각형이다
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}