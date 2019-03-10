package values;

public class BoolValue implements Value {
	private boolean d;

	public BoolValue(boolean b) {
		d = b;
	}

	public String toString() {
		if (d) {
			return "true";
		} else {
			return "false";
		}
	}
}
