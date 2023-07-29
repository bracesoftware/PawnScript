# Forms
- Functions in programming are blocks of precisely defined and chronologically ordered instructions that are executed when the function is called. In PawnScript, those are renamed to forms.

- Forms may be native forms, user forms and hook forms.

---------------------------------------------------------------------------------------------------------

## Native forms

- Native forms are those whose are defined in an interpreter component and are useable only if the component is imported. You may call native forms by specifying the component name.

```cpp
using.console;

console.println("Hello World");
```

So you are using the `using` procedure on a `console` component to use the `println` form - brilliant!



---------------------------------------------------------------------------------------------------------

## User forms

- User forms are forms whose are defined by the person who wrote the code. You may declare an user form using:

```cpp
void*form.formname;
{;
	console.println("my first user form");
};
```

So now you've made an user form. Code between the curly braces is called a form code block. It may contain a native form call or a variable, constant or iterator declaration, and even an inline form initialization.

You also may return values.

```cpp
str*form.formname;
{;
	console.println("my first user form");
	return,"this was returned";
};
```

Then you can use this user form as an argument in a native form.

```cpp
str*form.formname;
{;
	console.println("my first user form");
	return,"this was returned";
};

console.println(formname);
```

To call an user form, use:

```cpp
user.formname;
```

---------------------------------------------------------------------------------------------------------

## Using vars and constants as arguments

- You may also use variables and constants as arguments in native functions.

```cpp
const*new.str,CONST_NAME="constant worked";

console.println(CONST_NAME);
```

---------------------------------------------------------------------------------------------------------

## Hook forms
- You can hook already existing forms using **hook forms**.

```cpp
int*form.functobehooked;
{;
	console.println("HOOKED");
	return,1;
};

@hook;
int*form.functobehooked;
{;
	console.println("HOOKED 1");
	return.int,1;
};

@hook;
int*form.functobehooked;
{;
	console.println("HOOKED 2");
	return.int,1;
};

user.functobehooked;
```