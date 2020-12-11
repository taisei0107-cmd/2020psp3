#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int key_len = strlen(key);
    int text_len = strlen(text);
    int pos=0,start;
    for(start=0;start<text_len;start++) {
        for(pos=0;pos<key_len;pos++) {
            if(text[start+pos] == key[pos]) {
                if(pos == key_len - 1) {
                    return &text[start];
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    int i;
    int text_len = strlen(text);
    int key_len = strlen(key);
    int index = key_len-1;
    int key_index,k;
    int table[256];
    for(i=0;i<ALPHABET_LEN;i++) {
        table[i]=key_len;
    }
    for(i=0;i<key_len;i++) {
        table[key[i]] = index - i;
    }

    while(index<text_len) {
        k = index;
        for(key_index=key_len-1;key_index>-1;key_index=key_index-1) {
            if(text[index]==key[key_index]) {
                if(key_index == 0) {
                    return &text[index];
                } else {
                    index = index - 1;
                }
            } else {
                break;
            }
        }
        if(k >= index + table[text[k]]) {
        index = k + 1;
        } else {
            index = index + table[text[k]];
        }
    }
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}