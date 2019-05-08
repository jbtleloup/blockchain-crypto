//
// Created by Jean baptiste Tamas leloup on 2019-04-25.
//
/*
 * Only display cout in this file
 *
 * */

#ifndef FINAL_NAMESPACEDISPLAY_H
#define FINAL_NAMESPACEDISPLAY_H

#include "User.h"

namespace display {

    void registration() {
        cout << "Welcome! Before starting you must register.\n";
        cout << "Please enter your username:";
    }

    void init_wallet() {
        cout << "Do you want to deposit money immediately (y/n)? ";
    }

    void deposit_amount() {
        cout << "Enter the amount you want to deposit: ";
    }

    void main_menu() {
        cout << " Main Menu:\n";
        cout << "\t 1.Effectuate a transaction\n";
        cout << "\t 2.Get Last Block Data\n";
        cout << "\t 3.Check Keys\n";
        cout << "\t 4.Check Wallet\n";
        cout << "\t 5.Exit\n";
    }

    void transaction_amount() {
        cout << "How much do you want to send?" << endl;
    }

    void receiver_address() {
        cout << "Enter address of receiver" << endl;
    }

    void error_address() {
        cout << "Address incorrect" << endl;
    }
}


#endif //FINAL_NAMESPACEDISPLAY_H
