```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Programming is fun!" << endl;
    cout << "Fundamentals First" << endl;
    cout << "Problem Driven" << endl;
    cout << "(10.5 + 2 * 3) / (45 - 3.5) = ";
    cout << (10.5 + 2 * 3) / 45 - 3.5 << endl;
    
    return 0;
}
```

`std` is an abbreviation of *standard*. Namespace is a mechanism to avoid naming conflicts in a large program. The names `cout` and `endl` are defined in the `iostream` library in the standard namespace. For the compiler to find these names, the statement `using namespace std` must be used.

`cout` stands for *console output*. The `<<` operator, referred to as the *stream insertion operator*, sends a string a string to the console. `endl` stands for *end line*. Sending `endl` to the console ends a line and flushes the output buffer to ensure that the output is displayed immediately.

`return 0;` is placed at the end of every main function to exit the program. The value `0` indicates that the program has terminated with a successful exit. Some compilers will work fine if this statement is omitted; however, other compilers will not. It is a good practice to always include this statement for your program to work with all C++ compilers.

# 2 Elementary Programming

## 2.3 Reading Input from the Keyboard

```cpp
#include <iostream>
using namespace std;

int main()
{
    double number1, number2, number3;
    cout << "Enter three numbers: ";
    cin >> number1 >> number2 >> number3;
    
    // Compute average
    double average = (number1 + number2 + number3) / 3;
    cout << "The average of " << number1 << " " << number2 << " " << number3 << " is " << average << endl;
    return 0;
}
```

```bash
Enter three numbers: 1 2 3 #ENTER
The average of 1 2 3 is 2
```

```bash
Enter three numbers: 10.5 #ENTER
11 #ENTER
11.5 #ENTER
The average of 10.5 11 11.5 is 11
```

# 4 Mathematical Functions, Characters, and Strings

## 4.2 Mathematical Functions

```cpp
#include <cmath>
```

### Trigonometric

### Exponent

### Rounding

### `min, max, abs`

```cpp
#include <cstdlib>
```

## 4.6 Character Functions

```cpp
#include <cctype>
```

## 4.8 The `string` Type

Simple Functions from `string` Objects

| Function    | Description                                                  |
| ----------- | ------------------------------------------------------------ |
| `length()`  | Returns the number of characters in this string.             |
| `size()`    | Same as `length()`.                                          |
| `at(index)` | Returns the character at the specified index from this string. |

> By default, a string is initialized to an *empty string*. The following two statements have the same effect:
>
> ```cpp
> string s;
> string s = "";
> ```
>
> It is illegal to concatenate two string literals. The following code is **incorrect**:
>
> ```cpp
> string cities = "London" + "Paris";
> ```
>
> However, the following code is **correct**.
>
> ```cpp
> string s = "New York";
> string cities = s + "London" + "Paris";
> ```

### 4.8.3 Comparing Strings

Relational operators compare the characters lexographically one by one from left to right.

### 4.8.4 Reading Strings

```cpp
getline(cin, s, delimitCharacter)
```

The function stops reading characters when the delimiter character is encountered. The delimiter is read but not stored into the string. **The third argument `delimitCharacter` has a default value `'\n'`.**

```cpp
string city;
cout << "Enter a city: ";
getline(cin, city, '\n'); // Same as getline(cin, city)
cout << "You entered " << city << endl;
```

# 6 Functions

## 6.10 Inline Functions

> C++ provides inline functions for improving performance for short functions.

Function calls involve runtime overhead (i.e., pushing arguments and CPU registers into the stack and transferring control to and from a function). Inline functions are not called; rather the compiler copies the function code *in line* at the point of each invocation.

Behind the scenes, the C++ compiler expands the inline function call by copying the inline function code. So,

```c
inline void f(int month, int year)
{
    cout << "month is " << month << endl;
    cout << "year is " << year << endl;
}

int main()
{
    int month = 10, year = 2008;
    f(month, year); // Invoke inline function
    f(9, 2010);
    
    return 0;
}
```

the `main()` becomes:

```cpp
int main()
{
    int month = 10, year 2008;
    cout << "month is " << month << endl;
    cout << "year is " << year << endl;
    cout << "month is " << 9 << endl;
    cout << "year is " << 2010 << endl;
}
```

> It's up to the compiler to decide whether to honor or ignore the `inline` request.

## 6.13 Constant Reference Parameters

> You can specify a constant reference parameter to prevent its value from being changed by accident.

```cpp
int max(const int& num1, const int& num2)
{
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}
```

In pass-by-value, the actual parameter and its formal parameter are independent variables. In pass-by-reference, the actual parameter and its formal parameter refer to the same variable. Pass-by-reference is more efficient than pass-by-value for object types such as strings, because objects can take a lot of memory. **If a primitive data type is not changed in the function, you should simply declare it as pass-by-value parameter.**

# 9 Objects and Classes

## 9.2 Defining Classes for Objects

```cpp
#include <iostream>
using namespace std;

class Circle
{
    public:
    double radius;
    
    Circle()
    {
        radius = 1;
    }
    
    Circle(double newRadius)
    {
        radius = newRadius;
    }
    
    double getArea()
    {
        return radius * radius * 3.14159;
    }
}; // Must place a semicolon here

int main()
{
    Circle circle1(1.0);
    Circle circle2(25);
    Circle circle3(125);
    
    cout << "The area of the circle of radius " << circle1.radius << " is " << circle1.getArea() << endl;
    
    circle2.radius = 100;
    cout << "The area of the circle of radius " << circle2.radius << " is " << circle2.getArea() << endl;
    
    return 0;
}
```

## 9.4 Constructors

### Constructor Initializer List


## 9.6 Separating Class Definition from Implementation

