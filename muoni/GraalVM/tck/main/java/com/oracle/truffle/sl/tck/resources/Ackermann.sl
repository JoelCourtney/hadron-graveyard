fn ack(m,n) {
  if (m == 0) {
    return n + 1;
  }
  if (n == 0) {
      n = 1;
  } else {
      n = ack(m, n - 1);
  }
  return ack(m - 1, n);
}

fn execute() {
    ack(2,3);
}

fn main() {
  return execute;
}

