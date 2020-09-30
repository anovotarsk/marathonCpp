//#pragma once
#ifndef WALLET

#include <iostream>
#include <ostream>
#include <string>

struct Wallet {
    int septims;
};

Wallet* createWallet(int septims);
void destroyWallet(Wallet* wallet);
Wallet* createWallets(int amount);
void destroyWallets(Wallet* wallets);

#endif
