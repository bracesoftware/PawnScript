# Interpreter components
- Functions in PawnScript are called **forms**; to use certain *native forms*, you need to import standard built-in components into your code. For example - to use `cout`, you need to have a `console` interpreter component imported. Below, you can find the full list of available components.

## Contents
- [`console`](#component-console)
- [`system`](#component-system)
- [`samp`](#component-samp)
- [`files`](#component-files)
- [`misc`](#component-misc)
- [`data`](#component-data)
- [`pawn`](#component-pawn)
- [`math`](#component-math)
- [`iter`](#component-iter)
- [`vec`](#component-vec)
- [`graphics`](#component-graphics)

---------------------------------------------------------------------------------------------------------

## Component: `console`
- Provides console-related forms.

Import the component using:
```cpp
using console
```

### Form: `cout`
- Character output.

```pawn
console.cout('c')
```

### Form: `cin`
- Character input. Code execution will not be stopped, only a destination variable in which the RCON input will be stored is set.

```pawn
console.cin(destvar)
```

### Form: `println`
- Text line output.

```pawn
console.println("Hello World!")
```

### Form: `inputln`
- Text line input. Code execution will not be stopped, only a destination variable in which the RCON input will be stored is set.

```pawn
console.inputln(destvar)
```

### Form: `rawout`

- Raw text output.

```cpp
console.rawout(RandomTextIg??)
```

---------------------------------------------------------------------------------------------------------

## Component: `system`
- Provides random, usually internal, forms.

Import the component using:
```cpp
using system
```

### Form: `rem`
- Comments.
```pawn
system.rem("SOME TEXT")
```

### Form: `arginit`
- Used to initialize the arguments.

```cpp
int arginit_test(num,string) public
{
	return 1
}

system.arginit(arginit_test,1,"Hello!")
```

### Form: `ver`
- Prints out the system version information.

```cpp
system.ver()
```

Output:

```
 	PawnScript   1.0.8-R2	Brace Inc.
 	Pawn         3.10.11	ITB CompuPhase
```

### Form: `cd`
- Sets the current working directory. Example:

```cpp
// Create a directory named 'MyNewDir' in scriptfiles
files.createdir("MyNewDir")
// Set that as a working directory
system.cd("MyNewDir/")
// Create 'SubMyNewDir' inside
files.createdir("SubMyNewDir")
// Set MyNewDir/SubMyNewDir/ as working dir
system.cd("SubMyNewDir/")
// Create a file inside 'MyNewDir/SubMyNewDir/'
files.open_for_write("test.txt")
files.write("wrote this.")
files.close
system.cd(".."); // Reset back to scriptfiles
// Create a new folder in scriptfiles named 'MyNewDirAgain'
files.createdir("MyNewDirAgain")
```

**NOTE**: Always put `/` after the directory name when using `system.cd`; or `/` before a file name when using `files.open_...` - either one of those, never both or noone.

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


## Component: `files`
- Provides file-related forms.

Import the component using:
```cpp
using files
```

### Form: `open_for_write`
- Opens a file with an intention to write data into it. File is created if it does not exist.

```cpp
files.open_for_write("file_name.txt")
```

### Form: `open_for_read`
- Opens a file with an intention to read data from it. File is created if it does not exist.

```cpp
files.open_for_read("file_name.txt")
```

### Form: `open_for_append`
- Opens a file with an intention to append data into it. File is created if it does not exist.

```cpp
files.open_for_append("file_name.txt")
```

### Form: `read`
- Reads data from the opened file and stores it into a variable.

```cpp
new.str,dest_string="something that should change"
files.read(dest_string)
```

### Form: `write`
- Writes data into the opened file.

```cpp
files.write("wrote this into file_name.txt")
```

### Form: `close`
- Closes the opened file.

```cpp
files.close
```

### Form: `delete`

- Deletes a certain file.

```cpp
files.delete("newfile.omg")
```

### Form: `createdir`

- Creates a directory.

```cpp
files.createdir("mydir")
```

---------------------------------------------------------------------------------------------------------


## Component: `misc`
- Provides miscellaneous forms.

Import the component using:
```cpp
using misc
```

### Form: `swap`
- Swaps two's variable values.

```pawn
misc.swap(var1,var2)
```

**NOTE**: Now variable `var1` will have the value `var2` had, and `var2` will have the value `var1` had.


---------------------------------------------------------------------------------

## Component: `data`
- Provides forms for data management.

Import the component using:
```cpp
using data
```

### Form: `sscanf`
- Parses and splits a string.

```cpp
using data

new.str,scanftest1="ok"
new.str,scanftest2="ok"
new.str,scanftest3="ok"
new.str,scanftest4="ok"
new.int,scanftest5=2453
new.int,scanftest6=2453

new.str,scanftest="sscanf-is-so-cool-1-2"

data.sscanf(scanftest,scanftest1,scanftest2,scanftest3,scanftest4,scanftest5,scanftest6)

console.println.log(scanftest1)
console.println.log(scanftest2)
console.println.log(scanftest3)
console.println.log(scanftest4)
console.cout(scanftest5)
console.cout(scanftest6)
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

### Form: `strdist`
- Returns a distance between 2 strings.

```cpp
data.strdist("hi", "hi") myretref
console.println.log("myretref is {myretref}")
```

Output:

```
myretref is 0
```

#### Returns

Unlike most of the functions, whose return 0 for failed operation and 1 for successful operation, this one returns 65535 for failed operation and integer distance (difference) between 2 strings. In example above, `myretref` is 0 because the 2 strings are the same.

---------------------------------------------------------------------------------

## Component: `pawn`
- Provides forms for interaction with the Pawn language.

Import the component using:
```cpp
using pawn
```

### Form: `callfunction`
- Calls a public function declared in the running Pawn code.

```cpp
pawn.callfunction("public_name")
```

---------------------------------------------------------------------------------

## Component: `math`
- Mathematical operations and functions.

Import the component using:
```cpp
using math
```

### Form: `vectorsize`
- Calculates the distance between two 3-dimensional points.

```cpp
math.vectorsize(234.1,4211.3,43.3,-43.33,-0.1,-823) myretref; // Pretty random coordinates.
console.rawout.log(myretref)
```

Output:
```
4308.519042
```

#### Returns
This function is also one of those which have a specific return value, 0.0 is returned if the operation has failed or if the distance is REALLY just zero, and a specific `double` number will be returned if the operation is executed successfully.

---------------------------------------------------------------------------------------------------------

## Component: `iter`
- Iterator-related functions.

For further information, check the data structure and `foreach` documentation.

---------------------------------------------------------------------------------------------------------

## Component: `vec`
- Vector-related functions.

For further information, check the data structure and `foreach` documentation.

---------------------------------------------------------------------------------------------------------

## Component: `graphics`
- Graphics-related functions.

Import the component using:
```cpp
using graphics
```

### Form: `cls`
- Clean up the graphics grid.

```cpp
graphics.cls
```

### Form: `show`
- Show the graphics grid in your console.

```cpp
graphics.show
```

### Form: `showpixel`
- "Activate" a specific pixel on the graphics grid.

```cpp
graphics.showpixel(row, column)
```

Example:
```cpp
graphics.showpixel(9,50)
```

Output:
```
[Info] 	PawnScript: Graphics Mode			Version: [Gs2]
[Info] 	[Rows: 20		Columns: 100]
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info]                                                                                                    
[Info] 	Powered by: Pawn				Release: 3.10.11
```