# C based minimal Node.js native addon example

An example of a Node.js native addon using C.

No extra tools other than node and a C compiler on `$PATH` for build.
`node-gyp` that ships with node is used to install node headers.

If you are on windows, you can write a `build.bat` based off of
the `Makefile` yourself.

To build and run the addon &mdash;

```bash
npm run build && npm test
# Should print Hello from addon!
# No npm install necessary either btw.
```

## Learnings

- `.node` extension is necessary for `node` to actually load the addon
