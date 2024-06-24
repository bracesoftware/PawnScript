# Tasks

- Tasks in PawnScript are specific chunks of code that are being called every certain period of time.


```cpp
@task
	this->interval=1000
void mytask() public
{
	console.println("Task works!")
}
```

Code above will print `Task works!` every 1 second. It is also really important to note that tasks are VERY different from functions and cannot return any values. 

Tasks also can be only stopped using `exit;` which terminates everything else as well.