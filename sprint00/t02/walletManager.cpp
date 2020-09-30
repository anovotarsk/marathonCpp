#include "walletManager.h"


Wallet* createWallet(int septims) {
    Wallet* wallet = new Wallet;

    if (wallet == nullptr)
        return nullptr;
    wallet->septims = septims;
    return wallet;
}

void destroyWallet(Wallet* wallet) {
    delete wallet;
    wallet = nullptr;
}

Wallet* createWallets(int amount) {
    Wallet* wallets = new Wallet [amount];

    return wallets;
}

void destroyWallets(Wallet* wallets) {
    delete wallets;
    wallets = nullptr;
}
