def uniquify(paths: list[str]):
    existPaths = {}
    for path in paths:
        if not(path in existPaths.keys()):
            existPaths[path] = True
    return existPaths.keys()
