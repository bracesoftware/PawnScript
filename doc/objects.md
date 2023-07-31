# Objects

- Objects in PawnScript are simple little tags that you can mark variables with.

> ***NOTE***: Objects have no use right now.

## Example

- Assigning a `TestObj` object to a variable.

```cpp
object,TestObj;
TestObj<-new.int,testvar=10;
```

## Example `#2`

- Objects inside namespaces.

```cpp
namespace,ObjectTest;
<;
	object,TestObj;
>;

ObjectTest::TestObj<-new.int,testvar=1;
```