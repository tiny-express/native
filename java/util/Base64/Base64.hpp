/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

#include "../../Lang.hpp"

namespace Java {
		namespace Util {
				/**
				 * This class consists exclusively of static methods for obtaining
				 * encoders and decoders for the Base64 encoding scheme.
				 */
				class Base64 {
				public:
						/**
						 * This class implements an encoder for encoding byte data
						 * using the Base64 encoding scheme as specified in RFC 4648
						 * and RFC 2045.
						 */
						class Encoder {
								friend class Base64;
						
						private:
								// Base64 index table.
								static const Array<char> toBase64;
								// Base64URL (filename, url safe) index table.
								static const Array<char> toBase64Url;
								// Maximum number of characters of a single line.
								// RFC2045: Each line of character SHOULD be no more than 78 characters.
								//          (Excluding CRLF => 78 - 2 (of CRLF) = 76)
								static const int mimeLineMax = 76;
								static const Array<byte> crlf;
						
						private:
								Array<byte> newLine;
								int lineMax;
								boolean isUrl;
								boolean doPadding;
						
						private:
								/**
								 * Constructor
								 * Constructs base64 encoding scheme.
								 *
								 * @param isUrl
								 * @param newLine
								 * @param lineMax
								 * @param doPadding
								 */
								Encoder(boolean isUrl, const Array<byte> &newLine, int lineMax, boolean doPadding);
						
						private:
								static Encoder RFC4648;
								static Encoder RFC4648_URLSAFE;
								static Encoder RFC2045;
						
						private:
								/**
								 * Calculates length of output base on length of input.
								 *
								 * @param sourceLength
								 * @return int
								 */
								int outLength(int sourceLength) const;
								
								/**
								 * Encodes all bytes from offset (inclusive) to end (exclusive).
								 *
								 * @param source
								 * @param offset
								 * @param end
								 * @param destination
								 * @return int
								 */
								int encoding(const Array<byte> &source, int offset, int end,
									Array<byte> &destination) const;
						
						public:
								/**
								 * Constructor
								 * Constructs base64 encoding scheme from an other Encoder instance.
								 *
								 * @param source
								 */
								Encoder(const Encoder &source);
								
								/**
								 * Destructor
								 */
								virtual ~Encoder();
						
						public:
								/**
								 * Encodes all bytes from the specified byte array into a newly-allocated
								 * byte array using the Base64 encoding scheme.
								 * The returned byte array is of the length of the resulting bytes.
								 *
								 * @param source
								 * @return Array<byte>
								 */
								Array<byte> encode(const Array<byte> &source) const;
								
								/**
								 * Encodes all bytes from the specified byte array using the Base64 encoding scheme,
								 * writing the resulting bytes to the given output byte array, starting at offset 0.
								 * It is the responsibility of the invoker of this method to make sure the output
								 * byte array dst has enough space for encoding all bytes from the input byte array.
								 * No bytes will be written to the output byte array if the output byte array
								 * is not big enough.
								 *
								 * @param source
								 * @param destination
								 * @return int
								 * @throw IllegalArgumentException - if destination does not have enough space
								 * for encoding all input bytes.
								 */
								int encode(const Array<byte> &source, Array<byte> &destination) const;
								
								/**
								 * Encodes all remaining bytes from the specified byte buffer into
								 * a newly-allocated ByteBuffer using the Base64 encoding scheme.
								 *
								 * @param source
								 * @return ByteBuffer
								 */
//              ByteBuffer encode(const ByteBuffer &source) const;
								// TODO(truongchauhien): Waiting for ByteBuffer class.
								
								/**
								 * Encodes the specified byte array into a String using the Base64 encoding scheme.
								 * This method first encodes all input bytes into a base64 encoded byte array and
								 * then constructs a new String.
								 *
								 * @param source
								 * @return String
								 */
								String encodeToString(const Array<byte> &source) const;
								
								/**
								 * Returns an encoder instance that encodes equivalently to this one,
								 * but without adding any padding character at the end of the encoded byte data.
								 * The encoding scheme of this encoder instance is unaffected by this invocation.
								 * The returned encoder instance should be used for non-padding encoding operation.
								 *
								 * @return Encoder
								 */
								Encoder withoutPadding() const;
								
								/**
								 * Wraps an output stream for encoding byte data using the Base64 encoding scheme.
								 *
								 * @param source
								 * @return OutputStream
								 */
//              OutputStream wrap(const OutputStream &source) const;
								// TODO(truongchauhien): Waiting for OutputStream class.
						}; // class Encoder
						
						/**
						 * This class implements a decoder for decoding byte data
						 * using the Base64 encoding scheme as specified in RFC 4648
						 * and RFC 2045.
						 */
						class Decoder {
								friend class Base64;
						
						private:
								static const Array<int> fromBase64;
								static const Array<int> fromBase64Url;
						
