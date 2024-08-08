# Class unions
- Class unions are labels that can be defined within a class to classify class members. Creating objects using classes that contain unions is called non-explicit object declaration. In previous documentation, we've already met with explicit object declaration, which means that an explicitly created object will inherit all class members regardless of the union members are declared in.

- Let's take a look at the following example:

```cpp
class LabelTest
{
	new[int]variable_1=364
	union testunion
		new[int]variable_2=463
		// some other things
	union union2
		new[int]variable_3=634
		// some other things
}

LabelTest<explicit>MyObj2
LabelTest<testunion>MyObj3
LabelTest<union2>MyObj4

console.println.log("{MyObj2.variable_1}")
console.println.log("{MyObj2.variable_2}")
console.println.log("{MyObj2.variable_3}")

console.println.log("{MyObj3.variable_1}")
console.println.log("{MyObj3.variable_2}")
console.println.log("{MyObj3.variable_3}")

console.println.log("{MyObj4.variable_1}")
console.println.log("{MyObj4.variable_2}")
console.println.log("{MyObj4.variable_3}")
```

Output:
```
364
463
634
null
463
null
null
null
634
```

- In example above, we can see that `MyObj2` was explicitly created, so it inherits all class members regardless of the union; however other objects inherited class members non-explicitly and inherited only members that were in a specified union.

- In other words, `MyObj3` and `MyObj4` implicitly inherited the class contents, leaving the other class members "hidden" for these objects.