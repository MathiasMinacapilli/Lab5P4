#ifndef _TRANSPORTE_HPP
#define _TRANSPORTE_HPP

#include <iostream>

enum Transporte {Pie, Bici, Moto};

std::ostream& operator<<(std::ostream & os, Transporte t);

#endif
