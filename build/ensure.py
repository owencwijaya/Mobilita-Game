from os import mkdir, path


def ensure_all_outdir():
    if not(path.isdir("../dist")):
        mkdir("../dist")


def ensure_drivers_outdir():
    ensure_all_outdir()
    if not(path.isdir("../dist/drivers")):
        mkdir("../dist/drivers")
