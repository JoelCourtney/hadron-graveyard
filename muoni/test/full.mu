//a a = [1,2] // basic matrix
//a b = [a, 3] // [1, 2, 3]
//a b = [a; 3, 4] // [1,2;3,4]
//a c = a&[m] // convert a to meters
//a d = c&[s] // d is now in [m*s]

//a f = d * 1[m/ft] // useless

//a print f@[m] // strips units basically. under the hood it is just division
//a print f~[ft*hr] // converts before printing
//a print f&[m] // multiplies by 1[m] basically. opposite of @

//a print f@[m]~[hr] // strips m and converts to hr

//a g = [3;4][AU] // yep

//a print #b // [2,2]
//a print prod(#b) // 4
//a print $b

print norm(g) // should be 5[AU]
print norm(g)~[km] // the implication is that we need to treat ~,@,and & as operators

b = <"hello", a> // List
c = <b, true> // <<"hello",[1,2]>,true>

c.append("asdf") // <<"hello",[1,2]>,true,"asdf">

// insert, pop, prepend, etc

//a b = "true"~Bool // ~ is basically the convert/cast operator

// types: [units], Num, Str, Bool, [w,h][units], List

//a [x,y] = [1,2] // matrix decomposition
//a <x,y> = <1,2> // list decomposition

//a [w,h] = #[1,2;3,4]

//a a[1] // first element of a
//a c< -1 > = 7 // last element of c set to 7

//a a[a > 0] = 4 // matrix subset assignment

//a squareSum1(v) -> {
//a 	n = norm(v)
//a 	<- n^2
//a }
//a squareSum2(v) -> sum(v .^ 2)
//a squareSum3(v) -> {
//a 	<- sum({
//a 		m = prefill(0, #v)
//a 		for [1:1:$v] as i { // $v = prod(#v)
//a 			m = v[i]^2
//a 		}
//a 		<- m
//a 	})
//a }

//a foldLeft(v,acc,f) -> {
//a 	for [1:1:$v] as i {
//a 		acc = f(v[i],acc)
//a 	}
//a 	<- acc
//a }
//a v := [1,2,3]
//a acc = 1
//a print foldLeft(v,acc,(z,acc)->z^2 + acc) // square sum 4
