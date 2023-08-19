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

### `load.pri`

- Set the value of the primary register to the value stored inside the loaded address.

```cpp
new.int,var=1;
#emit:addrset,addressof?var;
#emit:load.pri;
```

`PRI` is now 1.

### `load.alt`

- Set the value of the alternate register to the value stored inside the loaded address.

```cpp
new.int,var=1;
#emit:addrset,addressof?var;
#emit:load.alt;
```

`ALT` is now 1.

### `const.pri`

- Set the value of the primary register to a constant value not loaded with `addrset`.

```cpp
#emit:const.pri,1;
```

`PRI` is now 1.


### `const.alt`

- Set the value of the alternate register to a constant value not loaded with `addrset`.

```cpp
#emit:const.alt,1;
```

`ALT` is now 1.


### `stor.pri`

- Set the value of the primary register to a constant value not loaded with `addrset`.

```cpp
new.int,var=1;
#emit:addrset,addressof?var;
#emit:const.pri,6;
#emit:stor.pri;
```

`var` is now 6.



### `stor.alt`

- Store the value of the alternate register into a loaded address.

```cpp
new.int,var=1;
#emit:addrset,addressof?var;
#emit:const.alt,6;
#emit:stor.alt;
```

`var` is now 6.

### `add`, `sub`, `mul`, `div`

- **Add**ittion, **sub**tractin, **mul**tiplication and **div**ision.

```cpp
#emit:add; //pri = pri+alt
#emit:sub; //pri = pri-alt<0?pri-alt*(-1):pri-alt;
#emit:mul; //pri = pri*alt
#emit:div; //pri = alt==0?0:pri/alt
```

### `xchg`

- Exchange the values of the primary and alternate register.

```cpp
#emit:const.pri,0; //pri=0
#emit:const.alt,1; //alt=1
#emit:xchg; //pri=1, alt=0
```

### `zero.pri`

- Changes the value of the primary register to 0.

```cpp
#emit:zero.pri; //pri=0
```


### `zero.alt`

- Changes the value of the alternate register to 0.

```cpp
#emit:zero.alt; //alt=0
```