#include <stdio.h>
void encrypter(char *str, int key);
FILE *test;
int main(){
    char str[200] = {0};
    int key = 2, i;
    test = fopen("test.txt", "r");
    i = 0;
    while(!feof(test)){ //loop creates string in array str
        fscanf(test, "%c",&str[i]);
        i++;    
    }
    encrypter(str, key);    //function called to encrypted each character of the string
}
void encrypter(char *str, int key){ //where stuff actually gets encrypted
    int i;
        for(i = 0; str[i] != 0; ++i){
            char code = str[i];
            if(code == 32){
                printf(" ");
            }
            else if(code>=97 && code<=122){
                code = code - 32;
            
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