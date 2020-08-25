/*
 * Copyright (c) 2012, 2018, Oracle and/or its affiliates. All rights reserved.
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
package net.joelcourtney.hadron.nodes.expression;

import com.oracle.truffle.api.CompilerDirectives.TruffleBoundary;
import com.oracle.truffle.api.dsl.Fallback;
import com.oracle.truffle.api.dsl.Specialization;
import com.oracle.truffle.api.nodes.NodeInfo;
import net.joelcourtney.hadron.HadronException;
import net.joelcourtney.hadron.nodes.HadronBinaryNode;
import net.joelcourtney.hadron.runtime.HadronBigNumber;
import com.google.common.math.LongMath;
import java.lang.Math;
import net.joelcourtney.hadron.runtime.HadronOperandOutOfRangeException;
import java.math.BigInteger;

/**
 * This class is similar to the extensively documented {@link HadronAddNode}.
 */
@NodeInfo(shortName = "^")
public abstract class HadronPowNode extends HadronBinaryNode {

    @Specialization(rewriteOn = ArithmeticException.class)
    protected long pow(long base, long exp) {
        if (exp < 0) {
        	if (base == 0)
                throw HadronOperandOutOfRangeException.divisionByZero(this);
        	else if (base == 1)
        	    return 1;
        	else if (base == -1)
        		return (exp%2==0)?1:-1;
        	else return 0;
        } else if (exp > Integer.MAX_VALUE) {
            throw HadronOperandOutOfRangeException.powerToLarge(this, exp);
        }
        return LongMath.checkedPow(base, (int) exp);
    }

    @Specialization
    protected HadronBigNumber pow(HadronBigNumber base, long exp) {
        BigInteger baseVal = base.getValue();
        if (exp < 0) {
            if (baseVal.signum() == 0)
				throw HadronOperandOutOfRangeException.divisionByZero(this);
            else if (baseVal.compareTo(BigInteger.ONE) == 0)
            	return new HadronBigNumber(BigInteger.ONE);
            else if (baseVal.compareTo(BigInteger.ONE.negate()) == 0)
            	return new HadronBigNumber((exp%2==0)?BigInteger.ONE:BigInteger.ONE.negate());
            else return new HadronBigNumber(BigInteger.ZERO);
        } else if (exp > Integer.MAX_VALUE) {
        	throw HadronOperandOutOfRangeException.powerToLarge(this, exp);
        }
        return new HadronBigNumber(base.getValue().pow((int) exp));
    }

    @Specialization
    @TruffleBoundary
    protected HadronBigNumber pow(HadronBigNumber base, HadronBigNumber exp) {
        BigInteger baseVal = base.getValue();
        BigInteger expVal = exp.getValue();
    	if (exp.getValue().signum() == -1) {
			if (baseVal.signum() == 0)
				throw HadronOperandOutOfRangeException.divisionByZero(this);
			else if (baseVal.compareTo(BigInteger.ONE) == 0)
				return new HadronBigNumber(BigInteger.ONE);
			else if (baseVal.compareTo(BigInteger.ONE.negate()) == 0)
				return new HadronBigNumber((expVal.mod(new BigInteger("2")).signum() == 0)?BigInteger.ONE:BigInteger.ONE.negate());
			else return new HadronBigNumber(BigInteger.ZERO);
        } else if (exp.getValue().signum() == 1 && !exp.fitsInInt()) {
            throw HadronOperandOutOfRangeException.powerToLarge(this, exp);
        }
    	int expValue = exp.getValue().intValue();
    	if (expValue < 0) {
    		return new HadronBigNumber(BigInteger.ZERO);
        }
        return new HadronBigNumber(baseVal.pow(expValue));
    }

    @Specialization
	protected double pow(double base, double exp) {
		if (exp < 0 && base == 0) {
			throw HadronOperandOutOfRangeException.divisionByZero(this);
		}
		return Math.pow(base, exp);
	}

    @Fallback
    protected Object typeError(Object left, Object right) {
        throw HadronException.typeError(this, left, right);
    }

}
