#include <iostream>

class A
{
    public:
    const static int me{1111};
};

class B
{
    public:
    const static int me{2222};
};



class Base
{
    public:
    typedef A MyInnerType;
    virtual void whoAmI()
    {
        std::cout << "I'm Base: " << MyInnerType::me << std::endl; 
    }
};

class Derived : public Base
{
    public:
    typedef B MyInnerType;
    void whoAmI()
    {
        std::cout << "I'm Derived: " << MyInnerType::me << std::endl; 
    }
};



int main()
{
    Base base;
    Base& baseRef = base;
    baseRef.whoAmI();

    Derived derived;
    Derived& derivedRef = derived;
    derivedRef.whoAmI();


    Base& baseRefToDerived = derived;
    baseRefToDerived.whoAmI();
}
