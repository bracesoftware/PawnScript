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

## `@task`

- Used to make a timer.

```cpp
@task;
void mytask() public;
{
	console.println("Task works!");
}
```

# `this` keyword

- This keyword is used for modifying decorator argument values, without a specific order.

```cpp
@task;
	this->interval=1000;
void mytask() public;
{
	console.println("Task works!");
}
```

Note that this is NOT possible:


```cpp
this->interval=1000; // `this` is modifying the arguments of last used decorator
@task;
void mytask() public;
{
	console.println("Task works!");
}
```