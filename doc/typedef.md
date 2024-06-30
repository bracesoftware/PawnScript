# `typedef`

- This keyword is used to replace an existing set of keywords with one keyword.

Example:

```cpp
typedef{double}decimal

new[decimal]typedeftest=123.4234
console.println.log("{typedeftest}")
```

Output:

```
123.4234
```

## `typedef`s inside namespaces

- You can also create a type definition within a namespace.

```cpp
namespace mytestnamespace
{
	typedef{int.short}shortint
}

new[mytestnamespace::shortint]myvar=0
```