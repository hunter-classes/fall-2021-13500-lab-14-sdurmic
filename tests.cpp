#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "MyVector.h"

TEST_CASE("MyVector(), size() capacity() empty() functions")
{
    MyVector<int> v = MyVector<int>(20);
    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);
    CHECK(v.empty() == true);

    MyVector<int> v2;
    CHECK(v2.size() == 0);
    CHECK(v2.capacity() == 10);
    CHECK(v2.empty() == true);
}

TEST_CASE("push_back(item) and []operator functions")
{
    MyVector<int> v = MyVector<int>(20);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (int i = 0; i < 10; i++)
    {
        CHECK(v[i] == i);
    }
    CHECK(v.size() == 10);
    CHECK(v.capacity() == 20);
    CHECK(v.empty() == false);

    for (int i = 10; i < 20; i++)
    {
        v.push_back(i);
    }
    CHECK(v.size() == 20);
    CHECK(v.capacity() == 20);
    CHECK(v[19] == 19);

    for (int i = 20; i < 30; i++)
    {
        v.push_back(i);
    }
    for (int i = 25; i < 30; i++)
    {
        CHECK(v[i] == i);
    }
    CHECK(v.size() == 30);
    CHECK(v.capacity() == 30);
}

TEST_CASE("pop_back() function")
{
    MyVector<int> v = MyVector<int>(20);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    CHECK(v.size() == 10);
    CHECK(v.capacity() == 20);

    v.pop_back();
    CHECK(v.size() == 9);
    CHECK(v.capacity() == 20);

    for (int i = 0; i < 9; i++)
    {
        v.pop_back();
    }
    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);

    v.pop_back();
    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);
}

TEST_CASE("pop_back(n) function")
{
    MyVector<int> v = MyVector<int>(20);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    CHECK(v.size() == 10);
    CHECK(v.capacity() == 20);

    CHECK(v[3] == 3);
    v.pop_back(3);
    CHECK(v.size() == 9);
    CHECK(v.capacity() == 20);
    CHECK(v[3] == 4);

    CHECK(v[0] == 0);
    v.pop_back(0);
    CHECK(v.size() == 8);
    CHECK(v.capacity() == 20);
    CHECK(v[0] == 1);

    v.pop_back(10); 
    v.pop_back(-3);
    CHECK(v.size() == 8);
    CHECK(v.capacity() == 20);

    v.clear();
    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);
    v.pop_back(0);
    CHECK(v.size() == 0);
}
   
TEST_CASE("clear() function")
{
    MyVector<int> v = MyVector<int>(20);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    CHECK(v.size() == 10);
    CHECK(v.capacity() == 20);
    CHECK(v.empty() == false);

    v.clear();
    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);
    CHECK(v.empty() == true);
}