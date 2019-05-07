#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *origin, char *destination){
    destination[0]='\0';
    int i, iChar, charEncrypted;
    char x[128];
    for(i = 0; i < strlen(origin); i++){
        int iChar = (int)origin[i];
        charEncrypted = (iChar-10)*13;
        itoa(charEncrypted, x, 10);
        strcat(destination, x);
        if (i<strlen(origin)-1) {
            strcat(destination,"-");
        }
    }
}
void decrypt(char *encrypted, char *destination){
    int x, originalChar, i=0;
    char c[128];
    char *ptr = strtok(encrypted, "-"); 
	while(ptr != NULL){
        x = atoi(ptr);
        originalChar = (x/13)+10;
        destination[i]= (char)originalChar;
        printf("%c", destination[i]);
		ptr = strtok(NULL, "-");
        i++;
	}
    destination[i+1]='\0';
    printf("2");
}