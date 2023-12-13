#include "framework.h"
#include "Entity.h"

Entity::Entity() : id(0)
{
	lstrcpy(this->name, L"");
}

Entity::Entity(int id, TCHAR name[]) : id(id)
{
	lstrcpy(this->name, name);
}

int Entity::getId()
{
	return id;
}

TCHAR* Entity::getName()
{
	return name;
}
