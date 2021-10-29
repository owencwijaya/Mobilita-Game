from pathlib import Path


def get_all_files():
    paths = list(Path("../").rglob("*.c"))
    str_paths = []
    for path in paths:
        str_path = str(path)
        if not(str_path.endswith(".driver.c")):
            str_paths.append(str(path))
    return str_paths
