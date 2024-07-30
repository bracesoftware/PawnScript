# Private functions
- Private functions in PawnScript are functions that cannot be accessed outside the PawnScript scope, in other words, these functions can't be called using the SDK.

Example:
```cpp
void myPrivateFunc() private
{
	//foo
}
```
Doing this in your Pawn script will not work:
```pawn
#include <open.mp>
#include <a_pawnscript>

main()
{
	CallPawnScriptFunction("myPrivateFunc","");
}
```