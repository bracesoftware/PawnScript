# Form methods

- Form methods are sub-functions executed after a certain function call. There are native and user methods. Native ones are built into the compiler, whereas user ones are defined by the programmer.

## User methods

```cpp
@method;
int*form.TestMethod?text;
{;
	console.println("Printed: {text@TestMethod}");
	return.int,1;
};

console.println.TestMethod("Method test #1");


namespace,MyNameSpace;
<;
	@method;
	int*form.TestMethod?text;
	{;
		console.println.log("Printed: {text@MyNameSpace::TestMethod}");
		return.int,1;
	};
>;

console.println.MyNameSpace::TestMethod("Method test #2");
```

Output:

```
Printed: Method test #1
Method test #1
Printed: Method test #2
Method test #2
```

## Native methods

- Native methods are a bit different, they are integrated into the interpreter and only work on certain native forms. Below is a list of forms and methods built into them.

### Form: `console.println`

#### Method: `log`

- Printed text will also be logged into `scriptfiles/dpp.log`.

```pawn
console.println.log("Test");
```

### Form: `console.cout`

#### Method: `log`

- Printed text will also be logged into `scriptfiles/dpp.log`.

```pawn
console.cout.log(char);
```

