# Tags

- Tags in PawnScript are simple little attributes that you can mark variables with.

> ***NOTE***: Tags have no particular use right now.

## Example

- Assigning a `TestObj` tag to a variable.

```cpp
tag,TestObj;
TestObj<-new.int,testvar=10;
```

## Example `#2`

- Tags inside namespaces.

```cpp
namespace,ObjectTest;
<;
	tag,TestObj;
>;

ObjectTest::TestObj<-new.int,testvar=1;
```