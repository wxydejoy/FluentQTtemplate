#ifndef IHBHOME_H
#define IHBHOME_H

#include "ihbpage.h"

class ElaMenu;
class IhbHome : public IhbPage
{
public:
    IhbHome(QWidget* parent = nullptr);
private:
    ElaMenu* _homeMenu{nullptr};
};

#endif // IHBHOME_H
