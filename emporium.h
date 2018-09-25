#ifndef EMPORIUM_H
#define EMPORIUM_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "order.h"
#include "server.h"
#include "customer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Mice {

class Emporium {
    public:
        Emporium(std::string name);
        Emporium(std::istream& ist);

        std::string name();
        std::vector<Mice::Container> containers;
        std::vector<Mice::Scoop> scoops;
        std::vector<Mice::Topping> toppings;
        std::vector<Mice::Order> orders;
        std::vector<Mice::Server> servers;
        std::vector<Mice::Customer> customers;

        int number_of_containers();
        int number_of_toppings();
        int number_of_scoops();
        int number_of_servers();
        int number_of_orders();
        int number_of_customers();




        double cash_register();
        void debit(double amount);
        void credit(double amount);
        int next_id();

        Container& container(int index);
        Scoop& scoop(int index);
        Topping& topping(int index);
        Order& order(int index);
        Server& server(int index);
        Customer& customer(int index);

        void add_container(Container container);
        void add_scoop(Scoop scoop);
        void add_topping(Topping topping);
        void add_order(Order order);
        void add_server(Server server);
        void add_customer(Customer customer);
        void save(std::ostream& ost);
        std::string name;
        double cashreg;
        int _id;



};

}
#endif
