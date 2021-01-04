#include<stdio.h>

//Assumed that the text in PI starts from the index 0 .
int main(){
	char date[6]="980812"; //my birthday: 1998.08.12
	FILE *fptr;// file pointer
	fptr=fopen("pi.txt","r");
	char c;
	int line_count=0;
	int l=0;
	int i,a=0;
	int j,flag=0;
	int flag1=0;
	int count=1;
//	int kount=0;
	int size_text=100000000;
	int size_pattern=6;
	int prefix_table[size_pattern];
	printf("\n\nMy birthday string is : 980812\n\n");
	if(fptr==NULL){
		printf("Cannot open the file!");
	}
	else{
	
		while(flag1!=1){
			
			while(line_count<21){//ignore the first 21lines  of PI as they are just text
				c=fgetc(fptr);
				while(c!='\n'){
				c=fgetc(fptr);
				}
				line_count++;
			}
			
			prefix_table[0]=0;

			for(a=1;a<size_pattern;a++){
				if(date[a]==date[l]){
					l++;
					prefix_table[a]=l;
				
				}
				else{
					if(l!=0){
						l=prefix_table[l-1];
						a--;
					}
					else{
						prefix_table[a]=0;
					
					}
				}
			}
			while(count<size_text){
				
				
					while(c==' ' || c=='\0' || c=='\t' ||c=='\n'){ //ignore spaces, line ends, newlines andtab spaces.
						c=fgetc(fptr);
						if(c==':'){//to ignore the character " : "
						while(c!='\n'){
							c=fgetc(fptr);
						}
				

					}
					}

				if(c==date[j]){
					j++;
					c=fgetc(fptr);
					while(c==' ' || c=='\0' || c=='\t' ||c=='\n'){ //ignore spaces, line ends, newlines andtab spaces.
						c=fgetc(fptr);
						if(c==':'){//to ignore the character " : "
						while(c!='\n'){
							c=fgetc(fptr);
						}

					}
					}
					count++;
			}
				if(j==size_pattern){
					//kount++;
					printf("pattern found at index %d \n",count-j);
					flag=1;
					j=prefix_table[j-1];
				}
				else if(count<size_text && date[j]!=c){
					if(j!=0){
						j=prefix_table[j-1];
					}
					else{	
						count++;

						c=fgetc(fptr);
						while(c==' ' || c=='\0' || c=='\t' ||c=='\n'){ //ignore spaces, line ends, newlines andtab spaces.
						c=fgetc(fptr);
						if(c==':'){//to ignore the character " : "
						while(c!='\n'){
							c=fgetc(fptr);
						}

					}
					}
					}
				}
			}
			if(c=='2'){
				flag1=1;
				break;
			}
						
				
					
					
					
			}
			

		}	
	
	fclose(fptr);
	if(flag==0){
		printf("Pattern isn't found in the text.");
	}
	printf("*************************************************************************************");
	
	return 0;
	}
	
	

