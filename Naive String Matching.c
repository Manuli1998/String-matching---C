#include<stdio.h>

//Assumed that the text in PI starts from the index 1 .
int main(){
	char date[6]="980812"; //my birthday: 1998.08.12
	FILE *fptr;// file pointer
	fptr=fopen("pi.txt","r");
	char c;
	int line_count=0;
	int i,a=0;
	int j,flag=0;
	int count=1;
	int size_text=100000000;
	int size_pattern=6;
	
	printf("\n\nMy birthday string is : 980812\n\n");
	if(fptr==NULL){
		printf("Cannot open the file!");
	}
	else{
	
		while(c!=EOF){
			while(line_count<21){//ignore the first 21lines  of PI as they are just text
				c=fgetc(fptr);
				while(c!='\n'){
				c=fgetc(fptr);
				}
				line_count++;
			}
			for(i=0;i<size_text-size_pattern;i++){
					
					for(j=0;j<size_pattern;j++){
							c=fgetc(fptr);
							
					
					while(c==' ' || c=='\0' || c=='\t' || c=='\n') { //ignore spaces, line ends, newlines andtab spaces.
						c=fgetc(fptr);
						if(c==':'){//to ignore the character " : "
						while(c!='\n'){
							c=fgetc(fptr);
						}
					}
					}
					//printf("%c\n",c);
					//printf("count: %d\n",count);
					count++;				
				
						
					
						if(c!=date[j]){ //if single string doesnt match, break
							break;
						}
						
					}
					if(j==size_pattern){
							printf("Pattern Found in index %d \n",count-size_pattern);
							flag=1;
						}
					
			}
			printf("%d\n",i);
		}	
	}
	fclose(fptr);
	if(flag==0){
		printf("Pattern isn't found in the text.");
	}
	printf("*************************************************************************************");
	
	return 0;
	}
	
	

