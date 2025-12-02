#import "@preview/diatypst:0.8.0": *

#show: slides.with(
  title: "C++ Lab 5 ", // Required
  subtitle: "Polymorphism",
  date: "02-12-2025",
  authors: ("Yoloba Anisca, Mouret Basile"),

  // Optional Styling (for more and explanation of options take a look at the typst universe)
  ratio: 16/9,
  layout: "medium",
  title-color: blue.darken(50%),
  toc: false,
)

== Polymorphism

In order to declare a function which definition is decided at runtime, we have to use the `virtual` keyword. 

In the first case, we use it on the `Account::debit` method declared as a pure virtual function by using the `virtual <type> <name>(...) = 0;` syntax. This way we don't have to give a definition for the general case, but derived classes will have to give one.

For the stream operator `<<` we will use the `print` methods that were already implemented.
We simply have to declare the method of the first parent class as virtual and use it in it's overloading of the `operator<<`.
This way when this is called the programm will choose the `print` method corresponding to the correct class.

// / *Term*: Definition


== Client update

test
