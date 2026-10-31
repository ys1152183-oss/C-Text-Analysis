#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char text[MAX];
    char word[100];
    char longest[100] = "";
    int freq[256] = {0};
    int i, j = 0;
    int words = 0, vowels = 0, consonants = 0;
    int len;
    char ch;

    printf("Enter a paragraph:\n");
    fgets(text, MAX, stdin);

    len = strlen(text);

    for (i = 0; i <= len; i++) {
        ch = text[i];

        /* build the current word from letters and digits */
        if (isalnum(ch)) {
            word[j] = ch;
            j++;
        } else {
            /* a space, punctuation or end of text means the word is over */
            if (j > 0) {
                word[j] = '\0';
                words++;

                if (strlen(word) > strlen(longest)) {
                    strcpy(longest, word);
                }
                j = 0;
            }
        }

        /* count vowels, consonants and frequency of each character */
        if (isalpha(ch)) {
            char lower = tolower(ch);

            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }

        if (ch != '\n' && ch != '\0') {
            freq[(unsigned char)ch]++;
        }
    }

    printf("\n----- Text Analysis -----\n");
    printf("Number of words      : %d\n", words);
    printf("Number of vowels     : %d\n", vowels);
    printf("Number of consonants : %d\n", consonants);
    printf("Longest word         : %s\n", longest);

    printf("\nFrequency of each character:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (i == ' ') {
                printf("' ' (space) : %d\n", freq[i]);
            } else {
                printf("'%c' : %d\n", i, freq[i]);
            }
        }
    }

    return 0;
}
