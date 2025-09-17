// Day07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Color.h"
#include "Employee.h"
#include "Manager.h"
#include <vector>


/*              CLASSESS

            ╔═════╗ ╔═════════╗
            ║class║ ║SomeClass║
            ╚═════╝ ╚═════════╝
                │          │        
             ┌──┘          │         
        ┌────▼─────┐   ┌───▼───┐   
        │ Keyword  │   │ Class │  
        │          │   │  Name │
        └──────────┘   └───────┘ 

        FIELDS - the data of the class

        METHODS - the behavior of the class (what the class can do)

        SPECIAL METHODS:
            Getters/Setters - the gatekeepers of the fields
            CONSTRUCTORS - the initializer of the class
            DESTRUCTORS - destroys allocated memory.


      


    ╔══════════════════╗
    ║ ACCESS MODIFIERS ║ - determines who can see it
    ╚══════════════════╝
        public: EVERYONE can see it
        private: ONLY this class can see it  (default)
        protected: this class and all its descendent classes can see it




*/

// Compile-Time Polymorphism:
// Overloading:
//  has to be different on the parameters
//  return type is not enough

void DoIt()
{}
int DoIt(int n)
{
    return 0;
}
int DoIt(int n1, int n2) { return 0; }
float DoIt(float f1, float f2) { return 0; }

void counter()
{
    static int i = 0;
    std::cout << i << " ";
    i++;
}
int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        counter();
    }
    //Animal animal;
    DoIt();
    DoIt(5);
    int n1 = 5, n2 = 6;
    int sum = n1 + n2;

    int num = 5;
    int num2 = 7;
    int* pNum;//pointer to an int
    pNum = &num;//address-of num
    pNum = &num2;//points pNum to num2
    std::cout << pNum << "\n" << *pNum << "\n";

    int& rNum = num;
    rNum = num2;//copying num2 TO num

    //
    // MODERN C++ pointer: unique_ptr object
    //   it manages the pointer for you
    //   it is the ONLY variable that can point to the memory (unique)
    // 
    // "=new" means memory is allocated on the heap, not the stack
    //EVERY "=new" requires a corresponding  "delete"!!
    {
        int* hNum = new int(10);
        delete hNum;//deallocated the int

        std::unique_ptr<Employee> uEmp = 
            std::make_unique<Employee>("Alfred Pennyworth", 95, "Butler", 50);
        //when it goes out of scope, it AUTOMATICALLY deletes the memory. no memory leak!!

        //std::unique_ptr<Employee> uEmp2 = uEmp;
    }//hNum is deallocated, but the int is still alive on the heap


    Person steve("Steve Austin", 30, "6.5", 250, "--");//creating an instance (object) of the class
    int age = steve.Age();//????
    std::cout << age << "\n";
    //steve.SSN = "123-45-6789";
    //steve.SSN = "BLAH!";
    //steve.SetName("Steve Austin");
    //steve.Age(30);
    Person::Report();

    Employee alfred("Alfred Pennyworth", 95, "Butler", 50);
    Manager bruce("Bruce Wayne", 35, "Butler", 30);
    bruce.DoWork(18);
    alfred.DoWork(20);
    Employee* pEmp = &alfred;
    std::cout << pEmp->GetName() << "\n";
    pEmp->DoWork(20);
    pEmp = &bruce;//UPCAST
    //UPCAST: casting from a CHILD type to a PARENT type
    //UPCAST is ALWAYS safe
    Person* peep = &bruce;

    //DOWNCAST: casting from a PARENT type to a CHILD type
    //DOWNCAST is NOT safe

    std::cout << "MEMORY LOCATIONS:\n"<< & bruce << "\n" << pEmp << "\n" << peep << "\n";
    std::cout << pEmp->GetName() << "\n";
    pEmp->DoWork(18);

    Employee e1 = bruce;//COPIES the employee parts to e1

    std::unique_ptr<Employee> uAlfred = std::make_unique<Employee>("Alfred Pennyworth", 95, "Butler", 50);
    std::unique_ptr<Manager> uBruce = std::make_unique<Manager>("Bruce Wayne", 35, "Butler", 30);
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::move(uAlfred));
    employees.push_back(std::move(uBruce));//copies the memory address to Bruce
    //pointers will keep this from happening

    for (auto& employee : employees)
    {
        employee->DoWork(rand() % 9);
    }

    int n5 = 6;
    long l5 = n5;//implicit cast
    n5 = (int)l5;//explicit cast




    Color redColor;
    redColor.red = 255;
    redColor.blue = 0;
    redColor.green = 0;
    redColor.alpha = 255;
    /*
        Lecture code: add a Car class
    
    */

    /*
        CHALLENGE:

            Create a Person class.
            Right-Click the project and select "Add > Class..."

    */




    /*
        ╔════════╗
        ║ FIELDS ║ - the data members of the class
        ╚════════╝

        use mCamelCasingNamingConvention to name your fields in a C# class

        int mModelYear;

        Lecture code: add year, make, model fields to the car class

    */

    /*
        CHALLENGE:
            Add an age field and a name field to the Person class
    */





    /*
        ╔═════════╗
        ║ METHODS ║ - the member functions of the class -- the behavior of the class (what it can do)
        ╚═════════╝

        non-static methods can access the fields/methods of the class
        static methods can only access the static members of the class

        EXAMPLE:
        void whoAmI()
        {
            std::cout << mName;
        }

        Lecture code: add a vehicleInformation method
    */


    /*
        CHALLENGE:
            write an ItsMyBirthday method. increment age and print out a happy message.
    */





    /*
        ╔═════════════════╗
        ║ Getters/Setters ║ - the gatekeepers (control access) of the fields
        ╚═════════════════╝

        use camelCasingNamingConvention to name your getter/setter methods


        int modelYear() const  //const says the method can't modify anything
        {
            return mModelYear;  //provides access to the field's value
        }

        void modelYear(int year)
        {
            mModelYear = year;
        }

        Lecture code: add getters/setters for year, make, model fields to the car class
    */


    /*

        CHALLENGE:
            Add Age getter/setter to provide access to the mAge field
            Add a Name getter/setter for the mName field
    */




    /*
        ╔══════════════╗
        ║ CONSTRUCTORS ║ - the initializer of the class. Initialize the data of the class.
        ╚══════════════╝

        RULES FOR CONSTRUCTORS...
        1) cannot have any return type, not even void
        2) must have the same name as the class

        HINT: use the ctor code snippet to provide a default constructor

        Car(int year, std::string make)
        {
           mModelYear = year;
           mMake = make;
        }

        Lecture code: add 2 ctors (default and non-default) to the car class
    */


    /*

        CHALLENGE:
            Add a constructor to the Person class to initialize the age and name fields
    */




    /*
        ╔══════════════╗
        ║  STRUCTURES  ║ - light-weight data objects
        ╚══════════════╝

        In C++, structs are just like classes EXCEPT members are public by default.

        Lecture code: add struct for ManufacturerDetails (Name, YearEstablished)
    */

}