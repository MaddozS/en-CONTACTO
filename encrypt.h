#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void encrypt(char *origin, char *destination){
    int i, iChar, charEncrypted;
    char *x;
    for(i = 0; i < strlen(origin); i++){
        int iChar = (int)origin[i];
        charEncrypted = (iChar-10)*13;

        sprintf(x, "%d", charEncrypted);
        strcat(destination, x);

        if (i<strlen(origin)-1) {
            strcat(destination,"-");
        }
    }
}
void decrypt(char *encrypted, char *destination){
    int x, originalChar;
    char *c, iToken[30];
    char *ptr = strtok(encrypted, "-"); 

	while(ptr != NULL){
        x = atoi(ptr);
        originalChar = (x/13)+10;
        printf("%c", originalChar);
		ptr = strtok(NULL, "-");
	}
}