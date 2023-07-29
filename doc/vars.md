# Variables
- Unlike constants, variables can change their value at any time.

- Like constants, variables may be integers, booleans and strings.

```cpp
new.str,myvar="myvar worked.";
```

To change its value, use:

```cpp
set.str,myvar="myvar worked again.";
```


## Data types

### `int`

- Integers are whole numbers.

```cpp
new.int,integer=1;
```

### `bool`

- Booleans are variables that can either be true or false.

```cpp
new.bool,boolean=true;
```

### `str`

- Strings are words or sequences of characters.

```cpp
new.str,string="test";
```

### `double`

- Doubles are numbers with decimal points.

```cpp
new.double,decimal_point=3.14;
```

### `char`

- Single characters.

```cpp
new.char,character='b';
```

### `unsigned int`

- Integers that can't have a negative value.

```cpp
new.int.unsigned,positivealways=-1;
```

**NOTE**: If you assign a negative value, it'll be replaced with a positive value; in this case - the variable will have a value of 1 instead.