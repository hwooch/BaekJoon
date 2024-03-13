#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 9765 _ ���� ������

// ����
// ���� ���� ������ �������� �־�����.
// �̶�, x1, x2, x3, x5, x6, x7�� ã�� ���α׷��� �ۼ��Ͻÿ�.
// x1, x2, x3, x5, x6, x7�� 2���� ũ�ų� ����, 20, 000, 000���� �۰ų� ���� �Ҽ��̴�.
// ���� �������� �Ʒ��� ����.
// 
// c1 = x1x2
// x4 = c4x1
// c3 = x6x7
// x8 = x7c2
// c5 = x2x3
// c6 = x6x5
// c1, c2, c3, c4, c5, c6�� ���� ������(20, 000, 000)2�� ���� �ʴ´�.
// c1, c2, c3, c4, c5, c6�� �־����� ��, x1, x2, x3, x5, x6, x7�� Ǫ�� ���α׷��� �ۼ��Ͻÿ�.
// �׻� Ǯ �� �ִ� �����ĸ� �Է����� �־�����.
// 
// �Է�
// ù° �ٿ� c1, c2, c3, c4, c5, c6�� �־�����. (c1 �� c5, c3 �� c6)
// 
// ���
// x1, x2, x3, x5, x6, x7 �� �������� ������ ����Ѵ�.
// ������ ���� ���� ������ ���, �ƹ��ų� ����Ѵ�.

long long int number[7][60] = { 0, };
int a[20000000] = { 1,1, };

void find(long long int n, long long int number[], int* count) {
    long long int temp[30]; // ū ����� �ӽ÷� ������ �迭
    int smallCount = 0, largeCount = 0; // ���� ����� ����, ū ����� ����

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            number[smallCount++] = i; // ���� ��� ����
            if (i != n / i) { // i�� n/i�� ���� ���� ���� ū ����� �ӽ� �迭�� ����
                temp[largeCount++] = n / i;
            }
        }
    }

    // ū ����� �������� number �迭�� �߰�
    for (int i = largeCount - 1; i >= 0; i--) {
        number[smallCount++] = temp[i];
    }

    *count = smallCount; // ����� �� ������ ����
}



int main() {
	long long int c1, c2, c3, c4, c5, c6;
    int x1, x2, x3, x5, x6, x7;
	scanf("%lld %lld %lld %lld %lld %lld", &c1, &c2, &c3, &c4, &c5, &c6);

    
    int count1 = 0; // ����� ����
    int count3 = 0;
    int count5 = 0;
    int count6 = 0;

    for (int i = 2; i <= sqrt(20000000); i++) { // �Ҽ����� a[i]�� 0�̸� �Ҽ�
        if (a[i] == 0) {
            for (int j = 2; i * j < 20000000; j++) {
                a[i * j] = 1;
            }
        }
    } //a[i]==0 �Ҽ� i
    
    find(c6, number[6], &count6); // c6�� ���ڿ��� number[6]�� ����� ������� ����
    // count6�� ����� ���� ����
    find(c3, number[3], &count3);
    int check = 0;
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count3; j++) {

            if (number[6][i] == number[3][j]) { // ����� �߿� �������� ��������

                if (a[number[6][i]] == 0) { // �� ���� ���ڰ� �Ҽ������ϰ�
                    if (a[c3 / number[6][i]] == 0 && a[c6 / number[6][i]] == 0) {
                        // c3�� c6�� �Ѵ� ���������� �Ҽ������Ѵ�
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