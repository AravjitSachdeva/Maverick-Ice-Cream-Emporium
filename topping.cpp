#include "topping.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

namespace Mice {

Topping::Topping(std::string name, std::string description, double cost, double price,
              int amount) :
    Item(name, description, cost, price), _amount{amount} { }

Topping::Topping(std::istream& instream) {
    
    getline(instream, _name);
    instream >> _cost; instream.ignore();
    instream >> _price; instream.ignore();
    instream >> _quantity; instream.ignore();
    instream >> _amount; instream.ignore();
    getline(instream, _description);
}

void Topping::save(std::ostream& outstream) {
    outstream << "#" << std::endl << "TOPPING" << std::endl; 
    outstream << _name << std::endl;
    outstream << _cost << std::endl;
    outstream << _price << std::endl;
    outstream << _quantity << std::endl;
    outstream << _amount << std::endl;
    outstream << _description << std::endl;
}

std::string Topping::type() const {return "Topping";}
int Topping::amount() const {return _amount;}
void Topping::set_amount(int amount) {
    if (0 < amount && amount < 5) _amount = amount;
    else throw std::runtime_error("Invalid topping amount");
}

std::string Topping::show_server() const {
    if (_amount == LIGHT_AMOUNT) return _name + " (light)";
    else if (_amount == NORMAL_AMOUNT) return _name;
    else if (_amount == EXTRA_AMOUNT) return _name + " (extra)";
    else if (_amount == DRENCHED_AMOUNT) return _name + " (drenched)";
    else throw std::runtime_error("Invalid topping amount in Topping::show_server()");
}

}

