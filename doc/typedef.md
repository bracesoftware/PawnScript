# `typedef`

- This keyword is used to replace an existing set of keywords with one keyword.

Example:

```cpp
typedef,const*new.int,constint;

constint,typedeftest=1234234;
console.println.log("{typedeftest}");
```

Output:

```
1234234
```

## `typedef`s inside namespaces

- You can also create a type definition within a namespace.

```cpp
namespace mytestnamespace;
{
	typedef,new.int.short,shortint;
}

mytestnamespace::shortint,myvar=0;
```