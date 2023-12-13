#pragma once
#include "Repository.h"
#include "Centuries.h"

class CenturyRepo :
    public Repository
{
    std::vector<Centuries> centuries;
public:
    CenturyRepo(std::string fileName);
    void loadData() override;
    void saveData() override;
    std::vector<Centuries> getCenturies();
};

