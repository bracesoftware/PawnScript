# Foreach-loop and data structures

- In computer programming, a foreach loop is a loop used to access a integer value at a specific index of an array-like data structure. 

## Iterators
- Iterators are arrays with a specific size assigned at declaration.

### Example

```cpp
using iter; // Use iter. functions.

iterator<100>testiter; // Declare a `testiter` with size of 100 which means it can hold up to 100 integers.
new.int,foreachtestvar=0;

// We use functions from the `iter` component to manipulate with them.
iter.add(testiter,1);
iter.add(testiter,10);
iter.remove(testiter,1);

foreach.int,foreachtestvar,testiter->console.println("foreach test {foreachtestvar}");

iter.add(testiter,1);

foreach.int,foreachtestvar,testiter->console.println("foreach test #2 {foreachtestvar}");

#undef:testiter;
```

Output:

```
foreach test 10
foreach test #2 1
foreach test #2 10
```

### Example `#2`

- Iterators inside classes.

```cpp
namespace,IterClass;
{
	iterator<10>iter;
}

iter.add(IterClass::iter,364);
foreach.int,foreachtestvar,IterClass::iter->console.println("foreach test #3 {foreachtestvar}");
```

Output:

```
foreach test #3 364
```

## Vectors
- Vectors are just like iterators, but with dynamic sizes (there is still a limit, but it is huge) which means that they can change after the vector declaration.

```
??? COMING SOON ???
```

## `sizeof` instruction

- `sizeof` is a keyword you may have seen in a huge variety of programming languages. In PawnScript, `sizeof` is by-default enabled instruction which returns the size of a data structure.


```cpp
console.cout(sizeof?testiter);
```

Output:

```
100
```