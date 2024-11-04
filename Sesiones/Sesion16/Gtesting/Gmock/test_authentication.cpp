#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Authentication.h"
#include "Mock_Database.h"


using::testing::Return; 

// Pureba para el inicio de sesión exitoso
TEST(AuthenticationTest, LoginSuccess){
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice")).WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice")).WillOnce(Return("password"));

    EXPECT_TRUE(auth.login("Alice", "password"));

}


//Prueba para incicio de sesion fallido

TEST(AuthenticationTest, LoginFailure){
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice")).WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice")).WillOnce(Return("password"));

    EXPECT_FALSE(auth.login("Alice", "wrongpassword"));
    EXPECT_CALL(db, userExists("Bob")).WillOnce(Return(false));
    EXPECT_FALSE(auth.login("Bob", "password"));

}

//Prueba para el registro de nuevo usuario

TEST(AuthenticationTest, RegisterUser){
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Charlie")).WillOnce(Return(false));
    EXPECT_CALL(db, addUser("Charlie", "password")).Times(1);

    auth.registerUser("Charlie", "password");

}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

