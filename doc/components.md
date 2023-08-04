# Interpreter components
- Functions in PawnScript are called **forms**; to use certain *native forms*, you need to import standard built-in components into your code. For example - to use `cout`, you need to have a `console` interpreter component imported. Below, you can find the full list of available components.

## Contents
- [`console`](#component-console)
- [`system`](#component-system)
- [`samp`](#component-samp)
- [`files`](#component-files)
- [`misc`](#component-misc)
- [`data`](#component-data)

---------------------------------------------------------------------------------------------------------

## Component: `console`
- Provides console-related forms.

Import the component using:
```pawn
using.console;
```

### Form: `cout`
- Character output.

```pawn
console.cout(1);
```

### Form: `println`
- Text line output.

```pawn
console.println("Hello World!");
```

---------------------------------------------------------------------------------------------------------

## Component: `system`
- Provides random, usually internal, forms.

Import the component using:
```pawn
using.system;
```

### Form: `rem`
- Comments.
```pawn
system.rem("SOME TEXT");
```

### Form: `arginit`
- Used to initialize the arguments.

```cpp
int*form.arginit_test?playerid&string;
{
	return,1;
}

system.arginit(arginit_test,1,"Hello!");
```

---------------------------------------------------------------------------------------------------------

### Automated user form: `main`

- Called when the code gets executed.

```cpp
extern&struct*public.main;
{
	console.println("Hello World from main");
	return.int,1;
}
```


---------------------------------------------------------------------------------------------------------

## Component: `samp`
- Provides a set of forms used to interact with the SAMP or open.mp server.

Import the component using:
```pawn
using.samp;
```

### Form: `SetGameModeText`

- Set the gamemode text.

```pawn
samp.SetGameModeText("d++ test");
```

### Form: `SendClientMessage`

- Send a message to a player.

```pawn
samp.SendClientMessage(playerid@OnPlayerConnect,0,"Welcome to the PawnScript server");
```

---------------------------------------------------------------------------------------------------------

### Automated user form: `OnGameModeInit`

- In SA:MP and open.mp these are also known as **callbacks**. In PawnScript they're automated user forms, and are called by the PawnScript interpreter when a certain event happens in SA:MP. So for example, when the gamemode starts loading, automated form will get called.

```cpp
system.rem("OnGameModeInit should be called by itself.");

extern&struct*public.OnGameModeInit;
{
	console.println("OnGameModeInit works");
}
```

### Automated user form: `OnGameModeExit`

- Called when the gamemode unloads.

```cpp
extern&struct*public.OnGameModeExit;
{
	console.println("OnGameModeExit works");
}
```

### Automated user form: `OnPlayerConnect`

- Called when a certain player connects to the server.

```cpp
extern&struct*public.OnPlayerConnect?playerid;
{
	samp.SendClientMessage(playerid@OnPlayerConnect,0,"Welcome to the PawnScript server");
}
```

### Automated user form: `OnPlayerDisconnect`

- Called when a certain player disconnects from the server.

```cpp

extern&struct*public.OnPlayerDisconnect?playerid&reason;
{
	console.println("Player {playerid@OnPlayerDisconnect} disconnected | Reason: {reason@OnPlayerDisconnect}");
	return.int,1;
}
```

**WARNING**: For some unknown reason, Windows can crash when the form is called with reason `1`.


---------------------------------------------------------------------------------------------------------


## Component: `files`
- Provides file-related forms.

Import the component using:
```pawn
using.files;
```

### Form: `open_for_write`
- Opens a file with an intention to write data into it. File is created if it does not exist.

```pawn
files.open_for_write("file_name.txt");
```

### Form: `open_for_read`
- Opens a file with an intention to read data from it. File is created if it does not exist.

```pawn
files.open_for_read("file_name.txt");
```

### Form: `open_for_append`
- Opens a file with an intention to append data into it. File is created if it does not exist.

```pawn
files.open_for_append("file_name.txt");
```

### Form: `read`
- Reads data from the opened file and stores it into a variable.

```pawn
new.str,dest_string="something that should change";
files.read(dest_string);
```

### Form: `write`
- Writes data into the opened file.

```pawn
files.write("wrote this into file_name.txt");
```

### Form: `close`
- Closes the opened file.

```pawn
files.close;
```

### Form: `delete`

- Deletes a certain file.

```pawn
files.delete("newfile.omg");
```

---------------------------------------------------------------------------------------------------------


## Component: `misc`
- Provides miscellaneous forms.

Import the component using:
```pawn
using.misc;
```

### Form: `swap`
- Swaps two's variable values.

```pawn
misc.swap(var1,var2);
```

**NOTE**: Now variable `var1` will have the value `var2` had, and `var2` will have the value `var1` had.


---------------------------------------------------------------------------------

## Component: `data`
- Provides forms for data management.

Import the component using:
```cpp
using.data;
```

### Form: `sscanf`
- Parses and splits a string.

```cpp
using.data;

new.str,scanftest1="ok";
new.str,scanftest2="ok";
new.str,scanftest3="ok";
new.str,scanftest4="ok";
new.int,scanftest5=2453;
new.int,scanftest6=2453;

new.str,scanftest="sscanf-is-so-cool-1-2";

data.sscanf(scanftest,scanftest1,scanftest2,scanftest3,scanftest4,scanftest5,scanftest6);

console.println.log(scanftest1);
console.println.log(scanftest2);
console.println.log(scanftest3);
console.println.log(scanftest4);
console.cout(scanftest5);
console.cout(scanftest6);
```

Output:

```
sscanf
is
so
cool
1
2
```

**WARNING**: Current `sscanf` delimiter is `-` because of some limitations we're facing, it may be changed in the future.


---------------------------------------------------------------------------------

## Component: `pawn`
- Provides forms for interaction with the Pawn language.

Import the component using:
```pawn
using.pawn;
```

### Form: `callfunction`
- Calls a public function declared in the running Pawn code.

```cpp
pawn.callfunction("public_name");
```