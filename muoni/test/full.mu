var a = (1,2) // basic matrix
var b = (a, 3)[s] // (1, 2, 3)
b = (a; 3, 4) // (1,2;3,4)
var c = a&[m] // convert a to meters
var d = c&[s] // d is now in [m*s]

val f = d * 1[m/ft] // useless

print f@[m] // strips units basically. under the hood it is just division
print f~[ft*hr] // converts before printing
print f&[m] // multiplies by 1[m] basically. opposite of @

print f@[m]~[hr] // strips m and converts to hr

val g = (3;4)[AU] // yep

print $b // (2,2)
print prod($b) // 4
print #b

print norm(g) // should be 5[AU]
print norm(g)~[km] // the implication is that we need to treat ~,@,and & as operators

b = ["hello", a] // List
c = [b, true] // [["hello",(1,2)],true]

c[#c] = "asdf" // [["hello",(1,2)],true,"asdf"]

// insert, pop, prepend, etc

b = "true"~Bool // ~ is basically the convert/cast operator

// types: [units], Num, Str, Bool, [w,h][units], List

var [x,y] = [1,2] // list decomposition
(x, y) = (1, 2) // matrix decomposition

(w,h) = $(1,2;3,4)

a[1] // first element of a
c[-1] = 7 // last element of c set to 7

a[3] = 5
a[4,5] = 3
a[[3:6),[1:5)] = 2
a[2:3,4:6] = 1
a[a > 0] = 4 // matrix subset assignment

fn squareSum1(v) -> {
	val n = norm(v)
	<- n^2
}
fn squareSum2(v) -> sum(v .^ 2)
fn squareSum3(v) -> {
	<- sum( {
		m = prefill(0, $v)
		for [1:#v] as i { // $v = prod(#v)
			m = v[i]^2
		}
		<- m
	} )
}

fn foldLeft(v,acc,f) -> {
	for [1:#v] as i {
		acc = f(v[i],acc)
	}
	<- acc
}
val v = [1,2,3]
val acc = 1
print foldLeft(v,acc,fn (z,acc)->z^2 + acc) // square sum 4

fn nomnom(acc) ->|v| acc * v + a // accesses a, captures v, passes acc
