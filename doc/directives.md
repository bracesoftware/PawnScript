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