/* 
 * File:   resources.h
 * Author: ns
 *
 * Created on January 12, 2019, 10:35 PM
 */

#ifndef RESOURCES_H
#define RESOURCES_H


#include <string>
#include <oxygine-framework.h>
#include "flags.h"

using namespace std;
using namespace oxygine;

namespace res{
    extern Resources resources;
    void load();
    void free();
}


#endif /* RESOURCES_H */

