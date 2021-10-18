#1. Develop a class "large decimal number" in accordance with the following task:

## Class state -

An integer is defined by its length (the number of digits in the number, for example, up to 47) and an array of decimal digit values (of the char type). A signed number is stored in a direct code. When performing arithmetic operations, use additional code. The memory for the array is allocated statically, at compile time, and is set by an array of a fixed size limit.

## Class Protocol -

Defines the possibilities of creating and initializing instances of the class and the rules for their use (methods of the class).

Provide for the following possibilities:

* empty constructor for initializing instances and arrays of default class instances;

* creating instances of a class with initialization with the value of a long integer (type long);

* creating instances of a class initialized with the value of a number as a string of characters;

* input of class instances from the input stream and output of their values to the output stream;

* getting an additional number code;

* performing operations of addition and subtraction of numbers taking into account the signs of numbers;

* performing the operation of "reducing the number by ten times” (dividing by 10 completely);

* performing the operation of "increasing the number tenfold".

## 2. It is recommended to start designing a class by presenting the state of the class, taking into account the specified operations, and then implementing constructors and an output method. For debugging and exhaustive testing of other methods of the developed class, implement a dialog program that allows you to enter parameters of debugged methods. To handle erroneous situations, use the mechanism of exceptional situations.

##3. Repeat the development of the class by implementing separate methods (where it is justified), overloaded with operators. It is advisable to coordinate the composition of overloaded operators with the teacher.

## 4. To repeat the development of the class once again, provided that memory for an array of the required length is allocated dynamically during program execution (using the new operator; memory is set by a pointer to char in the class state). Extra memory should not be used to store data in an instance of a class.

Add the following features to the class interface:

* creating an instance of a class with its initialization by another instance of the class (copying constructor);

* redefining an instance of a class (using an overloaded assignment operator).

Develop and implement an application program using a class developed by another student. The task for the application program should be developed independently and agreed with the teacher.
