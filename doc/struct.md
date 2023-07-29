# Form structure types

- In PawnScript, there are 2 form structure types, and those are local and external forms.

## Local forms

- Those are basic chunks or blocks of code that are called by the PawnScript user internally.

Example:

```cpp
void*form.Announce;
{;
	console.println("Script is loading");
};
```

## External forms

- External forms are forms that are called when a certain event happens in third-party API or outside local PawnScript scope (not called by the user); for example, SA-MP commands are external structures or forms that are called when a player uses a command. In short, externally structured forms are and are not forms at the same time. Because external form types are so special, they're only available after including a certain third-party API system or an interpreter component.

-----------------------------------------------------------------

### External structs integrated into the language

#### External struct name: `public`

```cpp
extern&struct*public.main;
{;
	console.println.log("Program begins here!");
};
```

### Component: `samp`

#### External struct name: `samp_command`

Example:

```cpp
extern&struct*samp_command.testcmd?playerid&params;
{;
	samp.SendClientMessage(playerid@testcmd,0,"Your command works!");
	return.int,1;
};
```