> Separating class definition from class implementation makes the class easy to maintain.

C++ allows you to separate class definition from implementation. The class definition simply lists all the data fields, constructor prototypes, and function prototypes. The class implementation implements the constructors and functions. The class definition and implementation may be in two separate files. **Both files should have the same name but different extension names.** The class definition file has an extension names `.hpp` and the class implmentation file an extension name `.cpp`.

`Circle.hpp`

```cpp
class Circle
{
    public:
    double radius;
    Circle(); // Construct a default circle object
    Circle(double); // Construct a circle object
    double getArea();
}; // DO NOT OMIT SEMICOLON AFTER CLASS DEFINITION
```

`Circle.cpp`

```cpp
#include "Circle.h"

Circle::Circle() // Construct a default circle object
{
    radius = 1;
}

Circle::Circle(double newRadius)
{
    radius = newRadius;
}

double Circle::getArea()
{
    return radius * radius * 3.14159;
}
```

The `::` symbol, known as the *binary scope resolution operator*, specifies the scope of a class member in a class.

Here, `Circle::` preceding each constructor and function in the `Circle` class tells the compiler that these constructors and functions are defined in the `Circle` class.

`TestCircleWithHeader.cpp`

```cpp
#include <iostream>
#include "Circle.h"
using namespace stf;

int main()
{
    Circle circle1;
    Circle circle2(5.0);
    
    cout << "The area of the circle of radius " << circle1.radius << " is " << circle1.getArea() << endl;
    
    circle2.radius = 100;
    cout << "The area of the circle of radius " << circle2.radius << " is " << circle2.getArea() << endl;
    
    return 0;
}
```

### compiling on a mac

```bash
g++ -c Circle.cpp
g++ -o main TestCircleWithHeader.cpp Circle.o
./main
```

## 9.7 Preventing Multiple Inclusions

```cpp
#ifndef
#define
#endif
```

## 9.8 Inline Functions in Classes

## 9.9 Data Field Encapsulation

`CircleWithPrivateDataFields.hpp`

```cpp
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle
{
    public:
    Circle();
    Circle(double);
    double getArea();
    double getRadius();
    void setRadius(double);
    
    private:
    double radius;
};

#endif
```

`CircleWithPrivateDataFields.cpp`

```cpp
#include "CircleWithPrivateDataFields.hpp"

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(double newRadius)
{
    radius = newRadius;
}

double Circle::getArea()
{
    return radius * radius * 3.14159;
}

double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double newRadius)
{
    radius = (newRadius >= 0) ? newRadius : 0;
}
```

# 10 Object-Oriented Thinking

## 10.2 The `string` class



## 10.6 Constant Member Functions

> tell the compiler that the function should not change the value of any data fields in the object.

place the `const` keyword at the end of the function header.

Only instance member functions can be defined as constant functions. Like constant parameters, constant functions are for *defensive programming*. If your function mistakenly changes the value of data fields in a function, a compile error will be reported. **You cannot define static functions to be constant.** ***An instance get function should always be defined as a constant member function, because it does not change the contents of the object.***

```cpp
void printCircle(const Circle& c)
{
    cout << "The area of the circle of " << c.getRadius() << " is " << c.getArea() << endl;
}
```

**The above code will not compile if the `getRadius()` or `getArea()` function is not defined `const`.**

> You can use `const` modifier to specify a constant reference parameter or a constant member function. You should use the `const` modifier *consistently* whenever appropriate.

# 11 Pointers and Dynamic Memory Management

## 11.12 Destructors

> Every class has a destructor, which is called automatically when an object is deleted.

Every class has a default destructor if the destructor is not explicitly defined. Sometimes, it is desirable to implement destructors to perform customized operations. Destructors are named the same as constructors, but you must put a `~` in front.

Implementing a destructor

```cpp
Circle::~Circle()
{
    numberOfObjects--;
}
```

## 11.14 Copy Constructors

Each class may define several overloaded constructors and one destructor. Additionally, every class has a *copy constructor*, which can be used to create an object initialized with the data of another object of the same class.

```cpp
ClassName(const ClassName&)
```

A default copy constructor is provided for each class implicitly, if it is not defined explicitly. The default copy constructor simply copies each data field in one object to its counterpart in the other object.

Note that memberwise assignment operator and copy constructor are similar in the sense that both assign values from object to the other. The difference is that a new object is created using a copy constructor. Using the assignment operator does not create new objects.

**The default copy constructor or assignment operator for copying performs a shallow copy, rather than a deep copy**, meaning that **if the field is a pointer to some object, the *address* of the pointer is copied rather than its contents.**

## 11.15 Customizing Copy Constructors

`CourseWithCustomCopyConstructor.hpp`

```cpp
#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;

class Course
{
    public:
    Course(const string& courseName, int capacity);
    ~Course(); // Destructor
    Course(const Course&); // Copy constructor
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;
    
    private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
};

#endif
```

`CourseWithCustomCopyConstructor.hpp`

```cpp
#include <iostream>
#include "CourseWithCustomCopyConstructor.hpp"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::~Course()
{
    delete [] students;
}

string Course::getCourseName() const
{
    return courseName;
}

void Course::addStudent(const string& name)
{
    if (numberOfStudents >= capacity)
    {
        cout << "The maximum size of array exceeded" << endl;
        cout << "Program terminates now" << endl;
        exit(0);
    }
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
    // Left as an exercise
}

string* Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

Course::Course(const Course& course) // Copy constructor
{
    courseName = course.courseName;
    numberOfStudents = course.numberOfStudents;
    capacity = course.capacity;
    students = new string[capacity]; // Create a new array, does not copy existing students.
}
```

# 14 Operator Overloading

