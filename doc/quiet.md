# Quiet function call

- Using the `[quiet]` decorator, you can quietly call a void function, which will allow your 2 user functions to communicate properly.

```cpp
void myQuietFunc(num,text) private
{
	static[int]PortableStatic=763
	console.println(text@myQuietFunc)
	console.println("num@myQuietFunc is {num@myQuietFunc}")
}

int MyInterestingFunc() private
{
	static[byte]StaticByteTest=873
	console.println.log("StaticByteTest is now {StaticByteTest}")
	StaticByteTest=-333
	console.println.log("StaticByteTest is now {StaticByteTest}")
	StaticByteTest=7
	console.println.log("StaticByteTest is now {StaticByteTest}")

	[quiet]
	user.myQuietFunc(2,"test print yo wtf")

	console.println.log("StaticByteTest is now {StaticByteTest}")
	console.println.log("PortableStatic is now {PortableStatic}")
	return int 1
}

user.MyInterestingFunc() some_return_reference
```

If we removed the `[quiet]` decorator before the function call, we'd get null outputs in this part of the code:

```cpp
console.println.log("StaticByteTest is now {StaticByteTest}")
console.println.log("PortableStatic is now {PortableStatic}")
```

- **WARNING**: If we used return in `myQuietFunc`, that return would actually return in `MyInterestingFunc`.