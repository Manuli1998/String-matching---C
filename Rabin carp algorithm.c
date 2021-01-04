#include<stdio.h>
#include<string.h>
#include<limits.h>
# define q 11
#define d 10



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
	char c;
	char g;
	int i,j=0;
	int z,r=0;
	int xyz=0;
	int hash_p=0;
	int hash_t=0;
	int hash_val=1;
	int line_count=0;
	int size_pattern=6;
	int size_text=100000000;
	int count=0;

	printf("My Birthday string is: 980812\n\n");

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

int xd=ftell(fptr);			
c=fgetc(fptr);				

for(i=0;i<size_pattern-1;i++){
	hash_val=(hash_val*d)%q;
}


		for(i=0;i<size_pattern;i++){
			hash_p=(d*hash_p+date[i])%q;
			c=fseek(fptr,i+589,SEEK_SET);
			c=fgetc(fptr);
			while(c==' ' || c=='\0'  || c=='\n' || c=='\t'){
				c=fgetc(fptr);
				if(c==':'){
					while(c!='\n'){
						c=fgetc(fptr);
					}
				}
			}
			
	//	printf("%d %c\n",i,c);
			hash_t=(d*hash_t+c)%q;
	}
	c=fseek(fptr,xd-1,SEEK_SET);
	c=fgetc(fptr);
	
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
	
/*	for(i=0;i<100;i++){
		printf("string window: %s\n",stringwindow);
		nextstringwindow(fptr);
	}*/
	

	for(i=0;i<size_text-size_pattern;i++){
		
		if(hash_p==hash_t){
			for(j=0;j<6;j++) {
				if(stringwindow[j]!=date[j]){
					j++;
					break;
				}
				
				
			}
			if(j==size_pattern){
				count++;
				printf("pattern found at index %d\n",position+1);
			//	printf("%d- pattern found at index %d\n",count,position);
				
			}			
		}
		
			if(i<size_text-size_pattern){
				nextstringwindow(fptr);
			//	printf("add %c, reduce %c\n",previouswindow[0],stringwindow[5]);
				hash_t=(d*(hash_t-previouswindow[0]*hash_val)+stringwindow[5])%q;
				if(hash_t<0){
					hash_t=(hash_t+q);
				}
			//	printf("hash_t %d, hash_p %d\n",hash_t,hash_p);
			}
		}
	}


return 0;
}
		

