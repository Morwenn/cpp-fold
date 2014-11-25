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
a type together with an operation:

Default value | Typed operation
------------- | ---------------
`1` | Integer multiplication
`0` | Integer addition
`-1` | Bitwise AND
`0` | Bitwise OR
`true` | Boolean AND
`false` | Boolean OR
`void()` | Elements separation

## cpp-fold

