#include "account_service.h"

bool AccountService::transfer(
    int from,
    int to,
    int amount
) {
    if (amount <= 0) {
        return false;
    }

    if (from == to) {
        return false;
    }

    if (
        !repository_.exists(from) ||
        !repository_.exists(to)
    ) {
        return false;
    }

    int fromBalance =
        repository_.getBalance(from);

    if (fromBalance < amount) {
        return false;
    }

    int toBalance =
        repository_.getBalance(to);

    repository_.setBalance(
        from,
        fromBalance - amount
    );

    repository_.setBalance(
        to,
        toBalance + amount
    );

    return true;
}