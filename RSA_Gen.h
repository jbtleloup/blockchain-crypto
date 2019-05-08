#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<sstream>

/*
 * RSA gen used to create users' keys
 * */
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];

class RSA_Gen {

public:

    int prime(long int pr) {

        int i;

        j = sqrt(pr);

        for (i = 2; i <= j; i++) {

            if (pr % i == 0)

                return 0;

        }

        return 1;

    }

    string func_main(string message) {

        for (int z = 0; z < message.length(); z++)
            msg[i] = message[i];

        unsigned int seed = time(0);
        srand(seed);
        do {
            p = rand() % 999983 + 2;
            q = rand() % 999983 + 2;
        } while (!prime(p) && !prime(q));

        // Variable catching Username goes here

        for (i = 0; msg[i] != '\0'; i++)
            m[i] = msg[i];

        n = p * q;

        t = (p - 1) * (q - 1);

        ce();

        string ret = "";
        stringstream returnval;
        for (int z = 0; z < sizeof(en); z++) {
            if (en[z] != 0)
                returnval << en[z];

            ret.append(returnval.str());
        }
        return ret;
    }

    void ce() {
        int k;
        k = 0;

        for (i = 2; i < t; i++) {
            if (t % i == 0)
                continue;

            flag = prime(i);

            if (flag == 1 && i != p && i != q) {
                e[k] = i;
                flag = cd(e[k]);
                if (flag > 0) {
                    d[k] = flag;
                    k++;
                }

                if (k == 99)
                    break;
            }
        }
    }

    long int cd(long int x) {
        long int k = 1;
        while (1) {
            k = k + t;
            if (k % x == 0)
                return (k / x);
        }
    }


    void encrypt() {

        long int pt, ct, key = e[0], k, len;

        i = 0;

        len = strlen(msg);

        while (i != len) {

            pt = m[i];

            pt = pt - 96;

            k = 1;

            for (j = 0; j < key; j++) {

                k = k * pt;

                k = k % n;

            }

            temp[i] = k;

            ct = k + 96;

            en[i] = ct;

            i++;

        }

        en[i] = -1;
    }
};