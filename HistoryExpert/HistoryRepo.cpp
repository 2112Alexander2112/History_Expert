#include "framework.h"
#include "HistoryRepo.h"

HistoryRepo::HistoryRepo(std::string fileName)
	: Repository(fileName)
{
}

void HistoryRepo::loadData()
{
	char buff[100];
	int id;
	TCHAR name[100];
	int historyId;

	std::ifstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		fin >> buff;
		if (strlen(buff) > 0) {
			id = atoi(buff);
			fin >> buff;
			mbstowcs_s(NULL, name, 100, buff, 100);
			fin >> buff;
			historyId = atoi(buff);

			History his(id, name, historyId);
			history.push_back(his);
		}
	}
	fin.close();
}

void HistoryRepo::saveData()
{
}
