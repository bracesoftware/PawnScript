# Inline functions

- Inline functions are functions that can be declared inside a local or external function and is erased from the stack after the function call.

## Example

```cpp
int InlineTestFunc() public
{
	new[int]formid=__proccessed_form_id
	console.println("'InlineTestFunc' is {formid}")
	
	void inlineformtest() inline
	<
		console.println("Inline works.")
		console.println.log("The inline finally works!")
	>
	
	user.inlineformtest
	user.inlineformtest
	user.inlineformtest
	user.inlineformtest
	@yield
	return 1
}

user.InlineTestFunc
user.InlineTestFunc
```

Output:

```
'InlineTestFunc' is 20
Inline works.
The inline finally works.
Inline works.
The inline finally works.
Inline works.
The inline finally works.
Inline works.
The inline finally works.
'InlineTestFunc' is 20
Inline works.
The inline finally works.
Inline works.
The inline finally works.
Inline works.
The inline finally works.
Inline works.
The inline finally works.
```