#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct MorseEntry
{
    char letter;
    const char *code;
};
struct MorseEntry morseTable[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}};

int tableSize = sizeof(morseTable) / sizeof(morseTable[0]);

void textToMorse(const char *text)
{
    for (int i = 0; text[i]; i++)
    {
        char ch = toupper(text[i]);
        if (ch == ' ')
        {
            printf(" / ");
            continue;
        }
        for (int j = 0; j < tableSize; j++)
        {
            if (morseTable[j].letter == ch)
            {
                printf("%s ", morseTable[j].code);
                break;
            }
        }
    }
    printf("\n");
}

void morseToText(const char *morse)
{
    char copy[1024];
    strncpy(copy, morse, sizeof(copy));
    copy[sizeof(copy) - 1] = '\0';

    char *token = strtok(copy, " ");

    while (token != NULL)
    {
        if (strcmp(token, "/") == 0)
        {
            printf(" ");
        }
        else
        {
            for (int i = 0; i < tableSize; i++)
            {
                if (strcmp(morseTable[i].code, token) == 0)
                {
                    printf("%c", morseTable[i].letter);
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main()
{
    char choice;
    char input[1024];
    printf("Morse Translator  (T = Text To Morse, M = morse to text)\n");
    scanf("%s", &choice);
    getchar();

    if (choice == 'T' || choice == 't')
    {
        printf("Text eingeben: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        textToMorse(input);
    }
    else if (choice == 'M' || choice == 'm')
    {
        printf("Morsecode eingeben:\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        morseToText(input);
    }
    else
    {
        printf("Ungültige Auswahl.\n");
    }

    return 0;
}