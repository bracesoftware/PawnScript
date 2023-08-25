# Templates

- Templates are used to substitute long function calls with shorter keywords.

```cpp
template<console.println.log>cpl;
cpl("Hi.");
```

Output:

```
Hi.
```

## Templates in namespaces

- Also possible.

```cpp
namespace nm;
{
	template<console.println.log>cpl;
}
nm::cpl("Hi.");
```

Output:

```
Hi.
```