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

#ifndef _ZENGL_EXPORT_FUNCTIONS_H_
#define _ZENGL_EXPORT_FUNCTIONS_H_

#include "zengl_exportPublicDefs.h"

/*����ΪzenglApi�ӿڵ�������Ŀǰһ����35��API�ӿں���(�������ײ���������Щ�ڽ�ģ�麯��)*/

/*ͨ��zenglApi_Load���Լ��ز�ִ��script_file�ű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Load(ZL_EXP_CHAR * script_file,ZENGL_EXPORT_VM_MAIN_ARGS * vm_main_args);

/*�����������µ������ָ�룬��ָ�����ͨ��zenglApi_Close�����ͷţ�����ᷢ���ڴ�й©*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_Open();

/*ʹ��zenglApi_Open�򿪵������������script_file��Ӧ�Ľű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Run(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * script_file);

/*�ر�zenglApi_Open�򿪵������ָ�룬���ͷ������ռ�õ�ϵͳ��Դ*/
ZL_EXPORT ZL_EXP_INT zenglApi_Close(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ����ò�����Ӧ�������*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_Reset(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ����ر�������ʱ�ĳ�����Ϣ*/
ZL_EXPORT ZL_EXP_CHAR * zenglApi_GetErrorString(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ�������������е�һЩѡ����*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetFlags(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_VM_MAIN_ARG_FLAGS flag);

/*API�ӿڣ����������һЩ��ѡ�Ĳ������������PRINTָ���Ӧ���û��Զ������������*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetHandle(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_VM_FLAGS_HANDLE_TYPE handleType,ZL_EXP_VOID * handle);

/*API�ӿڣ����û��Զ���Ĳ���ѹ������ջ��*/
ZL_EXPORT ZL_EXP_INT zenglApi_Push(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MOD_FUN_ARG_TYPE type,ZL_EXP_CHAR * arg_str,ZL_EXP_INT arg_integer,ZL_EXP_DOUBLE arg_floatnum);

/*API�ӿڣ����ýű��е�ĳ����*/
ZL_EXPORT ZL_EXP_INT zenglApi_Call(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * script_file,ZL_EXP_CHAR * function_name,ZL_EXP_CHAR * class_name);

/*API�ӿڣ�ͨ���˽ӿڻ�ȡĳ������ֵ���ַ�����ʽ*/
ZL_EXPORT ZL_EXP_CHAR * zenglApi_GetValueAsString(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * valueName);

/*API�ӿڣ�ͨ���˽ӿڻ�ȡĳ������ֵ��������ʽ*/
ZL_EXPORT ZL_EXP_INT zenglApi_GetValueAsInt(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * valueName,ZL_EXP_INT * retValue);

/*API�ӿڣ�ͨ���˽ӿڻ�ȡĳ������ֵ�ĸ�������ʽ*/
ZL_EXPORT ZL_EXP_INT zenglApi_GetValueAsDouble(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * valueName,ZL_EXP_DOUBLE * retValue);

/*API�ӿڣ��û�����ͨ���˽ӿڶ���ģ���ʼ������*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetModInitHandle(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * moduleName,ZL_VM_API_MOD_INIT_FUNC module_init_function);

/*API�ӿڣ��û�ͨ���˽ӿڿ����Զ���ĳģ���еĺ���������*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetModFunHandle(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT moduleID,ZL_EXP_CHAR * functionName,ZL_VM_API_MOD_FUN_HANDLE handle);

/*API�ӿڣ���ȡ�ű���ģ�麯������ʱ�Ĳ�����Ϣ
  argnum Ϊ����λ�ã���1��ʼ��1�����һ��������2����ڶ����������Դ�����*/
ZL_EXPORT ZL_EXP_INT zenglApi_GetFunArg(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*API�ӿڣ��˳���ǰ�ű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Exit(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * errorStr, ...);

/*API�ӿڣ��������û��Զ����ģ�麯�������ó�����Ϣ��Ȼ�����������ִֹͣ�У���zenglApi_Exit�õĵط����ڣ����᳤��תֱ�ӽ��������Ƿ������û������˳���ʱ������Ч��ֹ�ⲿC++���ó����ڴ�й©������쳣*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetErrThenStop(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * errorStr, ...);

/*����ģ�麯���ķ���ֵ*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetRetVal(ZL_EXP_VOID * VM_ARG,
										 ZENGL_EXPORT_MOD_FUN_ARG_TYPE type,ZL_EXP_CHAR * arg_str,ZL_EXP_INT arg_integer,ZL_EXP_DOUBLE arg_floatnum);

/*API�ӿڣ�������ֵ��Ϊ�ڴ��*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetRetValAsMemBlock(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock);

/*����size���������㹻����size��Ԫ�ص��ڴ��(�ڴ���С��һ������size��ֻ�Ǵ��ڵ���size)�����飬������������ڴ��*/
ZL_EXPORT ZL_EXP_INT zenglApi_CreateMemBlock(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock,ZL_EXP_INT size);

/*�����ڴ����index - 1������Ӧ��ֵ��index����Ϊ1��ʾ������ڴ��ĵ�һ��Ԫ�أ��Դ����ƣ�����0��ʾ�ɹ�������-1��ʾretval���ʹ���*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetMemBlock(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock,ZL_EXP_INT index,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*��ȡ������ڴ���е�index - 1��������Ԫ�أ�index����Ϊ1��ʾ������ڴ��ĵ�һ��Ԫ�أ��Դ�����*/
ZL_EXPORT ZENGL_EXPORT_MOD_FUN_ARG zenglApi_GetMemBlock(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock,ZL_EXP_INT index);

/*��ȡ��argnum�����������͵���Ϣ��argnum��1��ʼ��ʾ��һ��������֮ǰ��GetFunArg����ֻ�ܻ�ȡ������ֵ��������������ã���ֱ�ӻ�ȡ���õı�����ֵ��
�����޷�֪��������������Ϣ�������޷�֪��ĳ�������Ƿ������õ����ͣ��ú�������Ի�ȡ����Щ��Ϣ��������������������ͣ��������������ȼ�*/
ZL_EXPORT ZL_EXP_INT zenglApi_GetFunArgInfo(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*���ýű�ģ�麯���е�argnum��������ֵ��argnum��1��ʼ��ʾ��һ������*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetFunArg(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*��ȡ�ڴ���size��������Ϣ*/
ZL_EXPORT ZL_EXP_INT zenglApi_GetMemBlockInfo(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock,ZL_EXP_INT * mblk_size,ZL_EXP_INT * mblk_count);

/*API�ӿڣ��û�����ͨ���˽ӿ�����;ֹͣ�ű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Stop(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ��û�����ͨ���˽ӿ�����һЩ�������ݵ�ָ��*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetExtraData(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * extraDataName,ZL_EXP_VOID * point);

/*API�ӿڣ��û�����ͨ���˽ӿڵõ���������*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_GetExtraData(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * extraDataName);

/*API�ӿڣ��û�����ͨ���˽ӿڵõ�����������ݣ���Ϊ�����GetExtraData����չ��������������extraDataName��������ʱ������NULL�������ǲ���������Ϣ�˳��������
  ����Ҳ����ͬʱ�����������Ƿ����*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_GetExtraDataEx(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * extraDataName);

/*API�ӿڣ��û�ͨ���˽ӿ����ýű�Դ�����XOR��ͨ������������Կ*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetSourceXorKey(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * xor_key_str);

/*API�ӿڣ��û�ͨ���˽ӿ����ýű�Դ�����RC4������Կ*/
ZL_EXPORT ZL_EXP_INT zenglApi_SetSourceRC4Key(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * rc4_key_str,ZL_EXP_INT rc4_key_len);

/*API�ӿڣ��û�ͨ���˽ӿڽ��ַ���������������У�������C++�оͿ�����ǰ��Դ�ַ�����Դ���ֶ��ͷŵ�����������������е��·������Դ����ڽ���ʱ�Զ��ͷŵ���
  ��ֹ�ڴ�й©*/
ZL_EXPORT ZL_EXP_CHAR * zenglApi_AllocMemForString(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * src_str);

/*API�ӿڣ��û�ͨ���˽ӿ���������з���һ���ڴ�ռ�*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_AllocMem(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT size);

/*API�ӿڣ���AllocMem�������Դ�ֶ��ͷŵ�����ֹ��ԴԽ��Խ��*/
ZL_EXPORT ZL_EXP_INT zenglApi_FreeMem(ZL_EXP_VOID * VM_ARG,ZL_EXP_VOID * ptr);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
		�����������Ϊ�û��ṩ���ڽ�ģ�麯��������
********************************************************************************/

/*array�ڽ�ģ�麯�������ڴ���zengl�ű��Ķ�̬����*/
ZL_EXPORT ZL_EXP_VOID zenglApiBMF_array(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

/*bltExitģ�麯����ֱ���˳�zengl�ű�*/
ZL_EXPORT ZL_EXP_VOID zenglApiBMF_bltExit(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

/*bltConvToIntģ�麯����������תΪ������ʽ*/
ZL_EXPORT ZL_EXP_VOID zenglApiBMF_bltConvToInt(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

/*	bltIntToStrģ�麯����
	������תΪ�ַ�������ʽ������bltIntToStr(25,5,'0')��ô�õ��Ľ�������ַ���'00025'
	��Ϊ�ڶ�������5��ָ�ܿ�ȣ���һ������25�Ŀ��ֻ��2��С��5��
	������߻��Ե���������'0'���롣
	�������ʹ�ò��룬������bltIntToStr(25,0,'0')�����ĸ�ʽ�����ڶ����ܿ�Ȳ�����Ϊ0���Ͳ���Ӧ�ò��빦��
*/
ZL_EXPORT ZL_EXP_VOID zenglApiBMF_bltIntToStr(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

/*bltRandomģ�麯�������������*/
ZL_EXPORT ZL_EXP_VOID zenglApiBMF_bltRandom(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argcount);

/********************************************************************************
		�����������Ϊ�û��ṩ���ڽ�ģ�麯��������
********************************************************************************/

#endif/* _ZENGL_EXPORT_FUNCTIONS_H_ */
