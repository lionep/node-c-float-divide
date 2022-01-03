#include <nan.h>
#include <stdio.h>
#include <stdlib.h>

NAN_METHOD(divide) {
  if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowError(Nan::Error("Wrong number of arguments"));
    return;
  }

  double num = Nan::To<double>(info[0]).FromJust();
  double denD = Nan::To<double>(info[1]).FromJust();
  float den = (float) denD;

  if (den == 0) {
    // Throw an Error that is passed back to JavaScript
    Nan::ThrowError(Nan::Error("Could not divide by 0"));
    return;
  }

  float rate = num / den;
  char result[64];
  sprintf(result, "%.15f", rate);

  info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT(target, divide);
}

NODE_MODULE(nan_hello_world, Init)