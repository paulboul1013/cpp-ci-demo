#pragma once

#include "account_repository.h"

class AccountService {
public:
    explicit AccountService(
        AccountRepository& repository
    )
        : repository_(repository) {}

    bool transfer(
        int from,
        int to,
        int amount
    );

private:
    AccountRepository& repository_;
};