# Directives

- The preprocessors are the directives, which give instructions to the compiler to preprocess the information before actual compilation starts. But, since PawnScript is an interpreted language and actually does not have a compiler, directives here are just special operations that use different syntax to differ from other features.

## `#include`

- Used to include a file:

```cpp
#include:file
```

## `#undef`

- Used to undefine a symbol that can be an iterator, variable, constant or whatever.

```cpp
#undef:var
```

Example:

```cpp
new.int,undeftest=1

if.equ,defined?undeftest,1->console.println.log("undeftest is defined")

#undef:undeftest

if.equ,defined?undeftest,1->console.println.log("undeftest is defined *(again!*)")
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
#emit:addrset,addressof?varname
```

- This sets an address in the memory you will operate with.

### `vlset`

- Changes a return value.

```cpp
new.int,ADDRESSOFTEST=0
#emit:addrset,addressof?ADDRESSOFTEST
#emit:vlset,23746

console.cout.log(ADDRESSOFTEST)

new.bool,ADDRESSOFTEST2=false
#emit:addrset,addressof?ADDRESSOFTEST2
#emit:vlset,true

console.cout.log(ADDRESSOFTEST2)

new.str,ADDRESSOFTEST3="000"
#emit:addrset,addressof?ADDRESSOFTEST3
#emit:vlset,"#emit works!"

console.println.log(ADDRESSOFTEST3)

new.double,ADDRESSOFTEST4=0.0
#emit:addrset,addressof?ADDRESSOFTEST4
#emit:vlset,23.746

console.cout.log(ADDRESSOFTEST4)

new.char,ADDRESSOFTEST5='0'
#emit:addrset,addressof?ADDRESSOFTEST5
#emit:vlset,'K'

console.cout.log(ADDRESSOFTEST5)
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
#emit:addrset,addressof?varname
#emit:dtyp,4
```

- `1` = `int`
- `2` = `bool`
- `3` = `str`
- `4` = `double`
- `5` = `char`


#### Example

- Create an integer variable, change its data type to `char`, set a value, and then print the value.

```cpp
new.int,ADDRESSOFTEST6=1
#emit:addrset,addressof?ADDRESSOFTEST6
#emit:dtyp,5
#emit:vlset,'Z'

console.cout.log(ADDRESSOFTEST6)
```

Output:

```
'Z'
```

### `csnm`

- Change the symbol name.

```cpp
new.int,ADDRESSOFTEST7=364
#emit:addrset,addressof?ADDRESSOFTEST7
#emit:csnm,__ADDRESSOFTEST7

console.cout.log(__ADDRESSOFTEST7)
```

Output:

```
364
```

### `load.pri`

- Set the value of the primary register to the value stored inside the loaded address.

```cpp
new.int,var=1
#emit:addrset,addressof?var
#emit:load.pri
```

`PRI` is now 1.

### `load.alt`

- Set the value of the alternate register to the value stored inside the loaded address.

```cpp
new.int,var=1
#emit:addrset,addressof?var
#emit:load.alt
```

`ALT` is now 1.

### `const.pri`

- Set the value of the primary register to a constant value not loaded with `addrset`.

```cpp
#emit:const.pri,1
```

`PRI` is now 1.


### `const.alt`

- Set the value of the alternate register to a constant value not loaded with `addrset`.

```cpp
#emit:const.alt,1
```

`ALT` is now 1.


### `stor.pri`

- Set the value of the primary register to a constant value not loaded with `addrset`.

```cpp
new.int,var=1
#emit:addrset,addressof?var
#emit:const.pri,6
#emit:stor.pri
```

`var` is now 6.



### `stor.alt`

- Store the value of the alternate register into a loaded address.

```cpp
new.int,var=1
#emit:addrset,addressof?var
#emit:const.alt,6
#emit:stor.alt
```

`var` is now 6.

### `add`, `sub`, `mul`, `div`

- **Add**ittion, **sub**tractin, **mul**tiplication and **div**ision.

```cpp
#emit:add; //pri = pri+alt
#emit:sub; //pri = pri-alt<0?pri-alt*(-1):pri-alt
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
#emit:zero.pri //pri=0
```


### `zero.alt`

- Changes the value of the alternate register to 0.

```cpp
#emit:zero.alt //alt=0
```

### `lctrl`

- Set the value of the primary register to the current value of the register specified. There are a few registers available and they're listed below.

| ID  | Name  | Purpose |
|-----|-------|-----------------------------------------------------|
| `1` | `cur` | This is the register holding a cell ID in the memory. |
| `2` | `sec` | This is the register holding a cell entity type or memory sector. |
| `3` | `tmp` | This is the register holding some random rubbish. |
| `4` | `nxt` | This is the register holding a next free cell ID within a memory sector. |

```cpp
#emit:lctrl,1; //pri=cur
```

### `sctrl`

- Set the value of the specified register to the current value of the primary register. The registers use same IDs mentioned above.

```cpp
#emit:sctrl,1; //cur=pri
```

**WARNING**: Never change the value of the `CUR` and `SEC` register after using `addrset`, because those 2 update the address you are operating on and you may change something you didn't want to, whereas `TMP` can be used as a third general-use register.

### `push` and `pop`

#### `push`

- Push the current address contained within the `CUR` and `SEC` to the stack (create a symbol).

#### `pop`

- Pop the current address contained within the `CUR` and `SEC` from the stack (delete a symbol).

```cpp
#emit:const.pri,1 
// Set the value of PRI to 1 (which is var memory sector id)
#emit:sctrl,2 
// Set the sector to 1
#emit:lctrl,4 
// Get the next free cell id
#emit:sctrl,1 
// Set that cell id.
#emit:push 
// Push that address to the stack (kind of manual 'addrset').
#emit:csnm,temporaryvar 
// Name it that because it's name is not in the stack, so we will pop it later.
#emit:dtyp,1 
// Make it an integer.
#emit:vlset,300 
// Give it a value of 300.
std::writeln("temporaryvar is {temporaryvar}") 
// Print the value
#emit:pop 
// Invalidate the current address (free up the cell id we occupied).
// Optional: Reset the registers.
#emit:zero.pri
#emit:zero.alt
std::writeln("temporaryvar is {temporaryvar}") 
// We will see "temporaryvar is null"
```

NOTE:	We have to use the `pop` at the end to free up the cell we occupied, and to avoid some memory collisions because the name we set using `csnm` is not pushed to the variable name stack which controls all the symbol names registered in the memory. Without having the name in the name stack, we could just do `new.int,temporaryvar=0` even before the `pop` and not receive any errors - but then we would not know which value would we be using, the one set with `vlset` or `new.int,...`? It all depends on the stack order!

### `inc.alt`

- Increase the value stored inside the alternate register by 1.

```cpp
#emit:inc.alt 
//alt++
```

### `inc.pri`

- Increase the value stored inside the primary register by 1.

```cpp
#emit:inc.pri 
//pri++
```

### `dec.alt`

- Decrease the value stored inside the alternate register by 1.

```cpp
#emit:dec.alt 
//alt--
```

### `dec.pri`

- Decrease the value stored inside the primary register by 1.

```cpp
#emit:dec.pri 
//pri--
```