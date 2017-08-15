/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#ifndef JAVA_NET_URL_HPP_
#define JAVA_NET_URL_HPP_

#include "../../lang/String/String.hpp"
#include "../URLConnection/URLConnection.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Net {
				
				// Pre-declaration
				class URLConnection;
				
				class URL : public Object {
				private:
						String protocol;
						String host;
						int port;
						String path;
						String query;
				public:
						URL();
						URL(String spec);
						URL(const URL &target);
						~URL();
				
				public:
						String getHost();
						String getPath();
						int getPort();
						String getProtocol();
						String getQuery();
						//URLConnection openConnection();
						string toString() const;
				};
				
				class URLConnection : public Object {
				private:
						int connectTimeout;
						int readTimeout;
				protected:
						URL url;
						boolean doInput = true;
						boolean doOutput = false;
						boolean connected = false;
						long ifModifiedSince;
						boolean allowUserInteraction;
						boolean useCaches;
				public:
						URLConnection();
						URLConnection(URL url);
						~URLConnection();
				
				public:
						URL getURL();
						void setDoInput(boolean doInput);
						boolean getDoInput();
						void setDoOutput(boolean doOutput);
						boolean getDoOutput();
						void setUseCaches(boolean useCaches);
						boolean getUseCaches();
						void setIfModifiedSince(long ifModifiedSince);
						long getIfModifiedSince();
						void setReadTimeout(int timeout);
						int getReadTimeout();
						void setAllowUserInteraction(boolean allowUserInteraction);
						boolean getAllowUserInteraction();
						void setConnectTimeout(int timeout);
						int getConnectTimeout();
						virtual void connect() = 0;
						String getContentEncoding();
						int getContentLength();
						String getContentType();
//            HashMap< String, Array<String> > getRequestProperties();
						String getRequestProperty(String key);
						void setRequestProperty(String key, String value);
						string toString() const;
				};
		}
}

#endif  // JAVA_NET_URL_HPP_