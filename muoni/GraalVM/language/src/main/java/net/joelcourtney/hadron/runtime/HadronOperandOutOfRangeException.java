/*
 * Copyright (c) 2015, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * The Universal Permissive License (UPL), Version 1.0
 *
 * Subject to the condition set forth below, permission is hereby granted to any
 * person obtaining a copy of this software, associated documentation and/or
 * data (collectively the "Software"), free of charge and under any and all
 * copyright rights in the Software, and any and all patent rights owned or
 * freely licensable by each licensor hereunder covering either (i) the
 * unmodified Software as contributed to or provided by such licensor, or (ii)
 * the Larger Works (as defined below), to deal in both
 *
 * (a) the Software, and
 *
 * (b) any piece of software and/or hardware listed in the lrgrwrks.txt file if
 * one is included with the Software each a "Larger Work" to which the Software
 * is contributed by such licensors),
 *
 * without restriction, including without limitation the rights to copy, create
 * derivative works of, display, perform, and distribute the Software and make,
 * use, sell, offer for sale, import, export, have made, and have sold the
 * Software and the Larger Work(s), and to sublicense the foregoing rights on
 * either these or other terms.
 *
 * This license is subject to the following condition:
 *
 * The above copyright notice and either this complete permission notice or at a
 * minimum a reference to the UPL must be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
package net.joelcourtney.hadron.runtime;

import com.oracle.truffle.api.CompilerDirectives.TruffleBoundary;
import com.oracle.truffle.api.nodes.Node;
import net.joelcourtney.hadron.HadronException;

public final class HadronOperandOutOfRangeException extends HadronException {

    private static final long serialVersionUID = 1L;

    @TruffleBoundary
    public static HadronOperandOutOfRangeException powerToLarge(Node location, long n) {
        return new HadronOperandOutOfRangeException("Exponent too large to compute: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException powerToLarge(Node location, HadronBigNumber n) {
        return new HadronOperandOutOfRangeException("Exponent too large to compute: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException divisionByZero(Node location) {
        return new HadronOperandOutOfRangeException("Division by zero", location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException largeFactorial(Node location, long n) {
        return new HadronOperandOutOfRangeException("Factorial too large to compute: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException largeFactorial(Node location, HadronBigNumber n) {
        return new HadronOperandOutOfRangeException("Factorial too large to compute: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException largeFactorial(Node location, double n) {
        return new HadronOperandOutOfRangeException("Factorial too large to compute: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException negativeFactorial(Node location, long n) {
        return new HadronOperandOutOfRangeException("Factorial of negative number: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException negativeFactorial(Node location, HadronBigNumber n) {
        return new HadronOperandOutOfRangeException("Factorial of negative number: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException negativeFactorial(Node location, double n) {
        return new HadronOperandOutOfRangeException("Factorial of negative number: " + n, location);
    }

    @TruffleBoundary
    public static HadronOperandOutOfRangeException fractionalFactorial(Node location, double n) {
        return new HadronOperandOutOfRangeException("Factorial of a non-integer: " + n, location);
    }

    private HadronOperandOutOfRangeException(String message, Node node) {
        super(message, node);
    }
}
