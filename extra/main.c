#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

typedef struct node{
	char eng[256];
	char jpn[256];
	struct node* next;
} node;

int convert(int mode, const char* filename, const char* key)
{
	int i=0;
	FILE* fp=NULL;
	FILE* tmp=NULL;
	unsigned char hash[16];
	unsigned char checksum[16];
	node* loop[16];
	node* cur=NULL;
	char c='\0';
	
	printf("Opening file...\n");
	
	if(!(tmp=tmpfile())){
		fprintf(stderr,"Error: Failed to create tempfile.\n");
		return -1;
	}
	
	if(!(fp=fopen(filename,"r"))){
		fprintf(stderr,"Error: Failed to open \"%s\".\n", filename);
		fclose(tmp);
		return -1;
	}
	
	printf("Calculating md5 hash...\n");
	
	MD5(key,strlen(key),hash);
	MD5(hash,16,checksum);
	
	printf("\t    hash: ");
	for(i=0;i<16;i++)
		printf("%02x",hash[i]);
	printf("\n");
	
	printf("\tchecksum: ");
	for(i=0;i<16;i++)
		printf("%02x",checksum[i]);
	printf("\n");
	
	if(mode==1){
		printf("Verifing checksum...\n");
		
		for(i=0;i<16;i++)
			if(fgetc(fp)!=checksum[i]){
				printf("Error: Wrong hashkey.\n");
				fclose(fp);
				fclose(tmp);
				return -1;
			}
	}
	
	printf("Creating hash circle...\n");
	
	for(i=0;i<16;i++)
		loop[i]=(node*)malloc(sizeof(node));
	for(i=0;i<15;i++)
		loop[i]->next=loop[i+1];
	loop[15]->next=loop[0];
	
	for(i=0;i<16;i++)
		loop[i]->eng[0]=hash[i];
	cur=loop[0];
	
	printf("Converting...\n");
	
	while((c=fgetc(fp))!=EOF){
		fputc(c^cur->eng[0],tmp);
		cur=cur->next;
	}
	fflush(tmp);
	rewind(tmp);
	
	printf("Closing hash circle...\n");
	
	for(i=0;i<16;i++)
		free(loop[i]);
	
	printf("Reopening file...\n");
	
	fclose(fp);
	if(!(fp=fopen(filename,"w"))){
		fprintf(stderr,"Error: Failed to open \"%s\".\n", filename);
		fclose(tmp);
		return -1;
	}
	
	printf("Writing to file...\n");
	
	if(mode==0)
		for(i=0;i<16;i++)
			fputc(checksum[i],fp);
	
	while((c=fgetc(tmp))!=EOF)
		fputc(c,fp);
	
	printf("Closing file...\n");
	
	fclose(fp);
	fclose(tmp);
	
	printf("Everything done!\n");
	
	return 0;
}

int main (void)
{
	int mode=0;
	char key[256]="";
	
	printf("Select submenu:\n\t1: encrypt\n\t2: decrypt\n\t3: cancel\n>> ");
	scanf("%d",&mode);
	switch(mode){
		case 1:
		case 2:
			printf("key>> ");
			while(getchar()!='\n');
			fgets(key,256,stdin);
			if(strchr(key,'\n')){
				key[strlen(key)-1]='\0';
			}else{
				while(getchar()!='\n');
			}
			
			if(convert(mode-1,"dicdata.txt",key)==0){
				printf("Success.\n");
			}else{
				printf("Failed.\n");
			}
			
			break;
		
		case 3:
			break;
		
		default:
			printf("Select must be number (1-3)\n");
	}
	
	return 0;
}