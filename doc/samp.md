# `samp`
- The `samp` API module contains functions used to control an **open.mp** server. Use the API module using:

```cpp
requires samp
{
	...
}
```

To use a specific component of the `samp` API module, do the following:

```cpp
requires samp
{
	using @global
}
```

## Example 1
- You can do the following:
```cpp
requires samp
{
	using @global for
	{
		@global.setserverattrib.hostname("My Server")
	}
}
```

# Components
## `@global`
### Function: `setserverattrib`
This function is used to update server attributes.
**NOTE**: This function has no non-method configuration, so you need to use a method in order to specify a server attribute.
#### Method: `hostname`
- Used to change the server hostname:
```cpp
requires samp
{
	using @global
}

@global.setserverattrib.hostname("My Server")
```

# Callbacks
- This component module contains following callbacks:
## `@onserverinit`
- This callback gets called once the server starts.
```cpp
@extern
	this->struct=callback
int @onserverinit() public
{
	console.println.log("@onserverinit called!")
	void inlinefunc() inline
	<
		console.println.log("INLINE WORKS!")
	>
	user.inlinefunc

	console.println.log("end")
	return int 1
}
```