// DBase.h: interface for the DBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBASE_H__523EF433_75BC_403A_BD86_422E95F363AB__INCLUDED_)
#define AFX_DBASE_H__523EF433_75BC_403A_BD86_422E95F363AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Student.h"
#include <fstream>

#define DataOffset  (8+4+4)
using namespace std;

template <class T>
class DBase  
{
private:
	char versionTag[8];     // �汾��ʶ

	char *   filename;      // �ļ���
	fstream  file;          // �ļ�

	long     recordSpace;   // ��Ч��¼��Ŀ
	long     recordCount;   // �ռ��С
	void writeRecordHead();
	void readRecordHead();

public:
	DBase();
	DBase(char * filename);
	virtual ~DBase();

	void open();
	void close();
    void create();

	int getCount();

	void insert(T * s);
	bool load(long no, T & data);              // ����ĳһ����¼
	T *  loadAll();                            // �������еļ�¼
	void remove(long no);
};


#endif // !defined(AFX_DBASE_H__523EF433_75BC_403A_BD86_422E95F363AB__INCLUDED_)
