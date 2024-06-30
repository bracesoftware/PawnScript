# Persistent data management

- Persistent data management is a PawnScript feature which allows you to export your variables and store them in a `*.pspdmf` (PawnScript persistent data management file), and later import them again, allowing you to store your data on your hard disk instead of RAM.

## Example

```cpp

using data
new[int]myvariable=327
console.println.log("myvariable is {myvariable}")

@export
	this->typename=int
	this->from=myvariable
	this->to="pspdmftest"
data.testfunc

myvariable=0
console.println.log("myvariable is {myvariable}")

@import
	this->typename=int
	this->from="pspdmftest"
	this->to=myvariable
data.testfunc

console.println.log("myvariable is {myvariable}")

```


Output:

```
myvariable is 327
myvariable is 0
myvariable is 327
```