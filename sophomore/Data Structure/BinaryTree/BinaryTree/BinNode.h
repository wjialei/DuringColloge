#pragma once

// BinNode×´Ì¬ÅÐ¶Ï
#define IsRoot(x) ( ! ( (x).parent) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ))
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ))
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ( (p) ? (p) -> height : -1)
typedef enum { RB_RED, RB_BLACK} RBColor;

template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent, lc, rc;
	int height;
	int npl;
	RBColor color;

	BinNode()£º
		parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNodePosi p = nullptr, BinNodePosi l = nullptr, BinNodePosi r = nullptr, int h = 0, int n = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(l), rc(r), npl(n), color(c) {}

	int size();
	BinNodePosi(T) insertAsLC(T const&);
	BinNodePosi(T) insertAsRC(T const&);
	BinNodePosi(T) succ();
	template <typename VST> void travlevel(VST&);
	template <typename VST> void travPre(VST&);
	template <typename VST> void tranIn(VST&);
	template <typename VST> void tranPost(VST&);

	bool operator< (BinNode const& bn) { return data < bn.data; }
	bool operator== (BinNode const& bn) { return data == bn.data; }
};