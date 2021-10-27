from os import path
import re


def get_dependencies(filePath: str) -> list[str]:
    filePath = path.normpath(filePath)
    file = open(filePath, "r")
    contents = file.read()
    matches = re.findall(r'\#include\s+"(.*\.h)\"', contents)
    deps = []
    for match in matches:
        dep = str.replace(match, ".h", ".c")
        relDir = path.dirname(filePath)
        dep = path.join(relDir, dep)
        dep = path.normpath(dep)
        if (path.exists(dep)):
            if not(dep in deps) and not(dep == filePath):
                deps.append(str.replace(dep, "\\", "/"))
                subdeps = get_dependencies(dep)
                for subdep in subdeps:
                    if not(subdep in deps):
                        deps.append(str.replace(subdep, "\\", "/"))
    return deps
