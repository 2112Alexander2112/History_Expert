#pragma once
#include "Repository.h"
#include "History.h"

class HistoryRepo :
    public Repository
{
    std::vector<History> history;
public:
    HistoryRepo(std::string fileName);
    void loadData() override;
    void saveData() override;
};

