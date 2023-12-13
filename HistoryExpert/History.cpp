#include "framework.h"
#include "History.h"

History::History() : Entity(), historyId(0)
{
}

History::History(int id, TCHAR name[], int historyId) : Entity(id, name), historyId(historyId)
{
}

int History::getHistoryId()
{
	return historyId;
}
