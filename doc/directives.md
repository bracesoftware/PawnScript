# Directives

- The preprocessors are the directives, which give instructions to the compiler to preprocess the information before actual compilation starts. But, since PawnScript is an interpreted language and actually does not have a compiler, directives here are just special operations that use different syntax to differ from other features.

## `#include`

- Used to include a file:

```pawn
#include:file;
```

## `#undef`

- Used to undefine a symbol; that can be an iterator, variable, constant or whatever.

```pawn
#undef:var;
```

Example:

```pawn
new.int,undeftest=1;

if.equ,defined?undeftest,1->console.println.log("undeftest is defined");

#undef:undeftest;

if.equ,defined?undeftest,1->console.println.log("undeftest is defined *(again!*)");
```

Output:

```
undeftest is defined
```

## `#pragma`

Read more about it [here](options.md).

## `#emit`

- The most interesting one so far, it lets you to operate with the language elements such as variables on a higher level using completely different instructions and operations, also known as assembly, but my version of it. Below is a list of operations you can do:

### `addrset`

```cpp
#emit:addrset,addressof?varname;
```

- This sets an address in the memory you will operate with.

### `vlset`

- Changes a return value.

```cpp
new.int,ADDRESSOFTEST=0;
#emit:addrset,addressof?ADDRESSOFTEST;
#emit:vlset,23746;

console.cout.log(ADDRESSOFTEST);

new.bool,ADDRESSOFTEST2=false;
#emit:addrset,addressof?ADDRESSOFTEST2;
#emit:vlset,true;

console.cout.log(ADDRESSOFTEST2);

new.str,ADDRESSOFTEST3="000";
#emit:addrset,addressof?ADDRESSOFTEST3;
#emit:vlset,"#emit works!";

console.println.log(ADDRESSOFTEST3);

new.double,ADDRESSOFTEST4=0.0;
#emit:addrset,addressof?ADDRESSOFTEST4;
#emit:vlset,23.746;

console.cout.log(ADDRESSOFTEST4);

new.char,ADDRESSOFTEST5='0';
#emit:addrset,addressof?ADDRESSOFTEST5;
#emit:vlset,'K';

console.cout.log(ADDRESSOFTEST5);
```

Output:
```
23746
true
#emit works!
23.746000
'K'
```

### `dtyp`

- Used to change the return type.

```cpp
#emit:addrset,addressof?varname;
#emit:dtyp,4;
```

- `1` = `int`
- `2` = `bool`
- `3` = `str`
- `4` = `double`
- `5` = `char`


#### Example

- Create an integer variable, change its data type to `char`, set a value, and then print the value.

```cpp
new.int,ADDRESSOFTEST6=1;
#emit:addrset,addressof?ADDRESSOFTEST6;
#emit:dtyp,5;
#emit:vlset,'Z';

console.cout.log(ADDRESSOFTEST6);
```

Output:

```
'Z'
```

### `csnm`

- Change the symbol name.

```cpp
new.int,ADDRESSOFTEST7=364;
#emit:addrset,addressof?ADDRESSOFTEST7;
#emit:csnm,__ADDRESSOFTEST7;

console.cout.log(__ADDRESSOFTEST7);
```

Output:

```
364
```