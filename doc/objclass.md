# Object-oriented Programming

- Object-oriented programming (OOP) is a computer programming model that organizes software design around classes and objects. Classes are certain blocks of code, containing elements that can be accessed only via a certain object. After declaring an object  object drags elements from the class and creates its own copies, allowing same variable names, but with different values.

```cpp
class TestClass
{
	new[int]ClassTestVar=827346
	new[double]TestClassDouble=364.234
}

object TestObj=TestClass
console.cout.log(TestObj.ClassTestVar)
console.cout.log(TestObj.TestClassDouble)
console.println.log("#1 {TestObj.ClassTestVar} & {TestObj.TestClassDouble}")

object TestObj2=TestClass
TestObj2.ClassTestVar=9376216
TestObj2.TestClassDouble=314.159267243
console.cout.log(TestObj2.ClassTestVar)
console.cout.log(TestObj2.TestClassDouble)
console.println.log("#2 {TestObj2.ClassTestVar} & {TestObj2.TestClassDouble}")

class TestClass2
{
	new[int]ClassTestVar=100000
	new[double]TestClassDouble=21.7636
	new[bool]TestClassBool=false
}

object TestObj3=TestClass2
console.cout.log(TestObj3.ClassTestVar)
console.cout.log(TestObj3.TestClassDouble)
console.println.log("#3 {TestObj3.ClassTestVar} & {TestObj3.TestClassDouble} & {TestObj3.TestClassBool}")
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

## Classes within namespaces

```cpp
namespace testnamespace
{
	class testclass
	{
		new[int]testinteger=1
	}
}

object Obj=testnamespace::testclass
Obj.testinteger=13
std::writeln("{Obj.testinteger}")
```

Output:

```
13
```

## Virtual functions
- Virtual functions are blueprints for creating functions within classes:

```cpp
using namespace test
{
	void __eat() virtual
	{
		static[byte]StaticByte=9
		console.println.log("This human is eating")
	}
	void __eat2() virtual
	{
		console.println.log("This human is eating again!")
	}
}

class HumanBeing
{
	new[str]name="Mustafa"
	public eat=>test::__eat
	new[int]age=85
	public eat2=>test::__eat2
}

object MeAgain=HumanBeing

MeAgain.eat()
console.println.log("MeAgain.name is {MeAgain.name}")
console.rawout.log(MeAgain.age)

void testfunc() private
{
	static[byte]StaticByte2=10
	[quiet]
	MeAgain.eat()
	[quiet]
	MeAgain.eat2()
	console.println.log("StaticByte is {StaticByte}")
	console.println.log("StaticByte2 is {StaticByte2}")
}

user.testfunc
```

The following line contained within a class will create a new public function `eat` using data of the virtual function `test::__eat`:
```cpp
public eat=>test::__eat
```

If you want the new function to be private, just change the `public` modifier to `private`.

- **NOTE**: The reason you can't just create a function inside a class directly is an internal issue - basically, having a nested interpreter-terminating code block would cause potential issues.