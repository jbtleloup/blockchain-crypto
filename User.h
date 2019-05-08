#include "Blockchain.h"


class User {
private:
    string name;
    string private_key;
    string public_key;
    string CC_Address; //Cryptocurrency address
    double wallet;

public:
    static Blockchain chain;

    User();

    User(string);

    User(string, double);

    void setName(string);

    void setKeys();

    void setWallet(double);

    void transact(const string &receiver, const int &amount);

    string getPrivateKey();

    string getPublicKey();

    string getCC_Address();

    double getWallet();

};