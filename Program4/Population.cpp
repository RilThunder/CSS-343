//
// Created by thuan on 09/03/17.
//

#include "Population.h"


Population::~Population()
{

}

Population::Population()
{
	theFit = NULL;
	reproduction = NULL;
	initialPuzzle = NULL;
	factory = NULL;
	container[0] = NULL;
	size = 0;
}
