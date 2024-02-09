# C based Node.js native addon

Teaching myself how to write native addons for Node.js in C.

> je ne parle pas C++ ¯\\\_(ツ)\_/¯

To use the exported function, do &emdash;

```bash
pnpm build &>/dev/null && node -e 'console.log("Value returned from addon:", require("./addon").hello())'
```

## Learnings

- The `target_name` in `binding.gyp` is what is passed to `bindings(...)` in `<root>/addon.js`
