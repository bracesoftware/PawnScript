# Foreach-loop and data structures

- In computer programming, a foreach loop is a loop used to access a integer value at a specific index of an array-like data structure. 

## Iterators
- Iterators are arrays with a specific size assigned at declaration.

### Example

```cpp
using iter // Use iter. functions.

iterator<100>testiter // Declare a `testiter` with size of 100 which means it can hold up to 100 integers.
new.int,foreachtestvar=0

// We use functions from the `iter` component to manipulate with them.
iter.add(testiter,1)
iter.add(testiter,10)
iter.remove(testiter,1)

foreach.int,foreachtestvar,testiter->console.println("foreach test {foreachtestvar}")

iter.add(testiter,1)

foreach.int,foreachtestvar,testiter->console.println("foreach test #2 {foreachtestvar}")

#undef:testiter
```

Output:

```
foreach test 10
foreach test #2 1
foreach test #2 10
```

### Example `#2`

- Iterators inside namespaces.

```cpp
namespace IterClass
{
	iterator<10>iter
}

iter.add(IterClass::iter,364)
foreach.int,foreachtestvar,IterClass::iter->console.println("foreach test #3 {foreachtestvar}")
```

Output:

```
foreach test #3 364
```

## Vectors
- Vectors are just like iterators, but with dynamic sizes (there is still a limit, but it is huge) which means that they can change after the vector declaration.

### Example

```cpp

vector<324>vectorname // 	An initial size can be a completely random number,
// 							because the size updates dynamically during the runtime.

// `using vec` is already in stdlib.ps
using vec

vec.add(vectorname,1)
vec.add(vectorname,312)
vec.add(vectorname,2)
new.int,vectortest=0

console.rawout(sizeof?vectorname) // Size is changed from 324 to 3.
foreach.int,vectortest,vectorname->std::writeln("vector test #1 {vectortest}")

vec.remove(vectorname,312)

console.rawout(sizeof?vectorname) // Size is changed from 3 to 2.
foreach.int,vectortest,vectorname->std::writeln("vector test #2 {vectortest}")

```

Output:

```
3
vector test #1 1
vector test #1 312
vector test #1 2
2
vector test #2 1
vector test #2 2
```


### Example `#2`

- Vectors inside namespaces.

```cpp
namespace vectors
{
	vector<324>myvec
	new.int,vectortest2=0
}

vec.add(vectors::myvec,24)
vec.add(vectors::myvec,31)
vec.add(vectors::myvec,29)

console.rawout(sizeof?vectors::myvec)
 // Size is changed from 324 to 3.
foreach.int,vectors::vectortest2,vectors::myvec->std::writeln("vector test #3 {vectors::vectortest2}")

vec.remove(vectors::myvec,24)

console.rawout(sizeof?vectors::myvec)
 // Size is changed from 3 to 2.
foreach.int,vectors::vectortest2,vectors::myvec->std::writeln("vector test #4 {vectors::vectortest2}")
```

Output:

```
3
vector test #3 24
vector test #3 31
vector test #3 29
2
vector test #4 31
vector test #4 29
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