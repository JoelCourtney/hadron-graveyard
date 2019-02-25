package values;

public interface Value {
	public static StringValue from(String s) {
		return new StringValue(s);
	}
	public static BoolValue from(boolean b) {
		return new BoolValue(b);
	}
	public static IntegerValue from(int i) {
		return new IntegerValue(i);
	}
	public static FloatValue from(double f) {
		return new FloatValue(f);
	}

	public String toString();
}
