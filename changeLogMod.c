/*
	Author : Shanu Dey
	Date : 25/7/2019 

*/

#include<stdio.h>
int main(int argc, char const *argv[])
{
	if(argc!=3){
		printf("Enter the file name from command line input.\nsyntax: changeLog source.txt destination.txt\n");
		return 0;
	}
	FILE *fp,*fd;
	char c,i=0;
	fp = fopen(argv[1],"r");
	fd = fopen(argv[2],"w");
	if(fp==NULL){
		printf("%s files doesn't exists.\n",argv[1]);
		return 0;
	}
	if(fd==NULL){
		printf("%s files generation failed!!!\n",argv[2]);
		return 0;
	}

	while(1){
		c = fgetc(fp);
		if(c==EOF){
			printf("File created successfuly\n");
			break;
		}
		else if(i<13){
			i++;
			continue;	
		}
		else if(c=='\n'){
			i=0;
		}
		fputc(c,fd);
	}
	fclose(fp);
	fclose(fd);
	return 0;
}