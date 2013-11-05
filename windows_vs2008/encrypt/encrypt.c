#define ZL_EXP_OS_IN_WINDOWS //���ڸ���zenglǶ��ʽ�ű����Ե�ǰ��ִ�л�����windowsϵͳ����ֹ���ֱ������linuxϵͳ���Բ�����ZL_EXP_OS_IN_LINUX����ΪĬ�Ͼ���linuxģʽ
#include "zengl_exportfuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <stdarg.h>

 /* 
    ��������getFileSize(char * strFileName)  
    ���ܣ���ȡָ���ļ��Ĵ�С 
    ������ 
        strFileName (char *)���ļ��� 
    ����ֵ�� 
        size (int)���ļ���С 
 */  
int getFileSize(char * strFileName)   
{  
    FILE * fp = fopen(strFileName, "r"); 
	int size;
    fseek(fp, 0L, SEEK_END);  
    size = ftell(fp);  
    fclose(fp);  
    return size;  
}

int main_output_xor_source(char * src_filename,char * dest_filename,char * xor_key_str)
{
	FILE * src_pt = ZL_EXP_NULL ,* dest_pt = ZL_EXP_NULL;
	int src_filesize = 0;
	unsigned char buf[1024],enc_buf[1024],ch,enc_ch;
	int buf_len = 0,totalwrite_len = 0;
	int prev_percent = 0,cur_percent = 0;
	int cur = 0;
	int xor_key_cur = 0;
	int xor_key_len;

	if(xor_key_str == ZL_EXP_NULL)
	{
		printf("xor_key_str��Կ����Ϊ���ַ���ָ��\n");
		return -1;
	}
	xor_key_len = strlen(xor_key_str);
	src_filesize = getFileSize(src_filename);
	src_pt = fopen(src_filename,"rb");
	if(src_pt == ZL_EXP_NULL)
	{
		printf("xor���ܵ�Դ�ű��ļ��޷���\n");
		return -1;
	}
	dest_pt = fopen(dest_filename,"wb+");
	if(dest_pt == ZL_EXP_NULL)
	{
		printf("xor���ܵ�Ŀ��ű��ļ��޷��򿪻��޷�����\n");
		return -1;
	}
	while((buf_len = fread(buf,sizeof(unsigned char),1024,src_pt)) != 0)
	{
		for(cur = 0;cur < buf_len;cur++)
		{
			ch = buf[cur];
			enc_ch = ch ^ (unsigned char)xor_key_str[xor_key_cur];
			if((++xor_key_cur) >= xor_key_len)
				xor_key_cur = 0;
			enc_buf[cur] = enc_ch;
		}
		fwrite(enc_buf,sizeof(unsigned char),buf_len,dest_pt);
		totalwrite_len += buf_len;
		cur_percent = (int)(((float)totalwrite_len / (float)src_filesize) * 100);
		if(cur_percent != prev_percent)
			printf("%d%%...",cur_percent);
	}
	printf(" xor '%s' to '%s' is ok!\n",src_filename,dest_filename);
	fclose(src_pt);
	fclose(dest_pt);
	return 0;
}

/**
	�û�����ִ����ڡ�
*/
void main(int argc,char * argv[])
{
	if(argc != 4)
	{
		printf("usage: %s <src> <dest> <key> (�÷�����Ӧ���ǳ�������Դ�ļ�����Ҫ���ɵ�Ŀ���ļ�����������Կ����ʽ)\n",argv[0]);
		#ifdef ZL_EXP_OS_IN_WINDOWS
			system("pause");
		#endif
		exit(-1);
	}

	main_output_xor_source(argv[1],argv[2],argv[3]);

	#ifdef ZL_EXP_OS_IN_WINDOWS
		system("pause");
	#endif
}
