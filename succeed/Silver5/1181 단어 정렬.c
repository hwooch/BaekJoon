#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1181 _ 단어 정렬

// 문제
// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//
// 길이가 짧은 것부터
// 길이가 같으면 사전 순으로
// 단, 중복된 단어는 하나만 남기고 제거해야 한다.
//
// 입력
// 첫째 줄에 단어의 개수 N이 주어진다. 
// (1 ≤ N ≤ 20, 000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
// 주어지는 문자열의 길이는 50을 넘지 않는다.
//
// 출력
// 조건에 따라 정렬하여 단어들을 출력한다.

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