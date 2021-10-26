import {
  expandGlobSync,
  ensureDirSync,
} from "https://deno.land/std@0.113.0/fs/mod.ts";
import {
  relative,
  fromFileUrl,
  resolve,
} from "https://deno.land/std@0.113.0/path/mod.ts";

console.log("\x1b[38;5;46mStarting to build ...\x1b[0m");
const files: string[] = [];

console.log("Resolving root directory ... [1/4]");
const root = resolve(fromFileUrl(import.meta.url), "../../");

console.log("Getting files ... [2/4]");
for (const entry of expandGlobSync("**/*.c", {
  root: root,
  exclude: ["src/ADT/**"],
  //   globstar: true,
  //   extended: true,
})) {
  const driverRegex = new RegExp(/.*\.driver\.c/);
  const relativePath = relative(root, entry.path);
  const isDriver = relativePath.match(driverRegex);
  if (!isDriver) {
    files.push(relativePath.replaceAll(/\\/g, "/"));
  }
}

// files.forEach((file) => {
//   console.log(file);
// });

console.log("Ensuring dist directory ... [3/4]");
ensureDirSync("../dist");

const cmd = ["gcc", ...files, "-o", "dist/mobilita"];
console.log("Compiling ... [4/4]");
const proc = Deno.run({ cmd, cwd: "../" });
await proc.status();

console.log("\x1b[38;5;46mDone!\x1b[0m");
