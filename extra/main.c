#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <unistd.h>

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
	char* key;
	
	printf("Select submenu:\n\t1: encrypt\n\t2: decrypt\n\t3: cancel\n>> ");
	scanf("%d",&mode);
	switch(mode){
		case 1:
		case 2:
			key=getpass("key>> ");
			
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
