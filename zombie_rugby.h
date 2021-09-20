#ifndef ZOMBIE_RUGBY_H
#define ZOMBIE_RUGBY_H
#include "zombie.h"
#include "QMovie"

class Zombie_Rugby : public Zombie
{
public:
    Zombie_Rugby();
    void advance(int phase)override;
    QSound *sound;
};

#endif // ZOMBIE_RUGBY_H
