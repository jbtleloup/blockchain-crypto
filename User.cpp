#include "User.h"

Blockchain User::chain;
mutex mu;

User::User() {
    setName("");
    setWallet(0);
    setKeys();
}

User::User(string name) {
    setName(name);
    setWallet(0);
    setKeys();
}

User::User(string name, double starting) {
    setName(name);
    setWallet(starting);
    setKeys();
}

void User::setKeys() {
    Cryptography user;
    user._RSA(user.RSA(name));
    public_key = user.publicKey;
    private_key = user.getPrivateKey();
    user.~Cryptography();
    //CC_Address = sha256(public_key);

    //Patch waiting for RSA TODO
    CC_Address = sha256(name);

    //cout<<public_key<<private_key<<endl;
}

void User::setName(string Name) {
    name = Name;
}

void User::setWallet(double money) {
    wallet = money;
}

string User::getPrivateKey() {
    return private_key;
}

string User::getPublicKey() {
    return public_key;
}

string User::getCC_Address() {
    return CC_Address;
}

double User::getWallet() {
    return wallet;
}

void User::transact(const string &receiver, const int &amount) {
    mu.lock();
    uint32_t index = User::chain.GetLastBlock().getIndex() + 1;
    string sender = this->getCC_Address();
    string s_amount = to_string(amount);

    Block nBlock = Block(index, s_amount, receiver, sender);

    User::chain.AddBlock(nBlock);
    //set the new amount in wallet for sender
    double wallet_before_sender = this->getWallet();
    double wallet_sender = wallet_before_sender - amount;
    this->setWallet(wallet_sender);

    //set the new amount in wallet for receiver
    double wallet_before_receiver = this->getWallet();
    double wallet_receiver = wallet_before_receiver + amount;
    this->setWallet(wallet_receiver);
    mu.unlock();
    User::chain.GetLastBlock().showAll();
}


