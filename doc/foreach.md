# Foreach-loop and data structures

- In computer programming, a foreach loop is a loop used to access a value at a specific index of an array-like data structure, or data container. Data containers in PawnScript are hard-coded "nested objects" that can be manipulated using functions.

## Iterators
- Iterators are arrays with a specific size assigned at declaration.

### Example

```cpp
using iter
iterator<8>myIter

iter.myIter.add(657)
iter.myIter.add(345)
iter.myIter.add(2)
iter.myIter.add(24)
iter.myIter.add(1)

new[int]forvecvar2=0

try
{
	console.println("{forvecvar2}")
}
foreach forvecvar2>>myIter
```

Output:

```
657
345
2
24
1
```

## Vectors
- Vectors are just like iterators, but with dynamic sizes (there is still a limit, but it is huge) which means that they can change after the vector declaration.

### Example

```cpp
using vec
// 	An initial size can be a completely random number,
// 							because the size updates dynamically during the runtime.
vector<10>myVector

vec.myVector.add(1)
vec.myVector.add(12)
vec.myVector.add(133)
vec.myVector.add(1345)
vec.myVector.add(6543)

new[int]forvecvar=0

try
{
	console.println("{forvecvar}")
}
foreach forvecvar>>myVector
```

Output:

```
1
12
133
1345
6543
```


## LIFO stack

- You can use a stack to manipulate various types of data, basically a stack in PawnScript is pointer container; an array made of pointers. Here is an example how we can push memory addresses to our stack and then reset all of them to some random value.

```cpp
using stk
stack<8>myStack

new[ptr]myPtr=nullptr

new[int]stacktest1=243
new[int]stacktest2=072
new[int]stacktest3=87236
new[int]stacktest4=974

stk.myStack.push(addressof?stacktest1)
stk.myStack.push(addressof?stacktest2)
stk.myStack.push(addressof?stacktest3)
stk.myStack.push(addressof?stacktest4)

try
{
	myPtr=1
}
foreach myPtr>>myStack

console.println.log("{stacktest1}")
console.println.log("{stacktest2}")
console.println.log("{stacktest3}")
console.println.log("{stacktest4}")
```

Output:

```
1
1
1
1
```

## `sizeof` instruction

- `sizeof` is a keyword you may have seen in a huge variety of programming languages. In PawnScript, `sizeof` is by-default enabled instruction which returns the size of a data structure.


```cpp
console.cout(sizeof?testiter)
```

Output:

```
100
```

## Data containers in namespaces

- You can declare any of these containers above inside a namespace.

## Non-iterable data containers

### Bit arrays
- Declare bit arrays with a maximum size of 32 bits.
```cpp
using bitarr
using namespace test
{
	bitarray<8>myBitArray
}

bitarr.test::myBitArray.set_at(6,1)
new[int]getBitValue=0
bitarr.test::myBitArray.get_at(6) getBitValue
console.println.log("Bit 6 is {getBitValue}")
```