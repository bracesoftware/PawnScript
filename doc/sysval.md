# System values

- System values are variables or more-likely constants that can be accessed from the PawnScript code, but are used and updated internally. Below is a list of accessible system values.

## `__proccessed_form_id`

Return type: `int`

- Returns a processed form id.

```cpp
new.int,formid=__proccessed_form_id;
console.println("'inlinetest' is {formid}");
```

## `__majorver`

Return type: `int`

- Returns the major version number.

## `__minorver`

Return type: `int`

- Returns the minor version number.

## `__patch`

Return type: `int`

- Returns the patch version number.

## `__release`

Return type: `int`

- Returns the version release number.

## `__beta`

Return type: `int`

- Returns 1 if the build is beta and 0 if the build is stable.


## `__procspeed`

Return type: `int`

- Returns the current process execution speed (how many times was the interpreter core function called in this second) in hertz.


```cpp
@task
	this->interval=1000
void supercooltask() public
{
	new.int,process_speed=__procspeed
	console.println.log("Process execution speed: {process_speed} Hz")
	#undef:process_speed
}
```