#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int pos=0,start,key_len=4;
    for(start=0;start<48;start++) {
        for(pos=0;pos<key_len;pos++) {
            if(text[start+pos] == key[pos]) {
                if(pos == 3) {
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
    int table[256];
    int index=3,key_index,i;
    for(i=0;i<ALPHABET_LEN;i++) {
        table[i]=4;
    }
    table['d']=0,table['n']=1,table['i']=2,table['w']=3;

    while(index<48) {
        
        for(key_index=3;key_index>-1;key_index=key_index-1) {
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
        if(index < index + table[text[index]]) {
        index = index + table[text[index]];
        } else {
            index = index + 1;
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