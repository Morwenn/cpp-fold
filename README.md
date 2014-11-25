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
for the different elements. The `sum` function above performs a left fold.
To perform a right fold, we only have to switch the order of `args` and
`...` in the fold expression:

```cpp
return (... + args);
```

These two fold expressions are called *unary folds* since they only take
a parameter pack. However, the proposal also introduces *binary folds* in
order to provide an extra element to those of the pack: `(args + ... + 0)`
performs a *binary left fold* while `(0 + ... + args)` performs a *binary
right fold*. Both add 0 to `args`.

## Identity elements

The proposal about fold expressions also adds a a table which specifies
which value should be returned for which operator when an empty parameter
pack is given to an unary fold expression:

Operator | Value when parameter pack is empty
-------- | ----------------------------------
`*` | `1`
`+` | `0`
`&` | `-1`
`|` | `0`
`&&` | `true`
`||` | `false`
`,` | `void()`

If an operator does not appear in this table, using with an empty
parameter pack in a fold expression makes the program ill-formed.

The default values have probably been chosen because they represent the
[identity element](https://en.wikipedia.org/wiki/Identity_element) for
a type together with an operation (an element that leaves the other
operand unchanged):

Identity element | Typed operation
---------------- | ---------------
`1` | Integer multiplication
`0` | Integer addition
`-1` | Bitwise AND
`0` | Bitwise OR
`true` | Boolean AND
`false` | Boolean OR
`void()` | Elements separation

While these default values are fine with most of the built-in types,
they might not be suitable when an operation is overloaded for some
user-defined type (paper about that later).

## cpp-fold

**cpp-fold** is a generic library solution to propose to provide identity
elements for a given type/operation pair. Since fold expressions require
compiler support, **cpp-fold** provides two main operations to replace
them in pure C++14:

* `lfold`, a left fold function.
* `rfold`, a right fold function.

Both of these functions take a binary function object template parameter
and a number of parameters. Here is an example:

```cpp
int main
{
    using namespace cppfold;

    // Add integers
    int foo = rfold<plus>(1, 8, 5, 3, 6);

    // Concatenate strings
    std::string bar = lfold<multiplies>("Hello"s, "my"s, "dear"s, "world."s);
}
```

As you can see. Every function lives in the namespace `cppfold`. That is
also true for the function objects `plus` and `multiplies` that are used
in the example above.

### Function objects

**cpp-fold** provides some function object to represent the operators
allowed in fold expressions by N4191. These functions objects have a
straightforward implementation:

```cpp
struct plus
{
    template<typename T, typename U>
    constexpr auto operator()(T&& lhs, U&& rhs) const
        -> decltype(std::forward<T>(lhs) + std::forward<U>(rhs))
    {
        return std::forward<T>(lhs) + std::forward<U>(rhs);
    }
};
```

The implementation of `cppfold::plus` matches the implementation of
`std::plus<void>`. The aim of this specialization is to represent an
operation without representing its actual type so that other classes
and/or function can be specialized for an operation without having to
consider the type of its parameters. It represents what Eric Niebler
calls a [synchronization point](http://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/).
Therefore, every such function objects is meant to use ADL to find
the most suitable function to perform the operation.

### Folding empty parameter packs

When `lfold` or `rfold` is given an empty parameter pack, it returns
an instance of `empty_fold` which is implement as follows:

```cpp
template<typename BinaryFunction>
struct empty_fold
{
    template<typename T>
    constexpr operator T() const
    {
        return identity_element<T, BinaryFunction>::value;
    }
};
```

Here, `identity_element` is a trait class that represents the identity
element for the given binary operation. It is specialized for built-in
types so that the following code works:

```cpp
int a = lfold<plus>(); // 0
inb b = lfold<multiplies>(); // 1
float c = lfold<plus>(); // 0.0f
```

It can easily be specialized for user-defined types, including the
standard library ones. Here is how we can tell that the empty string
is the identity element of string concatenation:

```cpp
namespace cppfold
{
    template<>
    struct identity_element<std::string, plus>
    {
        static const std::string value = ""s;
    }
}
```

In a near future variable templates will be used instead of a class
template to represent the identity element for a given type/operation
pair. However, variable templates are still not widely supported by
compilers. When this happens, it will be a breaking change.

### Pitfalls

There are several pitfalls to this approach. First of all, we need to
use generic function objects and customization points to achieve the
generic mechanism since we need a full type to achieve the compile
time specialization. That means that, for a given operation, there must
be both an existing function *and* a function object. That is generic,
but still quite heavy.

Moreover, the element returned when an empty parameter is given to one
of the fold functions is probably not of the "expected type" but of a
type convertible to that expected type. This means, that the following
line may be surprising:

```cpp
auto res = lfold<multiplies>();
```

To avoid this kind of problems, we would need a way to tell the language
that a type cannot be deduced with `auto`. That could be the object of
yet another complete proposal and there may still be cases where we would
like to deduce the type.

In other words, these fold functions are generic but need some heavy
contribution from the users to work even with the empty parameter pack
case.


