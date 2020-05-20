#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*ͳ���ַ���*/
int countCharacter(char* filename){
    FILE* fp;//�ļ�ָ�룬ָ���ļ�����ʼ��ַ
    int charCount=0;//��¼�ַ�����
    int c;
    //�жϴ��ļ��Ƿ���ڻ�򿪵��ļ��Ƿ�Ϊ��
	if((fp=fopen(filename,"r"))==NULL){
		printf("open error\n");
		exit(1);
	}
	//fgetc()��ָ����ļ��ж�ȡһ���ַ�����ȡһ���ֽں󣬹���ƶ�����һ��
	while(c=fgetc(fp)!=EOF){
        charCount++;
	}
    fclose(fp);//�ر��ļ�
    return charCount;//�����ַ���
}

/*ͳ�Ƶ�����*/
int countWord(char* filename){
    FILE* fp;//�ļ�ָ�룬ָ���ļ�����ʼ��ַ
    int wordCount=0;//��¼���ʸ���
    char c;
    char buffer[100];//��ȡ�ļ���ÿһ������
    int bufferlen; //��¼�ļ�ÿһ�еĳ���
    //�жϴ��ļ��Ƿ���ڻ�򿪵��ļ��Ƿ�Ϊ��
	if((fp=fopen(filename,"r"))==NULL){
		printf("open error\n");
		exit(1);
	}
	//gets()��ָ�������ж�ȡ���ݣ�ÿ�ζ�ȡһ��
	while(fgets(buffer,100,fp)!=NULL){
        int blank=0; //��ʾ���ַ��Ƿ�Ϊ�ո�򶺺�
		bufferlen=strlen(buffer);//��ȡÿһ�е��ַ�������
		for(int i=0;i<bufferlen;i++){
			c=buffer[i]; //��ȡÿһ���ַ�
            if(c==' ' || c==','){
                blank=0;
            }else if(blank==0){
                blank=1;
                wordCount++;//�ո�򶺺ŵ������ȵ�������1
            }
        }

	}
    fclose(fp);//�ر��ļ�
	return wordCount;//���ص��ʸ���
}

int main(int argc,char *argv[]){
    char *op; //�ַ���ָ�룬����鿴�ľ������
	char fileName[20]; //�ַ����飬���ڶ�ȡ���ļ�����
	if(argc!=3){ //�жϸ����Ĳ��������Ƿ�Ϸ�
        printf("parameter missing!\n");
        exit(1);
	}
	op=argv[1];//��ȡָ���Ĳ���
	if(op[1]=='c'){
        int num=countCharacter(argv[2]);
        printf("�ַ���Ϊ��%d\n",num);
	}
	if(op[1]=='w'){
        int num=countWord(argv[2]);
        printf("������Ϊ��%d\n",num);
	}
	return 0;
}
