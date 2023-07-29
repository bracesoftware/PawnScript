# Miscellaneous

## `exit`

Use this to terminate the interpreter, after it was terminated, you'll need to restart the interpreter to run the code again.

```pawn
exit;
```

## String formatting
- You can format any string argument in any form.

```cpp
new.str,test="Test string";

console.println("{test}");
```

Output:
```
Test string
```

```cpp
void*form.testfunction?message;
{;
	console.println(message@testfunction);
};

user.testfunction("{test}");
```

Output:
```
Test string
```

## `defined` instruction

```cpp
new.int,variable=1;

if.equ,defined?variable,1->console.println("'variable' is defined!");
if.equ,defined?dummyvar,1->console.println("This should not be printed!!");
```

Output:

```
'variable' is defined!
```