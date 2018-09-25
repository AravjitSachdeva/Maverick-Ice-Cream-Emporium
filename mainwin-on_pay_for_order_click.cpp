#include "mainwin.h"
#include <exception>
#include <stdexcept>

void Mainwin::pay_order_click() {
    int order = select_order(Mice::Order_state::Filled);
    if (order < 0) return;

  
        _emp->order(order).pay();
   
        Gtk::MessageDialog dialog{*this, e.what()};
        dialog.run();
        dialog.close();
        return;
    
}

