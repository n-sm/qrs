#include "Cosos.h"
#include <iostream>

void Cosos::set_color(int num) {color = num + 1;};

int Cosos::get_color() { return color; };

Cosos::Cosos() {
    set_color(rand() % 4);
};

Cosos::~Cosos() {};
