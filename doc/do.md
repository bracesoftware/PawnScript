# `do` statement

- The `do` statement is a code block that can be combined with `if` and `else` statements. It lets you execute more than 1 line of code, or a code block. Just using `do` and opening curly braces will have the same result as without it.

## Example `#1`

```cpp

if.equ,1,1->do;
{
	if.notequ,1,2->do;
	{
		if.equ,1+1,3->console.println.log("Oh my God!");
	}
}
else->if.equ,1,1->do;
{
	console.println.log("No way this worked!");
	if.equ,1,1->do;
	{
		console.println.log("This has also worked...");
		if.equ,3,7->do;
		{
			console.println("NOO");
		}
		else->if.equ,1,1->do;
		{
			console.println.log("Oh yeah!");
		}
		else->do;
		{
			console.println.log("So yeah!");
		}
	}
}
else->if.equ,3,4->console.println.log("How does this even work?");
else->do;
{
	console.println.log("You should always return a value!");
}

```

Output:

```
No way this worked!
This has also worked...
Oh yeah!
So yeah!
You should always return a value!
```

## Example `#2`

```cpp
do;
{
	console.cout(1+1);
}
```

Output:

```
2
```