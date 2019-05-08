#include "NamespaceDisplay.h"
#include <thread>
#include <math.h>


vector<User> users;
static const string alpha = "abcdefghijklmonpqrstuvwxyz";
static const int num_threads = 10;
static const int nb_users = 10;
static const int MAX_ITERATIONS = 10000;
mutex mut;

/*Test if the Address exist*/
const bool verify_address(const string &address) {
    bool exist = false;
    for (auto &i : users) {
        if (i.getCC_Address() == address) {
            exist = true;
        }
    }
    return exist;
}

/*initialize first time user*/
void init_user(User newUser) {
    string name;
    double money;

    //does user want to deposit money
    char choice;

    display::registration();
    cin >> name;

    display::init_wallet();
    cin >> choice;

    if (choice == 'y') {
        display::deposit_amount();
        cin >> money;
        newUser.setName(name);
        newUser.setWallet(money);
    } else
        newUser.setName(name);

}
/*display a menu for user*/
void menu(User newUser) {

    int option = 0;

    do {
        display::main_menu();
        cin >> option;

        switch (option) {
            case 1: {
                int amount;
                string receiver_address;

                display::transaction_amount();
                cin >> amount;

                display::receiver_address();
                cin >> receiver_address;

                if (verify_address(receiver_address))
                    newUser.transact(receiver_address, amount);
                else
                    display::error_address();
                break;
            }
            case 2:
                User::chain.GetLastBlock().showAll();
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
                cout << "Action not recognized" << endl;
                break;
        }

    } while (option != 5);
}

/*put thread to sleep*/
void threadSleep(int tid) {

    mut.lock();
    std::cout << "thread " << tid << " sleeping...\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mut.unlock();
}

int main() {

    //reserve the space
    users.reserve(nb_users);
    srand(time(NULL));


    //create first user, uncomment if manual user creation wanted
    /*User user1;
    users.push_back(user1);
    User user2 = User("John Doe", 123);
    users.push_back(user2);*/

    //initialisation, name and wallet
    //init_user(user1);

    //display menu
    //menu(user1);

    //initialize users for threads, comment if manual user wanted
    //creates 10 users with random names
    const int MAX_NAME_LENGTH = 12;
    const int MAX_WALLET_AMOUNT = 500;
    for (int i = 0; i < nb_users; i++) {
        string user_name;
        int name_length = rand() % MAX_NAME_LENGTH + 1;
        for (int j = 0; j < name_length; j++) {
            int index = rand() % alpha.size();
            char letter = alpha[index];
            user_name += letter;
        }
        double wallet = rand() % MAX_WALLET_AMOUNT;
        users.emplace_back(User(user_name, wallet));
    }
    //create threads to go along users
    thread t[num_threads];
    int it = 0;
    int sleeping_thread = 0;

    while (it < MAX_ITERATIONS) {

        sleeping_thread = rand() % num_threads + 1;

        //Launch a group of threads and do transactions
        for (unsigned i = 0; i < num_threads; ++i) {

            if (i == sleeping_thread) {
                t[i] = thread(threadSleep, i);
            } else {
                User temp = users.at(i);

                int index_receiver = rand() % nb_users;
                string address_receiver = users.at((unsigned) index_receiver).getCC_Address();
                int amount = rand() % (int) round(temp.getWallet());
                t[i] = thread(&User::transact, temp, address_receiver, amount);
            }
        }

        cout << "Launched from the main\n";

        //Join the threads with the main thread, wait for the end of the execution to quit
        for (int i = 0; i < num_threads; ++i) {
            t[i].join();
        }
        it++;
    }

    return 0;
}