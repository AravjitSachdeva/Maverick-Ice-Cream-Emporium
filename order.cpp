#include "order.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

namespace Mice {

    Order::Order(Customer customer, int order_number) 
        : _customer{customer}, _id{order_number}, _state{Order_state::Unfilled} { }
    Order::Order(std::istream& instream) {
        std::string header1, header2;

        instream >> _id; instream.ignore();
        int state;
        instream >> state; instream.ignore();
        _state = (state == 0) ? Order_state::Canceled :
                 (state == 1) ? Order_state::Unfilled :
                 (state == 2) ? Order_state::Filled : Order_state::Paid;
        
        std::getline(instream, header1);
        std::getline(instream, header2);
 
        
        _customer = Customer{instream};

        std::getline(instream, header1);
        std::getline(instream, header2);

        _server = Server{ist};

        while (true) {
            std::getline(instream, header1); 
            std::getline(instream, header2);
          

            if (header2 == "END ORDER") break;  
            else if (header2 == "SERVING") _servings.push_back(Mice::Serving{instream});
           
        }
    }

    void Order::save(std::ostream& outstream) {
        outstream << "#" << std::endl << "ORDER" << std::endl; 
        outstream << _id << std::endl;
        outstream << ((_state == Order_state::Canceled) ? 0 :
                (_state == Order_state::Unfilled) ? 1 :
                (_state == Order_state::Filled)   ? 2 : 3) << std::endl;
        _customer.save(outstream);
        _server.save(outstream);
        for (Serving s : _servings) s.save(outstream);
        outstream << "#" << std::endl << "END ORDER" << std::endl; 
    }

    void Order::add_serving(Serving serving) {_servings.push_back(serving);}
    std::vector<Serving> Order::servings() const {return _servings;}

    void Order::fill(Server server) {process_event(Order_event::Fill, server);}
    void Order::pay() {process_event(Order_event::Pay);}
    void Order::cancel() {process_event(Order_event::Cancel);}

    int Order::id() const {return _id;}
    double Order::cost() const {return 0;}
    double Order::price() const {return 0;}
    Order_state Order::state() const {return _state;}

    // STATE MACHINE that manages Order's state
    void Order::process_event(Order_event event, Server server) {
        if (_state == Order_state::Unfilled) {
            if (event == Order_event::Fill) {
                _state = Order_state::Filled;
                _server = server;
            } else if (event == Order_event::Cancel) {
                _state = Order_state::Canceled;
            } else {
                throw std::runtime_error("Invalid state transition in Unfilled");
            }
        } else if (_state == Order_state::Filled) {
            if (event == Order_event::Pay) {
                _state = Order_state::Paid;
            } else {
                throw std::runtime_error("Invalid state transition in Filled");
            }
        } else if (_state == Order_state::Paid) {
            throw std::runtime_error("State transition attempted in Paid");
        } else if (_state == Order_state::Canceled) {
            throw std::runtime_error("State transition attempted in Canceled");
        } else {
            throw std::runtime_error("Invalid state");
        }
    }

    std::string Order::show_server() const {
        std::string result;
        for(int i=0; i < _servings.size(); ++i) {
            result += "<b>Serving " + std::to_string(i+1) + "</b>\n";
            result += _servings[i].show_server() + '\n';
        }
        return result;
    }
}

// OPERATOR OVERLOADING for class Order
std::ostream& operator<<(std::ostream& os, const Mice::Order& order) {
    double total = 0;
    for (Mice::Serving s : order.servings()) {
        os << s << std::endl << std::endl;
        total += s.price();
    }
    os << std::setw(40) << "Total: " << " $" << std::setprecision(2) << std::fixed << total;
    return os;
}

