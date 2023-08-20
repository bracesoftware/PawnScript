# `try`, `break` and `continue`

- `try` keyword is a `do` version made for loops, allowing you to execute more code at once. `break` and `continue` are 2 famous concepts of **break**ing the loop, and skipping the **continu**ous iteration.

```cpp
try;
{
	console.println.log("Try works!");
	break;
}
if.equ,1,1->while.equ,1,1->;


new.int,fortestagainomg=0;

try;
{
	if.equ,fortestagainomg,5->continue;
	else->if.equ,fortestagainomg,8->break;
	else->do;
	{
		console.cout(fortestagainomg);
	}
}
for.int,fortestagainomg,10->;

try;
{
	if.equ,fortestagainomg,15->break;
	console.cout(fortestagainomg);
	fortestagainomg=fortestagainomg+1;
}
while.notequ,fortestagainomg,20->;
```

Output:

```
Try works!
1
2
3
4
6
7
8
8
9
10
11
12
13
14
15
```