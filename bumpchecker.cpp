#include "bumpchecker.h"

BumpChecker::BumpChecker()
{

}

void BumpChecker::BeginContact(b2Contact *contact)
{
    static_cast<Item*>(contact->GetFixtureA()->GetBody()->GetUserData())->collision();
    static_cast<Item*>(contact->GetFixtureB()->GetBody()->GetUserData())->collision();
}
