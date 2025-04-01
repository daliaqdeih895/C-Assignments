#include <stdio.h>
#include <ctype.h> // Code that indicates characters will be converted into strings or other characters
#include <string.h>

int is_consonant(char c) {
    // Check if the character is a consonant, set it to ignore the capitalization/case
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

    // Find the first consonant of a word
    while (is_consonant(word[i]) && i < length) {
        first_consonant_cluster[j++] = word[i++];
    }
    first_consonant_cluster[j] = '\0';  

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

    // If the sentence ends without punctuation, print the last word
    if (word_index > 0) {
        word[word_index] = '\0';
        to_pig_latin(word);
    }
}

int main() {
    char sentence[500];
    
    // Prompt the user to input a sentence for translating
    printf("Input: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove potential trailing newline characters
    sentence[strcspn(sentence, "\n")] = 0;
    
    // Command that translates the sentence
    translate_sentence_to_pig_latin(sentence);
    printf("\n");

    return 0;
}
