#include <iostream>
#include "voxel_sculptor.h"

using namespace std;

int main()
{
    Sculptor paint(10,10,10);
    paint.setColor(1,1,1,1);
    paint.putBox(1,1,1,1,1,1);
    paint.cutBox(1,1,1,1,1,1);
    paint.putSphere(1,1,1,1);
    paint.cutSphere(1,1,1,1);
    paint.putEllipsoid(1,1,1,1,1,1);
    paint.cutEllipsoid(1,1,1,1,1,1);

    return 0;
}
