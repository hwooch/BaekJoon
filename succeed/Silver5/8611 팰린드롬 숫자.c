#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 8611 _ �Ӹ���� ����

// ����
// �Ӹ������ �տ��� ���� �о��� ���� �ڿ��� ���� �о��� ���� ���� ���ڿ��� ���Ѵ�.
// ���� ���, "ala"�� "aa"�� �Ӹ�����̰�, "adam"�� �Ӹ������ �ƴϴ�.
// 
// ��� ������ (an an-1 ... a1 a0)k �� ���� k�������� ��Ÿ�� �� �ִ�.
// ��� ai �� k���� ���� ���� �ƴ� �����̾�� �Ѵ�.
// 
// 
// (an an - 1 ... a1 a0)k�� ��Ÿ���� ���� a_n * k^n + a_{ n - 1 }*k^ { n - 1 } + ... + a_1 * k + a_0 �̴�.
// ���� ���, 10���� ���� 123�� ���� 1*100 + 2*10 + 3 �̰�, 8���� ���� 123�� ���� (1*64 + 2*8 + 3) �̴�.
// 
// 10���� ���� n �� �־����� ��, 2, 3, ..., 10�������� ��Ÿ���� ��, �Ӹ������ ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� n �� �־�����. (1<=N<=10^1000)
// 
// ���
// 
// n�� 2,3,...,10 �������� ��Ÿ���� ��, �Ӹ������ ��찡 ���ٸ�, "NIE"�� ����Ѵ�.
// �� ���� ��쿡�� �Ӹ������ �Ǵ� ���� b�� n�� b�������� ��Ÿ�� �� m�� ����Ѵ�.
// ����� b�� �����ϴ� ������� �Ѵ�.

char user[1002];
char user_copy[1002];
char result[10000];

int calculate(char* user, int jinbub, int len) {
    int copy_len = len;
    int count = 0;

    while (copy_len > 0) {
        int ten = 0;  // �ø���
        for (int i = 0; i < copy_len; i++) {
            int one = user[i] - '0';  // ���� �ڸ���
            int new_one = ten * 10 + one;  // ���� �ø����� ���� �ڸ����� ��ģ ��
            user[i] = (new_one / jinbub) + '0';  // ���ο� �ڸ���
            ten = new_one % jinbub;  // ���ο� �ø���
        }
        result[count++] = ten + '0';  // ��� ����

        // ���ڸ��� 0�� ��� ����
        while (copy_len > 0 && user[0] == '0') {
            for (int i = 1; i < copy_len; i++) {
                user[i - 1] = user[i];
            }
            user[copy_len - 1] = '\0';
            copy_len--;
        }
    }

    int end = 0;

    int check = 0;
    int WRONG = 0;

    for (int i = end; i <= count / 2; i++) {
        if (result[i] != result[count - 1 - check]) {
            WRONG = 1;
            break;
        }
        check++;
    }
    if (WRONG == 0) {
        printf("%d ", jinbub);
        for (int i = count - 1; i >= end; i--) {
            printf("%c", result[i]);
        }
        printf("\n");
        return 1;
    }

    return 0;
}
int main() {
    scanf("%s", &user);
    int len = strlen(user);

    int answer_count = 0;

    int K = 0;

    for (int jinbub = 2; jinbub <= 10; jinbub++) {
        strcpy(user_copy, user);
        if (calculate(user_copy, jinbub, len)) {
            answer_count++;
        }
    }
    if (answer_count == 0) {
        printf("NIE");
    }
}