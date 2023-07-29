# Operators

- An operator, in computer programing, is a symbol that usually represents an action or process. These symbols were adapted from mathematics and logic. An operator is capable of manipulating a certain value or operand.

### Operator: `+`
- Addition.
```pawn
console.cout(1+1);
```

Output:

```
2
```

### Operator: `-`
- Subtraction.
```pawn
console.cout(1-1);
```

Output:

```
0
```

### Operator: `*`
- Multiplication.
```pawn
console.cout(1*1);
```

Output:

```
1
```

### Operator: `/`
- Division.
```pawn
console.cout(4/2);
```

Output:

```
2
```

### Operator: `^`
- Exponentiation.
```pawn
console.cout(3^2);
```

Output:

```
9
```

### Operator: `%`
- Division remainder.
```pawn
console.cout(10%3);
```

Output:

```
1
```


---------------------------------------------------------------------------------------------------------

Little example:

```cpp
if.equ,5/5,1+0->console.println,"Math test passed!";
```

You may also use constants, variables and user forms as an Operator arguments:

```cpp
new.int,MATHVAR=1+1;
console.cout(MATHVAR);

new.int,MATHVAR22=6+MATHVAR;
console.cout(MATHVAR22);
```

Output:

```
2
8
```