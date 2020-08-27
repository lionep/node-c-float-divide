#include <node.h>
#include <stdio.h>
#include <stdlib.h>

namespace divide {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(v8::Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong number of arguments")));
    return;
  }

  float num = args[0].As<v8::Number>()->Value();
  float den = args[1].As<v8::Number>()->Value();
  float rate = num / den;
  char result[64];
  sprintf(result, "%.15f", rate);

  args.GetReturnValue().Set(String::NewFromUtf8(
      isolate, result));
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "divide", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace divide
