#include "framework.h"
#include "CenturyRepo.h"


CenturyRepo::CenturyRepo(std::string fileName) : Repository(fileName)
{}

void CenturyRepo::loadData()
{
	char buff[100];
	int id;
	TCHAR name[100];
	int centuriesId;

	std::ifstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		fin >> buff;
		if (strlen(buff) > 0) {
			id = atoi(buff);
			fin >> buff;
			mbstowcs_s(NULL, name, 100, buff, 100);
			fin >> buff;
			centuriesId = atoi(buff);

			Centuries cen(id, name, centuriesId);
			centuries.push_back(cen);
		}
	}
	fin.close();
}

void CenturyRepo::saveData()
{
}


std::vector<Centuries> CenturyRepo::getCenturies()
{
	return  centuries;
}
