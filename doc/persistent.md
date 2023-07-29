# Persistent data management

- Persistent data management is a PawnScript feature which allows you to export your variables and store them in a `*.pspdmf` (PawnScript persistent data management file), and later import them again, allowing you to store your data on your hard disk instead of RAM.

## Example

```cpp

new.int.unsigned,pdmtest=364;
export*int,"test1",pdmtest;
set.int,pdmtest=0;
import*int,"test1",pdmtest;
console.println.log("Imported {pdmtest}");

new.bool,pdmtest2=true;
export*bool,"test2",pdmtest2;
set.bool,pdmtest2=false;
import*bool,"test2",pdmtest2;
console.println.log("Imported {pdmtest2}");

new.str,pdmtest3="Hello World";
export*str,"test3",pdmtest3;
set.str,pdmtest3="stfu";
import*str,"test3",pdmtest3;
console.println.log("Imported {pdmtest3}");

new.double,pdmtest4=0.364;
export*double,"test4",pdmtest4;
set.double,pdmtest4=0.0;
import*double,"test4",pdmtest4;
console.println.log("Imported {pdmtest4}");

new.char,pdmtest5='D';
export*char,"test5",pdmtest5;
set.char,pdmtest5='0';
import*char,"test5",pdmtest5;
console.println.log("Imported {pdmtest5}");

```

Output:

```
364
true
Hello World
0.363990
'D'
```