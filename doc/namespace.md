# Namespace

- A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries.

## Creating a namespace

- A normal class with a normal purpose.

```cpp
namespace,customer;
<;
>;
```

Within the class code block, we can create a variable.

```cpp
namespace,customer;
<;
	new.str,name="Alex";
>;
```

To use this variable, we need to include the class name within the variable name; like this:

```cpp
console.println(customer::name);
```

---------------------------------------------------------------------------------------------------------

## Hooking namespaces
- You can also hook a namespace. To hook a namespace means to extend a namespace and add more elements to an existing namespace instead of creating a new one. For example, this is our code right now:

```cpp
namespace,customer;
<;
	new.str,name="Alex";
>;

console.println(customer::name);

```

We can hook the `customer` namespace:

```cpp
namespace,customer;
<;
	new.str,name="Alex";
>;

console.println(customer::name);

using*namespace,customer;
<;
	new.int,age=12;
>;

console.cout(customer::age);
```