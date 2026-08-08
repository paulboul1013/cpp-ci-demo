#include <gtest/gtest.h>

#include "account_service.h"
#include "fake_account_repository.h"


TEST(
    AccountServiceTest,
    TransferMoneySuccessfully
) {
    FakeAccountRepository repo;

    repo.addAccount(1, 1000);
    repo.addAccount(2, 500);

    AccountService service(repo);

    bool result =
        service.transfer(1, 2, 300);

    EXPECT_TRUE(result);

    EXPECT_EQ(
        repo.getBalance(1),
        700
    );

    EXPECT_EQ(
        repo.getBalance(2),
        800
    );
}


TEST(
    AccountServiceTest,
    CanTransferEntireBalance
) {
    FakeAccountRepository repo;

    repo.addAccount(1, 1000);
    repo.addAccount(2, 500);

    AccountService service(repo);

    EXPECT_TRUE(
        service.transfer(
            1,
            2,
            1000
        )
    );

    EXPECT_EQ(
        repo.getBalance(1),
        0
    );

    EXPECT_EQ(
        repo.getBalance(2),
        1500
    );
}


TEST(
    AccountServiceTest,
    RejectTransferWhenBalanceIsInsufficient
) {
    FakeAccountRepository repo;

    repo.addAccount(1, 1000);
    repo.addAccount(2, 500);

    AccountService service(repo);

    EXPECT_FALSE(
        service.transfer(
            1,
            2,
            1001
        )
    );

    EXPECT_EQ(
        repo.getBalance(1),
        1000
    );

    EXPECT_EQ(
        repo.getBalance(2),
        500
    );
}