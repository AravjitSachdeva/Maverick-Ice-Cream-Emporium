#include "emporium.h"
#include <stdexcept>

namespace Mice{

Emporium::Emporium(std::string name) : name{name}, cashreg{0}, _id{0} { }
Emporium::Emporium(std::istream& ist) {

    std::string header1, header2;

    std::getline(ist, header1);
    std::getline(ist, header2);



    std::getline(ist, name);
    ist >> cashreg;
    ist.ignore();
    ist >> _id;
    ist.ignore();

    while(ist) {
        std::getline(ist, header1);
        std::getline(ist, header2);


        if (header2 == "CONTAINER") containers.push_back(Container{ist});
        else if (header2 == "SCOOP") scoops.push_back(Scoop{ist});
        else if (header2 == "TOPPING") toppings.push_back(Topping{ist});
        else if (header2 == "ORDER") orders.push_back(Order{ist});
        else if (header2 == "SERVER") servers.push_back(Server{ist});
        else if (header2 == "CUSTOMER") customers.push_back(Customer{ist});
        else if (header2 == "END EMPORIUM") break;

    }
}

void Emporium::save(std::ostream& ost) {
        ost << "MICE" << std::endl << "0.4" << std::endl;
        ost << "#" << std::endl << "EMPORIUM" << std::endl;
        ost << name << std::endl;
        ost << cashreg << std::endl;
        ost << _id << std::endl;

        for (Mice::Container c : containers) c.save(ost);
        for (Mice::Scoop s : scoops) s.save(ost);
        for (Mice::Topping t : toppings) t.save(ost);
        for (Mice::Order o : orders) o.save(ost);
        for (Mice::Server s : servers) s.save(ost);
        for (Mice::Customer c : customers) c.save(ost);
        ost << "#" << std::endl << "END" << std::endl;
}

std::string Emporium::name() {return name;}
double Emporium::cash_register() {return cashreg;}
void Emporium::debit(double amount) {cashreg -= amount;}
void Emporium::credit(double amount) {cashreg += amount;}
int Emporium::next_id() {return ++_id;}

void Emporium::add_container(Container container) {containers.push_back(container);}
void Emporium::add_scoop(Scoop scoop) {scoops.push_back(scoop);}
void Emporium::add_topping(Topping topping) {toppings.push_back(topping);}
void Emporium::add_order(Order order) {orders.push_back(order);}
void Emporium::add_server(Server server) {servers.push_back(server);}
void Emporium::add_customer(Customer customer) {customers.push_back(customer);}

int Emporium::number_of_containers() {return containers.size();}
int Emporium::number_of_scoops() {return scoops.size();}
int Emporium::number_of_toppings() {return toppings.size();}
int Emporium::number_of_orders() {return orders.size();}
int Emporium::number_of_servers() {return servers.size();}
int Emporium::number_of_customers() {return customers.size();}

Container& Emporium::container(int index) {return containers[index];}
Scoop& Emporium::scoop(int index) {return scoops[index];}
Topping& Emporium::topping(int index) {return toppings[index];}
Order& Emporium::order(int index) {return orders[index];}
Server& Emporium::server(int index) {return servers[index];}
Customer& Emporium::customer(int index) {return customers[index];}




}
