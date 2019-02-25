package values;

public interface MatrixValue extends NumericValue {
	public FloatValue determinant();
	public void conjugate();
	public void invert();
	public void negate();
	// factoring?
}
