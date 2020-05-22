#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char buff[1024];
	int i;

	fp = fopen("file.txt", "r");

	if (fp == NULL){
		printf("error opening file idiot");
		(EXIT_FAILURE);	
	}

	while(feof(fp) == 0){
		buff[i] = fgetc(fp);
		printf("%c\n", buff[i]);

	}	
	fclose(fp);
	return(0);
}







