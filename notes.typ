= Polymorphism

In order to declare a function which definition is decided at runtime, we have to use the `virtual` keyword. 

In the first case, we use it on the `Account::debit` method declared as a pure virtual function by using the `virtual <type> <name>(...) = 0;` syntax. This way we don't have to give a definition for the general case, but derived classes will have to give one.

For the stream operator `<<` we will use the `print` methods that were already implemented.
We simply have to declare the method of the first parent class as virtual and use it in it's overloading of the `operator<<`.
This way when this is called the programm will choose the `print` method corresponding to the correct class.

