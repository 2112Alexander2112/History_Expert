#pragma once
#include "Entity.h"
class Centuries :
    public Entity
{
    int centuriesId;
public:
    Centuries();
    Centuries(int id, TCHAR millennium[], int centuriesId);
};

