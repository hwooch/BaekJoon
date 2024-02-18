#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1124 _ ���������

// ����
// �ڿ��� X�� ���μ������ϸ�, ���ؼ� X�� �Ǵ� �Ҽ��� ����� ���� �� �ִ�. 
// ���� ���, 12 = 2 �� 2 �� 3�̴�. 1�� �Ҽ��� �ƴϴ�.
// 
// � �� X�� ���μ����� �ؼ� ���� �Ҽ��� ����� ���̰� �Ҽ��̸�, �� ���� ��������� �̶�� �Ѵ�. 
// 12�� ��Ͽ� ���Ե� �Ҽ��� ������ 3���̰�, 3�� �Ҽ��̴� 12�� ����������̴�.
// 
// �� ���� A�� B�� �־����� ��, A���� ũ�ų� ����, B���� �۰ų� ���� ���� �߿��� ����������� ���� ������ ���غ���.
// 
// �Է�
// ù° �ٿ� �� ���� A�� B�� �־�����.
// 
// ���
// ù° �ٿ� A���� ũ�ų� ����, B���� �۰ų� ���� ��������� ������ ����Ѵ�.
// 
// ����
// 2 �� A �� B �� 100, 000

int array[100000] = { 1, };

int main() {
    array[1] = 1;
    for (int i = 2; i <= sqrt(100000); i++) {
        if (array[i] == 0) {
            for (int j = i * 2; j <= 100000; j = j + i) {
                array[j] = 1;
            }
        }
    } // array �� 0�̸� �Ҽ�

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
                if (array[i] == 0 && temp % i == 0) {// i�� �Ҽ��̰� ����� ���������� Ȯ��
                    while (temp % i == 0) { // ������������ �������� ���������� ������.
                        temp = temp / i;
                        count++;
                        memoryi = i + 1;
                    }
                    break;
                }
            }
            if (temp > 1 && array[temp] == 0) { // ������ ���� ���ڰ� �Ҽ����
                temp = temp / temp; // temp�� �ڱ��ڽ����� ������ 1�̵ȴ�
                count++;
            }
        }
        if (array[count] == 0) {
            answer++;
        }
    }
    printf("%d", answer);
}