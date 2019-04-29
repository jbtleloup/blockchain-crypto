#include "NamespaceDisplay.h"

void init_user(User newUser) {
    string name;
    double money;

    //does user want to deposit money
    char choice;

    display::registration();
    cin >> name;

    display::init_wallet();
    cin >> choice;

    if (choice == 'y')
    {
        display::deposit_amount();
        cin >> money;
        newUser.setName(name);
        newUser.setWallet(money);
    }
    else
        newUser.setName(name);

}

void menu(User newUser)
{

    int option = 0;

    do
    {
        display::main_menu();
        cin >> option;

        switch(option){
            case 1: {
                //TODO user.send()
                int amount=0;
                newUser.transact(std::string(),amount);
                break;
            }
            case 2:
                newUser.chain.GetLastBlock().showAll();
                break;
            case 3:
                cout << "Private Key:\n" << newUser.getPrivateKey() << endl << endl
                     << "Public Key:\n" << newUser.getPublicKey() << endl << endl
                     << "Address:\n" << newUser.getCC_Address() << endl;
                break;
            case 4:
                cout << "Amount in Wallet: " << newUser.getWallet() << endl;
                break;
            default:
                cout<<"Action not recognized"<<endl;
                break;
        }

    } while (option != 5);
}


int main() {


    /*  Blockchain bChain = Blockchain();

      cout << "Mining block 1..." << endl;
      bChain.AddBlock(Block(1, "Block 1 Data"));

      cout << "Mining block 2..." << endl;
      bChain.AddBlock(Block(2, "Block 2 Data"));

      cout << "Mining block 3..." << endl;
      bChain.AddBlock(Block(3, "Block 3 Data"));*/


    //create first user
    User user1;
    User user2=User("John Doe", 123);

    //initialisation, name and wallet
    init_user(user1);

    //display menu
    menu(user1);


    return 0;
}