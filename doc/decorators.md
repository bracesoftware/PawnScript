# Decorators

- Decoratos are some special kinds of declarations whose change the structure of a function. The list of available decorators is below.

## `@hook`

- Used to make a hook function.

```cpp
@hook;
void MyTestFunc() public;
{
}
```

## `@method`

- Used to make a function method.

```cpp
@method;
void MyTestFunc() public;
{
}

console.println.MyTestFunc(...);
```