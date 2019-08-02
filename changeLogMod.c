/*
	Author : Shanu Dey
	Build Date : 25/7/2019 
	Updated on : 2/08/2019
*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	if(argc!=3){
		printf("Enter the file name from command line input.\nsyntax: changeLog source.txt destination.txt\n");
		return 0;
	}

	FILE *fp,*fd;
	char c,isignored;
	char first_line[255];
	int number_of_character_removed,number_of_changelogs,i,j;
	char *log_command="git --git-dir ../.git log --pretty=oneline --abbrev-commit -n %d > raw.txt";
	char mod_command[255];
	char next_line[255];

	printf("\nEnter the number of change logs you want (Default=5) : ");
	scanf("%d",&number_of_changelogs);
	snprintf(mod_command,255,log_command,number_of_changelogs);
	//printf("new command = %s\n",mod_command);

	int status = system(mod_command);
	//printf("status  = %d\n",status);
	if(status!=0){
		printf(" ### Opps, Something went wrong !!! ###\n");
		return 0;
	}

	fp = fopen(argv[1],"r");
	fd = fopen(argv[2],"w");
	if(fp==NULL){
		printf("%s files doesn't exists.\n",argv[1]);
		return 0;
	}
	if(fd==NULL){
		printf(" ### Opps! %s files generation failed!!! ###\n",argv[2]);
		return 0;
	}

	fscanf(fp,"%[^\n]s",first_line);
	printf("\n%s",first_line);
	printf("\nEnter the number of character you want to remove from the above line (Default=13) : ");
	scanf("%d",&number_of_character_removed);
	fseek( fp, 7, SEEK_SET );

	printf("\n* Change Logs : \n");
	for(i=0;i<number_of_changelogs;i++){
		fseek( fp, 1, SEEK_CUR);
		if(fscanf(fp,"%[^\n]s",next_line)==EOF){
			break;
		}
		printf("%d) %s\n",i+1,next_line+number_of_character_removed);
		fprintf(fd, "%d) %s\n", i+1,next_line+number_of_character_removed);
	}
	fclose(fp);
	fclose(fd);
	printf("\t *** output file : outputLog.txt *** \n");
	printf("  ### Change Logs created successfully ### \n");

	printf("\nDo you want to ignore ChangeLogs-Generator? (Default=n[no] | y[yes]) : ");
	scanf(" %c",&isignored);
	if(isignored=='y'){
		status = system("echo \"ChangeLogs-Generator/\" >> ../.gitignore");
		if(status!=0){ 
			printf(" ### Opps, Something went wrong !!! ###\n");
			return 0;
		}
		printf(" ### ChangeLogs-Generator ignored successfully ###\n");
	}
	return 0;
}