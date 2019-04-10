#include <stdio.h>
void encrypter(char *str, int key);
int main(){
    char str[200];
    int key = 0;
    scanf("%s", str);
    encrypter(str, key); 
}
void encrypter(char *str, int key){ //where stuff actually gets encrypted
    int i;
        for(i = 0; str[i] != NULL; ++i){
            char code = str[i];
                code = (code + key)%91;
                if(code>=65)
                    printf("%c",code);
                else if(code<65 && key>0){
                    code = code + 65;
                    printf("%c",code);
                }
                else{
                    code = code + 26;
                    printf("%c",code);
                }

            }      
        } 
/*
#include <stdio.h>
int main(){
FILE *input;
FILE *output;
input = fopen("test.txt", "r");
output = fopen("outtest.txt", "w");
while(!feof(input)){
    char c;
    fscanf(input,"%c", &c);
    fprintf(output,"%c",c);
}
}
*/