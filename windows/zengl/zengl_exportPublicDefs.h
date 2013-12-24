/*
   Copyright 2012 zenglong (made in china)

   For more information, please see www.zengl.com

   This file is part of zengl language.

   zengl language is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   zengl language is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with zengl language,the copy is in the file licence.txt.  If not,
   see <http://www.gnu.org/licenses/>.
*/

#ifndef _ZENGL_EXPORT_PUBLIC_DEFS_H_
#define _ZENGL_EXPORT_PUBLIC_DEFS_H_

#define ZL_EXP_MAJOR_VERSION 1 //zengl���汾��
#define ZL_EXP_MINOR_VERSION 3 //zengl�Ӱ汾��
#define ZL_EXP_REVISION 1      //zengl�����汾��
#define ZL_EXP_VOID void //�����Զ���ĺ�������void , char֮���C��׼���ͣ������Ժ��ͳһ�������⼸�����ͺ�Ҳ������typedef������
#ifdef ZL_EXP_OS_IN_ARM_GCC
	#define ZL_EXP_CHAR signed char //ʹ��signed��ʾ�з��ŵ���˼����ΪARM GCC��charĬ����unsigned��(Ƕ��ʽ����������ܶ����⣡)�������б�Ҫ������ָ����signed
#else
	#define ZL_EXP_CHAR char
#endif
#define ZL_EXP_INT int
#define ZL_EXP_DOUBLE double
#define ZL_EXP_NULL 0 //ָ��Ϊ0�ĺ궨��

