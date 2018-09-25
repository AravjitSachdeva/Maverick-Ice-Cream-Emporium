#include "serving.h"
#include <iostream>
#include <stdexcept>

namespace Mice {

    Serving::Serving(Container container) : _container{container} { }
    Serving::Serving(std::istream& instream) {
       
        std::string header1, header2;
        while (true) {
            std::getline(instream, header1); 
            std::getline(instream, header2);
            if (header1 != "#") 
            if (header2 == "END SERVING") break; 
            else if (header2 == "CONTAINER") _container = Mice::Container{ist};
            else if (header2 == "SCOOP") _scoops.push_back(Mice::Scoop{ist});
            else if (header2 == "TOPPING") _toppings.push_back(Mice::Topping{ist});
            
        }
    }
    
    void Serving::save(std::ostream& outstream) {
        outstream << "#" << std::endl << "SERVING" << std::endl; 
        _container.save(outstream);
        for (Scoop& s : _scoops) s.save(outstream);
        for (Topping& t : _toppings) t.save(outstream);
        outstream << "#" << std::endl << "END SERVING" << std::endl;
    }
    
    Container Serving::container() const {return _container;}
    
    std::vector<Scoop> Serving::scoops() const {return _scoops;}
    std::vector<Topping> Serving::toppings() const {return _toppings;}
    
    void Serving::add_scoop(Scoop scoop) {_scoops.push_back(scoop);}
    void Serving::add_topping(Topping topping) {_toppings.push_back(topping);}
    
    double Serving::cost() const {
        double total = _container.cost();
        for (Scoop scoop : _scoops) total += scoop.cost();
        for (Topping topping : _toppings) total += topping.cost();
        return total;
    }
    
    double Serving::price() const {
        double total = _container.price();
        for (Scoop scoop : _scoops) total += scoop.price();
        for (Topping topping : _toppings) total += topping.price();
        return total;
    }
    
    std::string Serving::show_server() const { 
        std::string result = _container.show_server() + '\n';
        for (auto s : _scoops) result += s.show_server() + '\n';
        for (auto t : _toppings) result += t.show_server() + '\n';
        return result;
    }
    
}
    
// OPERATOR OVERLOADING for class Serving
std::ostream& operator<<(std::ostream& os, const Mice::Serving& serving) {
    os << serving.container();
    for (Mice::Scoop s : serving.scoops()) os << std::endl << s;
    for (Mice::Topping t : serving.toppings()) os << std::endl << t;
    return os;
}
    
