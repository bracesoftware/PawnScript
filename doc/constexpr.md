# `constexpr`

- This keyword a certain code block is marked with makes it uneditable after its declaration.

## Namespaces

```cpp
constexpr*namespace,TestConstNamespace;
{
	void*form.MyForm;
	{
		console.println.log("My namespace function works!");
	}
}

user.TestConstNamespace::MyForm;

using*namespace,TestConstNamespace;
{
	// Oops! Fatal error!
	// Process will be terminated at this point!
}
```

Output:

```
[Info] My namespace function works!
[Info] *** [PawnScript] FATAL ERROR - Info: Attempted to modify a constexpr code block.
[Info] [PawnScript] SERVER THREAD - Info: Process has been terminated to prevent further complication.
```