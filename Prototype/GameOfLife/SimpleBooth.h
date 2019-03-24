#ifndef SIMPLE_BOOTH_H
#define SIMPLE_BOOTH_H

#include "Booth.h"

class SimpleBooth : public Booth
{
public:
    SimpleBooth(int x, int y, bool alive);
    SimpleBooth(const SimpleBooth& clonable);
    virtual ~SimpleBooth();
    virtual std::unique_ptr<Booth> clone() override;
    virtual bool operator==(const Booth& booth) override;
};

#endif