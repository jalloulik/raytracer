#include "rtv1.h"
#include <stdio.h>

void    print_cut(t_cut *cut)
{
    printf("cut : \nx: %f , %f\ny: %f , %f\nz: %f , %f\n",
    cut->c1.x, cut->c2.x, cut->c1.y, cut->c2.y, cut->c1.z, cut->c2.z);
}