#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 10987 _ ������ ����

// ����
// ���ĺ� �ҹ��ڷθ� �̷���� �ܾ �־�����.
// �̶�, ����(a, e, i, o, u)�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� �ܾ �־�����.
// �ܾ��� ���̴� 1���� ũ�ų� ����, 100���� �۰ų� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.
// 
// ���
// ù° �ٿ� ������ ������ ����Ѵ�.

int main() {
    char user[200];
    scanf("%s", user);

    int len = strlen(user);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (user[i] == 'a' || user[i] == 'e' || user[i] == 'i' || user[i] == 'o' || user[i] == 'u') {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}