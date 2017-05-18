/*
   Copyright 2017 zenglong (made in china)

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

#ifndef _ZENGL_HASH_ARRAY_H_
#define _ZENGL_HASH_ARRAY_H_

#include "zengl_global_header.h"

#define ZL_R_HASH_CODE_TABLE_SIZE 10 // ��ϣ����ĳ�ʼ������̬���ݵĴ�С
#define ZL_R_HASH_STR_POOL_SIZE 120  // ��ϣ�ַ����صĳ�ʼ������̬���ݵĴ�С
#define ZL_R_HASH_CODE_SHIFT 4  // ��ϣֵ�ļ�������

typedef struct _ZENGL_RUN_HASH_CODE_TABLE_MEMBER{
	ZL_INT hash_code; // �ַ�����hash code
	ZL_INT str_len;   // �ַ����ĳ���
	ZL_INT str_offset; // �ַ������ַ������е��ֽ�ƫ��ֵ
	ZL_INT memblock_index; // �ڴ���У��ַ�����Ӧ����ʵ������ֵ
}ZENGL_RUN_HASH_CODE_TABLE_MEMBER; // ��ϣ�����е�����Ա�Ķ���

typedef struct _ZENGL_RUN_HASH_CODE_TABLE{
	ZL_INT size; // ��ϣ���Ӧ�Ķ�̬����ĳߴ�
	ZL_INT count; // ��ϣ���д洢��Ԫ�ظ���
	ZL_INT mempool_index; //�����membersָ�����ڴ���е�����
	ZENGL_RUN_HASH_CODE_TABLE_MEMBER * members; // ��ž���Ĺ�ϣ�����Ա
}ZENGL_RUN_HASH_CODE_TABLE; // ��ϣ����Ľṹ����

typedef struct _ZENGL_RUN_HASH_STR_POOL{
	ZL_INT size; // �ַ����صĳߴ�
	ZL_INT count; // �ַ�������ʵ�ʰ������ַ���
	ZL_INT mempool_index; //�����ptrָ�����ڴ���е�����
	ZL_CHAR * ptr; // ��������ַ���
}ZENGL_RUN_HASH_STR_POOL; // ��ϣ�����е��ַ�����

typedef struct _ZENGL_RUN_HASH_ARRAY{
	ZENGL_RUN_HASH_CODE_TABLE hash_code_table; // ��ϣ�����еĹ�ϣ��
	ZENGL_RUN_HASH_STR_POOL str_pool; // ��ϣ�����е��ַ������洢��str_pool��
}ZENGL_RUN_HASH_ARRAY;

#endif/* _ZENGL_HASH_ARRAY_H_ */
