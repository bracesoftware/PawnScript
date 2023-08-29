# Errors

- Errors often happen when you do something bad in your code. In PawnScript, there are 3 error levels. There are warnings, errors and fatal errors.

- Warnings and errors are just random messages implying that something didn't go as planned, they're not consistent regarding their output, whereas fatal errors are errors that are stopping the code from executing anymore and they ARE consistent with their output which is saying exactly what's wrong with your code. Below is a list of fatal errors you may encounter.

## `Attempted to modify a constexpr code block.`

- You attempted to modify a code block (code between 2 curly braces), but it is marked with the `constexpr` keyword.

```cpp
constexpr namespace test
{
	// Random code.
	template<console.println>cout
}

using namespace test; {
	// THIS IS AN ERROR!
}
```

## `System encountered an invalid declaration.`

- Every symbol (function, variable, constant, iterator, vector, etc.) must have its unique name within its memory sector, but it needs to be a valid alphabetic name, which means that this is not valid and will result in an error:

```cpp
new.int,$/87656RANDOM NAME LMAO=0
```

## `Invalid assembler instruction.`

- This is related to `#emit`, if you for example try to use a different instruction which is not mentioned in the documentation, then you will encounter this error.

```cpp
#emit:lmao_clown,XD
```

## `Invalid memory access.`

- This happens when you try to access an invalid address inside PawnScript memory. Often happens with `#emit`.

```cpp
#emit:addrset,LMAO_MY_ADDRESS@WashingTonDC
```

**TIP**: Avoid this by using the `addressof` keyword.

## `Redefinition of a symbol: 'SYMBOL_NAME'`

- Every single symbol within your code has to have an unique name which will be pushed to the symbol stack (STK). If you already have a certain symbol name pushed, and you try to push it again, you will encounter this error.


```cpp
new.int,hey=43
new.int,hey=9; // Error.
```

## `Invalid expression assumed zero.`

- You probably made a typo in your code or you wrote something non-sense.

```cpp
@hook=j
constexpr=namespace UUUUU+class+enum
inT func() publex{
	retern,0
}
```