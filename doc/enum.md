# Enumerators

- An enumeration, or an `enum` , is a symbolic name for a set of values. Enumerations are treated as data types, and you can use them to create sets of constants for use with variables and properties.

## Example `#1`

```cpp
enum,WeekDays;
{;
	monday;
	tuesday;
	thursday;
	saturday;
};

console.cout.log(WeekDays.monday);
console.cout.log(WeekDays.tuesday);
console.cout.log(WeekDays.thursday);
console.cout.log(WeekDays.saturday);

console.println.log("enum test included");
console.cout.log(WeekDays.saturday+WeekDays.monday);
```

## Example `#2`

```cpp
enum,WeekDays;
{;
	monday=1;
	tuesday=2;
	thursday=3;
	saturday=4;
};

console.cout.log(WeekDays.monday);
console.cout.log(WeekDays.tuesday);
console.cout.log(WeekDays.thursday);
console.cout.log(WeekDays.saturday);

console.println.log("enum test included");
console.cout.log(WeekDays.saturday+WeekDays.monday);


enum,Months;
{;
	january=5;
	february=6;
	december=7;
};

console.cout.log(Months.january);
console.cout.log(Months.february-Months.december);
console.cout.log(Months.january%WeekDays.monday);

console.println("Test?");
```