# Persistent data management

- Persistent data management is a PawnScript feature which allows you to export your variables and store them in a `*.pspdmf` (PawnScript persistent data management file), and later import them again, allowing you to store your data on your hard disk instead of RAM.

## Example

```cpp
#restemp
using data
myretref=327
console.println.log("myretref is {myretref}")

@export
	this->typename=int
	this->from=myretref
	this->to=pspdmftest
data.persistent

myretref=0
console.println.log("myretref is {myretref}")

@import
	this->typename=int
	this->from=pspdmftest
	this->to=myretref
data.persistent

console.println.log("myretref is {myretref}")
```


Output:

```
myvariable is 327
myvariable is 0
myvariable is 327
```