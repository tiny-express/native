#include <native/node.hpp>

void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {

    String helloString = "Welcome to Native Library";
    HashMap<String, String> hashMap;
    hashMap.put("first name", "Loi");
    hashMap.put("last name", "Nguyen");

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, hashMap.toString()));
}

void Init(v8::Handle<v8::Object> exports) {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    exports->Set(v8::String::NewFromUtf8(isolate, "native"),
                 v8::FunctionTemplate::New(isolate, Method)->GetFunction());
}

NODE_MODULE(hello, Init)