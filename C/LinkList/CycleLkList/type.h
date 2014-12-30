#ifndef _TYPE_H_
#define _TYPE_H_

#include "common.h"

typedef int customType;

/**
* Á´±í½áµã
*/
typedef struct LkNode
{
	customType data;
	struct LkNode *next;
}LkNode;

WORD LkNodeInput(LkNode *lkNode);
WORD LkNodeMemberInput(LkNode *lkNode);
WORD LkNodeDisplay(LkNode *lkNode);
WORD LkNodeCpy(LkNode *targetLkNode, LkNode *lkNode);
WORD LkNodeMemberEqual(LkNode *fristLkNode, LkNode *secondLkNode);


#endif