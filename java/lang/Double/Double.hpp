/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NATIVE_JAVA_LANG_DOUBLE_HPP
#define NATIVE_JAVA_LANG_DOUBLE_HPP

#include "../Number/Number.hpp"

namespace Java {
	namespace Lang {
		class Double : public virtual Number {
		private:
			double original;
            string string_original;

		public:
            /**
             * Double initialization
             *
             * @param original
             */
            Double();

            /**
             * Double initialization
             *
             * @param original
             */
			Double(double original);

            /**
             * Double initialization
             *
             * @param original
             */
			Double(const Double &target);

            /**
             * Double Destructor
             */
			~Double();
		
		public:
            /**
             * Double to Char
             *
             * @return char
             */
			char charValue() const;

            /**
             * Double to String
             *
             * @return CString
             */
			string stringValue() const;

            /**
             * Short value of Double
             *
             * @return short
             */
			short shortValue() const;

            /**
             * Double value in Double
             *
             * @return int
             */
			int intValue() const;

            /**
             * Double value in Long
             *
             * @return long
             */
			long longValue() const;

            /**
             * Double value in float
             *
             * @return float
             */
			float floatValue() const;

            /**
             * Double value in double
             *
             * @return double
             */
			double doubleValue() const;

            /**
             * Double to String
             *
             * @return String
             */
			string toString() const;

            /**
             * Parse double
             *
             * @param target
             * @return double
             */
			static Double parseDouble(String target);
			/**
			 * Returns the value of this {@code Double} as a {@code byte}
			 * after a narrowing primitive conversion.
			 *
			 * @return  the {@code double} value represented by this object
			 *          converted to type {@code byte}
			 */
			byte byteValue() const ;
		
		public:
            /// ---------- Arithmetic Operators ----------

            /**
             * Adds two operands
             *
             * @return Double
             */
			Double operator+(const Double &target);

            /**
             * Subtracts second operand from the first
             *
             * @return Double
             */
			Double operator-(const Double &target);

            /**
             *  Multiplies both operands
             *
             * @return Double
             */
			Double operator*(const Double &target);

            /**
             * Divides numerator by de-numerator
             *
             * @return Double
             */
			Double operator/(const Double &target);

//             For Integer, Long, Short ...
//            /**
//             * Modulus Operator and remainder
//             * of after an integer division
//             *
//             * @return Double
//             */
//            Double operator%(const Double &target) const;

//            /**
//             * Increment operator,
//             * increases integer value by one
//             *
//             * @return Double
//             */
//            Double operator++(const Double &target) const;

//            /**
//             * Decrement operator,
//             * decreases integer value by one
//             *
//             * @return Double
//             */
//            Double operator--(const Double &target) const;

        public:
            /// ---------- Relational Operators ----------

            /**
             * Checks if the values of two operands
             * are equal or not,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator==(const Double &target) const;

            /**
             * Checks if the values of two operands
             * are equal or not,
             * if values are not equal
             * then condition becomes true
             *
             * @return boolean
             */
            boolean operator!=(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator>(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is less than the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator<(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than or equal to the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator>=(const Double &target) const;

            /**
             *  Checks if the value of left operand
             *  is less than or equal to the value of right operand,
             *  if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator<=(const Double &target) const;

        public:
            /// ---------- Logical Operators ----------

            /**
             *  Called Logical AND operator.
             *  If both the operands are non-zero,
             *  then condition becomes true.
             *
             * @return boolean
             */
            boolean operator&&(const Double &target) const;

            /**
             *  Called Logical OR Operator.
             *  If any of the two operands is non-zero,
             *  then condition becomes true.
             *
             * @return boolean
             */
            boolean operator||(const Double &target) const;

//            /**
//             *  Called Logical NOT Operator.
//             *  Use to reverses the logical state of its operand.
//             *  If a condition is true,
//             *  then Logical NOT operator will make false.
//             *
//             * @return boolean
//             */
//            boolean operator!(const Double &target) const;


//            /// ---------- Bitwise Operators ---------- // For Integer, Long, Short ...
//
//            /**
//             *  Binary AND Operator copies a bit
//             *  to the result if it exists in both operands.
//             *
//             * @return boolean
//             */
//            boolean operator&(const Double &target) const;
//
//            /**
//             *  Binary OR Operator copies a bit
//             *  if it exists in either operand.
//             *
//             * @return boolean
//             */
//            boolean operator|(const Double &target) const;
//
//            /**
//             *  Binary XOR Operator copies the bit
//             *  if it is set in one operand but not both.
//             *
//             * @return boolean
//             */
//            boolean operator^(const Double &target) const;
//
//            /**
//             *  Binary Ones Complement Operator
//             *  is unary and has the effect of 'flipping' bits.
//             *
//             * @return Double
//             */
//            Double operator~(const Double &target);
//
//            /**
//             *  Binary Left Shift Operator.
//             *  The left operands value is moved left
//             *  by the number of bits specified by the right operand.
//             *
//             * @return Double
//             */
//            Double operator<<(const Double &target) const;
//
//            /**
//             *  Binary Right Shift Operator.
//             *  The left operands value is moved right
//             *  by the number of bits specified by the right operand.
//             *
//             * @return Double
//             */
//            Double operator>>(const Double &target) const;

        public:
            /// ---------- Assignment Operators ----------


            /**
             * Simple assignment operator,
             * Assigns values from right side operands
             * to left side operand
             *
             * @param target
             * @return Double
             */
            Double operator=(const Double &target);

            /**
             * Add AND assignment operator,
             * It adds right operand to the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator+=(const Double &target) const;

            /**
             * Subtract AND assignment operator,
             * It subtracts right operand from the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator-=(const Double &target) const;

            /**
             * Multiply AND assignment operator,
             * It multiplies right operand with the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator*=(const Double &target) const;

            /**
             * Divide AND assignment operator,
             * It divides left operand with the right operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator/=(const Double &target) const;

            /**
             * Modulus AND assignment operator,
             * It takes modulus using two operands
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
//              For ingeger , long , short ... only
//            Double operator%=(const Double &target) const;
//
//            /**
//             * Left shift AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator<<=(const Double &target) const;
//
//            /**
//             * Right shift AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator>>=(const Double &target) const;
//
//            /**
//             * Bitwise AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator&=(const Double &target) const;
//
//            /**
//             * bitwise exclusive OR and assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator^=(const Double &target) const;
//
//            /**
//             * bitwise inclusive OR and assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator|=(const Double &target) const;

		};
	}
}
#endif//NATIVE_JAVA_LANG_DOUBLE_HPP