package values;

public class IntegerValue implements ScalarValue {
	private int d;

	public IntegerValue(int i) {
		d = i;
	}

	public void increment() {
		d++;
	}
	public void decrement() {
		d--;
	}

	public void negate() {
		d = -d;
	}
	public FloatValue magnitude() {
		if (d >= 0) {
			return new FloatValue(-d);
		} else {
			return new FloatValue(d);
		}
	}
	public void conjugate() {}

	public String toString() {
		return Integer.toString(d);
	}
}
