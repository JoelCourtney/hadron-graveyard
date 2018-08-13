val grain = 1 + 10000

fn factorial(n) -> {
	var pieces = ()
	for grain:grain:n-1 at index as i {
		print "Calculating piece: " + i
		var partial = 1
		for i-grain+1:1:i as j {
			partial *= j
		}
		pieces = (pieces,partial)
	}
	var partial = 1
	print "Calculating piece: " + n
	for n - (n mod grain)+1:1:n as i {
		partial *= i
	}
	pieces = (pieces,partial)
	var result = 1
	var count = 0
	for pieces as piece {
		print "Multiplying piece: " + count
		count += 1
		result *= piece
	}
	result
}

print factorial(10)