						private:
								boolean isUrl;
								boolean isMime;
						
						private:
								/**
								 * Constructor
								 * Constructs base64 decoding scheme.
								 *
								 * @param isUrl
								 * @param isMime
								 */
								Decoder(boolean isUrl, boolean isMime);
						
						private:
								static Decoder RFC4648;
								static Decoder RFC4648_URLSAFE;
								static Decoder RFC2045;
						
						private:
								/**
								 * Calculates length of output base on input data.
								 *
								 * @param source
								 * @param offset
								 * @param end
								 * @return int
								 */
								int outLength(const Array<byte> &source, int offset, int end) const;
								
								/**
								 * Decodes all bytes from offset (inclusive) to end (exclusive).
								 *
								 * @param source
								 * @param offset
								 * @param end
								 * @param destination
								 * @return int
								 */
								int decoding(const Array<byte> &source, int offset, int end,
									Array<byte> &destination) const;
						
						public:
								/**
								 * Constructor
								 * Constructs base64 decoding scheme from an other Decoder instance.
								 *
								 * @param source
								 */
								Decoder(const Decoder &source);
								
								/**
								 * Destructor
								 */
								virtual ~Decoder();
						
						public:
								/**
								 * Decodes all bytes from the input byte array using the Base64 encoding scheme,
								 * writing the results into a newly-allocated output byte array.
								 * The returned byte array is of the length of the resulting bytes.
								 *
								 * @param source
								 * @return Array<byte>
								 * @throw IllegalArgumentException - if source is not in valid Base64 scheme
								 */
								Array<byte> decode(const Array<byte> &source) const;
								
								/**
								 * Decodes all bytes from the input byte array using the Base64 encoding scheme,
								 * writing the results into the given output byte array, starting at offset 0.
								 * It is the responsibility of the invoker of this method to make sure
								 * the output byte array dst has enough space for decoding all bytes
								 * from the input byte array.
								 * No bytes will be be written to the output byte array if the
								 * output byte array is not big enough.
								 *
								 * @param source
								 * @param destination
								 * @return int
								 * @throw IllegalArgumentException - if source is not in valid Base64 scheme,
								 * or destination does not have enough space for decoding all input bytes.
								 */
								int decode(const Array<byte> &source, Array<byte> &destination) const;
								
								/**
								 * Decodes all bytes from the input byte buffer using the Base64 encoding scheme,
								 * writing the results into a newly-allocated ByteBuffer.
								 *
								 * @param source
								 * @return ByteBuffer
								 */
//              ByteBuffer decode(const ByteBuffer &source) const;
								// TODO(truongchauhien): Waiting for ByteBuffer class.
								
								/**
								 * Decodes a Base64 encoded String into a newly-allocated byte array
								 * using the Base64 encoding scheme.
								 *
								 * @param source
								 * @return Array<byte>
								 */
								Array<byte> decode(const String &source) const;
								
								/**
								 * Returns an input stream for decoding Base64 encoded byte stream.
								 *
								 * @param source
								 * @return InputStream
								 */
//              InputStream wrap(const InputStream &source) const;
								// TODO(truongchauhien): Waiting for InputStream class.
						};  // class Decoder
				
				public:
						/**
						 * Returns a Base64::Encoder that encodes using the Basic type base64 encoding scheme.
						 *
						 * @return Encoder
						 */
						static Encoder getEncoder();
						
						/**
						 * Returns a Base64::Decoder that decodes using the Basic type base64 encoding scheme.
						 *
						 * @return Decoder
						 */
						static Decoder getDecoder();
						
						/**
						 * Returns a Base64::Encoder that encodes using the MIME type base64 encoding scheme.
						 * @return Encoder
						 */
						static Encoder getMimeEncoder();
						
						/**
						 * Returns a Base64::Decoder that decodes using the MIME type base64 decoding scheme.
						 * @return Decoder
						 */
						static Decoder getMimeDecoder();
						
						/**
						 * Returns a Base64::Encoder that encodes using the MIME type base64 encoding scheme
						 * with specified line length and line separators.
						 *
						 * @param lineLength
						 * @param lineSeparator
						 * @return Encoder
						 * @throw IllegalArgumentException - if lineSeparator includes any character
						 * of "The Base64 Alphabet" as specified in Table 1 of RFC 2045.
						 */
						static Encoder getMimeEncoder(int lineLength, const Array<byte> &lineSeparator);
						
						/**
						 * Returns a Base64::Encoder that encodes using the URL and Filename safe type base64 encoding scheme.
						 *
						 * @return Encoder
						 */
						static Encoder getUrlEncoder();
						
						/**
						 * Returns a Base64::Decoder that decodes using the URL and Filename safe type base64 encoding scheme.
						 *
						 * @return Decoder
						 */
						static Decoder getUrlDecoder();
				};  // class Base64
		}  // namespace Util
}  // namespace Java
