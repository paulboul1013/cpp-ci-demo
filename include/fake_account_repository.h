#include "account_repository.h"

#include <unordered_map>

class FakeAccountRepository
    : public AccountRepository {

public:
    void addAccount(
        int id,
        int balance
    ) {
        accounts_[id] = balance;
    }

    bool exists(
        int id
    ) const override {
        return accounts_.contains(id);
    }

    int getBalance(
        int id
    ) const override {
        return accounts_.at(id);
    }

    void setBalance(
        int id,
        int balance
    ) override {
        accounts_[id] = balance;
    }

private:
    std::unordered_map<int, int>
        accounts_;
};