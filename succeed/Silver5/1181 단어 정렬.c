#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1181 _ �ܾ� ����

// ����
// ���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// ���̰� ª�� �ͺ���
// ���̰� ������ ���� ������
// ��, �ߺ��� �ܾ�� �ϳ��� ����� �����ؾ� �Ѵ�.
//
// �Է�
// ù° �ٿ� �ܾ��� ���� N�� �־�����. 
// (1 �� N �� 20, 000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����.
// �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.
//
// ���
// ���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�.

typedef struct {
    char word[51];
    int length;
} Word;

int compare(const void* a, const void* b) {
    Word* word1 = (Word*)a;
    Word* word2 = (Word*)b;

    if (word1->length > word2->length) {
        return 1;
    }
    else if (word1->length < word2->length) {
        return -1;
    }
    else {
        return strcmp(word1->word, word2->word);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Word* words = (Word*)malloc(sizeof(Word) * N);

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }

    qsort(words, N, sizeof(Word), compare);

    printf("%s\n", words[0].word);
    for (int i = 1; i < N; i++) {
        if (strcmp(words[i].word, words[i - 1].word) != 0) {
            printf("%s\n", words[i].word);
        }
    }
    free(words);
    return 0;

}