# Tags

- Tags in PawnScript are simple little attributes that you can mark variables with.

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

## `tagof` instruction

- Since tags serve as little marks you can mark your special variables with, `tagof` instruction can be used to check if specific data is marked with a specific tag.

```cpp
tag,MyNewTag;
MyNewTag<-new.int,tagtestinteger=1;
if.equ,tagof?tagtestinteger,MyNewTag->console.println.log("tagtestinteger has the MyNewTag!");
```

Output:

```
tagtestinteger has the MyNewTag!
```