//
// Created by dquang on 8/1/17.
//

#ifndef NATIVE_MEDIATYPE_H
#define NATIVE_MEDIATYPE_H

#include "../../../../java/Lang.hpp"

namespace Javax {
    namespace Ws {
        class MediaType : public virtual Java::Lang::Object {
        public:
            static String APPLICATION_ATOM_XML          = "application/atom+xml";
            static String APPLICATION_FORM_URLENCODED   = "application/x-www-form-urlencoded";
            static String APPLICATION_JSON              = "application/json";
            static String APPLICATION_OCTET_STREAM      = "application/octet-stream";
            static String APPLICATION_SVG_XML           = "application/svg+xml";
            static String APPLICATION_XHTML_XML         = "application/xhtml+xml";
            static String APPLICATION_XML               = "application/xml";
            static String MEDIA_TYPE_WILDCARD           = "*";
            static String MULTIPART_FORM_DATA           = "multipart/form-data";
            static String TEXT_HTML                     = "text/html";
            static String TEXT_PLAIN                    = "text/plain";
            static String TEXT_XML                      = "text/xml";
            static String WILDCARD                      = "*/*";
        };
    }
}

#endif //NATIVE_MEDIATYPE_H
