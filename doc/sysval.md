# System values

- System values are variables or more-likely constants that can be accessed from the PawnScript code, but are used and updated internally. Below is a list of accessible system values. System values are prefixed with `$`.


## `$system.speed`

Return type: `int`

- Returns the current process execution speed (how many times was the interpreter core function called in this second) in hertz.


```cpp
@task
	this->interval=4000
	this->repeat=true
void myTask() private
{
	new[int]process_speed=$system.speed
	console.println("Process speed: {process_speed} Hz")
	#undef:process_speed
}
```