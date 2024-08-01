# Function structure types

- In PawnScript, there are 2 function structure types, and those are local and external functions.

## Local functions

- Those are basic chunks or blocks of code that are called by the PawnScript user internally.

Example:

```cpp
void Announce() public
{
	console.println("Script is loading")
}
```

## External functions

- External functions are functions that are called when a certain event happens in third-party API or outside local PawnScript scope (not called by the user). For example, a callback is a type of external function which automatically gets called when a certain event occurs. There are following types of external functions:

### `default`
Default events that happen in PawnScript, there's currently only one available and that's `main`:

```cpp
@extern
	this->struct=default
void main() public
{
	// foo
}
```

### `callback`
Event functions or, callbacks, are functions that are called by the component module such as `samp` when a certain event related to it occurs. Callbacks are usually prefixed with `@`.

- **NOTE**: A list of available callbacks that are called by a specific module should be available in the component module documentation.

```cpp
@extern
	this->struct=callback
void @onserverinit() public
{
	// foo
}
```