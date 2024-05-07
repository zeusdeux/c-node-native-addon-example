#include <node_api.h>
#include "./src/my_addon.h"

NAPI_MODULE_INIT(/* napi_env env, napi_value exports */) {
  return create_my_addon(env, exports);
}
