#include <stdio.h>
void encrypter(char *str, int key);
int main(){
    char str[200];
    int key = 3;
    scanf("%s", str);
    encrypter(str, key); 
}
void encrypter(char *str, int key){ //where stuff actually gets encrypted
    int i;
        for(i = 0; str[i] != NULL; ++i){
            char code = str[i];
                if(code>=97 && code<122){
                    code = code + key;
                    printf("%c",code);
                }
                else if (code>=122){
                    code = code + key - 25;
                    printf("%c",code);
                }
                if(code>=65 && code<90){
                    code = code + key;
                    printf("%c",code);
                }
                else if (code>=90 && code<97){
                    code = code + key - 25;
                    printf("%c",code);
                }     
            }      
        } 
