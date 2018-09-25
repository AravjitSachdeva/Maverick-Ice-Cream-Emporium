#ifndef _SCOOP_H
#define _SCOOP_H

#include "item.h"
#include <iostream>
#include <fstream>

namespace Mice {

class Scoop : public Item {
  public:
    Scoop(std::string name, std::string description, double cost, double price);
    Scoop(std::istream& instream);
    void save(std::ostream& outstream);
    std::string type() const override;
};

}
#endif
