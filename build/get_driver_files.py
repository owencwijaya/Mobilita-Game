from pathlib import Path


def get_driver_files():
    paths = list(Path("../").rglob("*.driver.c"))
    strPaths = []
    for path in paths:
        strPaths.append(str(path))
    return strPaths
