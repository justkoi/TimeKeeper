#pragma once

#include <vector>

using namespace std;



class cEmSpriteList
{
private:
	typedef struct List
	{
		stdEMString		m_sName;

		List*			m_pNext;

		List(const stdEMString sPush)
		{
			m_sName = sPush;
			m_pNext	= NULL;
		}
	} List;

private:
	vector<stdEMString>		m_Table;

	//CRITICAL_SECTION		m_csLock;


	List*				m_pHead;

public:
	cEmSpriteList();
	~cEmSpriteList();

public:
	stdEMString GetString(UINT index);
	void Commit(const stdEMString temp);
	void Clear();

	int GetSize();

protected:
	void Entry(List** ppTemp, const stdEMString sPush);
	void Destroy(List** ppTemp);
};