import os
from pathlib import Path
from os import path

base = path.basename(os.getcwd())

if (base != "build"):
    os.chdir("build")

excluded = []
paths = list(Path("../").rglob("*.c"))

for p in paths:
    str_path = str(p)
    if str_path.find("ADT") != -1:
        excluded.append(str_path)

excluded.append(path.normpath("../src/commandMatching.c"))
excluded.append(path.normpath("../src/configInput.c"))


def excludes(path: str):
    global excluded
    return not(path in excluded)
