#pragma once
#include "Node.h"

class CompareNodes
{
public:
	bool operator() (Node* pn1, Node* pn2)
	{
		return pn1->GetF() > pn2->GetF();
	}
};

