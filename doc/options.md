# Interpreter options
You can modify some interpreter options using `#pragma`. You may use `default` instead of `true` and `false` in order to reset the value to its default one.

## `debug`
- Default value: `false`

You can toggle PawnScript debugging on or off.

```cpp
#pragma:debug,false;
#pragma:debug,true;
```

## `warnings`
- Default value: `true`

You can toggle PawnScript warning system on or off.

```cpp
#pragma:warnings,false;
#pragma:warnings,true;
```

## `hooking`
- Default value: `true`

You can toggle PawnScript hooking system on or off.

```cpp
#pragma:hooking,false;
#pragma:hooking,true;
```

## `ctrlchar`
- Default value: `\`

Change the parsing escape character.

```cpp
#pragma:ctrlchar,*;
```

## `allspc`
- Default value: `false`

By default, you aren't supposed to put spaces and extra characters in argument values, so your PawnScript code should look this in order to work properly:

```pawn
system.rem,"Example code";
if.equ,1,1->while.equ,testvar,11->var::set.int,testvar,add?testvar:1&using::console.println,"This should be printed again!";
```

Enabling `allspc` option with:

```cpp
#pragma:allspc,true;
```

Enables crazy syntax like this:

```pawn
system . rem,    "Example code"   ;
if. equ, 1 , 1-> while.equ, testvar, 11 -> var::set . int , testvar,add?testvar:1 & using :: console. println("This should   be printed again!"   ) ;
```

Which can be really buggy and can bring negative side-effects with it, such as for example wrong value reading. But the most important thing to note is that your code will slow down a lot. There are also high chances of such code getting somewhy ignored by the interpreter.