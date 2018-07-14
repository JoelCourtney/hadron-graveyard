#! /usr/bin/env muoni

grain := 10000

factorial(n) -> {
	pieces = ()
	for [grain:grain:n) at index as i {
		print "Calculating piece: " + i
		partial = 1
		for (i-grain:1:i] as j {
			partial *= j
		}
		pieces = (pieces,partial)
	}
	partial = 1
	print "Calculating piece: " + n
	for (n - (n mod grain):1:n] as i {
		partial *= i
	}
	pieces = (pieces,partial)
	result = 1
	count = 0
	for pieces as piece {
		print "Multiplying piece: " + count
		count += 1
		result *= piece
	}
	<- result
}

print factorial(10)

// Alternatively...
print 10!
