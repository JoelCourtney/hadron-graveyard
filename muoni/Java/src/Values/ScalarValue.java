package values;

public interface ScalarValue extends NumericValue {
	public void negate();
	public FloatValue magnitude();
	public void conjugate();
}
