# Temporary component inclusion
* **Temporary component inclusion**, or __TCI__ for short, is a way of temporarily including some interpreter components just to run certain blocks of code ensuring faster execution and thus better performance.

```cpp
using console for
{
	console.println.log("test"); // This will execute normally
}

console.println.log("I should not be printed"); // This will give an error
```

An example above can be applied to any interpreter component.