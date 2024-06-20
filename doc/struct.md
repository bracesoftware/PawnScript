# Function structure types

- In PawnScript, there are 2 function structure types, and those are local and external functions.

## Local functions

- Those are basic chunks or blocks of code that are called by the PawnScript user internally.

Example:

```cpp
void Announce() public
{
	console.println("Script is loading")
}
```

## External functions

- External functions are functions that are called when a certain event happens in third-party API or outside local PawnScript scope (not called by the user); for example, SA-MP commands are external structures or functions that are called when a player uses a command. In short, externally structured functions are and are not functions at the same time. Because external function types are so special, they're only available after including a certain third-party API system or an interpreter component.

-----------------------------------------------------------------

### External structs integrated into the language

#### External struct name: `default`

```cpp
@extern
	this->struct=default
void main() public
{
	console.println.log("Program begins here!")
}
```

### Component: `samp` - COMING SOON!

#### External struct name: `samp_command`

Example:

```cpp
@extern
	this->struct=samp_command
int testcmd(playerid,params) public
{
	samp.SendClientMessage(playerid@testcmd,0,"Your command works!");
	return.int,1;
}
```