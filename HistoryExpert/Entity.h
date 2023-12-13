#pragma once
class Entity
{
protected:
	int id;
	TCHAR name[100];
public:
	Entity();
	Entity(int id, TCHAR name[]);
	int getId();
	TCHAR* getName();

};

