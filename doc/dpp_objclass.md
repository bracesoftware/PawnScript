# Object-oriented Programming

- Object-oriented programming (OOP) is a computer programming model that organizes software design around classes and objects. Classes are certain blocks of code, containing elements that can be accessed only via a certain object. After declaring an object, object drags elements from the class and creates its own copies, allowing same variable names, but with different values.

```cpp

class,TestClass;
{
	new.int,ClassTestVar=827346;
	new.double,TestClassDouble=364.234;
}

object,TestObj=TestClass;
console.cout.log(TestObj.ClassTestVar);
console.cout.log(TestObj.TestClassDouble);
console.println.log("#1 {TestObj.ClassTestVar} & {TestObj.TestClassDouble}");

object,TestObj2=TestClass;
set.int,TestObj2.ClassTestVar=9376216;
set.double,TestObj2.TestClassDouble=314.159267243;
console.cout.log(TestObj2.ClassTestVar);
console.cout.log(TestObj2.TestClassDouble);
console.println.log("#2 {TestObj2.ClassTestVar} & {TestObj2.TestClassDouble}");

class,TestClass2;
{
	new.int,ClassTestVar=100000;
	new.double,TestClassDouble=21.7636;
	new.bool,TestClassBool=false;
}

object,TestObj3=TestClass2;
console.cout.log(TestObj3.ClassTestVar);
console.cout.log(TestObj3.TestClassDouble);
console.println.log("#3 {TestObj3.ClassTestVar} & {TestObj3.TestClassDouble} & {TestObj3.TestClassBool}");

```

Output:
```
827346
364.234
#1 827346 & 364.234
9376216
314.159
#2 9376216 & 314.159
100000
21.763
#3 100000 & 21.763 & false
```