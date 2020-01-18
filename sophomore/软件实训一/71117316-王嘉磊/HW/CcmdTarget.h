#pragma once

#ifndef CMDTARGET_H
#define CMDTARGET_H

// 声明基类 cmdTarget
class cmdTarget;

// 声明 MY_MSGMAP_ENTRY 结构体 (消息映射表)
struct MY_MSGMAP_ENTRY;

// 声明 MY_MSGMAP 结构体 （消息映射项）
struct MY_MSGMAP;



// DELERE_MESSAGE_MAP 宏定义
// BEGIN_MESSAGE_MAP 宏定义
// END_MESSAGE_MAP 宏定义

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
	// 此函数用于查找对应的处理函数
	void check(unsigned, int*, int);
};

// 自定义类型 MY_PMSG
typedef void (*MY_PMSG)(int*, int);

// 定义 MSGMAP_ENTRY 消息映射表 
struct MY_MSGMAP_ENTRY
{
	unsigned nID;        // 消息ID
	MY_PMSG mpfn;             // 消息处理函数
};

// MY_MSGMP 结构体用于得到消息处理类的“消息映射表”和“处理函数”
struct MY_MSGMAP
{
	const MY_MSGMAP * (*pGetBaseMap)();          // 获得基类消息映射入口
	const MY_MSGMAP_ENTRY* lpEntries;            // 消息映射表 （得到类的消息映射数组）
};

#endif

