#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1049 _ 기타줄

// 문제
// Day Of Mourning의 기타리스트 강토가 사용하는 기타에서 N개의 줄이 끊어졌다.
// 따라서 새로운 줄을 사거나 교체해야 한다. 강토는 되도록이면 돈을 적게 쓰려고 한다. 
// 6줄 패키지를 살 수도 있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.
// 
// 끊어진 기타줄의 개수 N과 기타줄 브랜드 M개가 주어지고, 
// 각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격, 낱개로 살 때의 가격이 주어질 때, 
// 적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 N과 M이 주어진다.
// N은 100보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 M개의 줄에는 각 브랜드의 패키지 가격과 낱개의 가격이 공백으로 구분하여 주어진다.
// 가격은 0보다 크거나 같고, 1, 000보다 작거나 같은 정수이다.
// 
// 출력
// 첫째 줄에 기타줄을 적어도 N개 사기 위해 필요한 돈의 최솟값을 출력한다.

int main() {
	int N, M;
	scanf("%d %d", &N, &M);


	int store_bundle[50];
	int store_each[50];
	int min_bundle = 1001;
	int min_each = 1001;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &store_bundle[i], &store_each[i]);
		if (min_bundle > store_bundle[i]) {
			min_bundle = store_bundle[i];
		}
		if (min_each > store_each[i]) {
			min_each = store_each[i];
		}
	}

	int count = 0;
	int answer = 0;

	if (min_each * 6 < min_bundle) { // 만약 낱개 6개가 묶음보다 싸다면

		printf("%d", min_each * N); // 낱개로 다 산다
	}
	else { // 낱개 6개가 묶음보다 싼게 없다면

		// 일단 제일 싼 묶음으로 최대한 많이 산다 
		while (N >= 6) {
			count++;
			N = N - 6;
		}
		answer = count * min_bundle;

		// 그 다음 제일싼 낱개가격으로 샀을때와 묶음을 샀을때를 비교한다

		if (N * min_each < min_bundle) { // 만약 낱개로 산 것이 더 싸다면
			answer = answer + N * min_each;
		}
		else { // 그렇지 않다면 묶음으로 산다
			answer = answer + min_bundle;
		}
		printf("%d", answer);
	}
}