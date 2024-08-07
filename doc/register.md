# Register variables
- Using the `register` keyword instead of `new`, you can create registers with same datatypes as of variables, but there is a slight difference - you cannot point at them!

```cpp
register[int]myRegister=364

new[ptr]pointToReg=addressof?myRegister

pointToReg=73

console.println.log("myRegister remains {myRegister}")
```

- The `addressof` instruction will return a value, but that value will not be a valid address that can be accessed; and you will eventually get a runtime error that something is wrong.