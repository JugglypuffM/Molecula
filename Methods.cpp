//
// Created by Jugglyuser on 05.04.2023.
//

#include "Methods.h"

Point crossover(Line l, Plane f){
    double t = -((f.d + f.a*l.p.x + f.b*l.p.y + f.c*l.p.z)/(f.a*l.v.x + f.b*l.v.y + f.c*l.v.z));
    return Point(l.p.x + l.v.x*t, l.p.y + l.v.y*t, l.p.z + l.v.z*t);
}