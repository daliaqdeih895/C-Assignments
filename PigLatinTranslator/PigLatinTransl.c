#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a vowel
int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to translate English word to Pig Latin
void toPigLatin(char* word) {
    int len = strlen(word);
    int firstVowelIndex = -1;

    // Find the first vowel in the word
    for (int i = 0; i < len; i++) {
        if (isVowel(word[i])) {
            firstVowelIndex = i;
            break;
        }
    }

    // If the word starts with a vowel, add "way" at the end
    if (firstVowelIndex == 0) {
        strcat(word, "way");
    } else {
        // Move the consonant cluster to the end and add "ay"
        char temp[100];
        int i = 0;
        
        // Move consonant cluster to temp
        while (!isVowel(word[i]) && word[i] != '\0') {
            temp[i] = word[i];
            i++;
        }
        temp[i] = '\0';

        // Shift the remaining part of the word
        char remaining[100];
        strcpy(remaining, &word[i]);

        // Combine consonant cluster + remaining + "ay"
        strcat(remaining, temp);
        strcat(remaining, "ay");
        strcpy(word, remaining);
    }
}

// Function to process a sentence and convert each word to Pig Latin
void convertSentenceToPigLatin(char* sentence) {
    char word[100];
    int j = 0;

    // Process each word in the sentence
    for (int i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0' || sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') {
            word[j] = '\0';  // End of the current word
            if (j > 0) {
                toPigLatin(word);
                printf("%s", word);
            }
            
            // Print the punctuation mark or space
            if (sentence[i] != '\0') {
                printf("%c", sentence[i]);
            }
            j = 0;  // Reset word index
        } else {
            word[j++] = sentence[i];
        }
    }
    printf("\n");
}

int main() {
    char input[1000];
    int choice;

    printf("Input: ");
    scanf("%d", &choice);
    getchar();  // To clear the newline character from the input buffer

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character

    switch (choice) {
        case 1:
            convertSentenceToPigLatin(input);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
