# Tags

- Tags in PawnScript are simple little attributes that you can mark variables with.

> ***NOTE***: Tags have no particular use right now.

## Example

- Assigning a `MyTag` tag to a variable.

```cpp
tag,MyTag;
MyTag<-new.int,testvar=10;
```

## Example `#2`

- Tags inside namespaces.

```cpp
namespace,TagTestNameSpace;
<;
	tag,MyTag;
>;

TagTestNameSpace::MyTag<-new.int,testvar=1;
```