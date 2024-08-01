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

## Example `#2`

- You can also create pointers within namespaces.

```cpp
using namespace test
{
	new[ptr]myPtr=addressof?myNewByte1
}

test::myPtr=-9
test::myPtr=addressof?myNewbyte2
test::myPtr=457
console.println.log("myNewByte1 is {myNewByte1} and myNewbyte2 is {myNewbyte2}")
```

- **WARNING**: It is really important to mention that you CANNOT include a pointer within a class.

## Example `#3`
- This example is literally the point of pointers themselves - modify variables passed by reference.

```cpp
void ChangeVarTo38(address) private
{
	test::myPtr=address@ChangeVarTo38
	test::myPtr=38
}
user.ChangeVarTo38(addressof?myNewbyte2)
console.println.log("myNewbyte2 is now {myNewbyte2}")
```

Output:
```
myNewbyte2 is now 38
```