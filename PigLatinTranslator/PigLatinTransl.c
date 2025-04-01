#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_consonant(char c) {
    // Check if the character is a consonant (ignore case)
    return (isalpha(c) && !strchr("AEIOUaeiou", c));
}

void to_pig_latin(char *word) {
    int length = strlen(word);
    char first_consonant_cluster[100];
    int i = 0, j = 0;

    // Skip leading punctuation marks
    while (!isalpha(word[i]) && i < length) {
        i++;
    }

    // If the word has no alphabetic character, return it as is
    if (i == length) {
        printf("%s", word);
        return;
    }

    // Find the first consonant cluster
    while (is_consonant(word[i]) && i < length) {
        first_consonant_cluster[j++] = word[i++];
    }
    first_consonant_cluster[j] = '\0';  // Null-terminate the consonant cluster

    // If the word starts with a vowel, just add 'ay'
    if (j == 0) {
        printf("%say", word);
    } else {
        // Move the consonant cluster to the end and add "ay"
        printf("%s%say", word + j, first_consonant_cluster);
    }
}

void translate_sentence_to_pig_latin(char *sentence) {
    int i = 0;
    char word[100];
    int word_index = 0;

    while (sentence[i] != '\0') {
        if (isalpha(sentence[i])) {
            // If the character is alphabetic, add it to the current word
            word[word_index++] = sentence[i];
        } else {
            // If the character is not alphabetic, print the word and the punctuation
            if (word_index > 0) {
                word[word_index] = '\0';
                to_pig_latin(word);
                word_index = 0;
            }
            printf("%c", sentence[i]);
        }
        i++;
    }

    // Print the last word if the sentence ends without punctuation
    if (word_index > 0) {
        word[word_index] = '\0';
        to_pig_latin(word);
    }
}

int main() {
    char sentence[500];
    
    // Prompt the user for input
    printf("Input: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove trailing newline character from fgets
    sentence[strcspn(sentence, "\n")] = 0;
    
    // Translate the sentence
    translate_sentence_to_pig_latin(sentence);
    printf("\n");

    return 0;
}
