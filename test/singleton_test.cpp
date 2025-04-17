#include <gtest/gtest.h>
#include "../singleton.cpp" // or use a header if you have singleton.h

TEST(SingletonTest, GetInstanceShouldReturnSameObject) {
    auto& obj1 = Singleton::getInstance();
    auto& obj2 = Singleton::getInstance();
    EXPECT_EQ(&obj1, &obj2); // Same address = same instance
}
