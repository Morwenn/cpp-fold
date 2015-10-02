**cpp-fold** is a C++14 library whose goal is to explore the intersection
of variadic fold functions, empty parameter packs and identity elements.
It is a library experiment to possibly improve C++17's fold expressions.

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
from left to right. ADL is used to find the right overloads of `operator+`
for the different elements. The `sum` function above performs a left fold.
To perform a right fold, one only has to switch the order of `args` and
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

The fold expressions proposal also adds a table which specifies which
value should be returned for which operator when an empty parameter pack
is given to an unary fold expression:

Operator | Value when parameter pack is empty
-------- | ----------------------------------
`*` | `1`
`+` | `0`
`&` | `-1`
`|` | `0`
`&&` | `true`
`||` | `false`
`,` | `void()`

If an operator does not appear in this table, using it with an empty
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
user-defined type (see my own paper, [N4358](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4358.pdf)).

## cpp-fold

**cpp-fold** is a generic fold library solution which provides identity
elements for several type/operation pairs. Since fold expressions require
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

    // Multiply integers
    int foo = rfold<multiplies>(1, 8, 5, 3, 6);

    // Concatenate strings
    std::string bar = lfold<plus>("Hello"s, "my"s, "dear"s, "world."s);
}
```

As you can see. Every function lives in the namespace `cppfold`. That is
also true for the function objects `plus` and `multiplies` which are used
in the example above.

### Function objects

**cpp-fold** provides some function objects to represent the operators
allowed in fold expressions by N4191. These function objects have a
straightforward implementation:

```cpp
struct assign
{
    template<typename T, typename U>
    constexpr auto operator()(T&& lhs, U&& rhs) const
        -> decltype(std::forward<T>(lhs) = std::forward<U>(rhs))
    {
        return std::forward<T>(lhs) = std::forward<U>(rhs);
    }
};
```

The implementation of `cppfold::plus` matches the implementation of
`std::plus<void>`. The aim of this specialization is to represent an
operation without representing its actual type so that other classes
and/or functions can be specialized for an operation without having to
consider the type of its parameters. It represents what Eric Niebler
calls a [synchronization point](http://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/).
Therefore, every such function object is meant to use ADL to find
the most suitable real function to perform the operation.

The names of the objects for the usual binary operations are the same
than the ones in the standard library. For a standard library functor,
`cppfold::functor` is strictly equivalent to `std::functor<void>`. The
new function objects have mainly been introduced to simplify the whole
thing. Moreover, when the equivalent function object already exists in
the standard library, the **cpp-fold** version is merely a type alias
to its `void` specialization.

### Folding empty parameter packs

When the functions `lfold` or `rfold` are given an empty parameter pack,
they respectively return an instance of `empty_lfold` or `empty_rfold`,
which are implemented as follows (you can guess `empty_rfold`):

```cpp
template<typename BinaryFunction>
struct empty_lfold
{
    template<typename T>
    constexpr operator T() const
    {
        return left_identity_element<T, BinaryFunction>::value;
    }
};
```

Here, `left_identity_element` is a trait class which represents the left
identity element for the given binary operation. It is specialized for
built-in types so that the following code works:

```cpp
int a = lfold<plus>(); // 0
int b = lfold<multiplies>(); // 1
float c = lfold<plus>(); // 0.0f
```

There is a matching `right_identity_element` in the library as well as a
generic `identity_element`. These classes can easily be specialized for
user-defined types, including the standard library ones. Here is how we
can tell that an empty string is the identity element for string concatenation:

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

These three classes are defined in a way that allows one to specialize
`identity_element` and get working right and left identity elements at
once:

```cpp
namespace cppfold
{
    template<typename T, typename BinaryFunction>
    struct identity_element;

    template<typename T, typename BinaryFunction>
    struct right_identity_element:
        identity_element<T, BinaryFunction>
    {};

    template<typename T, typename BinaryFunction>
    struct left_identity_element:
        identity_element<T, BinaryFunction>
    {};
}
```
    
In a near future, variable templates will be used instead of a class
template to represent the identity element for a given type/operation
pair. However, variable templates are still not widely supported by
compilers. When this happens, it will be a breaking change.

### Standard library types

Some standard library types have binary operations with identity elements,
but no standard way retrieve them. Therefore, cpp-fold provides some
specializations of `identity_element` for these type/operation pairs.
Currently, cpp-fold provides identity elements for the following magmas:

* `std::basic_string` and `cppfold::plus`
* `std::complex` and `cppfold::plus`
* `std::complex` and `cppfold::multiplies`

The identity elements are also provided by default for built-in types when
a functor is included. For standard library types, one has to include the
header `<cppfold/std/header.h>` where `header.h` has a corresponding
`<header>` in the standard library.

```cpp
#include <cassert>
#include <complex>
#include <cppfold/std/complex.h>

int main()
{
    using namespace cppfold;

    std::complex<double> comp = { 1.5, 2.3 };
    auto idp = identity_element<std::complex<double>, plus>;
    auto idm = identity_element<std::complex<double>, multiplies>;
    
    assert(comp + idp == comp);
    assert(idp + comp == comp);
    assert(comp * idm == comp);
    assert(idm * comp == comp);
}
```

### Pitfalls

There are several pitfalls to this approach. First of all, we need to
use generic function objects and customization points to achieve the
generic mechanism since we need a full type to achieve the compile
time specialization. It means that, for a given operation, there must
be both an existing function *and* a function object. That is generic,
but still quite heavy for a mere corner case of folding operations.

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
like to deduce the type anyway.

In other words, these fold functions are generic but need some heavy
contribution from the users to work properly with the empty parameter pack
case. And that only cover the cases where operations *do* have identity
elements. That's a big hammer for such a small benefit.

Another notable pitfall concerns the floating point types: identity
elements are provided for some of the floating point operations, but they
do not play well with `NAN` since comparing anything to `NAN` will return
`false`, including `NAN` itself. Therefore, `NAN` is ignored in the library
since users would still want to get the identity elements for "floating
point without `NAN`" anyway. That's a question of correctness versus
usability.
