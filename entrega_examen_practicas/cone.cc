#include "cone.h"

_cone::_cone(unsigned int perfiles, float Size)
{
    Vertices.resize(3);

    Vertices[0] = _vertex3f(0,-Size/2,0);
    Vertices[1] = _vertex3f(Size/2,-Size/2,0);
    Vertices[2] = _vertex3f(0,Size/2,0);

    this->revolucion(perfiles);

}
