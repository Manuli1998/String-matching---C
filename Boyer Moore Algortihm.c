#include<stdio.h>
#include<string.h>
#include<limits.h>

#define num 10
//bad character heuristic approach

int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}


char search(FILE* fptr,int jumpposition);
char stringwindow[6];
char previouswindow[6];
int position;

void nextstringwindow(FILE *fptr){
	strcpy(previouswindow,stringwindow);
	int l;
	for(l=0;l<5;l++){
		stringwindow[l]=stringwindow[l+1];
	}
	stringwindow[5]=search(fptr,1);
}

char search(FILE* fptr,int jumpposition){
	char character;
	int l;
	for(l=0;l<jumpposition;l++){
		character=fgetc(fptr);
		while(character==' ' || character=='\0'  || character=='\n' || character=='\t'){
			
					character=fgetc(fptr);
					if(character==':'){
						while(character!='\n'){
						
							character=fgetc(fptr);
						}
					}
		}
	}
position+=jumpposition;
return character;	
}


int main(){
	char date[6]="980812";
	FILE *fptr;
	fptr=fopen("pi.txt","r");
	char c,g;
	int i,r=0;
	int shift=0;
	int line_count=0;
	int flag=0;
	int size_pattern=6;
	int size_text=100000000;
	int badchararray[num];
	int count=0;
	
	
	
		
		for(i=0;i<num;i++){
			badchararray[i]=-1;
		}
		
	printf("My Birthday string is: 980812\n");
	if(fptr==NULL){
		printf("Cannot open the file!");
	}
	else{
		while(line_count<21){
				c=fgetc(fptr);
				while(c!='\n'){
					c=fgetc(fptr);
				}
				line_count++;
			}
		/*int a=ftell(fptr);
		printf("%d",a);	*/			
	//	c=fgetc(fptr);
				
		
		for(i=0;i<size_pattern;i++){
			badchararray[(int)date[i]]=i;
		}
			for(i=0;i<6;i++){
				c=fgetc(fptr);
			//printf("this point %c\n",c);
				while(c==' ' || c=='\0'  || c=='\n' || c=='\t'){
				//	printf("this point %c\n",c);
					r++;
					c=fgetc(fptr);
					if(c==':'){
						while(c!='\n'){
							r++;
							c=fgetc(fptr);
						}
					}
				}
				stringwindow[i]=c;
				previouswindow[i]=c;
			}
//		for(i=0;i<100;i++){
//		printf("string window: %s - %d\n",stringwindow,position);
//		nextstringwindow(fptr);
//	}//printf("c %c\n",c);
		
		while(1){
			if(position>=100000000){
				return 0;
			}
			int j=size_pattern-1;
			//printf("stringwindow[j] : %c, date[j]: %c\n",stringwindow[j],date[j]);
				while(j>=0 && date[j]==stringwindow[j]){
					//printf("yes\n");
					j--;	
				}
				if(j<0){
				count++;
			//	printf("%d - Pattern found at index: %d\n",count,position);
			printf("pattern found at index %d\n",position+1);
				flag=1;
				nextstringwindow(fptr);
			}
			else{
				c=stringwindow[j];
				//printf("txt[s+j] %c\n",c);
				shift=max(1,j-badchararray[c]);
				//printf("shi: %d\n\n\n",shift);
				//fseek(fptr,589+shift,SEEK_SET);
				//printf("%d\n",shift);
				int i;
				for(i=0;i<shift;i++){
					nextstringwindow(fptr);
				}	
			}
		
			}
		}
		fclose(fptr);
	if(flag==0){
		printf("Pattern isn't found in the text.");
	}
	
	return 0;
	
}

