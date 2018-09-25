#include "container.h"

namespace Mice {

Container::Container(std::string name, std::string description, double cost, double price,
              int max_scoops)
          : Item(name, description, cost, price), _max_scoops{max_scoops} { }
int Container::max_scoops() const {return _max_scoops;}
Container::Container(std::istream& instream) {

    getline(instream, _name);
    instream >> _cost; instream.ignore();
    instream >> _price; instream.ignore();
    instream >> _quantity; instream.ignore();
    instream >> _max_scoops; instream.ignore();
    getline(instream, _description);
}

void Container::save(std::ostream& outstream) {
    outstream << "#" << std::endl << "CONTAINER" << std::endl;
    outstream << _name << std::endl;
    outstream << _cost << std::endl;
    outstream << _price << std::endl;
    outstream << _quantity << std::endl;
    outstream << _max_scoops << std::endl;
    outstream << _description << std::endl;
}
std::string Container::type() const {return "Container";}

}
