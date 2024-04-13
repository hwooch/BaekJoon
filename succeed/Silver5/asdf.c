#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 11059 _ ũ�� ���ڿ�

// ����
// ���ڷθ� �̷���� ���ڿ� S�� �־�����.
// S�� ���ӵ� �κ� ���ڿ� �߿��� ���̰� ¦���̰�, ���� ������ �հ� ���� ������ ���� ���� �κ� ���ڿ��� ũ�� ���ڿ��̶�� �Ѵ�.
// �� ���ڿ��� ũ�� ���ڿ��� �ƴϴ�.
// 
// S�� ũ�� ���ڿ� �߿��� ���� ���̰� �� ���� ã�� ���α׷��� �ۼ��Ͻÿ�.
// 
// ���� ��� S = "67896789" �� ��쿡 ������ "67896789"�� �ȴ�.
// ��, S = "6789789" �� ��쿡 ������ "789789"�� �ȴ�.
// S = "6789678" �� ��쿡 ������ "9678" �̴�.
// 
// �Է�
// ù° �ٿ� ���ڿ� S�� �־�����.
// S�� ���ڷθ� �̷���� ������, ���̴� 1, 000�� ���� �ʴ´�.
// �׻� ũ�� ���ڿ��� �����ϴ� �Է¸� �־�����.
// 
// ���
// ù° �ٿ� S�� ũ�� ���ڿ� �߿��� ���� �� ���� ���̸� ����Ѵ�.
   
int main() {
    char user[1001];
    scanf("%s", user);

    int answer = 0;
    int len = strlen(user);


    for (int start = 0; start < len; start++) {

        for (int length = 2; start + length <= len; length += 2) {
            int left = 0, right = 0;


            for (int i = start; i < start + length / 2; i++) {
                left += user[i] - '0';
            }
            for (int i = start + length / 2; i < start + length; i++) {
                right += user[i] - '0';
            }


            if (left == right) {

                if (length > answer) {
                    answer = length;
                }
            }
        }
    }

    printf("%d", answer);

    return 0;
}