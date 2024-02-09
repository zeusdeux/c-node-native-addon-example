#include <assert.h>
#include "./my_addon.h"

static napi_value Hello(napi_env env, napi_callback_info info)
{
  napi_status status;
  napi_value world;
  status = napi_create_string_utf8(env, "world", 5, &world);
  assert(status == napi_ok);
  return world;
}

#define DECLARE_NAPI_METHOD(name, func)         \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Export(napi_env env, napi_value exports)
{
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Hello);
  status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);
  return exports;
}

napi_value create_my_addon(napi_env env, napi_value exports)
{
  return Export(env, exports);
}
