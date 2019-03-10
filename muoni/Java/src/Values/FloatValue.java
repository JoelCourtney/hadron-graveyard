package values;

public class FloatValue implements ScalarValue {
	private double d;

	public FloatValue(double _d) {
		d = _d;
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
		return Double.toString(d);
	}
}
