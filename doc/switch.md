# `switch` and `case`

- A case or switch statement is a type of selection control mechanism used to allow the value of a variable or expression to change the control flow of program execution via a multiway branch.

```cpp
new[int]switchtest=23

switch switchtest
case 1
{
	console.println("switchtest is 1")
}
case 23
{
	console.println("switchtest is 23")
}
case 2
{
	console.println("switchtest is 2")
}
```

Output:

```
switchtest is 23
```

### Another example
- This language literally has no limits! It even amazed me when I nested a namespace within a case code block:
```cpp
switch myNewbyte2
// You can also change the value of myNewbyte2 
// before the case statements
case 43
{
	console.println.log("myNewbyte2's 43")
}
case 38
{
	console.println.log("myNewbyte2's 38")
	namespace nestedNSpace
	{
		new[int]LOL=83
	}
	console.println.log("nestedNSpace::LOL is {nestedNSpace::LOL}")
}
case 3
{
	console.println.log("myNewbyte2's 43")
}
```