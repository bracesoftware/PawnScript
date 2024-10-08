# Operators

- An operator, in computer programing, is a symbol that usually represents an action or process. These symbols were adapted from mathematics and logic. An operator is capable of manipulating a certain value or operand.

### Operator: `+`
- Addition.
```pawn
console.cout(1+1)
```

Output:

```
2
```

### Operator: `-`
- Subtraction.
```pawn
console.cout(1-1)
```

Output:

```
0
```

### Operator: `*`
- Multiplication.
```pawn
console.cout(1*1)
```

Output:

```
1
```

### Operator: `/`
- Division.
```pawn
console.cout(4/2)
```

Output:

```
2
```

### Operator: `^`
- Exponentiation.
```pawn
console.cout(3^2)
```

Output:

```
9
```

### Operator: `%`
- Division remainder.
```pawn
console.cout(10%3)
```

Output:

```
1
```

### Operator: `::`
- Namespace access operator.
```cpp
namespace MyNameSpace
{
	void MyFunc() public
	{
		console.println.log("I'm here!")
	}
}

user.MyNameSpace::MyFunc
```

### Operator: `.`
- Object access operator.

```cpp
console.println.log("Hi!")
```

### Operator: `@`
- Memory access operator.

```cpp
void MyFunc(argument) public
{
	console.cout.log(argument@MyFunc)
}
```

### Operator: `->`

- Conditional operator.

```cpp
if.equ,1,1->console.println.log("1 and 1 are equal")
```

### Operator: `<-`

- Attribute assignment operator.

```cpp
MyTag<-new[int]myvar=1
```

### Operator: `=`

- Data assignment operator.

```cpp
new[int]myvar=1
```

### Operator: `=>`
- Memory copy operator used to create entities or objects from virtual blueprints.

```cpp
int myBluePrint() virtual
{
	//foo
	return int 4
}

//class
class MyFuncs
{
	private myFunc=>myBluePrint
}

MyFuncs<explicit>MyObj
// This will do foo and return 4:
MyObj.myFunc()
```

### Operator: `|`

- Bitwise OR.

```cpp
console.cout.log(1|0)
```

Output:
```
1
```

### Operator: `&`

- Bitwise AND.

```cpp
console.cout.log(1&0)
```

Output:

```
0
```

### Operator: `==`

- Is equal to.

```cpp
new[int]testvar=1==1
console.println.log("1==1: {testvar}")
```
### Operator: `!=`

- Not equal to.

```cpp
testvar=1!=1
console.println.log("1!=1: {testvar}")
```
### Operator: `>=`

- Greater equal to.

```cpp
testvar=1>=1
console.println.log("1>=1: {testvar}")
```
### Operator: `<=`

- Less or equal to.

```cpp
testvar=1<=2
console.println.log("1<=2: {testvar}")
```
### Operator: `<`

- Less than.

```cpp
testvar=1<2
console.println.log("1<2: {testvar}")
```
### Operator: `>`

- Greater than.

```cpp
testvar=1>2
console.println.log("1>2: {testvar}")
```
---------------------------------------------------------------------------------------------------------

## More info

Little example:

```cpp
if.equ,5/5,1+0->console.println,"Math test passed!"
```

You may also use constants, variables and user functions as an operator arguments:

```cpp
new.int,MATHVAR=1+1
console.cout(MATHVAR)

new.int,MATHVAR22=6+MATHVAR
console.cout(MATHVAR22)
```

Output:

```
2
8
```