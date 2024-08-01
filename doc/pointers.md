# Pointers
- Pointers are variables of their own data type. Their value is esentially an address of an another variable. Pointer declaration is very similar to variable declaration, however we must assign an address, and not a regular number, boolean or something else:

```cpp
new[ptr]myPointer=addressof?SomeVar
```

Now, `myPointer` has a value of `SomeVar`'s address. If we want to change the address our pointer is pointing to, we simply do:

```cpp
myPointer=addressof?SomeOtherVar
```

Now, if we want to change the value of a variable our pointer is pointing to, address a normal value to the pointer instead:

```cpp
// This will change SomeOtherVar to 3 instead of myPointer
myPointer=3
```

## Example

```cpp
new[byte]myNewByte1=0
new[byte]myNewbyte2=0

new[ptr]myFirstPointer=addressof?myNewByte1
myFirstPointer=56

myFirstPointer=addressof?myNewbyte2
myFirstPointer=-53

console.println.log("myNewByte1 is {myNewByte1} and myNewbyte2 is {myNewbyte2}")
```

Output:
```
myNewByte1 is 56 and myNewbyte2 is -53
```