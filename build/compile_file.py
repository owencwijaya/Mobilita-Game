import os
from os import path
from pathlib import Path
from get_dependencies import get_dependencies
from uniquify import uniquify

DIST_DIR = "dist"


def compile_file(filePath: str, dir: str):
    deps = get_dependencies(filePath)
    deps = uniquify(deps)
    fileName = str.replace(Path(filePath).name, ".driver.c", "")
    outPath = path.join("..", DIST_DIR, dir, fileName)
    outName = str.replace(outPath, "\\", "/")
    cmd = ["gcc", str.replace(filePath, "\\", "/"),
           *deps, "-o", outName]
    print(f'Compiling {fileName}')
    status = os.system(" ".join(cmd))
    if (status == 0):
        print("\033[38;5;46mCompilation successful!\033[0m")
    else:
        print("\033[38;5;196mFailed to compile. There was an error.\033[0m")
