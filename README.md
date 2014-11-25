**cpp-fold** is a C++14 library whose goal is to explore the intersection
of variadic fold functions, empty parameter packs and identity elements.
It is a library experiment to possibly improve the C++17 fold expressions.

## Fold expressions

Fold expressions are a new kind of expressions introduced by the proposal
[N4191](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4191.html).
The aim of fold expressions is to provide a simple way to apply some
operations to parameter packs. For example, to add all the elements of a
parameter pack, one can write such a function:

```cpp
template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}
```

In this example, the elements of the parameter pack `args` will be added
from left to right. ADL is used to find the good overloads of `operator+`
for the different elements.

## Identity elements

## cpp-fold

