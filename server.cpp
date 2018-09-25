#include "server.h"

namespace Mice {
Server::Server(std::string name, std::string id, std::string phone, double salary)
             : Person(name, id, phone), _salary{salary}, _num_orders{0} { }
Server::Server(std::istream& instream) {
   
    getline(instream, _name);
    getline(instream, _id);
    getline(instream, _phone);
    instream >> _salary; instream.ignore();
    instream >> _num_orders; instream.ignore();
}

void Server::save(std::ostream& outstream) {
    outstream << "#" << std::endl << "SERVER" << std::endl; 
    outstream << _name << std::endl;
    outstream << _id << std::endl;
    outstream << _phone << std::endl;
    outstream << _salary << std::endl;
    outstream << _num_orders << std::endl;
}

bool Server::fill_order_and_pay() {
    ++_num_orders;
    return (_num_orders % PAY_PERIOD) == 0;
}
bool Server::restock_and_pay() {
    _num_orders += 2;
    return ((_num_orders % PAY_PERIOD) == 0) 
       || (((_num_orders - 1) % PAY_PERIOD) == 0);
}
double Server::pay_server() { }
int Server::num_orders() {return _num_orders;}
int Server::salary() {return _salary;}
}
