# Inline forms

- Inline forms are forms that can be declared inside a local or external form and is erased from the stack after the form call.

## Example

```cpp
int*form.InlineTestFunc;
{;
	new.int,formid=__proccessed_form_id;
	console.println("'InlineTestFunc' is {formid}");
	
	inline&form.inlineformtest; 
		do->console.println("Inline works.");
		do->console.println.log("The inline finally works!");

	user.inlineformtest;
	user.inlineformtest;
	user.inlineformtest;
	user.inlineformtest;
	yield&return,1;
};

user.InlineTestFunc;
user.InlineTestFunc;
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