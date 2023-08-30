# Value returning

- A return statement causes execution to leave the current function and resume at the point in the code immediately after where the function was called. Return statements in many languages allow a function to specify a return value to be passed back to the code that called the function.

### `return`

- In PawnScript, to return a value it means to execute the code and give the result output, after returning a value, code block execution will stop.

```cpp
int MyForm() public
{
	console.println("Hello World")
	return 1
	console.println("This code won't be executed")
}

console.cout(MyForm)
system.rem("Thing above will print 1")
```


### `yield&return`

- `yield` return will do the same thing as a normal return, the difference is that the code block won't stop being executed until `};` or `return..,..;`.

```cpp
int MyForm() public
{
	console.println("Hello World")
	yield&return,1
	console.println("This code will be executed too")
}

console.cout(MyForm);
system.rem("Thing above will print 1")
```


## Return types

- Each function can have one of 5 return types - integer, boolean, string, double or a character. Return type is assigned when a function is declared, and can be changed with the `return` keyword.

Little example:

```cpp
int TestFunction() public
{
	return bool false
}
```

- Return type assigned to a function `TestFunction` is integer, but we returned a boolean. If we do not want to return any value, we just assign the `void` return type:

```cpp
void TestFunction() public
{
	system.rem("Now we can't use a return keyword in this function block.")
}