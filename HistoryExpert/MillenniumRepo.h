#pragma once
#include "Repository.h"
#include "Millennium.h"

class MillenniumRepo :
    public Repository
{
	std::vector<Millennium> millennium;
public:
	MillenniumRepo(std::string fileName);
	void loadData() override;
	void saveData() override;
	std::vector<Millennium> getMillennium();
	void addMillennium(Millennium& add);
};

