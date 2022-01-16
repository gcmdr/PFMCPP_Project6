/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    
    
    T(int& v, const char* newChar)  :  //1
    value(v),
    name{*newChar}
    {}

    int value;          //2
    std::string name;   //3
    
};

struct CompareClass                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        
        return nullptr;
    }
};

struct U
{
    float floatVal1 { 0 }, floatVal2 { 0 };
    float decreaseDistance(float& updatedFloatPtr) 
    {
        std::cout << "U's floatVal1 value: " << floatVal1 << std::endl;
        floatVal1 = updatedFloatPtr;
        std::cout << "U's floatVal1 updated value: " << floatVal1 << std::endl;
        while( std::abs(floatVal2 - floatVal1) > 0.001f )
        {
            /*
             write something that makes the distance between that->floatVal2 and that->floatVal1 get smaller
             */
            floatVal2 -= 0.01f;
        }
        std::cout << "U's floatVal2 updated value: " << floatVal2 << std::endl;
        return floatVal1 * floatVal2;
    }
};

struct DrawTogether 
{
    static float decreaseDistance(U& that, float& updatedFloat )        //10
    {
        
        std::cout << "U's floatVal1 value: " << that.floatVal1 << std::endl;
        that.floatVal1 = updatedFloat;
        std::cout << "U's floatVal1 updated value: " << that.floatVal1 << std::endl;
        while( std::abs(that.floatVal2 - that.floatVal1) > 0.001f )
        {
            /*
            write something that makes the distance between that->floatVal2 and that->floatVal1 get smaller
            */
            that.floatVal2 -= 0.01f;
        }
        std::cout << "U's floatVal2 updated value: " << that.floatVal2 << std::endl;
        return that.floatVal2 * that.floatVal1;
        
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    char a = 'a'; 
    char b = 'b'; 
    
    int one = 1;
    int two = 2;

    T t1(one , &a);                                          //6
    T t2(two , &b);                                          //6 

    CompareClass f;                                          //7
    auto* smaller = f.compare( t1, t2);                      //8

    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl;     //9
    else
        std::cout << t1.name << " and " << t2.name << " are equal" << std::endl; //9

    U u3{2.0f, 5.2f};
    float updatedValue = 5.f;

    std::cout << "decreaseDistance u3's multiplied values: " << std::endl << DrawTogether::decreaseDistance(u3, updatedValue) << std::endl;               //11
    
    U u4{2.0f, 5.2f};

    std::cout << "decreaseDistance u4's multiplied values: " << std::endl << u4.decreaseDistance(updatedValue) << std::endl;
}
