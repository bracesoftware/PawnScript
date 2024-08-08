# Return reference

- Return reference in PawnScript is a certain variable a return value of a native function will be stored in. 

```cpp
#pragma:reqref,true

new[int.unsigned]ReturnReference__=9283

console.println("Heyy"); // This will give a warning.

console.println.log("Hello World again") ReturnReference__


#pragma:reqref,false

console.cout(ReturnReference__)
```

Output:

```
[PawnScript] WARNING (dpp.amx @ modules/interpreter.inc:116): Return reference is required.
Hello World again
1
```

**Note**: All NATIVE (built-in) functions return either 0 (function failed) or 1 (function executed successfully) unless it is stated otherwise in the documentation.