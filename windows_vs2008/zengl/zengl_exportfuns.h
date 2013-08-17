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

/*ͨ��zenglApi_Load���Լ��ز�ִ��script_file�ű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Load(ZL_EXP_CHAR * script_file,ZENGL_EXPORT_VM_MAIN_ARGS * vm_main_args);

/*�����������µ������ָ�룬��ָ�����ͨ��zenglApi_Close�����ͷţ�����ᷢ���ڴ�й©*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_Open();

/*ʹ��zenglApi_Open�򿪵������������script_file��Ӧ�Ľű�*/
ZL_EXPORT ZL_EXP_INT zenglApi_Run(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * script_file);

/*�ر�zenglApi_Open�򿪵������ָ�룬���ͷ������ռ�õ�ϵͳ��Դ*/
ZL_EXPORT ZL_EXP_VOID zenglApi_Close(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ����ò�����Ӧ�������*/
ZL_EXPORT ZL_EXP_VOID * zenglApi_Reset(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ����ر�������ʱ�ĳ�����Ϣ*/
ZL_EXPORT ZL_EXP_CHAR * zenglApi_GetErrorString(ZL_EXP_VOID * VM_ARG);

/*API�ӿڣ�������������е�һЩѡ����*/
ZL_EXPORT ZL_EXP_VOID zenglApi_SetFlags(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_VM_MAIN_ARG_FLAGS flag);

/*API�ӿڣ����������һЩ��ѡ�Ĳ������������PRINTָ���Ӧ���û��Զ������������*/
ZL_EXPORT ZL_EXP_VOID zenglApi_SetHandle(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_VM_FLAGS_HANDLE_TYPE handleType,ZL_EXP_VOID * handle);

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
ZL_EXPORT ZL_EXP_VOID zenglApi_SetModFunHandle(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT moduleID,ZL_EXP_CHAR * functionName,ZL_VM_API_MOD_FUN_HANDLE handle);

/*API�ӿڣ���ȡ�ű���ģ�麯������ʱ�Ĳ�����Ϣ
  argnum Ϊ����λ�ã���1��ʼ��1�����һ��������2����ڶ����������Դ�����*/
ZL_EXPORT ZL_EXP_VOID zenglApi_GetFunArg(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*API�ӿڣ��˳���ǰ�ű�*/
ZL_EXPORT ZL_EXP_VOID zenglApi_Exit(ZL_EXP_VOID * VM_ARG,ZL_EXP_CHAR * errorStr, ...);

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
ZL_EXPORT ZL_EXP_VOID zenglApi_GetFunArgInfo(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*���ýű�ģ�麯���е�argnum��������ֵ��argnum��1��ʼ��ʾ��һ������*/
ZL_EXPORT ZL_EXP_VOID zenglApi_SetFunArg(ZL_EXP_VOID * VM_ARG,ZL_EXP_INT argnum,ZENGL_EXPORT_MOD_FUN_ARG * retval);

/*��ȡ�ڴ���size��������Ϣ*/
ZL_EXPORT ZL_EXP_VOID zenglApi_GetMemBlockInfo(ZL_EXP_VOID * VM_ARG,ZENGL_EXPORT_MEMBLOCK * memblock,ZL_EXP_INT * mblk_size,ZL_EXP_INT * mblk_count);

/*API�ӿڣ��û�����ͨ���˽ӿ�����;ֹͣ�ű�*/
ZL_EXPORT ZL_EXP_VOID zenglApi_Stop(ZL_EXP_VOID * VM_ARG);

#endif/* _ZENGL_EXPORT_FUNCTIONS_H_ */
