#include "container.h"

#include "customer.h"

namespace Mice {
Customer::Customer(std::string name, std::string id, std::string phone)
             : Person(name, id, phone) { }
Customer::Customer(std::istream& instream) {
   
    getline(instream, _name);
    getline(instream, _id);
    getline(instream, _phone);
}

void Customer::save(std::ostream& outstream) {
    outstream << "#" << std::endl << "CUSTOMER" << std::endl; 
    outstream << _name << std::endl;
    outstream << _id << std::endl;
    outstream << _phone << std::endl;
}

}
