# Function methods

- Function methods are sub-functions executed after a certain function call. There are native and user methods. Native ones are built into the compiler, whereas user ones are defined by the programmer.

## User methods

```cpp
@method
int TestMethod() public
{
	console.println("Printed: {text@TestMethod}")
	return int 1
}

console.println.TestMethod("Method test #1")


namespace MyNameSpace
{
	@method
	int TestMethod(text) public
	{
		console.println.log("Printed: {text@MyNameSpace::TestMethod}")
		return int 1
	}
}

console.println.MyNameSpace::TestMethod("Method test #2")
```

Output:

```
Printed: Method test #1
Method test #1
Printed: Method test #2
Method test #2
```

## Native methods

- Native methods are a bit different, they are integrated into the interpreter and only work on certain native functions. Below is a list of functions and methods built into them.

### Function: `console.println`

#### Method: `log`

- Printed text will also be logged into `scriptfiles`.

```pawn
console.println.log("Test");
```

### Function: `console.cout`

#### Method: `log`

- Printed text will also be logged into `scriptfiles`.

```pawn
console.cout.log(char);
```

### Function: `pawn.callfunction`

#### Method: `local`

- Equivalent to `CallLocalFunction` (it can only call functions declared inside `pawnscript.amx`).

```pawn
pawn.callfunction.local("funcname");
```

#### Method: `remote`

- Equivalent to `CallRemoteFunction`.

```pawn
pawn.callfunction.remote("funcname");
```

### Function: `system.rem`

#### Method: `log`

- A comment text will also be logged into `scriptfiles`.

```pawn
system.rem.log("Test");
```

### Function: `data.persistent`

#### Method: `export`

```pawn
data.persistent.export
```

#### Method: `import`

```pawn
data.persistent.import
```