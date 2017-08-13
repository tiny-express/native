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

#ifndef NATIVE_JAVA_UTIL_LOCALE_HPP_
#define NATIVE_JAVA_UTIL_LOCALE_HPP_

#include "../../Lang.hpp"
#include "../../Util.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Locale : public Serializable, public Cloneable {
        public:
            class Builder {
            public:
                Builder();

            public:
                Locale::Builder &addUnicodeLocaleAttribute(const String attribute);
                Locale build() const;
                Locale::Builder &clear();
                Locale::Builder &clearExtensions();
                Locale::Builder &removeUnicodeLocaleAttribute(const String &attribute);
                Locale::Builder &setExtension(char key, const String &value);
                Locale::Builder &setLanguage(const String &language);
                Locale::Builder &setLanguageTag(const String languageTag);
                Locale::Builder &setLocale(const Locale &locale);
                Locale::Builder &setRegion(const String &region);
                Locale::Builder &setScript(const String script);
                Locale::Builder &setUnicodeLocaleKeyword(const String &key, const String &type);
                Locale::Builder &setVariant(const String &variant);
            };  // classBuilder

            class Category{

            };  // class Category

            class FilteringMode{

            };  // class FilteringMode

            class LanguageRange {
            public:
                static const double MAX_WEIGHT;
                static const double MIN_WEIGHT;

            public:
                LanguageRange(const String &range);
                LanguageRange(const String &range, double weight);

            public:
                static List<Locale::LanguageRange> mapEquivalents(const List<Locale::LanguageRange> &priorityList, const Map<String,List<String>> &map);
                static List<Locale::LanguageRange> parse(const String &ranges);
                static List<Locale::LanguageRange> parse(const String &ranges, const Map<String,List<String>> &map);

            public:
                boolean equals(const Object &target) const;
                String getRange() const;
                double getWeight() const;
                long hashCode() const;
            };  // class LanguageRange

        public:
            static const Locale ENGLISH;
            static const Locale FRENCH;
            static const Locale GERMAN;
            static const Locale ITALIAN;
            static const Locale JAPANESE;
            static const Locale KOREAN;
            static const Locale CHINESE;
            static const Locale SIMPLIFIED_CHINESE;
            static const Locale TRADITIONAL_CHINESE;
            static const Locale FRANCE;
            static const Locale GERMANY;
            static const Locale ITALY;
            static const Locale JAPAN;
            static const Locale KOREA;
            static const Locale CHINA;
            static const Locale PRC;
            static const Locale TAIWAN;
            static const Locale UK;
            static const Locale US;
            static const Locale CANADA;
            static const Locale CANADA_FRENCH;
            static const Locale ROOT;

        public:
            static const char PRIVATE_USE_EXTENSION;
            static const char UNICODE_LOCALE_EXTENSION;

        private:
            static const int DISPLAY_LANGUAGE = 0;
            static const int DISPLAY_COUNTRY = 1;
            static const int DISPLAY_VARIANT = 2;
            static const int DISPLAY_SCRIPT = 3;

        public:
            Locale(const String &language);
            Locale(const String &language, const String &country);
            Locale(const String &language, const String &country, const String &variant);
            virtual ~Locale();

        public:
            static List<Locale> filter(const List<Locale::LanguageRange> &priorityList, const Collection<Locale> &locales);
            static List<Locale>	filter(const List<Locale::LanguageRange> &priorityList, const Collection<Locale> &locales, const Locale::FilteringMode &mode);
            static List<String>	filterTags(const List<Locale::LanguageRange> &priorityList, const Collection<String> &tags);
            static List<String> filterTags(const List<Locale::LanguageRange> &priorityList, const Collection<String> &tags, const Locale::FilteringMode &mode);
            static Locale forLanguageTag(const String &languageTag);
            static Array<Locale> getAvailableLocales();
            static Locale getDefault();
            static Locale getDefault(const Locale::Category &category);
            static Array<String> getISOCountries();
            static Array<String> getISOLanguages();
            static Locale lookup(const List<Locale::LanguageRange> &priorityList, const Collection<Locale> &locales);
            static String lookupTag(const List<Locale::LanguageRange> &priorityList, const Collection<String> &tags);
            static void setDefault(const Locale::Category &category, const Locale &newLocale);
            static void setDefault(const Locale &newLocale);

        public:
            Locale clone();
            boolean equals(const Object &target) const;
            String getCountry() const;
            String getDisplayCountry() const;
            String getDisplayCountry(const Locale &inLocale) const;
            String getDisplayLanguage() const;
            String getDisplayLanguage(const Locale &inLocale) const;
            String getDisplayName() const;
            String getDisplayName(const Locale &inLocale) const;
            String getDisplayScript() const;
            String getDisplayScript(const Locale &inLocale) const;
            String getDisplayVariant() const;
            String getDisplayVariant(const Locale &inLocale) const;
            String getExtension(char key) const;
//          Set<Character> getExtensionKeys() const;
            String getISO3Country() const;
            String getISO3Language() const;
            String getLanguage() const;
            String getScript() const;
//          Set<String> getUnicodeLocaleAttributes() const;
//          Set<String> getUnicodeLocaleKeys() const;
            String getUnicodeLocaleType(const String &key) const;
            String getVariant() const;
            boolean hasExtensions() const;
            long hashCode() const;
            Locale stripExtensions() const;
            String toLanguageTag() const;
            string toString() const;
        };  // class Locale
    }  // namespace Util
}  // namespace Java

#endif  // NATIVE_JAVA_UTIL_LOCALE_HPP_
