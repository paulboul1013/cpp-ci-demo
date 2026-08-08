#pragma once

class AccountRepository {
public:
    virtual ~AccountRepository() = default;

    virtual bool exists(int id) const = 0;

    virtual int getBalance(int id) const = 0;

    virtual void setBalance(
        int id,
        int balance
    ) = 0;
};