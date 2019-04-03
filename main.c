#include <stdio.h>
int main(){
    char str[200], code;
    int i = 0, key = 3;
    scanf("%s", str);
    if(key<7){
        for(i = 0; str[i] != NULL; ++i){
            code = str[i];
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
        } else{
            printf("Change key");
        }
}
