#include <stdio.h>
#include <string.h>
void encrypter(char *str, int key);
void decrypter(char *str); 
void subencrypter(char *str, char *substr);
void subdecrypterknown(char *str, char *substr);
void subdecrypter(char *str);
FILE *input, *output;
int main(){
    char str[200] = {0}, substr[26];
    int key, i,ci; //Both a negative and positive key works
    input = fopen("input.txt", "r");
    output = fopen("output.txt","w");
    i = 0;
    while(!feof(input)){ //loop creates string in array str
        fscanf(input, "%c",&str[i]);
        i++;    
    }
    printf("Please Select Enter Text into test.txt as Capital Letters and Select Option\n");
	printf("1) Encryption via Caesar Cipher\n");
	printf("2) Decryption of Caesar Cipher via Brute Force Attack\n");
	printf("3) Encryption via Substitution Cipher\n");
	printf("4) Decryption of Substitution Cipher using known Cipher Text\n");
	printf("5) Decryption of Substitution Cipher using Character Frequency. At least 50 Characters are need for this.\n");
	scanf("%d", &ci);
	switch (ci) {
	case 1:
		printf("Enter Key between -26 and 26: \n");
		scanf("%d", &key);
		encrypter(str, key);
		break;
	case 2:
		printf("\nScan the Lines of Text to Find the Correct Result. There are 52 Possibilities.");
		decrypter(str);
		break;
	case 3:
		printf("Enter Custom Cipher Text\n");
		scanf("%s", substr);
		subencrypter(str,substr);
		break;
	case 4:
		printf("Enter Cipher Text that Encrypted Message\n");
		scanf("%s", substr);
		subdecrypterknown(str, substr);
		break;
	case 5:
		subdecrypter(str);;
		break;
	default: printf("Error");
	} 
	//*********************FOR TESTING PURPOSES*********************
    //encrypter(str, key); 
    //decrypter(str);//function called to encrypted each character of the string
    //subencrypter(str,substr);
    //subdecrypterknown(str,substr);
    //subdecrypter(str);
}

void encrypter(char *str, int key){ //Function takes inputs and encrypts string
    int i;
        for(i = 0; str[i] != 0; ++i){ //Runs through string until end
            char code = str[i];
            if(code == 32){ //If a space occurs, print but don't alter
                fprintf(output," ");
            }
            else{ //Shift string characters by key
                if(code>=97 && code<=122){ 
                    code = code - 32;
            }
                code = (code + key)%91; //Using modulus allows 65 to be added to code in order to reenter 65 - 90 for ascii characters
                if(code>=65){
                    fprintf(output,"%c",code);
                }

                else if(code<65 && key>0){
                    code = code + 65;
                    fprintf(output,"%c",code);
                }
                else {
                    code = code + 26;
                    fprintf(output,"%c",code);
                }

            }      
     }
 }

void decrypter(char *str){
    
    int i, key = 0;
    for(key = -26; key<26; key++){ //Attempts every key between -26 and 26, including -26, which is printing the encrypted string
        for(i = 0; str[i] != 0; ++i){ //The same code as encryption, as the string is repeatedly shifted until legible text comes out
             char code = str[i];
            if(code == 32){
                fprintf(output," ");
            }
            else{
                if(code>=97 && code<=122){
                    code = code - 32;
            }
                code = (code + key)%91;
                if(code>=65){
                    fprintf(output,"%c",code);
                }

                else if(code<65 && key>0){
                    code = code + 65;
                    fprintf(output,"%c",code);
                }
                else {
                    code = code + 26;
                    fprintf(output,"%c",code);
                }
                
            }
        }
            fprintf(output,"\n"); //Prints a new line every new key
    }
}

void subencrypter (char *str, char *substr){
    int i;
    for(i=0;str[i] != 0; i++){
        if(str[i] == 32){
            fprintf(output," ");
        }
        else{
            fprintf(output,"%c", substr[str[i]-65]);
        }
    }
}

void subdecrypterknown(char *str, char *substr){
    int i,c;
    char *ciphertext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i=0;str[i]!=0;i++){
        for(c=0;substr[c];c++){
            if(str[i]==substr[c]){
                str[i]=ciphertext[c];
                break;
                }
        }
        fprintf(output,"%c",str[i]);
    }
}
void subdecrypter (char *str){ //Unable to get this working well.
    int length, i, x, spc = 0, count[26] = {0};
    float freq;
    for(i=0;str[i] != 0; i++){
        if (str[i]>=65 && str[i]<=90){
            x = str[i] - 65;
            count[x]++; //Element Pos increased, so it may be recalled later to find freqency
        }
        else if (str[i] >=32 && str[i]<=64){
            spc++; //When non-letter character is used variable is increased by 1
        }
    }
    length = strlen(str); //string.h function to find length of string
    for(i=0;str[i]!=0;i++){ //Does not work with less than 26 characters -- However, would be innacurate with that many characters, so does not matter
        freq = (float)count[i]/(float)(length-spc); //Denominator decreased depending on number of non-letter charcters used
        if(str[i]>=65 && str[i]<=90){ //Letter is printed according to its frequency   
            if(freq>=0.12 && freq<=0.15)
                fprintf(output,"E");
            else if(freq>=0.088 && freq<0.12)
                fprintf(output,"T");
            else if(freq>=0.08 && freq<0.088)
                fprintf(output,"A");
            else if(freq>=0.075 && freq<0.08)
                fprintf(output,"O");
            else if(freq>=0.071 && freq<0.075)
                fprintf(output,"I");
            else if(freq>=0.066 && freq<0.071)
                fprintf(output,"N");
            else if(freq>=0.061 && freq<0.066)
                fprintf(output,"S");
            else if(freq>=0.06 && freq<0.061)
                fprintf(output,"R");
            else if(freq>=0.055 && freq<0.06)
                fprintf(output,"H");
            else if(freq>=0.042 && freq<0.055)
                fprintf(output,"D");
            else if(freq>=0.035 && freq<0.042)
                fprintf(output,"L");
            else if(freq>=0.028 && freq<0.035)
                fprintf(output,"U");
            else if(freq>=0.0265 && freq<0.028)
                fprintf(output,"C"); //Point of diminishing returns -- Frequencies too similar it will probably lead to further derangement
            else
                fprintf(output,"%c",str[i]);
            }
        else{
            fprintf(output,"%c",str[i]);    
        }
       //printf("%c with freq %f\n",i+65,freq); //TESTING PURPOSES
    }
}
