import {
  expandGlobSync,
  ensureDirSync,
  WalkEntry,
} from "https://deno.land/std@0.113.0/fs/mod.ts";
import {
  relative,
  fromFileUrl,
  resolve,
  basename,
} from "https://deno.land/std@0.113.0/path/mod.ts";

console.log("\x1b[38;5;46mStarting to build ...\x1b[0m");
const files: WalkEntry[] = [];

console.log("Resolving root directory ...");
const root = resolve(fromFileUrl(import.meta.url), "../../");

console.log("Ensuring dist directory ...");
ensureDirSync("../dist");
ensureDirSync("../dist/drivers");

const headerOnly = ["macros.h", "boolean.h"];
console.log("Getting driver files ...\n");
for (const entry of expandGlobSync("**/*.driver.c", {
  root: root,
  exclude: ["src/ADT/**"],
  //   globstar: true,
  //   extended: true,
})) {
  files.push(entry);
  const relativePath = relative(root, entry.path);
  const decoder = new TextDecoder("utf-8");
  const buffer = decoder.decode(Deno.readFileSync(entry.path));
  const matches = buffer.matchAll(/\#include\s+"(.*)\"/g);
  const cmd = ["gcc", relativePath.replaceAll(/\\/g, "/")];
  for (const match of matches) {
    let included = resolve(resolve(entry.path, "../"), match[1]);
    included = relative(root, included);
    if (!headerOnly.includes(basename(included))) {
      cmd.push(included.replaceAll(/\\/g, "/").replace(".h", ".c"));
    }
  }
  const outName =
    "dist/drivers/" + basename(relativePath).replace(".driver.c", "");
  cmd.push("-o");
  cmd.push(outName);
  console.log(`Compiling ${outName}`);
  const proc = Deno.run({ cmd, cwd: "../" });
  const status = await proc.status();
  if (status.success) {
    console.log("\x1b[38;5;46mSuccess!\x1b[0m");
  } else {
    console.log("\x1b[38;5;196mFailed!\x1b[0m");
  }
  console.log();
}

console.log("\x1b[38;5;46mDone!\x1b[0m");
