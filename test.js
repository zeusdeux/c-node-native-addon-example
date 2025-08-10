console.log(
  `Direct require of addon.node:               ${require("./.build/addon.node").hello()}`,
);
console.log(
  `Indirect require of addon via a js wrapper: ${require("./addon").hello()}`,
);
