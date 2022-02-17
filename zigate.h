/******************************************************************************
 *  zigate.h
 *  gestion de la Zigat USB
 ******************************************************************************/
#ifndef ZIGATE_H
#define ZIGATE_H

#include <iostream>
#include <string>     // std::string, std::to_string
#include <stdio.h>
#include <stdlib.h>

#include "serieLin.h"

using namespace std;

class zigate {
private:
    int portZ;
    serieLin comZ;
public:
    zigate();
    int ouvertureSerie(string);
    void serial();
    void parser();
};
#endif
