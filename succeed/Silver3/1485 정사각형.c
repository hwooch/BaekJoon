#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1485 _ ���簢��

// ����
// �� ���� �־����� ��, �� ���� �̿��� ���簢���� ���� �� �ִ��� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
// �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����.
// ���� ��ǥ�� - 100, 000���� ũ�ų� ����, 100, 000���� �۰ų� ���� �����̴�.
// ���� ���� �� �� �̻� �־����� �ʴ´�.
// 
// ���
// �� �׽�Ʈ ���̽����� �Է����� �־��� �� ���� �̿��ؼ� ���簢���� ���� �� ������ 1��, ������ 0�� ����Ѵ�.

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
			scanf("%lld %lld", &x[i], &y[i]); // 4���� ���� �Է¹޴´�
		}
		for (int i = 0; i < 3; i++) {
			distance[i] = (x[i] - x[3]) * (x[i] - x[3]) + (y[i] - y[3]) * (y[i] - y[3]);
			// 4��°�� �Է¹��� ���� ������ 3���� �� ������ �Ÿ��� �����Ѵ�.
			if (distance[i] > max) { // �� �� ���� �� �Ÿ��� max ������ �����ϰ�
				max = distance[i];
				memoryi = i; // i�� ��������ν� ���°�� �Է¹��� ���� 4��°�� �Է¹��������κ��� ���� �ָ��ִ� �������� ����Ѵ�
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i != memoryi) {
				distance_test = (x[i] - x[memoryi]) * (x[i] - x[memoryi]) + (y[i] - y[memoryi]) * (y[i] - y[memoryi]);
				// ���� �ָ��ִ� ������ ������ 3���� �� ������ �Ÿ��� ���Ѵ�
				for (int j = 0; j < 3; j++) {
					if (distance_test == distance[j]) { // ���� 4��°�� �Է¹��� �Ÿ��� ���� ���ٸ�
						count++; // �� 5���� �Ȱ��� ���̴�.
					}
				}
			}
		}
		long long compare_x1, compare_x2;
		long long compare_y1, compare_y2;
		int count2 = 0;
		for (int i = 0; i < 3; i++) { // 4��° �Է¹��� ���� �����ϰ�
			if (i != memoryi && count2 == 0) { // 4��° �Է¹��� ���� ���� �ָ� �ִ� ������ ������ ������ �� ���� ���Ѵ�.
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
			// �� ������ �� �� ������ �Ÿ��� ���� ���� �� �Ÿ��� �Ȱ��� �ʴٸ� ���簢���� �ƴϴ�.
			// ex) (0.1),(3.0),(3.2),(6.1)
			printf("0\n");
		}
		else if (count == 5) { // �Ȱ��� count�� 5��� ���簢���̴�
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}