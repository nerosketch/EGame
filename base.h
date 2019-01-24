/* 
 * File:   base.h
 * Author: ns
 *
 * Created on January 24, 2019, 11:03 PM
 */

#ifndef BASE_H
#define BASE_H

#include <cstdint>
#include <cstdlib>

#ifdef WIN32
#define uint UINT
#endif


#define RANDOM_RANGE(min, max)  (rand()%(max-min+1) + min)


#endif /* BASE_H */

