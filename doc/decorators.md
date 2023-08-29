# Decorators

- Decoratos are some special kinds of declarations whose change the structure of a function. The list of available decorators is below.

## `@hook`

- Used to make a hook function.

```cpp
@hook
void MyTestFunc() public
{
}
```

## `@method`

- Used to make a function method.

```cpp
@method
void MyTestFunc() public
{
}

console.println.MyTestFunc(...)
```

## `@task`

- Used to make a timer.

```cpp
@task
void mytask() public
{
	console.println("Task works!")
}
```

# `this` keyword

- This keyword is used for modifying decorator parameter values, without a specific order.

```cpp
@task
	this->interval=1000
void mytask() public
{
	console.println("Task works!")
}
```

Note that this is NOT possible:


```cpp
this->interval=1000; // `this` is modifying the arguments of last used decorator
@task
void mytask() public
{
	console.println("Task works!")
}
```

## `@task` parameters

### `interval` (integer)

- How much does it take till the timer is (re)called.

```cpp
@task
	this->interval=1000
void mytask() public
{
	console.println("Task works!")
}
```

**NOTE**: This parameter's default value is 0, so it is obligatory to set it before creating the task unless you want to rape your logs.

### `repeat` (boolean)

- Will the timer recall after being called once?

```cpp
@task
	this->interval=1000
	this->repeat=false
void mytask() public
{
	console.println("Task works!")
}
```

**NOTE**: Now the timer will be called only once 1 second after `main` external-structured function gets called. Default value of this parameter is `true` so you don't need to set it unless you want to create a non-repeating timer.