#pragma once
#include "Entity.h"

class History : public Entity
{
	int historyId;
public:
	History();
	History(int id, TCHAR name[], int historyId);
	int getHistoryId();

};

