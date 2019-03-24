#ifndef GENE_BOOTH_H
#define GENE_BOOTH_H

#include "Booth.h"

class GeneBooth : public Booth
{
public:
    GeneBooth(int x, int y, bool alive, std::vector<char> gene);
    GeneBooth(int x, int y, bool alive);
    GeneBooth(const GeneBooth& clonable);
    virtual ~GeneBooth();
    std::vector<char> getGene() const;
    virtual std::unique_ptr<Booth> clone() override;
    virtual bool operator==(const Booth& booth) override;
private:
    std::vector<char> gene;
};

#endif