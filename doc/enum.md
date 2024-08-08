# Enumerators

- An enumeration, or an `enum` , is a symbolic name for a set of values. Enumerations are treated as data types, and you can use them to create sets of constants for use with variables and properties.

## Example `#1`

```cpp
enum WeekDays
{
	monday
	tuesday
	thursday
	saturday
}

console.cout.log(WeekDays.monday)
console.cout.log(WeekDays.tuesday)
console.cout.log(WeekDays.thursday)
console.cout.log(WeekDays.saturday)

console.println.log("enum test included")
console.cout.log(WeekDays.saturday+WeekDays.monday)
```

## Example `#2`

```cpp
enum WeekDays
{
	monday=1
	tuesday=2
	thursday=3
	saturday=4
}

console.cout.log(WeekDays.monday)
console.cout.log(WeekDays.tuesday)
console.cout.log(WeekDays.thursday)
console.cout.log(WeekDays.saturday)

console.println.log("enum test included")
console.cout.log(WeekDays.saturday+WeekDays.monday)


enum Months
{
	january=5
	february=6
	december=7
}

console.cout.log(Months.january)
console.cout.log(Months.february-Months.december)
console.cout.log(Months.january%WeekDays.monday)

console.println("Test?")
```

### Enums within namespaces
- You can create enums within namespaces as well.

```cpp
namespace Me
{
	enum Family
	{
		Mom
		Dad
		Sister
	}

	enum Friends
	{
		Bob
		Dave
	}
}

console.rawout(Me::Family.Mom+Me::Family.Dad)
```

### `final enum` and `using enum`

```cpp
console.println("Const expr enum test:")

namespace ConstexprTest
{
	enum MyNonConstEnum
	{
		q=1
		w
		e
	}
	final enum MyConstEnum
	{
		q
		w
		e
	}
}

console.rawout.log(ConstexprTest::MyNonConstEnum.q)
console.rawout.log(ConstexprTest::MyNonConstEnum.w)
console.rawout.log(ConstexprTest::MyNonConstEnum.e)

console.rawout.log(ConstexprTest::MyConstEnum.q)
console.rawout.log(ConstexprTest::MyConstEnum.w)
console.rawout.log(ConstexprTest::MyConstEnum.e)

using enum ConstexprTest::MyNonConstEnum
{
	r
	t
}
console.rawout.log(ConstexprTest::MyNonConstEnum.r)
console.rawout.log(ConstexprTest::MyNonConstEnum.t)

using enum ConstexprTest::MyConstEnum
{
	// boom error 9/11
}
```

Output:
```
[Info] Const expr enum test:
[Info] 1
[Info] 2
[Info] 3
[Info] 4
[Info] 5
[Info] 6
[Info] 7
[Info] 8
[Info] *** [PawnScript] FATAL ERROR - Info: Attempted to modify a constexpr code block.
[Info] [PawnScript] SERVER THREAD - Info: Process has been terminated to prevent further complication.
```