typedef ZL_EXP_VOID (* ZL_VM_API_MOD_INIT_FUNC)(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT moduleID);
typedef ZL_EXP_VOID (* ZL_VM_API_MOD_FUN_HANDLE)(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

typedef enum _ZENGL_EXPORT_VM_MAIN_ARG_FLAGS{
	ZL_EXP_CP_AF_IN_DEBUG_MODE = 0x1,		//�����������ڴ��е��﷨�����ű����Դ���Թ����������Ե���;
	ZL_EXP_CP_AF_OUTPUT_DEBUG_INFO = 0x2,	//��ӡ����������ķ��ű�ȵ�����Ϣ
}ZENGL_EXPORT_VM_MAIN_ARG_FLAGS;

typedef enum _ZENGL_EXPORT_VM_FLAGS_HANDLE_TYPE{
	ZL_EXP_VFLAG_HANDLE_NONE,			//Ĭ�ϳ�ʼֵ
	ZL_EXP_VFLAG_HANDLE_COMPILE_INFO,	//userdef_info�û��Զ������ʾ��ͨ��Ϣ�ĺ���
	ZL_EXP_VFLAG_HANDLE_COMPILE_ERROR,	//userdef_compile_error�û��Զ������ʾ������Ϣ�ĺ�����
	ZL_EXP_VFLAG_HANDLE_RUN_INFO,		//userdef_run_info�û��Զ���Ľ���������ʾ��ͨ��Ϣ�ĺ���
	ZL_EXP_VFLAG_HANDLE_RUN_PRINT,		//userdef_run_print����ʱ��PRINTָ���Ӧ���û��Զ��庯�����
	ZL_EXP_VFLAG_HANDLE_RUN_ERROR,		//userdef_run_error�û��Զ���Ľ���������ʾ������Ϣ�ĺ�����
	ZL_EXP_VFLAG_HANDLE_MODULE_INIT,	//userdef_module_init�û��Զ����ģ���ʼ������
}ZENGL_EXPORT_VM_FLAGS_HANDLE_TYPE;

typedef enum _ZENGL_EXPORT_MOD_FUN_ARG_TYPE{
	ZL_EXP_FAT_NONE,
	ZL_EXP_FAT_INT,
	ZL_EXP_FAT_FLOAT,
	ZL_EXP_FAT_STR,
	ZL_EXP_FAT_MEMBLOCK, //�ڴ������
	ZL_EXP_FAT_ADDR,	 //ȫ�ֱ���������
	ZL_EXP_FAT_ADDR_LOC, //�ֲ�����������
	ZL_EXP_FAT_ADDR_MEMBLK,//�ڴ�������
	ZL_EXP_FAT_INVALID,	 //��Ч�Ĳ�������,��������ָʾAPI����
}ZENGL_EXPORT_MOD_FUN_ARG_TYPE; //ͨ��API��ȡ�Ĳ�������

#ifdef __cplusplus 
	#ifdef ZL_EXP_OS_IN_WINDOWS
		#define ZL_EXPORT extern "C" __declspec (dllexport) 
	#else 
		#define ZL_EXPORT extern "C" __attribute__((visibility("default")))
	#endif 
#else 
	#ifdef ZL_EXP_OS_IN_WINDOWS
		#define ZL_EXPORT __declspec (dllexport) 
	#else 
		#define ZL_EXPORT __attribute__((visibility("default")))
	#endif 
#endif

typedef struct _ZENGL_EXPORT_MEMBLOCK{
	ZL_EXP_VOID * ptr; //�ڴ��ָ��
	ZL_EXP_INT index;//�ڴ��ָ�����ڴ���е�����
}ZENGL_EXPORT_MEMBLOCK; //���飬��������ڴ��

typedef struct _ZENGL_EXPORT_ADDR{
	ZL_EXP_INT index;
	ZENGL_EXPORT_MEMBLOCK memblock;
}ZENGL_EXPORT_ADDR; //ȫ�ֱ������ֲ��������ڴ�������

typedef struct _ZENGL_EXPORT_MOD_FUN_ARG{
	ZENGL_EXPORT_MOD_FUN_ARG_TYPE type;
	struct{
		ZL_EXP_INT integer; //���������õĲ���Ϊ����ʱ
		ZL_EXP_DOUBLE floatnum; //������
		ZL_EXP_CHAR * str; //�ַ���
		ZENGL_EXPORT_MEMBLOCK memblock; //�ڴ������
		ZENGL_EXPORT_ADDR addr; //��������
	}val;
}ZENGL_EXPORT_MOD_FUN_ARG; //ͨ��API��ȡ�Ĳ����ṹ�嶨��

typedef struct _ZENGL_EXPORT_VM_MAIN_ARGS{
	ZL_EXP_INT (* userdef_info)(ZL_EXP_CHAR * infoStrPtr, ZL_EXP_INT infoStrCount, ZL_EXP_VOID * VM_ARG); //�û��Զ������ʾ��ͨ��Ϣ�ĺ������û������Զ�����Ϣ�Ĵ�ӡ�������ʽ��
	ZL_EXP_INT (* userdef_compile_error)(ZL_EXP_CHAR * infoStrPtr, ZL_EXP_INT infoStrCount, ZL_EXP_VOID * VM_ARG); //�û��Զ������ʾ������Ϣ�ĺ�����
	ZL_EXP_INT (* userdef_run_info)(ZL_EXP_CHAR * infoStrPtr, ZL_EXP_INT infoStrCount, ZL_EXP_VOID * VM_ARG); //�û��Զ���Ľ���������ʾ��ͨ��Ϣ�ĺ������û������Զ�����Ϣ�Ĵ�ӡ�������ʽ��
	ZL_EXP_INT (* userdef_run_print)(ZL_EXP_CHAR * infoStrPtr, ZL_EXP_INT infoStrCount, ZL_EXP_VOID * VM_ARG); //�û��Զ���Ľ�����PRINT֮���ָ���Ӧ�Ĵ�ӡ�����ʽ��
	ZL_EXP_INT (* userdef_run_error)(ZL_EXP_CHAR * infoStrPtr, ZL_EXP_INT infoStrCount, ZL_EXP_VOID * VM_ARG); //�û��Զ���Ľ���������ʾ������Ϣ�ĺ�����
	ZL_EXP_VOID (* userdef_module_init)(ZL_EXP_VOID * VM_ARG); //�û��Զ����ģ���ʼ������
	ZL_EXP_INT flags; //�û��Զ����һЩ���������������ѡ��
}ZENGL_EXPORT_VM_MAIN_ARGS;

#endif/* _ZENGL_EXPORT_PUBLIC_DEFS_H_ */
