#include <stdlib.h>     /* srand, rand */
#include "Coso.h"
//#include <iostream>


void Coso::set_color(int num) {color = num + 1;};

int Coso::get_color() { return color; };

Coso::Coso() { set_color(rand() % 4); };

Coso::~Coso() {};
