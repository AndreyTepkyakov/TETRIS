#pragma once
#include <iostream>
#include <vector>

#ifndef Figure
#include "Figure.h"
#endif

/*Stores the Figure "O" data, inherits the implementation of the rotation of the shape from Figure*/
class Figure_O : public Figure {
public:
	Figure_O();
	~Figure_O();
};

