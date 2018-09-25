#include "scoop.h"

namespace Mice {

Scoop::Scoop(std::string name, std::string description, double cost, double price)
      : Item(name, description, cost, price) { }
Scoop::Scoop(std::istream& instream) {

    getline(instream, _name);
    instream >> _cost; instream.ignore();
    instream >> _price; instream.ignore();
    instream >> _quantity; instream.ignore();
    getline(instream, _description);
}

void Scoop::save(std::ostream& outstream) {
    outstream << "#" << std::endl << "SCOOP" << std::endl;
    outstream << _name << std::endl;
    outstream << _cost << std::endl;
    outstream << _price << std::endl;
    outstream << _quantity << std::endl;
    outstream << _description << std::endl;
}

std::string Scoop::type() const {return "Scoop";}

}
