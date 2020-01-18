#include "CcmdTarget.h"

BEGIN_MESSAGE_MAP(cmdTarget, cmdTarget)
END_MESSAGE_MAP()

void cmdTarget::check(unsigned message, int *arr, int size)
{
	const MY_MSGMAP * messagemap;
	messagemap = GetMessageMap();
	for (int i = 0;((messagemap->lpEntries)->nID != message) ; i++)
	{
		if ((((messagemap->lpEntries)[i]).nID) == message)
		{
			((messagemap->lpEntries)[i]).mpfn(arr, size);
			break;
		}
		if ((messagemap->lpEntries)->nID == 0)
		{
			i = -1;
			messagemap = messagemap->pGetBaseMap();
		}
	}
}