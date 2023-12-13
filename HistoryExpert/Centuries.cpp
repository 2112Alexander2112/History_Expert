#include "framework.h"
#include "Centuries.h"

Centuries::Centuries() : Entity(), centuriesId(0)
{
}

Centuries::Centuries(int id, TCHAR millennium[], int centuriesId)
	: Entity(id, millennium), centuriesId(centuriesId)
{
}
