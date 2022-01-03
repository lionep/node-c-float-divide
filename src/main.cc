#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <stdlib.h>

static void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
    return;
  }

  double num = args[0].As<v8::Number>()->Value();
  float den = args[1].As<v8::Number>()->Value();

  if (den == 0) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(v8::Exception::Error(
        v8::String::NewFromUtf8(isolate, "Could not divide by 0").ToLocalChecked()));
    return;
  }

  float rate = num / den;
  char result[64];
  sprintf(result, "%.15f", rate);

  args.GetReturnValue().Set(v8::String::NewFromUtf8(
        isolate, result).ToLocalChecked());
}

extern "C" NODE_MODULE_EXPORT void
NODE_MODULE_INITIALIZER(v8::Local<v8::Object> exports,
                        v8::Local<v8::Value> module,
                        v8::Local<v8::Context> context) {
  NODE_SET_METHOD(exports, "divide", Method);
}

void Initialize(v8::Local<v8::Object> exports,
                v8::Local<v8::Value> module,
                v8::Local<v8::Context> context) {
  auto isolate = context->GetIsolate();
  auto exception = v8::Exception::Error(v8::String::NewFromUtf8(isolate,
      "Initialize should never run!").ToLocalChecked());
  isolate->ThrowException(exception);
}

// Define a Node.js module, but with the wrong version. Node.js should still be
// able to load this module, multiple times even, because it exposes the
// specially named initializer above.
#undef NODE_MODULE_VERSION
#define NODE_MODULE_VERSION 3
NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)