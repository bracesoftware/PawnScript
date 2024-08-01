# Variables
- Unlike constants, variables can change their value at any time.

- Like constants, variables may be integers, booleans and strings.

```cpp
new[str]myvar="myvar worked."
```

To change its value, use:

```cpp
myvar="myvar worked again.";
```


## Data types

### `int`

- Integers are whole numbers.

```cpp
new[int]integer=1
```

### `bool`

- Booleans are variables that can either be true or false.

```cpp
new[bool]boolean=true
```

### `str`

- Strings are words or sequences of characters.

```cpp
new[str]string="test"
```

### `double`

- Doubles are numbers with decimal points.

```cpp
new[double]decimal_point=3.14
```

### `char`

- Single characters.

```cpp
new[char]character='b'
```

### `int.unsigned`

- Integers that can't have a negative value.

```cpp
new[int.unsigned]positivealways=-1
```

**NOTE**: If you assign a negative value, it'll be replaced with a positive value; in this case - the variable will have a value of 1 instead.


### `int.short`

- Integers that can't have a negative value or a value bigger than 65535.

```cpp
new[int.short]positivealways=-1; // Value will be set to 0.
new[int.short]theresalimit=65576; // Value will be set to 0.
```

**NOTE**: If you set a value that is smaller than 0 or bigger than 65535, value of the variable will be 0.

### `byte`
- Integers that take up to a mere byte of memory to store information (store values from -128 to 127).

```cpp
new[byte]foobyte=743; // we will see 0
console.println("{foobyte}")
foobyte=-4847; // we will see 0
console.println("{foobyte}")
foobyte=128; // we will see 0
console.println("{foobyte}")
foobyte=127; // we will see 127
console.println("{foobyte}")
```

### `ptr`

Check pointer documentation for more...

## `addressof` instruction

- This is a built-in instruction which returns an address of a symbol, most frequently a variable.

```cpp
console.cout(addressof?myvar)
```

Output:

```
1@1
```

