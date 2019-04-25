#include "User.h"

bool already_made = false;

void menu()
{

    User newUser = User();

    if (!already_made)
    {
        string name;
        double money;

        //does user want to deposit money
        char choice;

        cout << "Welcome! Before starting you must register.\n";
        cout << "Please enter your username:";
        cin >> name;

        cout << "Do you want to deposit money immediately (y/n)? ";
        cin >> choice;

        if (choice == 'y')
        {
            cout << "Enter the amount you want to deposit: ";
            cin >> money;
            newUser.setName(name);
            newUser.setWallet(money);
        }
        else
            newUser.setName(name);

        already_made = true;
    }

    int option = 0;

    do
    {
        cout << " Main Menu:\n";
        cout << "\t 1.Mine a new Block\n";
        cout << "\t 2.Get Last Block Data\n";
        cout << "\t 3.Check Keys\n";
        cout << "\t 4.Check Wallet\n";
        cout << "\t 5.Exit\n";
        cin >> option;

        /*if (option == 1)
            //newUser.chain.AddBlock();
            break;
        else if (option == 2)
            newUser.chain.GetLastBlock().showAll();
        else if (option == 3)
            cout << "Private Key:\n" << newUser.getPrivateKey() << endl << endl
                 << "Public Key:\n" << newUser.getPublicKey() << endl << endl
                 << "Address:\n" << newUser.getCC_Address() << endl;
        else if (option == 4)
            cout << "Amount in Wallet: " << newUser.getWallet() << endl;*/

        switch(option){
            case 1:
                //newUser.chain.AddBlock();
                break;
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

    menu();


    return 0;
}