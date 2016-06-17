#ifndef BUMPCHECKER_H
#define BUMPCHECKER_H

#include "pointtransfer.h"
#include "item.h"

class BumpChecker :  public b2ContactListener
{
public:
    BumpChecker();
    void BeginContact(b2Contact *contact);
};

#endif // BUMPCHECKER_H
