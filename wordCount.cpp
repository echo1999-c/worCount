#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char op[2];
	char fileName[20];
	char buffer[1000];//ÿһ�ж�ȡ������
	char c;
	int wordCount=0; //ͳ�Ƶ��ʸ���
	int charCount=0; //ͳ���ַ�����
	int isBlank=1; //����1��ʾ��һ�����Ƕ��Ż��߿ո�
	int bufferlen;
	scanf("%s%s",op,fileName);
	FILE* fp=fopen(fileName,"r");
	if(fp==NULL){
		printf("Can't open the file\n");
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);//��ȡ�ַ�������
		//charCount+=bufferlen;
		for(int i=0;i<bufferlen;i++){
			c=buffer[i];
			charCount++;
			if((c==',' || c==' ' ) && isBlank==1){
				wordCount++;
				isBlank=0;
			}
			else if(c=='\n' && isBlank==1){
				wordCount++;
				isBlank=1;
			}
			else{
				isBlank=1;
			}
		}
	}

	if(op[1]=='c'){
		printf("�ַ���Ϊ��%d\n",charCount);
	}
	if(op[1]=='w'){
		printf("������Ϊ��%d\n",wordCount);
	}

	return 0;
}
