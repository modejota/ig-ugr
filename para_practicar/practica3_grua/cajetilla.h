#ifndef CAJETILLA_H
#define CAJETILLA_H

#include "cube.h"

class _cajetilla{
public:
    _cube Cubo;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);

};

#endif // CAJETILLA_H
