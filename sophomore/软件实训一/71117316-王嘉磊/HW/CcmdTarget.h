#pragma once

#ifndef CMDTARGET_H
#define CMDTARGET_H

// �������� cmdTarget
class cmdTarget;

// ���� MY_MSGMAP_ENTRY �ṹ�� (��Ϣӳ���)
struct MY_MSGMAP_ENTRY;

// ���� MY_MSGMAP �ṹ�� ����Ϣӳ���
struct MY_MSGMAP;



// DELERE_MESSAGE_MAP �궨��
// BEGIN_MESSAGE_MAP �궨��
// END_MESSAGE_MAP �궨��

#define DECLARE_MESSAGE_MAP()\
	private:\
		static const MY_MSGMAP_ENTRY _messageEntries[];\
	protected:\
		static const MY_MSGMAP messageMap;\
		static const MY_MSGMAP* _GetBaseMessageMap();\
		virtual const MY_MSGMAP* GetMessageMap() const;\

#define BEGIN_MESSAGE_MAP(theClass, baseClass)\
	const MY_MSGMAP* theClass::_GetBaseMessageMap()\
		{ return &baseClass::messageMap; }\
	const MY_MSGMAP* theClass::GetMessageMap() const\
		{ return &theClass::messageMap; }\
	const MY_MSGMAP theClass::messageMap =\
		{ &theClass::_GetBaseMessageMap, &theClass::_messageEntries[0] };\
	const MY_MSGMAP_ENTRY theClass::_messageEntries[] = \
		{\

#define END_MESSAGE_MAP()\
	{0, 0}\
};\

#define ON_MESSAGE(mymessage, solution)\
{ mymessage, (MY_PMSG)solution},\

class cmdTarget
{
	DECLARE_MESSAGE_MAP();
public:
	// �˺������ڲ��Ҷ�Ӧ�Ĵ�����
	void check(unsigned, int*, int);
};

// �Զ������� MY_PMSG
typedef void (*MY_PMSG)(int*, int);

// ���� MSGMAP_ENTRY ��Ϣӳ��� 
struct MY_MSGMAP_ENTRY
{
	unsigned nID;        // ��ϢID
	MY_PMSG mpfn;             // ��Ϣ������
};

// MY_MSGMP �ṹ�����ڵõ���Ϣ������ġ���Ϣӳ����͡���������
struct MY_MSGMAP
{
	const MY_MSGMAP * (*pGetBaseMap)();          // ��û�����Ϣӳ�����
	const MY_MSGMAP_ENTRY* lpEntries;            // ��Ϣӳ��� ���õ������Ϣӳ�����飩
};

#endif

