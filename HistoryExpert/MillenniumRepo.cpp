#include "framework.h"
#include "MillenniumRepo.h"
#include "Millennium.h"

MillenniumRepo::MillenniumRepo(std::string fileName) : Repository(fileName)
{
}

void MillenniumRepo::loadData()
{
	char buff[100];
	int id;
	TCHAR name[100];

	millennium.clear();
	std::ifstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		fin.getline(buff, 100);
		if (strlen(buff) > 0) {
			id = atoi(buff);
			fin.getline(buff, 100);
			mbstowcs_s(NULL, name, 100, buff, 100);

			Millennium m(id, name);
			millennium.push_back(m);
		}
	}
	fin.close();
}

void MillenniumRepo::saveData()
{
	char buff[100];
	std::ofstream fout;
	fout.open(fileName);

	// 2
	for (auto& m : millennium) {
		fout <<m.getId() << std::endl;
		wcstombs_s(NULL, buff, m.getName(), 100);
		fout << buff << std::endl;
	}

	// 3
	fout.close();
}

std::vector<Millennium> MillenniumRepo::getMillennium()
{
	return millennium;
}

void MillenniumRepo::addMillennium(Millennium& add)
{

	millennium.push_back(add);
}
