#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char op[2];
	char fileName[20];
	char buffer[1000];//每一行读取的内容
	char c;
	int wordCount=0; //统计单词个数
	int charCount=0; //统计字符个数
	int isBlank=1; //等于1表示上一个不是逗号或者空格
	int bufferlen;
	scanf("%s%s",op,fileName);
	FILE* fp=fopen(fileName,"r");
	if(fp==NULL){
		printf("Can't open the file\n");
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);//获取字符串长度
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
		printf("字符数为：%d\n",charCount);
	}
	if(op[1]=='w'){
		printf("单词数为：%d\n",wordCount);
	}

	return 0;
}
