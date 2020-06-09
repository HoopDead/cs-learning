#include <stdio.h>
#include <stdlib.h>

/*
Function: string_file_len

Load file, and check how much of charaters there is

in: pointer to file, and pointer to empty variable length
return: number of characters in txt file
*/
void string_file_len(FILE *file, int* length) {
    int c;
    int len = 0;
    while ((c = getc(file)) != EOF) {
        len = len+1;
    }
    *length = len;
}

/*
Function: string_file_to_char

Load characters from file to char in our program

in: pointer to file, and length
return: char of letters found in loaded file
*/

char* string_file_to_char(FILE *file, int length) {
    int c, index = 0;
    char txt[length];
    while ((c = getc(file)) != EOF) {
        txt[index] = c;
        index++;
    }
    char *str;
    for(int i = 0; i < sizeof(txt); i++) {
        str[i] = txt[i];
    }
    return str;
}

/*
Function: caesar_hash

Hash our char with defined key

in: hash_key - number of times to move character, *txt - pointer to char of characters, length - number of characters in char 
*/

void caesar_hash(int hash_key, char* txt, int length) {
    for(int i = 0; i < length; i++) {
        if (txt[i] >= 65 && txt[i] <= 90) {
            txt[i] = (((txt[i] + hash_key - 65) % 26) + 65);
        } else if (txt[i] >= 97 && txt[i] <= 122) {
            txt[i] = (((txt[i] + hash_key - 97) % 26) + 97);
        }
    }
}


void save_to_file(FILE *file, char* txt, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c - SAVED TO FILE\n", txt[i]);
        fputc(txt[i], file);
    }
}

int main()
{
    FILE *file;
    FILE *file_out;
    int length;
    file = fopen("text.txt", "r");
    file_out = fopen("out_hash.txt", "w");
    string_file_len(file, &length);
    rewind(file);
    char* txt = string_file_to_char(file, length);
    caesar_hash(213, &*txt, length);
    save_to_file(file_out, &*txt, length);
    return 0;
}
