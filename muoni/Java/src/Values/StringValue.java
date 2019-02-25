package values;

public class StringValue implements Value {
	private String d;

	public StringValue(String s) {
		d = s;
	}

	public String toString() {
		return d;
	}
}
