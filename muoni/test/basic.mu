print `phi`
print 2
//print "hello world!"

//val x = 5
//print x

//var x = 4
//print x

//{
//	val y = true
//	print y
//}

// print y

//fn hello(x) => {
//	print x
//}
//hello(7)
//print x

//{
//	fn hello() => {print "hello"}
//	{
//		(fn world() => {
//			hello()
//			print "world"
//		})()
//	}
//}

//var x = 5
//x += 1
//print x

//val x += 7
//print x

//if x is 122
//	print "yep"
//else
//	print "nop"

var x = 0
while x < 5; x += 1
print x

fn test() => 10

print x
test()
print x

var x = 0
loop {
	x += 1
	if x is 3; <-
	print x
	if x is 7; <~
}
print "made it past the loop"

for 1:5 as i at x
	print i


print x

// dropping
// unit declaration and usage
// integer input

val x = 5.5
val y = 1
print x + y

//val x = .1ie3
print x

val m = (1,2,5;5,6,12)
print m

val m2 = (m, (11;12); 1,2,3,4)
print m2

val c = 1+1i

print c

val cm = (1, 1+2)
print cm
print (cm,5i+3i)

print i
print e

val l = ["hello",5]
val l2 = [l, (3,4,5)]
print l2

dimension Length [
	m,
	km = 1000*m,
	ft = 0.3048*m
]

dimension Area [
	ac = 43560*ft^2
]

dimension Time [
	s,
	min = 60*s,
	hr = 60*min
]

val d = 6[m]
print d

val v = d / 4[min]
print v
