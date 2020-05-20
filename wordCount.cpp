#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*统计字符数*/
int countCharacter(char* filename){
    FILE* fp;//文件指针，指向文件的起始地址
    int charCount=0;//记录字符个数
    int c;
    //判断打开文件是否存在或打开的文件是否为空
	if((fp=fopen(filename,"r"))==NULL){
		printf("open error\n");
		exit(1);
	}
	//fgetc()从指向的文件中读取一个字符，读取一个字节后，光标移动到下一个
	while(c=fgetc(fp)!=EOF){
        charCount++;
	}
    fclose(fp);//关闭文件
    return charCount;//返回字符数
}

/*统计单词数*/
int countWord(char* filename){
    FILE* fp;//文件指针，指向文件的起始地址
    int wordCount=0;//记录单词个数
    char c;
    char buffer[100];//读取文件的每一行内容
    int bufferlen; //记录文件每一行的长度
    //判断打开文件是否存在或打开的文件是否为空
	if((fp=fopen(filename,"r"))==NULL){
		printf("open error\n");
		exit(1);
	}
	//gets()从指定的流中读取数据，每次读取一行
	while(fgets(buffer,100,fp)!=NULL){
        int blank=0; //表示该字符是否为空格或逗号
		bufferlen=strlen(buffer);//获取每一行的字符串长度
		for(int i=0;i<bufferlen;i++){
			c=buffer[i]; //获取每一个字符
            if(c==' ' || c==','){
                blank=0;
            }else if(blank==0){
                blank=1;
                wordCount++;//空格或逗号的数量比单词数多1
            }
        }

	}
    fclose(fp);//关闭文件
	return wordCount;//返回单词个数
}

int main(int argc,char *argv[]){
    char *op; //字符串指针，代表查看的具体操作
	char fileName[20]; //字符数组，用于读取的文件名称
	if(argc!=3){ //判断给定的参数个数是否合法
        printf("parameter missing!\n");
        exit(1);
	}
	op=argv[1];//读取指定的操作
	if(op[1]=='c'){
        int num=countCharacter(argv[2]);
        printf("字符数为：%d\n",num);
	}
	if(op[1]=='w'){
        int num=countWord(argv[2]);
        printf("单词数为：%d\n",num);
	}
	return 0;
}
