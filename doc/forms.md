# Functions
- Functions in programming are blocks of precisely defined and chronologically ordered instructions that are executed when the function is called. Functions may be native functions, user-defined functions and hook functions.

---------------------------------------------------------------------------------------------------------

## Native functions

- Native functions are those whose are defined in an interpreter component and are useable only if the component is imported. You may call native functions by specifying the component name.

```cpp
using console

console.println("Hello World")
```


---------------------------------------------------------------------------------------------------------

## User functions

- User functions are functions whose are defined by the person who wrote the code. You may declare an user functions using:

```cpp
void formname() public
{
	console.println("my first user functions")
}
```

So now you've made an user functions. Code between the curly braces is called a functions code block. It may contain a native functions call or a variable, constant or iterator declaration, and even an inline function initialization.

You also may return values.

```cpp
str funcname() public
{
	console.println("my first user functions")
	static[str]return_str="this was returned"
	return return_str
}
```

Then you can use this user function as an argument in a native function.

```cpp
str funcname() public
{
	console.println("my first user functions")
	static[str]return_str="this was returned"
	return return_str
}

console.println(funcname)
```

To call an user function, use:

```cpp
user.funcname()
```


### Using vars and constants as arguments

- You may also use variables and constants as arguments in native functions.

```cpp
const[str]CONST_NAME="constant worked"

console.println(CONST_NAME)
```

---------------------------------------------------------------------------------------------------------

## Hook functions
- You can hook already existing functions using **hook functions**.

```cpp
int functobehooked() public
{
	console.println("HOOKED")
	return 1
}

@hook
int functobehooked() public
{
	console.println("HOOKED 1")
	return int 1
}

@hook
int functobehooked() public
{
	console.println("HOOKED 2")
	return int 1
}

user.functobehooked()
```