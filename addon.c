#include <assert.h>
#include <node_api.h>
#include <js_native_api.h>

static napi_value Hello(napi_env env, napi_callback_info info)
{
  napi_value output_str;
  napi_status status = napi_create_string_utf8(env, "Hello from addon!", 17,  &output_str);
  assert(status == napi_ok);

  return output_str;
}

#define DECLARE_NAPI_METHOD(name, func) \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

NAPI_MODULE_INIT(/* napi_env env, napi_value exports */) {
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Hello);
  napi_status status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);

  return exports;
}
